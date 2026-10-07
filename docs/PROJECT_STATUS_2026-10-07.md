# MSD WINDOWS S1XLV 项目进度与交接（2026-10-07，LAB r20＋退出路径修订）

本文件供后续对话快速恢复上下文并继续开发，内容为 2026-10-07 结束时的快照；开始任务前先执行第 10 节的启动检查。完整历史与验证细节见 `F:\egg\AGENTS.md`（第 1–65 节，本日 LAB 工作为第 61–65 节）与 `docs/lab/HANDOFF_LAB_UI.md`（本日为第 2.11–2.15 节）。

## 1. 当前状态快照

| 项目 | 值 |
| --- | --- |
| 正式版 Git 工作区 | `F:\egg\github\metal-slug-defense-on-Windows-ported-edition`，分支 `main` |
| HEAD | `b8c2573`（fix）。其后的 r17–r19 修改均**未提交**，由用户通过 GitHub Desktop 提交 |
| 未提交变化（本日） | `lab.py`、`lab_prep.py`、`lab_ui.py`、`lab_stages.py`（新增）、两份 `lab_runtime.py`、两份 `player.py`、两份 `local_platform.py`、两份 `core_runtime.json`、`src/lab_hooks.cpp`、`docs/lab/HANDOFF_LAB_UI.md`、`build/MSD_Core_LAB_r17/r18/r19/r20_20261007.dll`（新增）、本文件 |
| 显示版本 | 1.47.0（未改动） |
| 运行核心 | `MSD_Core_LAB_r20_20261007.dll`（`build/` 与 `src/build/` 各一份；根与 `src/` 的 `core_runtime.json`、两份 `lab_runtime.py` 的 `LAB_CORE` 均指向它） |
| LAB 钩子版本 | 12（`msd_lab_hooks_version`） |
| 运行目录 | `dist/MSD_Windows` 与用户实际运行副本均已同步 r20（见第 2 节） |
| beta 工作区 | 停用，仅在用户要求大型测试时使用（AGENTS 第 2.1 节） |

正式版所有入口（普通 EXE、原满级、全兵种 Lv1、全解锁满级、独立 LAB）共用 r20 核心与同一宿主；LAB 共享头为 0 时 LAB 钩子回落原生行为（普通关卡不受影响）。

## 2. 目录与同步规则

每次正式版相关修改完成并验证后，按明确文件清单同步到两个运行目录（AGENTS 第 2.2、2.3 节，持续授权，无需再问）：

1. `F:\egg\research\metal_slug_defense\windows_native\dist\MSD_Windows`（本地正式运行目录，含原满级入口 `Start_MSD_Max_Level.vbs`）
2. `F:\egg\metal-slug-defense-on-Windows-ported-edition-main\metal-slug-defense-on-Windows-ported-edition-main`（用户实际运行副本，入口 `Start_MSD_All_Unlocked_Max_Level.vbs`）

同步要求：

- 覆盖前核对目标处于上一轮同步状态（运行目录里的文本文件是 CRLF，工作区是 LF，比较内容时先统一换行）；覆盖后逐字节比对。
- 根目录与 `src/` 镜像、两份 `core_runtime.json`、两份 `lab_runtime.py` 的核心名一并同步。
- 严格保留全部 `play_save*`、`lab_test_save`、`lab_presets`、`lab_config.json` 及其他个人设置；同步前后逐字节比较这些文件。用户会在两轮之间自己玩游戏，受保护文件数量增加属于正常情况。
- 记录来源、目标、清单与验证状态，并更新 AGENTS.md。可复用脚本：`verification/lab_ai_tier_r19_20261007/deploy_r19.py`（先改 `FILES` 与 `r17_state` 中的前置状态检查）。

## 3. 硬性工作约定

- **禁止写入任何个人存档**（`play_save*`）。运行测试只用 `verification/lab_ui_20261006/save`（`lab_test_save` 的副本）。
- **停用 SHA-256 计算与哈希核验**（AGENTS 第 12.1 节）；用文件存在、逐字节比较、结构/启动/行为检查代替。
- **不暂存、不提交、不推送**；Git 操作由用户完成。
- 表述采用学术化、客观的中文；区分“已实现 / 已构建 / 已验证 / 待核验”，验证结论不得超出实际证据（第 9 节有本日的反例）。
- 可能有其他对话并行修改工作区：动手前看 `git status`，保留他人改动。新核心用新文件名（当前最新 r20，下一个 r21），不覆盖已部署的 DLL。
- **原生调用必须在游戏线程**：GLFW 回调只向 `lab.commands` 入队，由 `step_frame` 中的 `lab.update()` 执行。
- 用户界面文字：AI 段位名一律英文大写；其他界面文字随游戏语言（繁/简/日/英）。

## 4. 技术架构速览

- 原 Android ARM 核心（Metal Slug Defense 1.46.0）经静态重编译为 C++（`src/generated/blocks_*.cpp`，块名 `b_<地址>`，guest 地址 = so 偏移 + 0x10000000），编译为 Windows x64 DLL。所有分支经 `c.pc` 分派，`register_block` 的钩子对所有调用生效。
- Python 宿主（`player.py`、`probe.py` 等）负责图形、音频、输入、窗口、存档、平台接口与扩展内容。
- 原生钩子：`old = find_block(pc|1); register_block(pc|1, fn)`。函数入口钩子返回用 `c.pc = c.r[14]`；在钩子里调用原生函数用 `guest_call`（只能走到核心自行处理的导入：memset/memcpy/memmove、sin/cos、pthread_mutex_*、clock；不能用 malloc/new、文件 I/O、GL）。需要分配内存的对象（如音效通道）由宿主 `p.call` 在顶层创建。
- 社区单位：`community_content/registry.json`（schema 2）+ `community_content.py`；UnitID 1024–1087；AP 写在数据行 `+4` 等六个等级锚点。

## 5. 已完成功能

### 5.1 社区单位

| UID | 键 | 名称 | AP | 勋章 |
| ---: | --- | --- | ---: | ---: |
| 1024 | s1xlv.sarubia_future | 爆竹红（未来） | 400 | 300 |
| 1025 | s1xlv.m15a_future | M-15A型（未来） | 250 | 300 |
| 1026 | s1xlv.heavy_b_future | 未来重装B型 | 250 | 300 |
| 1027 | s1xlv.di_cokka_mk2 | 基·寇卡坦克 MK.II | 110 | 30 |
| 1028 | s1xlv.di_cokka_mk3 | 基·寇卡坦克 MK.III | 180 | 50 |
| 1029 | s1xlv.girida_o_mk2 | 吉利塔·O MK.II | 110 | 50 |
| 1030–1036 | s1xlv.pf_* | 正规军盾牌/步枪/反坦克/加特林/伞兵/冲天火箭弹/迫击炮兵 | 35–50 | 15–65 |
| 1037、1038 | pf_*_child | 伞兵、迫击炮兵内部子单位（不可选） | — | — |
| 1039 | s1xlv.white_mummy | 白木乃伊 | 80 | 100 |
| 1040 | s1xlv.green_mummy | 绿木乃伊 | 90 | 100 |
| 1041 | s1xlv.mummy_generator_mk2 | 木乃伊召唤箱 MKII | 220 | 160 |
| 1042 | …_box | MKII 完成箱体（内部） | — | — |
| 1043 | s1xlv.kt21 | KT-21（通关第二世界后免费发放） | 200 | 0 |

参数规则见 AGENTS 第 6.1 节；各单位修订记录见 AGENTS 第 35–47 节。注意：社区单位继承基准单位的 AI 战力值（数据行 `+0x354`）与 AI 攻击距离（`+0x370`），加载器未单独设定。

### 5.2 系统与入口

- 玩家等级：原版世界开放判定、30/50/70 勋章阶段解锁与阵营核心 Lv40（AGENTS 第 38 节）。
- 独立存档入口：全兵种 Lv1、全解锁满级（AGENTS 第 50 节）。
- 标题画面使用用户 LOGO（`custom_content/LOGO_IN_GAME.png`，`title_visuals.py`）。
- 退出：标题画面 Esc 直接退出（原生 `showEndDialogView` 按关闭窗口处理）；对战中关闭窗口只还原 LAB 内存存档映像，不报错（HANDOFF 2.15）。
- 扩展世界/关卡、独立场景与音乐、自有服务器预备接口已有配置接口，界面默认关闭（AGENTS 第 18–19 节）。

### 5.3 LAB（实验室对战）

| 功能 | 状态 |
| --- | --- |
| 入口：主菜单 LAB 图标（MEDAL 与 MISSION 之间）+ F7；CUSTOMIZE/SHOP/OPTION 子页均可进入 | 已实现并验证（r10/r13） |
| 准备界面：独立全屏、原生顶栏（ConvMenuParts 0，等比 2.25 倍）、MISSION BGM 135（战后也保持） | 已实现并验证（r17） |
| 退出准备界面：一律回到主菜单主画面（出击/强化/Wi-Fi 对战），播放主菜单 BGM 101 | 已实现并验证（r17） |
| 顶栏 OK/BACK：原生图标 1.5 倍（90×72，位于顶栏深色区内），按住显示原生青色框与三灯，执行后保持到闸门合拢 | 已实现（r19，按用户修图确定尺寸） |
| 双方牌组 10 格、选择器、Lv1–40、一括等级、据点初始等级（标题行）、复制对方、随机、清空 | 已实现（复制对方 r17） |
| 地图：地图 1–3（世界 0–2）与里地图 1–3（世界 9–11）共 377 关，世界/小关两个选择器 + 原生缩略图（`lab_stages.py`） | 已实现并验证（r17）：战场、BGM 与关卡记录一致；只有据点，无关卡默认敌军 |
| 控制：完全控制、双方 AI（开/关 + 段位）、双方自动绝招 | 已实现 |
| AI 段位 ROOKIE −2 / BRONZE −1 / SILVER 0（原版水平）/ GOLD / PLATINUM / DIAMOND / MASTER / PREDATOR +5，双方各自设定，默认 SILVER | 已实现并验证（r19，见第 6.4 节）；r20 起 GOLD 以上按单位价值选择、积累 AP、建筑类只在己方半场出击，并在“填补/囤积”两种积累策略间随机切换 |
| 优势设定（生命/攻击各 +20%/级）、预设 A/B/C 与战斗履历 | 已实现 |
| 底栏左右分栏、敌方点击绝招、敌我滤镜、敌方 AP 框与按钮、敌方人物/弹头车镜像动画、出兵格拖动 | 已实现（r3–r16） |
| 敌方 AP 升级反馈、LV UP/MAX/ATTACK 横幅镜像、敌方首次触发资源 | 已实现（r15/r16） |
| LAB 战斗中双方音效通道各 11 个（原生 3 + 扩展 8） | r17 实现；r17 有音量错误致 SE 静音，r18 修复并验证 |
| 原生闸门、战斗中 ESC 菜单、战后 Back/Esc、仅自动绝招时手动出兵、存档隔离 | 已实现（r9–r13） |
| 界面文字随游戏语言（繁/简/日/英）；切换语言后单位名与地图名随之切换 | 已实现（语言跟随 r18） |
| 韩语：单位名与区域名为韩文，改用 Malgun Gothic 显示；界面文字在韩语下为英文 | 已实现（r19） |
| 支援接口（原生钩子保留，界面只开放弹头车出击） | 接口保留 |

LAB 关键文件：`lab.py`（流程、AI 应用、段位表 `AI_TIERS`、优势、闸门、音效通道建立）、`lab_prep.py`（准备界面）、`lab_stages.py`（地图目录与缩略图）、`lab_menu.py`（ESC 菜单）、`lab_menu_entry.py`（主菜单图标）、`lab_ui.py`（素材、文字表、字体、音效/BGM、原生闸门、按钮绘制）、`lab_runtime.py`（各入口接入，有 `src/` 镜像）、`lab_launcher.py`、`src/lab_hooks.cpp`（全部原生钩子）。`lab.py`、`lab_prep.py`、`lab_ui.py`、`lab_stages.py` 只在根目录，没有 `src/` 镜像。

## 6. 关键原生事实（已核实）

### 6.1 共享头与界面

| 用途 | 位置/函数 |
| --- | --- |
| LAB 共享头 `0x1ffeb000`（魔数 LAB1） | +4 功能位（1/2/4/16/32/64 音效扩展/128 AI 段位）、+0x30 自动禁用位、+0x34 支援、+0x40 敌方图集、+0x70 敌方出兵栏、+0x100..+0x1e8 敌方横幅、+0x300..+0x337 音效扩展（'LSE1'、个数、通道指针）、+0x380..+0x3f7 音效统计与诊断、+0x500/+0x520 AI 段位块、+0x800 起绘制临时区。**新增字段前先查占用**（本日曾发生重叠，见第 9 节） |
| 主菜单入口共享头 | `0x1ffef000`（魔数 0x4c41424d） |
| 菜单音效 / BGM | `Sound_RequestPlayMenuSE`：13 确定、8 关闭；`Sound_RequestPlayBGMEx2(app,id,0)`；当前曲目 `app+38656+212`、未处理请求 `+208`；MISSION 135、地图 103、主菜单 101 |
| 主菜单 BGM 与子画面 | `SC_MainMenuLoop` 状态 0 在 `IsShutterEnd` 后请求 BGM 101，并按 `app+0xb168` 进入子画面（1 OPTION、3 CUSTOMIZE、4 SHOP，其余主画面）；场景 `app+0x22bc`、子状态 `app+0x22dc` |
| 顶栏素材 | ConvMenuParts 0 `(0,68,568,51)` 为各菜单顶栏（第 0–2 行亮线、3–40 深色区、41 起铆钉条）；ConvMenuParts 1 `(0,0,568,67)` 是底部按钮栏底板 |
| 原生图标按钮 | `GT_CockpitButtonDraw`（0x2003bc）：按下时画 ConvMenuParts 79 青色框（锚点 3,3）→ 图标 → 37 三灯（锚点 −19,−2）；OK=36、BACK=30（60×48）。drawConv 目标位置为 x−锚点 |
| 语言 | `app+0x3d64`：0 EN、1 JP、2 KR、3 ES、4 PT、5 FR、6 DE、7 IT、8（无单位名）、9 繁中、10 RU。`lab_ui.LANGS` 把 10 映射为简体中文（俄语用户会看到简体中文，用户表示不处理） |

### 6.2 地图（`lab_stages.py`）

- 区域表 `0x902384`：GetAreaNum/GetAreaData 对 WorldType 0 取 `+0xcc`，即世界 w 位于第 w+3 行（每行 0x44 字节：区域数 + 16 个区域指针）。有效世界 0–2（各 67 关）与 9–11（61/61/54 关）。区域 `+0` 名称序号、`+0xc` 区域缩略图号、`+0x12` 小关数、`+0x14` 起小关指针；小关 `+8` BGM、`+0xc` 缩略图图块号。区域名表 `strAreaNameTbl`（`0x946b8c`，按语言）。
- 战斗 StageID = `(世界+1)×1000 + (区域+1)×10 + (小关+1)`（SC_BattleStart 关卡模式）；`BattleInfo::getMissionInfo(id)` 的 `+4` 为战场；Mission BGM 为 0 时 `setupResourceAll` 用同一 StageID 调 `GetStageBgmID`。
- 联机 GameMode 1 的敌方是 `BattleControllerNetPlayer`，不读 Mission 敌军波次；捕虏（UnitID 116）与 UnitID 363 只在游戏类型 1/7 生成（LAB 为 2）。
- 缩略图：`LoadThumbnailImage` 用区域缩略图号查 `0x31d420` 文件对，再按语言查 ImageDataInfo（GOT `0x93681c`，12 字节/项，+0 文件名）；`GT_InfoWindowDraw` 用 drawPict 转换表 28 画图块（每关 128×56）。缩略图 OBM 为 `OI 00 18/20` 的 RGB 图集。

### 6.3 音效

- 请求：`Sound_RequestPlaySE`（0x1c67e8）每端口 4 个请求槽（3 用 + 1 溢出，按优先级淘汰）。`BattleObject::playSE` 以对象 `+0x70` 选端口：我方 0、敌方 1。
- 播放：`Sound_PlaySE`（0x1c7538）/`_2P`（0x1c778c）各 3 个 CAudioPresenter（1P `app+0x9b00..08`、2P `app+0x9b18..20`；VO 1P `0x9b0c..14`、VO 2P `0x9b24..2c`），满时停止最早者。音量：两支都在 0x1c76f0 以 `vcvt.f32.s32` 把整数音量（`app+0x9ae8`，淡出支乘 `app+0xaf5c` 后右移 8）转为浮点再传 `play`。
- 混音：CMediaManager（`app+0xab50`）32 个播放槽（manager+0x20 起），`play` 追加不查重；`delAudioPresenter` 找到即返回，实际不注销；混音回调（0x138584）在通道已结束（`+0`）或已停止（`+0x60`）时清槽。原生 `Sound_Stop` 不处理 `Sound_StopSE_2P` 的 0x200 位（置位后一直保留）。
- LAB 扩展（hooks10）：每端口每帧最多 24 条请求（同帧同 SoundID 合并），原生 3 + 扩展 8 通道，扩展通道由宿主按 Sound_Create 的方式建立（每进程一次）；`Sound_Stop` 标志 2、`Sound_ChangeVolumeSE`、`bufferReleaseCheck` 同时处理扩展通道；每次 play 前按混音回调规则整理播放槽。

### 6.4 AI（`BattleControllerPlayerBase::noukinAutoPlay` 0x1cbfe0）

- 等待：每次出兵、弹头车或绝招后调用 `setAutoPlayWaitTimer`（0x1cbfca），原生等待 `rand() & mask` 帧（mask = controller+0x420，`startAutoPlay` 以 rand()%240 抽取，整场固定）；等待期间整帧跳过（自动绝招也受影响）。倒计时在 controller+0x428。
- 战力与模式：双方场上单位 AI 战力（数据行 `+0x354`，如士兵 40、基寇卡 150、SV-001 300）求和，按“对方 − 己方”（−1000/0/800/1600）与对方前线位置（0.4/0.6/0.8 场宽）分 5 档。
- 紧急：AP 恰好满，或己方战力 < 阈值 −30（据点 1 级时阈值/2 −30；阈值 controller+0x424，原生 rand()%220）。
- 据点：等级 controller+0x3fc（0–10）；`isKyotenLevelup` 0x1cbd48；原生在不处于劣势时有 AP 就升至满级。远程规则：攻击距离（`+0x370`）大于 79 的单位要己方场上超过 3 个单位才出。
- LAB 出兵选择（hooks12，GOLD 以上）：在出兵调用点 0x1cc40e 按单位价值 S = √(HP×每秒伤害)×(1+min(击退门槛,40)/40) 与理解度 s 排序（S/AP^(1−0.75s)，低段位带随机误判），为目标积累 AP；策略 A 填补 / B 囤积每次出兵后随机切换；压力时出能买得起的最高者；建筑类（行动表 [0x109373f4][UnitID] 的 Kouhei/Donou 系 vtable）只在对方前线位于己方半场时出击。注意：队伍单位链表为环形；原生战力合计包含据点。详见 HANDOFF 2.14。
- LAB 段位（hooks11）：反应间隔区间（帧）ROOKIE 160–320、BRONZE 80–160、SILVER 30–90、GOLD 18–54、PLATINUM 10–32、DIAMOND 6–18、MASTER 3–10、PREDATOR 1–6；紧急阈值 0/0/110/300/800/1500/永远紧急×2；开局据点目标 1/2/原生/3/4/4/5/5。低于目标且对方前线未推进到 60% 以内时在 0x1cc070 优先升据点（AP 不足则保留）；达到目标后 AI 自身的 `isKyotenLevelup` 调用只在 AP 已满且无可出单位时放行。远程规则保持原生。参数表在 `lab.py` 的 `AI_TIERS`。

### 6.5 其他（沿用）

| 用途 | 位置/函数 |
| --- | --- |
| 原生闸门 | `SetShutterClose/Open`；任务槽 `app+0x3820`×4；`CTaskSystem2D::Caller(app+0x3830,5)` 推进，`GraphicsOpt::drawStack(word(app+124))` 立即绘制 |
| 关卡强化（优势设定） | `BattleObjectManager+72+(队伍×2+成员)×8` 两个 float（生命、攻击） |
| 战斗结束清理 | 补做 `SC_BattleEnd` 的清理后 `BattleEnd_ClearBattleMain`（见 `lab.leave`） |
| 单位名称 / 头像 | `GetMenuUnitName(uid, 语言)`；菜单表 → `ConvUnitIcon`；社区单位取 registry `icon.rect` |
| 单位状态 | BattleUnit 状态记录 `unit+0x128 + 子状态(+0x300)×0xec`；BattleUnitStatus `+0xc8` = 数据行 `+0x354`，`+0xd0` = 数据行 `+0x374`（−1 时取特攻/普通射程） |

## 7. 构建与验证工具

- 构建候选核心（不改配置）：在 `src/` 执行 `..\windows_runtime\python.exe build.py --library MSD_Core_LAB_rNN_YYYYMMDD.dll --no-activate --no-sha256`，验证后复制到 `build/` 并更新两份 `core_runtime.json` 与两份 `lab_runtime.py`。
- 通用时间线驱动：`verification/lab_ui_20261006/lab_driver.py <timeline.json> [--core DLL] [--capture]`（动作：`nostart`、`lab <指令>`、`press/move/release/touch x y`、`eval`、`shot`、`quit`；准备界面坐标为 1280×720 画布坐标）。
- 准备界面/战斗/退出回归：`verification/lab_prep_r17_20261007/driver_r17.py <StageID> [--seconds N] [--noai] [--direct] [--keep-slots] [--core DLL]`（SHOP 进入 → 准备界面 → 战斗 → 战场/BGM/敌军/音效/战后 BGM/退出主菜单检查）。
- AI 段位：`verification/lab_ai_tier_r19_20261007/driver_ai.py <我方段位> <敌方段位> [--seconds N] [--core DLL]`（记录每次等待、紧急阈值、首次出兵时的据点等级）。
- 出兵选择：`verification/lab_ai_tier_r19_20261007/driver_value.py <我方段位> <敌方段位>`（统计出兵平均 AP、积累帧、建筑类位置、策略 B 次数、各槽出兵）。三个驱动默认加速（去掉 30 Hz 节拍，约 10 倍实时，`--realtime` 恢复），同一进程种子固定、结果可重复。
- 原生表导出：`verification/lab_prep_r17_20261007/dump_stages.py`（运行时导出世界/区域/小关/缩略图）。
- 静态反汇编：capstone 在 `F:\egg\research\metal_slug_defense\windows_probe\deps`，需用 `C:\python3.12\python`（运行包内 Python 缺 `_ctypes`）；`windows_runtime\python.exe` 使用 PIL 前要先 `import portable_launcher`。
- 汇总：各验证目录的 `summarize.py` 生成 `verification_summary.json`。

## 8. 待办与待核验

### 8.1 尚未实施（用户已提出或可选）

- **本地双人对战（下一阶段任务）**：以 LAB r20 为基础设计，任务书见 `docs/lab/local_versus_design_2026-10-06.md` 第 5 节（可复用部分、实施顺序与开工前需确认事项）；尚未实施。
- **联机对战**：原 Wi-Fi 十位 UID 协议无法表达社区单位；接口见 `docs/ONLINE_INTERFACE.md`。
- **额外关卡 / 新世界**：接口见 `docs/CONTENT_AUTHORING.md`；内容与素材未制作。
- **支援选项扩展**：原生已支持两项，界面未开放。
- **可选**：韩语界面文字（目前英文，需用户确认译文）；高段位是否放开“不足 4 个单位不出远程”规则；社区单位的 AI 战力值 `+0x354` 是否单独设定。

### 8.2 待用户实机核验

- LAB：AI 各段位实际强度与手感（r20 囤积阶段会少出兵，PREDATOR 推进速度下降，需实战评估）；双方 11 通道音效听感；顶栏按钮新尺寸观感；长时间对战。
- 单位：KT-21 喷火燃烧死亡与突进距离、爆竹红（未来）/未来重装 B 型击退与滚动、木乃伊系列实战。
- 全关卡自然通关、长期运行稳定性与跨设备性能均未全面验证。

## 9. 本日教训（后续避免）

1. **验证要覆盖用户可感知的结果**：r17 音效扩展只核对了播放次数与并发，没有核对实际音量，导致上线后大量单位无声。涉及音频时同时检查通道增益（presenter `+0xac`）或录音 PCM。
2. **共享头新增字段前先查占用**：r19 开发中 AI 段位块与音效统计区重叠，表现为数值逐帧变大。
3. **Windows 上 `Path.write_text` 会把 LF 转成 CRLF**；工作区按 `.gitattributes` 为 LF，补丁脚本改用 `read_bytes/write_bytes`。
4. **bash heredoc 写含引号、`\x..`、三引号的 Python 补丁容易出错**；复杂补丁先用 Write 工具写成文件再运行。
5. **测试运行会向仓库根的 `lab_probe.jsonl`（已跟踪文件）追加记录**；每次测试后执行 `git checkout -- lab_probe.jsonl` 还原。
6. **驱动采样要排除战斗结束后的帧**：控制器内存在结束演出期间会被复用，读到的值无意义。
7. **遍历原生队伍单位链表要在回到首个单位时结束**（环形链表；r20 开发中曾按 4096 步上限遍历导致计数放大数百倍）。
8. **AI 测试用加速模式**（驱动默认），一场 90 秒对战约 14 秒。
9. **原生“看起来的 bug”先核对再假设**：例如 0x200 停止位在原生中本就不处理；按原生语义镜像，不另行“修正”。

## 10. 新对话启动检查清单

1. 阅读 `F:\egg\AGENTS.md`（至少文首摘要、第 2 节与第 61–63 节）和本文件。
2. 在正式版工作区执行 `git status --short`、`git log -3 --oneline`；若用户已提交，以实际 HEAD 为准。
3. 核对两份 `core_runtime.json`、两份 `lab_runtime.py` 指向同一核心，且该 DLL 在 `build/` 与 `src/build/` 都存在（当前 r20）。
4. 明确本轮修改范围与验证方式；运行测试只用 `verification/` 下的副本。
5. 完成后同步两个运行目录（第 2 节），更新 AGENTS.md、`docs/lab/HANDOFF_LAB_UI.md` 与本文件。

## 11. 文档索引

| 文档 | 内容 |
| --- | --- |
| `F:\egg\AGENTS.md` | 全项目规则与第 1–65 节进度记录 |
| `docs/lab/HANDOFF_LAB_UI.md` | LAB 逐轮实施、机制与验证记录（本日 2.11–2.14） |
| `docs/lab/lab_design_2026-10-06.md` | LAB 原始设计 |
| `docs/lab/local_versus_design_2026-10-06.md` | 本地双人对战设计与下一阶段任务书（第 5 节，未实施） |
| `docs/LAB_BUGFIX_2026.10.07.md`、`LAB_MENU_ENTRY_…`、`LAB_VISUAL_TITLE_…`、`LAB_AP_FEEDBACK_…` | 2026-10-07 早前各轮 LAB 修复说明 |
| `verification/lab_prep_r17_20261007/` | r17/r18：地图、退出、音效验证与对照（含 `stage_dump.json`） |
| `verification/lab_ai_tier_r19_20261007/` | r19/r20：AI 段位、按钮、韩文、单位价值验证与截图 |
| `verification/exit_paths_20261007/` | 标题 Esc 与对战中关闭的复现与验证（`driver_exit.py`，四种模式） |
| `docs/ALL_UNLOCKED_MAX_LEVEL_2026.10.07.md` | 全解锁满级入口 |
| `docs/UNIT_LEVEL_UNLOCK_2026.10.05.md` | 玩家等级规则 |
| `docs/MUMMY_VARIANTS_2026.10.05.md`、`CLASSIC_VEHICLES_2026.10.04.md` | 社区单位参数 |
| `docs/CONTENT_AUTHORING.md`、`ONLINE_INTERFACE.md` | 内容制作与联机接口 |
