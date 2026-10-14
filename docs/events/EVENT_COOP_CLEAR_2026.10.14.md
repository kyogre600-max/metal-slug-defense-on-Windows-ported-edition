# 合作活动通关记录修正（2026-10-14，宿主修改，核心保持 r57）

## 1. 现象

用户报告：EVENT 浏览页最后两个入口（合作活动 PART 1、PART 2，`cooperation_2016_current`）以 S 级通关后，回到地图时该关显示为未游玩。

## 2. 原因

- 合作活动以原生模式 6 运行（EventMSD WorldType 4），关卡经原生合作编队（场景 74）开战。
- 宿主登记关卡的两个核心钩子位于 `BattleInit_StageClearMode`（0x101e5b99）与 `BattleInit_SurvivalMode`（0x101e5cff），合作关卡的开战不经过这两处，宿主的 `active_battle` 始终为空。
- 战斗结束时，核心钩子 `event_end`（`SC_BattleEnd`，0x101ea099）在模式 6 下交原生结算，宿主的 `finish_battle` 不运行。
- 原生结算把通关写入原生存档，但地图读取通关、时间与救出数的函数（`IsStageClearSaveData`、`GetStageClearTimeSaveData`、`GetPrisonerSaveData`）已由核心钩子改读宿主的活动进度表（`historical_event_progress.json` 经 `NativeEventMap.enable` 写入）。宿主进度中没有这场胜利，地图因此显示未游玩。
- 合作积分由既有的每帧同步回写，不受影响。
- M6b-4 的自制合作活动（`current_cooperation`）走同一路径，有同样问题。

## 3. 修正

`event_trial.py`（含 `src/` 镜像）新增 `track_native_coop`，只在所选活动为合作类、EventMSD 有效且模式为 6 时运行：

- 进入战斗场景 100 时，按地图当前选择（`app+0xc624` 世界、`+0xc628` 区域、`+0xc62c` 小关）在地图表中找到该关，登记 `active_battle`（标记 `native_coop`）。
- 离开场景 100 后、BattleMain 释放前（场景 101–107，实测约 12 帧）读取胜负（BattleMain+0x1c）、时间（+0x48）与救出数（`getGetPrisoner`），写入活动进度。
  - 通关、时间与救出数经 `NativeEventMap.save_result` 同时写入地图表。
  - 胜利时照常处理人质奖励与首胜单位奖励。
- 原生结算、积分、MSP 与原生画面流程不变；核心未改。
- 既有的战败继续弹窗处理路径不作用于合作战斗（交原生处理）。

## 4. 验证

隔离存档，核心 r57，未计算 SHA-256。驱动 `verification/coop_clear_20261014/driver_coop.py`。

| 用例 | 结果 |
| --- | --- |
| 修正前复现（PART 1 第 1 关，受控胜利） | 宿主未登记战斗；回到地图后宿主进度为空、通关 0、时间 0 |
| PART 1 第 1 区第 1 关，胜利 | 进度：挑战 1、胜利 1、时间 6；地图：通关 1、时间 6、评级 0；回基地再出击后保持；进度文件已写入 |
| PART 2 第 2 区第 2 关，胜利 | 同上，确认按地图选择定位非首关正确 |
| PART 1 第 1 关，战败 | 挑战 1、胜利 0，地图仍为未通关 |

回归：

- EVENT 原生流程（`event_repair_20261008/native/driver_native_runtime.py --all`，13 个入口的基地、地图与商店返回）：156/156。
- M6b-4 自制合作活动（`run_tokens.py --phase coop`）：5/5，积分 15→30；该关在活动进度中记录挑战 1、胜利 1、时间 30（修正前为空）。

## 5. 限制

- 修正前已通关的合作关卡不会自动恢复为已通关（宿主进度中没有记录），需要重新游玩一次。
- 实体窗口手动操作、合作联机（原生 NPC / 联机接口）未测试。
