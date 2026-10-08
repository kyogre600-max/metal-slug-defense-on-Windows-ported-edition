"""活动分期视图采用独立入口，并保留既有活动进度身份。"""
from pathlib import Path
import copy
import json


class EventPhases:
    def __init__(self, root, data):
        path = Path(root) / 'historical_events/phase_views.json'
        document = json.loads(path.read_text(encoding='utf-8')) if path.exists() else {'schema': 1, 'families': {}}
        if document.get('schema') != 1:
            raise ValueError('Unsupported Event phase schema')
        self.families = document.get('families', {})
        for key, family in self.families.items():
            if key not in data or family.get('progress_key') != key:
                raise ValueError('Event phase progress identity must retain its existing family key')
            stages = [s['id'] for s in data[key]['stages']]
            products = {r['id'] for r in data[key].get('shop', {}).get('rows', [])}
            for phase in family['parts'].values():
                ids = phase['stage_ids']
                if ids != stages[:len(ids)] or len(ids) != len(set(ids)):
                    raise ValueError('Event phase stages must match the original ordered prefix')
                if not set(phase['shop_ids']).issubset(products):
                    raise ValueError('Event phase products are outside the source catalog')

    def resolve(self, key, phase_id=None):
        family = self.families.get(key)
        if family is None:
            if phase_id is not None:
                raise ValueError('Phase requested for an unphased Event')
            return None
        phase_id = phase_id or ('part2' if family.get('default_part2', True) else 'part1')
        if phase_id not in family['parts']:
            raise ValueError('Unknown Event phase')
        return phase_id

    def part(self, key, phase_id=None):
        phase_id = self.resolve(key, phase_id)
        return self.families[key]['parts'][phase_id] if phase_id is not None else None

    def map_view(self, key, phase_id, source):
        phase = self.part(key, phase_id)
        if phase is None:
            return source
        allowed = set(phase['stage_ids'])
        view = copy.deepcopy(source)
        areas = []
        for area in view['areas']:
            markers = [m for m in area['markers'] if m['stage_id'] in allowed]
            if not markers:
                continue
            if len(markers) != len(area['markers']):
                raise ValueError('Event phase cannot split an original area marker record')
            area['markers'] = markers
            areas.append(area)
        view['areas'] = areas
        view['world_count'] = max((a['world'] for a in areas), default=-1) + 1
        prisoners = {str(a['prisoner_id']) for a in areas if a['prisoner_id'] >= 0}
        view['prisoners'] = {k: v for k, v in view['prisoners'].items() if k in prisoners}
        return view
