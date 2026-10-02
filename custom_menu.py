"""Read a user PNG as an in-memory replacement for the menu monitor atlas."""
from pathlib import Path
import hashlib,json,struct

CONTENT_SIZE=(360,240)
ATLAS_SIZE=(512,256)
FILE_NAME='menu_screen.png'
ASSET_NAMES=frozenset(('menu_news00.obm','menu_news00_us.obm',
                       'menu_news00_hk.obm','menu_news00_kr.obm'))

class MenuScreenOverride:
    """Load at first menu access; retain one immutable atlas per game session."""
    def __init__(self,folder,log,filename=FILE_NAME):
        self.folder=Path(folder);self.log=log;self.loaded=False
        self.filename=filename
        self.atlas=None;self.metadata=None;self.reported_assets=set()

    def read_asset(self,path,mode,asset_folder):
        path=Path(path)
        if path.parent!=Path(asset_folder) or path.name not in ASSET_NAMES:
            return None
        if not mode.startswith('r') or any(c in mode for c in 'wa+'):
            return None
        if not self.loaded:self._load()
        if self.atlas is not None and path.name not in self.reported_assets:
            self.reported_assets.add(path.name)
            self.log('CUSTOM_MENU_ASSET',path.name,self.metadata['atlas_sha256'])
        return self.atlas

    def _load(self):
        self.loaded=True;source=self.folder/self.filename
        if not source.is_file():
            self.log('CUSTOM_MENU_DEFAULT',str(source));return
        try:
            from PIL import Image,ImageOps
            with Image.open(source) as original:
                if original.format!='PNG':raise ValueError('The menu image must use PNG format')
                if original.width*original.height>16_000_000:
                    raise ValueError('The menu image exceeds 16 million pixels')
                image=ImageOps.exif_transpose(original).convert('RGBA')
            iw,ih=image.size;cw,ch=CONTENT_SIZE
            scale=min(cw/iw,ch/ih)
            size=(max(1,min(cw,round(iw*scale))),max(1,min(ch,round(ih*scale))))
            if size!=image.size:image=image.resize(size,Image.Resampling.LANCZOS)
            # Fit the complete source and composite transparency onto the
            # monitor's black backing; preserve the atlas and frame geometry.
            offset=((cw-size[0])//2,(ch-size[1])//2)
            atlas=Image.new('RGB',ATLAS_SIZE,'black');atlas.paste(image,offset,image)
            self.atlas=b'OI\x00\x20'+struct.pack('<HH',*ATLAS_SIZE)+atlas.tobytes()
            self.metadata={'source':str(source),'source_size':[iw,ih],
                'content_size':list(CONTENT_SIZE),'fitted_size':list(size),
                'content_offset':list(offset),'atlas_size':list(ATLAS_SIZE),
                'source_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
                'atlas_sha256':hashlib.sha256(self.atlas).hexdigest(),
                'fit':'contain','reference_crop':False,'nonuniform_stretch':False}
            self.log('CUSTOM_MENU_LOADED',json.dumps(self.metadata,ensure_ascii=False))
        except Exception as error:
            self.atlas=None
            self.log('CUSTOM_MENU_INVALID',str(source),type(error).__name__,str(error))
