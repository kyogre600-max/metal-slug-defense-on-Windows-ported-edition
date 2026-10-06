# LAB 交接说明（给 Claude Code，2026-10-06）

本文件供在本机运行的 Claude Code 接手 LAB（实验室）功能。完整设计、原生地址与历次实测记录见同目录 `lab_design_2026-10-06.md`（以下简称“设计文档”，章节号沿用）。

## 0. 工作约定（必须遵守）
- 只在正式版仓库 `F:\egg\github\metal-slug-defense-on-Windows-ported-edition` 开发；**禁止写入 `play_save*` 目录**（`play_save_max_level` 是用户的满级存档）。LAB 测试存档为 `lab_test_save`（满级存档副本）。
- `F:\egg\AGENTS.md` 为项目总规范，开工前阅读其文首摘要与第 2 节。
- 核心构建：在 `src` 目录运行
  `..\windows_runtime\python.exe build.py --library MSD_Core_LAB_rN_20261006.dll --no-activate`
  （N 递增；`--no-activate` 不改根目录与 src 的 `core_runtime.json`）。构建后把 `lab_launcher.py` 中 `LAB_CORE` 改为新文件名；LAB 启动器只为自己加载该核心，其他启动器不受影响。
- 便携 Python 的 `ctypes` 必须在 `portable_launcher`（由 `all_units_level1_launcher` 导入）之后导入，否则 `_ctypes` 加载失败。
- 运行：`windows_runtime\python.exe -B -I -S lab_launcher.py --windowed`（控制台可见异常）或双击 `Start_LAB.vbs`。菜单按 F7 进入 LAB 战斗，F5 退出。F12 截图到 `screenshots\`。
- 记录：`lab_probe.jsonl`（LAB 事件与采样）、`lab_player.log`、`lab_status.json`、`lab_launcher_error.log`。

## 1. 生成代码阅读要点
- 原生 ARM 代码静态重编译在 `src/generated/blocks_*.cpp`，块名 `b_<地址>`，客体地址 = so 偏移 + 0x10000000。符号用 `libAppMain.so`（`game_data/original.apk` 内 `lib/armeabi-v7a/`）的动态符号表解析。
- `add(c,x,~(k),1,true)` 等价于 `cmp x,#k`（结果 x−k）；`cond` 编号：1=EQ 2=NE 3=CS 4=CC 5=MI 6=PL 9=HI 10=LS 11=GE 12=LT 13=GT 14=LE（`src/aot_runtime.h`）。
- 钩子：`old=find_block(pc|1); register_block(pc|1, fn)`；fn 内可改寄存器后 `old(c)` 或直接设 `c.pc` 跳转；模拟调用为设置 r0–r3、`c.r[14]=返回块地址|1`、`c.pc=函数|1`（见 `src/audio_options.cpp`）。块地址必须是已存在的块起点。
- LAB 共享头 `0x1ffeb000`，魔数 `0x4c414231`（LAB1）：+4 功能位，+8 敌方队伍，+12 等待条补画状态。宿主 `lab.py` 的 `write_header()` 写入、离开时清零。0x1ffea000（音频）、0x1ffec000（扩展世界 EXT1）、0x1ffed000（活动）、0x1ffee000（社区）已被占用。

## 2. 当前状态（已实机验证）
- LAB 入口：绕过 Wi-Fi 菜单直接建立 GameMode 1 战斗（设计文档 8.1），“同步中”自动关闭，F5 可退出。
- 敌方由玩家控制：Q–P 出兵、`[` AP 升级、`]` 弹头车、`\` 全体绝招；F4/F3 敌我 AI 开关（原生 AUTO，含自动绝招），F8 完全控制（宿主层：据点满级、AP 每帧补满、冷却清零）。
- 敌方牌组支持原版与社区单位（`lab_config.json`，可写 UnitID 或社区 key）。
- 双方 HP 对称（清除 +981 本地免伤标记）。
- 敌方绝招光圈为红色（宿主层第二个 `BattleEffectRenderer`，`aurR.obm` 换色）——用户截图已确认。
- 敌方绝招等待条：核心钩子 N1，2026-10-06 自动截图确认敌方单位下方显示等待条。
- T1–T7、T9 已实现（2026-10-06，当前 LAB 核心 `MSD_Core_LAB_r7_20261006.dll`，`msd_lab_hooks_version`=4），见第 2.1–2.3 节；待办为 T8 准备界面。

### 2.1 T1–T5 实施记录（2026-10-06）
- 验证入口：`verification/lab_ui_20261006/lab_driver.py <时间线.json> [--core DLL]`，按战斗开始后的帧号注入出兵/点击/拖动/截图；存档为同目录 `save/`（`lab_test_save` 副本），屏蔽真实鼠标。截图位于 `shots/<时间线名>/`。
- T1（r2）：`onGameScreenTouchEnded` 本方未命中时以敌方队伍/成员再跑一遍原生遍历（模拟调用 `getInstance` 返回 0x1d7642；本方列表为空时在 0x1d764a 入口进入），命中则在 0x1d76d2 改用敌方控制器 vtable+0x98。头部 +16 敌方控制器、+20 敌方成员、+24 补遍状态。验证：有/无我方单位两种情况下只有被点击的敌方单位发动，我方与其他敌方单位不受影响（`shots/t1/`）。
- T2（r3）：按用户 2026-10-06 修订布局 `[我方 AP][我方弹头车]▌我方 3 格▐敌方 3 格▐[敌方弹头车][敌方 AP]`。drawUI 每帧作为嵌套调用执行 11 遍（底栏外 1 遍、敌方 AP 框 1 遍、9 个底栏片段），各遍以软件裁剪与仿射变换（统一缩放 0.88，以底栏上沿为基准）排布；glScissor 由 Python 宿主处理，嵌套调用中不可用，故裁剪在 `Graphics::drawImageS/fillRect` 钩子内按源矩形完成。敌方各遍换入敌方控制器与出兵栏状态（头部 +0x70，7 字）以及敌方出兵格图集（宿主以敌方控制器调用 `createGrahics`，结果存头部 +0x40）。触点在 `onUITouchBegan/Moved/Ended` 入口按片段换回原生坐标，敌方片段处理期间换入敌方状态、出口块后换回。每侧最大滚动 = (槽位数−3)×格距；1–0 / Q–P 出兵时自动滚动到该格。中间分隔条旋转 180°；开场（MISSION START）起即为分栏布局。验证：双方出兵格点击、各自拖动滚动、按键自动滚动、双方 AP 升级与弹头车按钮、30 FPS（`shots/t2*`、`shots/slug`、`shots/intro`）。
- 与原方案的差异：敌方半区在完全控制关闭时同样响应点击（与 Q–P、`[` `]` 按键一致；否则完全控制开启时敌方 AP 恒为 MAX，按钮无法使用）。
- T3（r4）：出兵格循环的 `setClip` 前（原生已提交背景批次）在本遍 3 格窗口叠约 36% 不透明的蓝/红色块；警示条为独立片段，格子、头像、数字在其后绘制，不受影响（`shots/t3/`，像素抽样确认底纹保留）。
- T4：由 T2 修订布局取代——右侧为可操作的敌方 AP 升级与弹头车按钮，显示敌方自身状态，不再绘制影子按钮。
- T5（r5）：`drawApBar` 以敌方控制器单独执行一遍：框体翻转到右下，框内文字带（“AP:”、暗色占位数字、“/”）以无字底纹覆盖镜像后不翻转地平移绘制，数字平移，最后叠约 38% 红色底。显示敌方当前 AP/上限；完全控制下显示 9999/9999（是否改为“∞”待用户定）（`shots/t5/`）。
- 尚未验证：普通关卡中加载 LAB 核心时的原版行为（所有新钩子在 LAB 头为 0 时直接回落原生块，未做实机截图对照）。

### 2.3 T9、T6、T7（2026-10-06，核心 r7，钩子版本 4）
- T9 存档隔离（宿主层，`lab.py` enter_sandbox/leave_sandbox，`lab_launcher.py` LabProbe.sandbox_open）：LAB 启动时快照内存中的主存档映像（app+0x3d08，0x5ab0 字节），离开时还原；LAB 期间原生对存档目录的写入改写到内存中的虚拟文件，原生保存后的读回校验由虚拟文件提供。宿主异常与启动中途失败时同样还原。验证（`shots/t9*`）：LAB 期间 1 次原生保存全部虚拟化，存档目录无新增文件；离开后存档映像与 LAB 前快照的差异仅为保存种子与校验和（对照：普通保存同样变化）及区域选择界面每秒递增的体力计数（对照：区域选择界面内同样递增）。
- T6 战斗中菜单（`lab_menu.py`）：GameMode 1 无原生暂停页，采用宿主自绘面板（trial_overlay.SurfaceOverlay）；打开时置 BattleGameMaster+0x1c 暂停战斗（原生不显示暂停界面），关闭时还原。行：完全控制、我方/敌方 AI 自动出兵、我方/敌方自动释放绝招、重新开始、退出 LAB、继续。Esc 打开/关闭，鼠标点击或 ↑/↓ + Enter 选择；打开期间其他游戏按键与触点不送入战斗。重新开始 = 离开后 45 帧再启动。验证（`shots/t6`）：暂停期间单位不移动，开关写入生效，重新开始回到战斗，退出后隔离解除。
- T7 自动出兵与自动绝招拆分（原生钩子，功能位 16）：`noukinAutoPlay` 中 0x1cc018（弹头车）、0x1cc04e（逐单位绝招检查）、0x1cc070（出兵决策）三处按头部 +0x30 禁用位跳过；宿主在任一开关开启时对该方 startAutoPlay。“自动出兵”含弹头车。验证（`shots/t7a`、`t7b`）：仅自动绝招时手动出的单位自动发动、无新增出兵；仅自动出兵时持续出兵、就绪绝招不发动。
- 原生 AUTO 开启时该方出兵格显示为灰色（原版 AUTO 表现）。

### 2.2 r6 修订（2026-10-06 用户反馈）
- 底栏两端增加底栏背景最外侧边缘块（源 x −88.89…−70，含 AP 框下方圆角），右端为镜像；缩放比改为按片段总宽占满屏宽计算（约 0.863），消除 AP 框左下/右下缺口与两侧空隙。
- AP 数值框从第 0 遍中排除，我方、敌方各单独执行 `drawApBar`，裁剪到框体下沿（D 520），由底栏照原版压住下沿。敌方框保留水平翻转（文字带不翻转），取消红底。
- 中间分隔条：上沿边框不动，只把条纹段（D 513 起）绕自身中心旋转 180°，与两侧条纹起点对齐。
- 蓝/红滤镜只覆盖上沿边框以下的骨架区，不透明度约 27%（`drawImageS` 不读取当前颜色，无法做纹理着色）。
- AP 升级按钮成本数字右移 2（D），实测与数字框中心一致（“MAX” 不移动）。
- 敌方 AP 按钮人物与敌方弹头车朝向与我方镜像。人物动画与我方同一逻辑：每帧推进在 `BattlePlayerOperator::update` 入口执行（开场前不动）；`BattleScene::onEventBaseLevelup` / `onEventFeverTimeStart` / `onEventBaseUnitDead` 入口对敌方精灵执行升级、LevelMAX、Escape/Win（敌方据点被毁 → Escape；我方据点被毁且敌方未满级 → Win）。验证见 `shots/fix3`–`fix6`（战斗结束通过直接调用 `onEventBaseUnitDead` 触发）。

## 3. 待办（按建议顺序；T1–T5 已完成，见第 2.1 节，以下保留原始说明）

### T1 鼠标点击敌方单位释放绝招（用户新反馈）
- 原生 `BattlePlayerOperator::onGameScreenTouchEnded`（0x1d74a8）：`BattleScreen::getScreenPosition()`（约 0x1d7630）取镜头，读控制器 +908，`getTeamUnitList(本方)`（约 0x1d7646），逐单位 `isSpAttack()`（0x1d766c/0x1d7672）与命中判断，命中后以本方控制器发动。
- 做法：本方列表未命中时，以敌方队伍再遍历一次，命中后调用**敌方控制器**的 `actionUnitSpAttack(uid)`（虚表 +0x98，参数为单位 +0x62 的 16 位 ID，与 `lab.py` 的 `enemy_special` 相同）。仅在 LAB 头有效时启用。

### T2 底部出兵栏左右分栏（设计文档 4、4.1b、4.2）
- 16:9 布局，按钮不缩放：AP 升级 x 122–253→约 51 起；弹头车 1025–1156→约 1098 起；出兵区由 5 格扩为左 3（我方）+ 右 3（敌方），格距 133、格宽约 109，中间分隔复用警示条贴图；两侧各自滚动浏览 10 格、各自的青色滚动箭头。
- 原生：整块 HUD 在 `BattlePlayerOperator::drawUI`（0x1d7ca8–0x1d9a90）；滚动位置 `getUnitPanelScreenPosition`（0x1d6df6）；点击换算 `getUnitIndex`（0x1d6e40，被 `onUITouchBegan/Moved/Ended` 调用）；按钮命中 `getScreenItem`（0x1d6d8c）；Operator 只绑定 operator+0x18 一个控制器。
- 绘制右半区：出兵格循环第二遍时临时把 operator+0x18 换成敌方控制器，画完换回（同 N1 的“再跑一遍”手法）。右半区点击路由到敌方 `createUnit`；完全控制关闭时只显示不响应。
- 键盘：1–0 我方、Q–P 敌方保持；按到不可见槽位时可自动滚动该半区。

### T3 敌我背景滤镜（设计文档 4.2b）
- 只染出兵栏**背景层**（两条警示条内缘之间、格子后面的金属骨架），左蓝右红，约 35–45% 不透明度；**警示条、格子、头像、数字均不染色**。在背景绘制后、首个格子绘制前 `Graphics::setColor`+`fillRect`（或 `setRenderMode` 乘法/叠加），随后复位。

### T4 敌方 AP 升级 / 弹头车影子按钮（设计文档 3.0）
- 在我方按钮之下以敌方状态再画一次：AP 升级影子在我方 AP 按钮左上、弹头车影子在右上，偏移约 (∓14, −7)，红色调约 55% 不透明，不超出底栏框架（底栏上沿 y≈573）。可用/已充满时提亮或闪烁，不可用时暗淡。示意：同目录 `enemy_ghost_mockup.png`。

### T5 右侧敌方 AP 数值框（设计文档 3.0）
- `drawApBar`（0x1d7ac4，`drawUI` 内 0x1d84dc、0x1d9788 调用）之后以敌方 AP/上限再画一次，位置镜像到右下（约 x 995–1280、y 505–570）；框体水平翻转（`setFlipMode`）并以红色为底，文字不翻转。完全控制下显示满值或“∞”（待用户定）。

### T6 LAB 战斗中菜单（设计文档 5）
- 本项目已在原生暂停页加入音频行（`src/audio_options.cpp`），LAB 菜单同法：完全控制开/关、我方 AI 自动出兵、我方自动绝招、敌方 AI 自动出兵、敌方自动绝招、重新开始、返回 LAB 准备界面、继续。注意：GameMode 1 中原生暂停/脱离不可用（因此目前用 F5 退出），需先确认暂停页能否在 LAB 中打开。

### T7 自动出兵与自动绝招拆成独立开关（设计文档 3.0）
- `BattleControllerPlayerBase::noukinAutoPlay`（0x1cbfe0）内 `isSpAttack` 调用点 0x1cc050 为自动绝招分支；按 LAB 头开关跳过或单独执行。

### T8 LAB 准备界面（MSA 实验室 7 项，设计文档“参考”节与 2）
- 我方/敌方牌组、单位等级（默认 Lv40；`GetUnitLevelSaveData` 钩子，不写存档）、一括设定、据点等级、支援、地图（联机地图表 0x8fd730+48 起：1011,1021,…）、战斗履历。当前用 `lab_config.json` 代替。

### T9 结算与存档
- 结束时直接返回菜单，但尚未拦截可能的奖励/存档写入（当前依赖测试存档副本）；正式化前需在 `SC_BattleEnd` 路径或 `WriteMainSaveData` 处拦截。

## 4. 验收方式
- 每项完成后：构建新 LAB 核心 → 启动 LAB → F12 截图对照设计文档的位置与颜色要求 → 检查 `lab_probe.jsonl` 与日志无异常 → 在普通关卡确认原版行为未变（LAB 头为 0 时钩子必须完全回落）。
