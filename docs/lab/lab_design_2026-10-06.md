# LAB 自定义功能实现方案（2026-10-06，同日修订：敌方配兵改为底部出兵栏左右分栏）

决定：等级基准暂定 **Lv40**（表/里世界 4 未设计）；其余设定照搬 MSA 实验室（见 `roadmap_lab_pvp_2026-10-06.md`）。本文只讨论本项目的自定义部分：**完全控制模式、敌方配兵条、LAB 战斗中菜单**，以及它们依赖的 LAB 战斗底座。

依据：正式版仓库 `battle_controls.py`、`player.py`、`probe.py`（`activate_unit_slot`）、`local_platform.py`、`event_trial.py`、`graphics.py`、`window_layout.py`，原版 `libAppMain.so` 导出符号，`src/generated/blocks_032/034.cpp`。只读核查，未运行。标“待实测”的项需在隔离存档下运行确认。

---

## 1. 核查结论（原生战斗结构）

### 1.1 控制器类
| 类 | 用途 | 关键方法 |
| --- | --- | --- |
| `BattleController` | 基类 | `createUnit(int)`（→`BattleGameMaster::notifyEventUnitCreate`）、`getUnitInfo(int)`、`isUnitCountOver()`、`initialize(team,member)` |
| `BattleControllerPlayerBase` | 有 AP 的一方 | `isUnitCreate(int)`、`createUnit(int)`、`getAP/getMaxAP/plusAP`、`clearCreateUnitWaitTimer()`、`actionKyotenLevelMax()`、`startAutoPlay/resetAutoPlay/getAutoPlay`、`noukinAutoPlay()`（由 `update` 调用，即 AUTO 出兵逻辑） |
| `BattleControllerPlayer` | 本地玩家 | 继承 PlayerBase |
| `BattleControllerNetPlayer` | 联机玩家 | `update` 调 `PlayerBase::update` 后经 `CGameCenter::GetRecvData(int, MSG_BATTLE_CMD*)` 取对端指令，分派到 `BattleGameMaster::notifyEventUnitCreate/UnitSpAttack/MetasuraHou/OnlineTimer`；`onEvent*First` 经 `AppMain::SendData` 发出 |
| `BattleControllerEnemy` | 关卡敌方（脚本 `runScriptAction`） | 无 AP |
| `BattleControllerNetEnemy` | 继承 Enemy，联机协作敌方 | — |

### 1.2 `BattleScene::initialize`（0x1d43b8）按 GameMode（scene+0x24）建控制器
- 先固定建 `BattleControllerPlayer` 与 `BattlePlayerOperator`（scene+0x3c，`battle_controls.player_controller` 即由此取控制器）。
- 再按模式（TBB 跳转表 0x1d448c）建其他控制器，写入 scene+0x40 起的数组（下标 = 队伍/成员组合 +16）：
  - 0 → `Enemy`（关卡）
  - 1 → 1 个 `NetPlayer`（1v1 联机）
  - 2 → 3 个 `NetPlayer`（2v2）
  - 3 → `NetMultiPlayer` + `NetEnemy`（协作）
  - 4/5/6/7 → 其他分支，待细读
- NPC 对战：`AppMain::GetPlayerInfo` 在 NPC 时调用 `AppMain::MakeNPCInfo(_SEND_MESSAGE*, char*)` 在本地伪造对手信息（含牌组）；`local_platform` 已用 `app+0xc061==1 && app+0xc63c==4` 识别 NPC 模式。

### 1.3 对两项任务的意义
1. **联机协议是指令型**（出兵/绝招/弹头车/据点升级 + 计时），收发全部经过 `CGameCenter::GetRecvData` 与 `AppMain::SendData`。任务二可在这两处替换传输层，阶段 0.4 的方向基本明确。
2. **LAB 以 Wi-Fi NPC 对战为底座最合适**：双据点、PvP 场地、对手为带 AP 和 10 槽牌组的控制器、对手出兵由 AUTO（`noukinAutoPlay`）驱动。完全控制只需对**对手控制器**调用现成方法，无需新写 AI。

**R1（静态已确认，2026-10-06）**：`BattleControllerNetPlayer` 构造函数调用 `BattleControllerPlayerBase` 构造函数；其虚表 +0x94/+0x98/+0xa0/+0xa8 分别为 `PlayerBase::createUnit`、`BattleController::actionUnitSpAttack`、`PlayerBase::actionMetasuraHou`、`PlayerBase::actionKyotenLevelup`，与 `BattleControllerPlayer` 相同；`NetPlayer::update` 调用 `PlayerBase::update`（内含 `noukinAutoPlay`）。因此 GameMode 1 的对手控制器属于 PlayerBase 系，具备 AP、10 槽、出兵、绝招、弹头车、据点升级与 AUTO。运行时探测改为在 LAB 入口原型中顺带记录。
- 现状限制：Wi-Fi 菜单受残留 Google Play 登录判断阻挡，无法从菜单进入 NPC 对战（用户 2026-10-06）。LAB 入口应**绕过 Wi-Fi 菜单**，参照 `EventTrial.start_battle` 直接调用 `AppMain::BattleInit_OnlinerMode(int, BattleTeamID)` 建立 1v1 战斗，并预先填好对手信息（`GetPlayerInfo`/`MakeNPCInfo` 路径）。需核查：该模式下 `BattleSceneNetworkWait` 等待、`OnlineTimer` 同步与 `NetPlayer::onEvent*First` → `AppMain::SendData` 在无网络时的行为（`local_platform` 需在 LAB 中本地吞掉发送）。
- 附带发现（任务二）：`CGameCenter` 含 `getBroadcastWifiListData/getBroadcastWifiListMax`、`connectMatch(sockaddr_in*)`，原版疑似有局域网广播配对路径，可作为同 Wi-Fi 联机的切入点。

---

## 2. LAB 战斗底座

| 需求 | 实现 |
| --- | --- |
| 进入 LAB | 宿主层入口（与 `EventTrial` 同一模式：自绘面板 + 热区，经 `SceneEndFunc/ChangeExeST` 切场景）。快捷键可先用 F7。 |
| 敌方牌组 | 钩住 `MakeNPCInfo`：LAB 激活时以 LAB 敌方牌组（UnitID、等级）覆盖伪造的对手信息。社区单位 ≥1024 需确认该消息结构里单位 ID 的位宽（code map 第 5 节：原协议 10 位 UID）——若放不下，敌方牌组改在控制器初始化后直接写槽位信息（`getUnitInfo` 返回的结构：+0 成本、+0xc 可用、+0x10 UnitID、+0x18 冷却）。 |
| 我方牌组 | 战斗开始前临时换牌组（`BattleStartSetUnit` 前写入），战后还原。 |
| Lv40 / 未持有单位 | LAB 激活期间钩 `GetUnitLevelSaveData`，返回 LAB 设定等级（默认 39 = Lv40，按存档表示方式核对），**不改存档**。 |
| 双方据点等级 | 最高/当前：`setupBaseStatus` 后改写，或对双方调用 `actionKyotenLevelMax`。 |
| 场地 | NPC 对战的地图选择处注入 LAB 选择的地图 ID。 |
| 不给奖励、不写存档 | 战斗结束跳过 `SelectWiFiResultPanel` 的结算；LAB 期间拦截 `WriteMainSaveData*`（参照 `EventTrial.transaction` 的快照/还原）。 |
| 联网调用 | NPC 模式下 `sendDataTCP/UDP`、`startQuickGame` 已由 `local_platform` 本地吞掉，LAB 沿用。 |

---

## 3.0 控制权与 AI 设定（用户确认 2026-10-06，优先于下文）

- **默认：敌方完全由玩家手动控制，敌方 AI 关闭**；我方同样手动。
- 前置准备界面与战斗中菜单均可分别设定四个开关：
  | 开关 | 默认 |
  | --- | --- |
  | 我方 AI 自动出兵 | 关 |
  | 我方自动释放绝招 | 关 |
  | 敌方 AI 自动出兵 | 关 |
  | 敌方自动释放绝招 | 关 |
- 这四个开关与“完全控制模式”（无冷却 / 不耗 AP / AP 无限）**相互独立**：完全控制只管资源与冷却，AI 开关只管谁来下指令。
- 原生依据：`BattleControllerPlayerBase::startAutoPlay/resetAutoPlay/getAutoPlay` 控制 AUTO；AUTO 逻辑 `noukinAutoPlay` 内部调用 `BattleUnit::isSpAttack` 并发动绝招（调用点 0x1cc050），即原生 AUTO 出兵与自动绝招是绑在一起的。拆成两个开关的做法：钩住 `noukinAutoPlay` 的绝招分支，按该方“自动绝招”开关决定是否执行；“自动绝招开 + 自动出兵关”时，由钩子只运行绝招分支（或宿主每帧对就绪单位调用 `actionUnitSpAttack`，与 `battle_controls.special_all` 同法）。
- 敌方手动绝招与其他操作需要按键（待用户确认），建议紧接 Q–P 之后：`[` 敌方 AP 升级、`]` 敌方弹头车、`\` 敌方全体绝招；另支持点击战场上的敌方单位发动其绝招（原生点击仅处理本方单位，需钩 `onGameScreenTouchEnded` 的阵营判断）。
- 按键已确认：`[` 敌方 AP 升级、`]` 敌方弹头车、`\` 敌方全体绝招。
- **敌方 AP 升级 / 弹头车的“影子按钮”**（用户方案 2026-10-06）：在我方按钮**之下**再画一份半透明、红色调的敌方按钮，向外上方错开——AP 升级的影子在我方 AP 按钮左上，弹头车影子在我方弹头车右上，偏移约 (∓14, −7) 逻辑像素，不透明度约 55%，不超出底栏框架。
  - 实测空间：AP 按钮框 x 122–253、y 580–713；弹头车框 x 1025–1156、y 585–708（坦克图超出框顶约 20 px）；底栏框架上沿 y≈573，按钮上方只有约 7 px，因此纵向偏移上限约 7 px；横向在新布局下外侧余量 AP≈51、弹头车≈38，足够。
  - 绘制：`drawUI` 中在画我方按钮之前，以敌方控制器状态再画一次同一按钮（坐标偏移 + `setSpriteFog`/`setColor` 红色调 + 半透明），之后正常画我方按钮覆盖其上。
  - 影子大部分被遮住，敌方的数值（AP 升级费用、弹头车充能条）看不清；用影子整体亮度表达状态：可升级 / 已充满时提亮或闪烁，不可用时保持暗淡（用户确认 2026-10-06）。
  - 示意图：`enemy_ghost_mockup.png`（基于用户截图合成，仅示意位置与透明度）。
- **敌方 AP 数值框**（用户方案 2026-10-06）：我方 AP 框（左下，约 x 0–285、y 505–570）镜像到右下（约 x 995–1280、同高），底色改为红色。
  - 原生依据：`BattlePlayerOperator::drawApBar`（0x1d7ac4）由 `drawUI` 调用（0x1d84dc、0x1d9788 两处）。做法：在其后以敌方控制器的 AP / 上限再调用一次，坐标镜像；框体贴图水平翻转（`Graphics::setFlipMode`），数字与 “AP:” 文字不翻转；框体底色以红色调着色。数字颜色先保持原绿色，若在红底上不清楚再改为浅色。
  - 完全控制模式下 AP 无限：两侧数值框可显示满值或 “∞”（待定）。
  - 注意：镜像后该框覆盖战场右下角（敌方据点附近地面一带），与我方框覆盖左下角对称。


## 3. 完全控制模式

### 3.1 按键（`player.py`）
- 现有绑定：1–0 我方槽位、Space 全绝招、` AP 升级、- 弹头车、= 全出击、F6/F9/F11/F12、Esc。**Q–P 未占用。**
- `Player.key()` 新增：Q W E R T Y U I O P → `('enemy_unit', 0..9)`，仅在 LAB 战斗中入队，其他场景忽略。
- 游戏线程中处理 `enemy_unit`：调用新函数 `lab.activate_enemy_slot(slot)`，结果写入 `last_unit_result` 和 `unit_feedback`，与 `activate_unit_slot` 一致。

### 3.2 敌方出兵
- 新增 `battle_controls.opponent_controller(p, main)`：遍历 scene+0x40 数组，取 team（controller+0x38c）≠ 我方 team 的控制器。
- `activate_enemy_slot` 复用 `probe.activate_unit_slot` 的逻辑，只是换成对手控制器：`getUnitInfo` → `isUnitCountOver` → `isUnitCreate` → vtable+0x94 `createUnit(slot)`。
- 敌方 AUTO 由第 3.0 节开关决定（默认关）：关时对对手调用 `resetAutoPlay()`，开时 `startAutoPlay()`。若 `resetAutoPlay` 不能完全停止 AI（待实测 R2），改为原生钩子：`noukinAutoPlay` 入口处检查开关后直接返回。

### 3.3 无冷却、不耗 AP、AP 无限（双方）

**方案 A：原生钩子（正式实现）**
- 新共享内存头 `0x1ffec000`，魔数 `0x4c414231`（LAB1），字段：`active`、`full_control`、`player_team`、`opponent_team`、`strip_band`、保留位。宿主 `lab.py` 写，`lab_hooks.cpp` 读。
- `HOOK(PlayerBase::isUnitCreate)`：`full_control` 时，只要槽位非空、单位可用、未超过单位数上限，就直接返回真（忽略 AP 和冷却）。
- `HOOK(PlayerBase::createUnit)`：`full_control` 时记录调用前的 AP，原生创建后写回（不扣 AP），并清该槽冷却。
- AP 显示：`full_control` 时 `getAP` 返回 `getMaxAP`。
- 优点：不受 AP 上限影响；1–0 和 Q–P 走同一套原生判断；不需要逐帧写内存。

**方案 B：宿主层（原型）**
- 开启时对双方 `actionKyotenLevelMax()`；每帧 `plusAP(getMaxAP(level) - getAP())`；每次出兵后 `clearCreateUnitWaitTimer()`。
- 局限：单价超过 AP 上限的单位仍出不来；关闭时需还原据点等级与 AP 快照。

先用方案 B 验证流程，正式实现采用方案 A。

### 3.4 关闭完全控制
- 清除标志恢复 AP、冷却的原生判断（方案 B 还原快照）。
- AI 开关状态不变（按第 3.0 节）。
- 已在场的单位保留。

---

## 4. 敌方配兵：底部出兵栏左右分栏（2026-10-06 用户方案，取代画面外信息带）

画面顶部是双方据点 HP 与战场雷达，不能遮挡。采用用户方案：LAB 中把原生底部操作栏改为
`[AP 升级（缩小）] [我方 3 格 | 敌方 3 格] [弹头车（缩小）]`。
布局前提（用户确认 2026-10-06）：分栏只按 16:9 布局设计，不再兼容原版窄画面布局（原比例放不下 6 格 + 两侧按钮）。Windows 版逻辑画布固定 1280×720（`window_layout.WIDTH/HEIGHT`），实际运行不受影响；原比例坐标仅作参考。

左右各显示 3 格、各自可滚动浏览 10 个单位（原版为 5 格显示、共 10 个单位），合计 20 个单位；操作逻辑与原版相同。仅 LAB 中启用，其他模式保持原栏。

### 4.1 原生结构（符号核查）
- 整个战斗 HUD 由 `BattlePlayerOperator::drawUI`（0x1d7ca8–0x1d9a90，约 7.6 KB）绘制：顶部 HP/雷达、AP 条（`drawApBar`）、出兵栏、AP 升级、弹头车、暂停等。
- 出兵栏位置：`getUnitPanelScreenPosition`（0x1d6df6），被 `drawUI` 与 `getUnitIndex` 调用，推断为出兵栏横向滚动位置。
- 点击：`getUnitIndex(x,y)`（0x1d6e40）把触点换成槽位，由 `onUITouchBegan/Moved/Ended` 使用（Moved 即拖动滚动）；按钮类命中推断由 `getScreenItem(x,y)`（0x1d6d8c）处理。
- Operator 只绑定一个控制器（operator+0x18，构造函数 `BattlePlayerOperator(GameMode, BattleControllerPlayer*)`）。
- 先例：本项目已把 16:9 布局的界面位置调整进原生绘制，并在原生战斗暂停页加入音频开关（AGENTS.md 第 99、364 行），说明改原生 HUD 坐标与按钮是已走通的路线。

### 4.1b 实测尺寸（2026-10-06 用户 F12 截图，2560×1440 换算为逻辑 1280×720）
| 元素 | 逻辑 x 范围 | 宽 |
| --- | --- | --- |
| AP 升级按钮 | 125–253 | 128 |
| 左警示条 | 276–298 | 22 |
| 出兵格（5 格） | 317–957，格宽约 109，间距 133 | 640 |
| 右警示条 | 973–998 | 25 |
| 弹头车按钮 | 1024–1168 | 144 |
| 两侧空白 | 0–125、1168–1280 | 125 / 112 |

底栏高度约 y 575–715；AP 数值框位于左上 y≈505–570，不在底栏内。第 5 格右侧有青色滚动箭头。

**结论：16:9 下不需要缩小任何按钮。** 6 格 + 中间分隔约 24 + 两条警示条 + AP 升级 + 弹头车 + 间隙 ≈ 1170，小于 1280。只需平移：
- 出兵区由 5 格扩为 3+3 格（宽 640→约 822），两条警示条各向外移约 74。
- AP 升级按钮 125→约 51；弹头车 1024→约 1098（右缘约 1242）。
- 左右半区各自需要滚动箭头（原生青色箭头复用）；中间加分隔（可复用警示条贴图）。

### 4.2 实现要点
1. **布局**：按 4.1b 平移 AP 升级、弹头车与警示条的绘制坐标，以及 `getScreenItem` 的命中矩形；按钮不缩放（R5 已完成）。
2. **分栏绘制**：出兵栏的槽位循环执行两次——第一次用我方控制器、左半区域；第二次临时把 operator+0x18 换成对手控制器、右半区域、独立滚动位置，绘制后换回。需要先读懂 `drawUI` 中出兵栏循环的入口、槽宽常量与裁剪矩形（R6）。
3. **两个滚动位置**：`getUnitPanelScreenPosition` 按当前半区返回各自的滚动值；拖动时按触点所在半区更新对应值；滚动范围由 10 格减去可见 3 格计算。
4. **点击**：`getUnitIndex` 左半区返回 0–9（我方，走原逻辑）；右半区返回敌方槽位，由钩子改为调用对手控制器 `createUnit`。完全控制关闭时右半区只显示、不响应点击。
5. **键盘**：1–0 我方、Q–P 敌方不变；按下不在可见范围的槽位时，自动把对应半区滚动到该格（可选）。
6. **显示状态**：右半区格子显示敌方单位、成本、冷却；完全控制开启时成本显示“∞”或隐藏成本。

### 4.2b 敌我滤镜（用户要求 2026-10-06，以用户标注图为准）
- 着色对象是**出兵栏背景层**（警示条之间、格子后面的金属骨架底图），不是格子本身：左半区（我方 3 格后方）叠**蓝色**滤镜，右半区（敌方 3 格后方）叠**红色**滤镜；原背景纹理保留可见。
- 格子边框、绿色格底、单位头像、成本数字、滚动箭头**不染色**，保持原样。
- 实现：在 `drawUI` 中背景层绘制完成之后、第一个格子绘制之前插入两次半透明填充——`Graphics::setColor(ARGB)` + `fillRect`（左半蓝、右半红，约 35–45% 不透明度，按实际观感调），之后复位颜色与混合模式。因为格子在其后绘制，滤镜自然只落在背景上。若半透明叠色发灰，改用 `setRenderMode` 的乘法/叠加混合。
- 范围：左右各自从外侧警示条内缘到中间分隔。**警示条不染色**（用户确认 2026-10-06），保持原色。
- 前提（R6 一并核查）：确认 `drawUI` 中背景层先于格子绘制；若背景与格子同一次绘制，则改用背景素材调色两版（蓝/红）替换。
- 原版冷却状态（整格红底 + 红色进度条）保持不变；它是格子本身变色，与背景滤镜层次不同，可区分。

### 4.3 风险与后备
- `drawUI` 体量大且混合绘制全部 HUD，分栏需要逐段核查，工作量明显高于信息带方案。
- 后备方案：画面外信息带（`fit_rect` 预留一条带，游戏画面等比缩小 4–5%），在 R5/R6 证明分栏不可行时采用。

---

## 5. LAB 战斗中菜单

- 本项目已在原生战斗暂停页内加入音频开关（五行按钮位于原生面板内），LAB 菜单优先采用同一做法：在原生暂停页增加“完全控制 开/关”“重新开始”“返回 LAB 准备界面”等行，Esc 打开/恢复沿用现有路径。
- 若暂停页行数不足，再改用宿主层自绘菜单（`EventTrial.draw/touch` 同一套）。
- 原生 PAUSE 按钮保留。

---

## 6. 新增文件与改动范围

| 文件 | 内容 |
| --- | --- |
| `lab.py`（新） | LAB 状态、预设读写、准备界面、战斗中菜单、配兵条、`activate_enemy_slot`、共享头写入 |
| `src/lab_hooks.cpp`（新，方案 A） | `isUnitCreate` / `createUnit` / `getAP` / `noukinAutoPlay` / `GetUnitLevelSaveData` / `MakeNPCInfo` 钩子 + `msd_lab_hooks_version` 导出 |
| `src/lab_hooks.cpp`（分栏部分） | `drawUI` 布局与分栏、`getUnitPanelScreenPosition`、`getUnitIndex`、`getScreenItem` 钩子 |
| `player.py` | Q–P 按键、LAB 菜单键、事件分派 |
| `battle_controls.py` | `opponent_controller` |
| `local_platform.py` | 无改动（沿用 NPC 路径） |
| `lab_presets/`（新目录） | 牌组预设与战斗履历 JSON，独立于 `play_save*/` |

---

## 7. 实施顺序

1. **R1–R6 运行实测/核查**（R1 用仓库根目录 `lab_probe_launcher.py`，结果写入 `lab_probe.jsonl`）（隔离存档 + NPC 对战）：对手控制器类型与 AUTO 状态、`resetAutoPlay` 效果、暂停写法、Windows 版战斗底栏实测截图与尺寸（R5）、`drawUI` 出兵栏循环与常量（R6）。
2. Q–P → 对手 `createUnit` 原型（方案 B），在普通 NPC 对战中先跑通。
3. 底部出兵栏左右分栏（布局压缩 → 分栏绘制 → 双滚动 → 点击路由）。
4. 原生暂停页加入完全控制开关等 LAB 菜单项。
5. 方案 A 原生钩子替换方案 B。
6. LAB 准备界面（牌组/等级/地图/据点/履历）与 `MakeNPCInfo` 敌方牌组注入。
7. 验证：社区单位在敌方一侧、对象池上限、存档无写入。


---

## 8. 原型 P1（2026-10-06）：LAB 战斗入口

文件（正式版仓库根目录）：`lab.py`、`lab_launcher.py`、`Start_LAB.vbs`、`lab_config.json`（示例敌方牌组含 KT-21、白/绿木乃伊、生成器 MK2、PF 步枪兵与 5 个原版单位）；默认独立存档 `lab_test_save`（`play_save_max_level` 的副本，拒绝 `play_save*`）；配置 `lab_config.json`（首次运行自动生成）。

### 8.1 原生启动路径（由 `AppMain::SC_BattleStart` 0x1ea53c 的联机分支还原）
1. `SceneEndFunc(当前场景)`；app+0xC030=1（联机）、app+0xC034=0（1v1）、app+0xC061=1（NPC）、app+0xC63C=4。
2. `GetPlayerInfo()`：NPC 时调用 `MakeNPCInfo`，把 106 字节对手信息复制到 app+0xC081。
3. 敌方牌组（已解决 UID 限制，2026-10-06）：原生对手数据区 app+0xC081+2i 每槽 2 字节，只容 10 位 UID 且位 9 表示空槽（UID < 512）。原型做法：
   - 数据区仍写入，但 UID ≥ 400 的单位以**同阵营原版单位**代写（`GetUnitAffiliation` 查表），仅供 `BattleStartSetStatusEnemy` 计算“全同阵营”标记（对手控制器 +928），该标记随后进入 `setupBaseStatus`。
   - **不调用** `BattleStartSetUnitEnemy`（0x1e8966），改为与其相同的顺序对敌方控制器（`BattleMain::getEnemyController`）逐槽调用 `BattleController::entryUnit(UnitID, 存档等级, 0)`，空槽传 −1，UnitID 不经 10 位编码，原版 0–399 与社区单位（1024 起）均可。
   - 配置可写 UnitID 或社区单位 key（如 `s1xlv.kt21`）；`internal_only` 子单位（1037、1038、1042）拒绝；全部校验在改动场景状态之前完成。
4. `BattleInit_OnlinerMode(stage, team=0)` → `BattleStartSetStatus(0,0,0,0)` → `BattleStartSetUnit` → `BattleStartSetStatusEnemy`（读 app+0xC0C1 起的对手据点参数）→ `BattleStartSetUnitEnemy`（`entryUnit(UID, 等级, …)`）→ `ChangeExeST(99)`。
5. 联机地图表：0x8fd730+48 起为 1011, 1021, 1022, 1023, 1024, 1031, … （原生以 [[app+16]+420] 为下标），原型默认 1011。

### 8.2 原型功能
- F7 启动；Q–P 敌方出兵；`[` `]` `\` 敌方 AP 升级 / 弹头车 / 全体绝招；F8 完全控制（方案 B）；F4 / F3 敌方 / 我方 AI。
- `sendDataTCP/UDP`、`startQuickGame` 等在 LAB 中本地吞掉。
- 进入结算场景（110/120）即清理战斗并返回菜单（`ChangeExeST(31)`），不走 Wi-Fi 结算。
- 记录：`lab_probe.jsonl`（启动参数、控制器类型、AP、AUTO、槽位，前 30 秒每 2 秒一次）与 `lab_player.log`。

### 8.3 未验证风险（首次实机运行需观察）
- `BattleSceneNetworkWait`（场景类型 6）可能等待对端消息而停住：其 `update` 读 app+0xC1BF、`BattleGameMaster`+0x4828 与 `getHostFlag`；若卡住，由宿主调用其 `finish()` 跳过。
- 联机计时 `notifyEventOnlineTimer` 在无对端时的表现。
- 未加载战斗 BGM（原型静音或沿用原 BGM）。
- 结算返回路径与存档写入：原型使用存档副本，未拦截 `WriteMainSaveData`。


### 8.4 首次实机结果与修正（2026-10-06）
- 结果：F7 后原生进入 99/101 并显示“同步中”，约 11 帧后出现场景 120，原型误判为结算并返回菜单（区域选择）。敌方牌组记录正确（社区单位 1043/1039/1040/1041/1031 + 原版 5 个，Lv40）。
- 场景编号：120 = `SC_PopupInit` 弹窗（`ChangeST(120)`），110 = 续关；不是结算。
- 原因：应用层联机标记 app+0xC030=1 时，`AppMain::BattleConnectionCheck` 要求 `CGameCenter::getState()`（gc+0x8904）== 3，无对端时弹出通讯中断弹窗；此外联机开场 `BattleMain::initializeOnlineMode` 依次 `changeScene(1)`、`changeScene(6)`，类型 6 为 `BattleSceneNetworkWait`（等待对端同步，app+0xC1BF=1 表示超时/错误）。
- 对照：`BattleMain::initializePracticeMode` 设 GameMaster+0x4828=4、`setupScene(GameMode 0)`、`changeScene(2)`，无网络等待；GameMode 0 的敌方为脚本控制器，不适合完全控制。
- 修正：战斗对象建立后立即清除 app+0xC030；扫描 BattleMain 找到 `BattleSceneNetworkWait` 实例并调用其原生 `finish()`；结束判定改为“曾开战、非暂停、离开战斗场景或停止满 2 秒”；开战前出现 110/120 才视为错误退出。另逐帧记录场景切换。

### 8.5 第二次实机结果（2026-10-06）
- 成功进入战斗（场景 100）。运行时确认 R1：scene+0x40 数组为 [0] `BattleControllerPlayer`（team 0）、[1] `BattleControllerNetPlayer`（team 1）、[4] 同 [0]；对手 AUTO=0。
- 完全控制方案 B 生效：双方 AP 9999/9999、据点 MAX、弹头车 MAX。
- 敌方牌组 10 槽与配置一致（含社区单位 1043/1039/1040/1041/1031），Q/W/E/R 出兵成功（KT-21、白/绿木乃伊、生成器 MK2），`\` 敌方绝招成功（2、3 个）。
- 残留：“同步中”窗口未关闭——`finish()` 只置完成标记，原生各分支另调 `AppMain::CloseContentsWindow()`；已补调用。
- 无法退出：GameMode 1 战斗内原生暂停/脱离不可用，且无时间限制。原型新增 F5 = 退出 LAB（`BattleEnd_ClearBattleMain` → `ChangeExeST(31)` 并还原 app 标记）；正式版并入 LAB 战斗菜单（第 5 节）。

### 8.6 HP 对称与敌方绝招显示（2026-10-06）
- 用户反馈：我方 HP 无限。原因：`BattleScene::setupResourceAll` 在 GameMode 1 中按 `scene+44`（本地队伍）把本方据点的单位字节 +981 置 1；`BattleUnit::damage`（0x1e0aa8）在 +981≠0 时跳过扣血，该 HP 原由对端同步（`BattleUnit::updateKyotenHpOnline` 读取同一标记）。`BattleConnectionCheck` 也会写该字节。原型修正：开战后每帧把双方单位列表与双方据点（`BattleController::getBaseUnit`）的 +981 清零。
- 敌方绝招光圈：`BattleUnit::draw`（0x1e130a）在 `isSpAttack()` 且 +976∈{1,2} 时调用 `BattleEffectRenderer::drawSpAttackEffect`（渲染器 +972）；`BattleObjectManager::createUnit`（0x1df418）仅当 GameMaster+0x4828≠4、单位队伍=管理器+20、成员=管理器+116（即本地玩家）时 `setEffectRenderer(管理器+64, 1)`。原型为敌方单位补设同一渲染器（类型 1）——光圈先以原色（亮蓝）显示。
- 敌方绝招等待条：由 `BattlePlayerOperator::drawUI` 0x1d8d2a 起的循环绘制，只遍历本地队伍 `getTeamUnitList(本方, 0)`，每个单位按 `getSpAttackCooldownRate` 用 `GraphicsOpt::drawConv` + `fillRect` 绘制。敌方等待条与红色光圈都需原生改动（分别为该循环追加敌方队伍一遍；`drawSpAttackEffect` 前按队伍设置红色调），归入方案 A 原生钩子批次（需在用户机器以 MinGW 运行 `src/build.py` 重建核心）。
- 结论修正：生成代码中 `add(c,x,~(k),1,true)` 等价于 `x−k`；`cond` 编号 1=EQ、2=NE、3=CS、4=CC、9=HI、10=LS、11=GE、12=LT、13=GT、14=LE（`aot_runtime.h`）。

## 9. 原生批次 N1（2026-10-06）：敌方绝招等待条 + 红色光圈
- 构建：`src/lab_hooks.cpp` 已加入 `src/build.py` 源列表；候选核心 `MSD_Core_LAB_r1_20261006.dll`（`--no-activate`，输出 `src/build/`）。`lab_launcher.py` 发现该文件时以同等 ABI 检查加载它（替换 `probe.Uc`），根目录 `core_runtime.json` 与其他启动器不变；核心缺失时等待条功能停用、其余照常。
- 共享头：0x1ffeb000，魔数 `LAB1`（0x4c414231）；+4 功能位（1=敌方等待条）、+8 敌方队伍、+12 等待条补画状态（原生使用）。0x1ffec000 已被扩展世界（EXT1）占用，故不用。离开 LAB 或宿主异常时清零。
- 等待条钩子：块 0x101d8f0b（第一循环出口）首次到达时置状态 1、r7←[sp+56]（敌方队伍）、跳回 0x101d8d27 再跑一遍；块 0x101d8e49（小地图点）在状态 1 时跳到 0x101d8ef7（下一单位）；第二次到达出口时复位并执行原生敌方小地图循环。寄存器核查：循环只读 s18/s20/s22–s28、r4、r5、r9、[sp+40/48/68]；循环后代码对 r6/r8/r10/r11 先写后读。
- 红色光圈（宿主层，无需核心）：`BattleEffectRenderer`（12 字节：vtable、Image*、帧号 float）构造时 `Image::createImage("aura.obm")`；宿主临时把 .rodata 0x3011c3 的字符串改为 `aurR.obm` 构造第二个渲染器后还原，`fopen("…/aurR.obm")` 返回调色板换色后的数据（aura.obm：OI 04 04、256×256、16 色 RGB5_A1 + 4bpp；R←max、G/B←min，洋红键不变）。每帧同步原渲染器帧号，敌方单位 `setEffectRenderer(红色渲染器, 1)`。
