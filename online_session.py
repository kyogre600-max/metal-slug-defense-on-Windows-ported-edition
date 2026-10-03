"""自有服务器的版本化传输契约；原生战斗调用由宿主线程执行。"""
import socket,ssl,struct,json,uuid,ipaddress,re,hashlib
PROTOCOL=1
MAX_PACKET=65536
MODES=('coop','pvp')
COMMANDS=('deploy','special','upgrade_ap','slug_attack','pause','resume')

def fingerprint(unit_manifest,campaign_catalog):
    normalized=dict(unit_manifest)
    normalized['stages']=[s for s in normalized.get('stages',[]) if s.get('key') not in campaign_catalog.scenes]
    if not normalized['stages']:normalized.pop('stages')
    raw={'units':normalized,'campaign':campaign_catalog.raw,'combat_contract':1}
    return hashlib.sha256(json.dumps(raw,sort_keys=True,separators=(',',':'),ensure_ascii=False).encode()).hexdigest()

def encode(message):
    if not isinstance(message,dict):raise ValueError('协议消息要求对象结构')
    data=json.dumps(message,separators=(',',':'),allow_nan=False).encode()
    if not 0<len(data)<=MAX_PACKET:raise ValueError('协议消息超过容量')
    return struct.pack('!I',len(data))+data

def receive(sock):
    def exact(size):
        data=bytearray()
        while len(data)<size:
            chunk=sock.recv(size-len(data))
            if not chunk:raise EOFError('连接已关闭')
            data.extend(chunk)
        return bytes(data)
    size=struct.unpack('!I',exact(4))[0]
    if not 0<size<=MAX_PACKET:raise ValueError('协议消息长度无效')
    def invalid(value):raise ValueError('协议包含非有限数值')
    message=json.loads(exact(size),parse_constant=invalid)
    if not isinstance(message,dict):raise ValueError('协议消息要求对象结构')
    return message

def validate_command(message):
    if message.get('command') not in COMMANDS:raise ValueError('未知战斗输入')
    for field in ('frame','sequence'):
        v=message.get(field)
        if type(v) is not int or not 0<=v<=0x7fffffff:raise ValueError('帧号或序号无效')
    if message['command']=='deploy':
        uid=message.get('unit_id');key=message.get('unit_key')
        if type(uid) is not int or not 1<=uid<=0xffffffff:raise ValueError('单位 ID 应为 uint32')
        if not isinstance(key,str) or not re.fullmatch(r'[a-zA-Z0-9_.-]{1,120}',key):raise ValueError('单位稳定键无效')
    if 'slot' in message and (type(message['slot']) is not int or not 0<=message['slot']<10):raise ValueError('出击槽位无效')

def validate_snapshot(message):
    if type(message.get('frame')) is not int or not 0<=message['frame']<=0x7fffffff:raise ValueError('状态帧号无效')
    units=message.get('units')
    if not isinstance(units,list) or len(units)>160:raise ValueError('单位状态容量超出范围')
    import math
    seen=set()
    for unit in units:
        for field,low,high in (('unit_id',0,0xffffffff),('instance_id',0,0xffffffff),('team',0,1),('hp',0,0x7fffffff)):
            value=unit.get(field)
            if type(value) is not int or not low<=value<=high:raise ValueError('单位状态整数无效')
        key=unit.get('unit_key')
        if not isinstance(key,str) or not re.fullmatch(r'[a-zA-Z0-9_.-]{1,120}',key):raise ValueError('单位状态内容键无效')
        for field in ('x','y'):
            value=unit.get(field)
            if type(value) not in (int,float) or not math.isfinite(value) or abs(value)>100000:raise ValueError('单位位置无效')
        identity=(unit['team'],unit['instance_id'])
        if identity in seen:raise ValueError('单位实例身份重复')
        seen.add(identity)
    return hashlib.sha256(json.dumps({'frame':message['frame'],'units':units},sort_keys=True,separators=(',',':'),allow_nan=False).encode()).hexdigest()

class OnlineClient:
    def __init__(self,content_hash):
        self.content_hash=content_hash;self.socket=None;self.session_id=None;self.sequence=0;self.room=None;self.buffer=bytearray()
    def connect(self,host,port,token,tls=True,ca_file=None,timeout=5):
        self.close()
        if not tls:
            try:local=ipaddress.ip_address(host).is_loopback
            except ValueError:local=host=='localhost'
            if not local:raise ValueError('外部服务器连接要求 TLS')
        sock=socket.create_connection((host,port),timeout)
        try:
            if tls:sock=ssl.create_default_context(cafile=ca_file).wrap_socket(sock,server_hostname=host)
            sock.sendall(encode({'type':'hello','protocol':PROTOCOL,'content_hash':self.content_hash,'token':token,'client_id':str(uuid.uuid4())}))
            reply=receive(sock)
            if reply.get('type')!='welcome':raise ValueError(reply.get('reason','握手失败'))
            self.socket=sock;self.session_id=reply['session_id'];return reply
        except Exception:sock.close();raise
    def send(self,message):
        if self.socket is None:raise RuntimeError('服务器尚未连接')
        self.socket.sendall(encode(message))
    def join(self,room,mode='coop'):
        if mode not in MODES or not re.fullmatch(r'[a-zA-Z0-9_.-]{1,64}',room):raise ValueError('房间或对战模式无效')
        self.send({'type':'join','room':room,'mode':mode});self.room=room
    def input(self,frame,command,**fields):
        message=dict(fields,type='input',frame=frame,command=command,sequence=self.sequence)
        validate_command(message);self.send(message);self.sequence+=1
    def snapshot(self,frame,units):
        message={'type':'snapshot','frame':frame,'units':units}
        message['state_hash']=validate_snapshot(message);self.send(message)
    def poll(self,limit=64):
        if not self.socket:return []
        import select
        messages=[]
        while len(messages)<limit:
            if len(self.buffer)>=4:
                size=struct.unpack('!I',self.buffer[:4])[0]
                if not 0<size<=MAX_PACKET:self.close();raise ValueError('协议消息长度无效')
                if len(self.buffer)>=4+size:
                    raw=bytes(self.buffer[4:4+size]);del self.buffer[:4+size]
                    def invalid(value):raise ValueError('协议包含非有限数值')
                    message=json.loads(raw,parse_constant=invalid)
                    if not isinstance(message,dict):raise ValueError('协议消息要求对象结构')
                    messages.append(message);continue
            pending=isinstance(self.socket,ssl.SSLSocket) and self.socket.pending()>0
            if not pending and not select.select([self.socket],[],[],0)[0]:break
            data=self.socket.recv(MAX_PACKET)
            if not data:self.close();break
            self.buffer.extend(data)
            if len(self.buffer)>MAX_PACKET*2:self.close();raise ValueError('协议接收缓冲超过容量')
        return messages
    def close(self):
        if self.socket:
            try:self.socket.shutdown(socket.SHUT_RDWR)
            except OSError:pass
            self.socket.close()
        self.socket=None;self.room=None;self.session_id=None;self.sequence=0;self.buffer.clear()
