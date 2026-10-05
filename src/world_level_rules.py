"""启用原版世界开放、阶段勋章解锁与社区核心权限规则。"""


class WorldLevelRules:
    def __init__(self, p):
        self.p = p
        if (not hasattr(p.uc.lib, 'msd_native_level_rules_version')
                or p.uc.lib.msd_native_level_rules_version() != 1):
            raise RuntimeError('原版等级解锁流程需要匹配的游戏核心')
        p.uc.lib.msd_enable_world_level_rules()
        # 最终区域通关后的后继入口属于原生结算结果；兼容历史缺失状态。
        restored = []
        for world in (0, 1):
            if (p.call('_Z19IsAreaClearSaveDataii9WorldType', world, 11, 0)
                    and not p.call('_Z12IsAreaEnableii9WorldType', world + 1, 0, 0)):
                p.call('_Z21SetAreaEnableSaveDataiib9WorldType', world + 1, 0, 0, 0)
                restored.append(world + 1)
        p.log('NATIVE_PLAYER_LEVEL_RULES', 1)
        if restored:
            p.log('NATIVE_WORLD_ENTRY_RECOVERY', restored)
