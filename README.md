# metal slug defense on Windows ported edition

## English

An unofficial Windows port based on the Android version of **Metal Slug Defense 1.46.0**. The game core is statically recompiled for Windows x64, with local adaptations for graphics, audio, input, and saving.

This edition adds keyboard controls and a **16:9 layout** with expanded backgrounds and adjusted interface positions. Sprites retain their proportions, and the layout preserves the original visible content. Borderless fullscreen is enabled by default.

**Stamina regenerates at 1 point per second.** The original Android version regenerates 1 point per minute.

### Update 1.46.4

- Updated the Windows display version, launcher titles, and EXE file/product versions to **1.46.4**.
- This revision retains the current formal edition's content. Version metadata and launcher declarations have been checked; full campaign and long-term validation remain pending.

### Update 1.46.3.1

- Added seven Regular Army infantry units: **Regular Army Shield Soldier**, **Regular Army Rifleman**, **Regular Army Bazooka Soldier**, **Regular Army Gatling Soldier**, **Regular Army Paratrooper**, **Regular Army Rocket Bomb Soldier**, and **Regular Army Mortar Soldier**.
- Their uniforms use the existing Regular Army Soldier palette, and all seven belong to PF. AP is the Rebel counterpart's AP plus 5; HP is `floor(counterpart HP × 10 / 9)`. Attack damage, attack timing, movement, and production intervals retain the counterpart's behavior.
- Shield Soldier, Rifleman, Bazooka Soldier, and Gatling Soldier cost **15 medals each**. Paratrooper, Rocket Bomb Soldier, and Mortar Soldier cost **45, 55, and 65 medals**, respectively. The **Regular Army Soldier Pack** contains all seven for **150 medals** and preserves the levels of units already owned.
- All seven units and their pack are purchasable from the initial profile, with no stage, faction-core, Event, or prerequisite-unit requirement. Existing profiles acquire the new units through the shop.
- Paratrooper deployment, landing, and mortar assembly retain PF identity. Shop and Customize HP displays use the actual combat units.
- The optional all-units Lv1 profile now includes all **13 playable community units** when first created. Existing profile progress is preserved.
- Corrected retained machine-gun, shotgun, rocket, and laser parameters for Marco, Fat Marco, Tarma, Fat Tarma, Eri, Christmas Eri, Fio, Fat Fio, and Christmas Fio. Retained attacks now use their native special-weapon damage and hit behavior; Fat Eri's existing laser correction passed regression checks.
- Weapon validation and original movement-asset findings are recorded in [the weapon report](docs/WEAPON_BEHAVIOUR_1.46.3.1_2026.10.05.md).
- Release preparation and validation scope are recorded in [the 1.46.3.1 report](docs/VALIDATION_1.46.3.1_2026.10.05.md).

### Update 1.46.2

- Added a selector for historical MSD Event missions.
- Enabled acquisition of Event units through the corresponding Event shops and prisoner rewards.
- Added three units: **DI-COKKA MK.II**, **DI-COKKA MK.III**, and **GIRIDA-O MK.II**.
- Fixed misaligned sprite pixels on **HEAVY B (Future)**.
- Added independent music and sound-effects controls using native buttons in title options, main-menu options, and the battle pause menu. Settings are saved and remain stable when entering Customize and the other checked menu pages.
- Added `Esc` for Back and battle pause/resume. Corrected the opening/ending movie button overlap and centered the main-menu option rows.
- Player units use the original world's unlock state to determine the initial Lv10/Lv20 limit. The original medal transactions unlock Lv20→25, Lv25→30 and Lv30→35 for 30, 50 and 70 medals respectively; the matching faction core permits Lv40 after the Lv35 stage. Registered community units use the same rules, including future additions. Existing unit levels and completed unlock stages are retained. Details: [level unlock verification](docs/UNIT_LEVEL_UNLOCK_2026.10.05.md).
- Corrected Fat Eri's retained large laser to use native stationary laser parameters and bounded damage, preserving the large visual effect.
- Events without a registered shop now hide SHOP in the base and map. Registered Event shops retain their catalog and exchange flow; ordinary unit shops retain native prices.
- Improved status-report file-lock handling and rendering-thread cleanup on exit.
- Added an optional all-units Lv1 profile with independent progress. All 399 original units and six registered community units are owned at Lv1; all nine native faction/base upgrades start at Lv1. Map progress follows the initial save and requires normal progression.
- Release verification and its scope are recorded in [VALIDATION_1.46.2_2026.10.04.md](docs/VALIDATION_1.46.2_2026.10.04.md).

### Update 1.46.1

- Fixed the persistent sprite flickering and body-part misalignment affecting Sol Dae Rokker, including its enraged variant.
- Added three independent units: **NOP-03 SARUBIA (Future)**, **M-15A (Future)**, and **HEAVY B (Future)**.

### Update 2026.10.02.1

This release includes performance improvements targeting **30 FPS**, the Event deck-switch keyboard fix, and weapon behaviour changes for **ten units**: Marco, Tarma, Eri, Fio, Fat Marco, Fat Tarma, Fat Eri, Fat Fio, Christmas Eri, and Christmas Fio.

These ten units start each deployment with a pistol. After the first special attack, their ordinary ranged attacks retain the strengthened weapon, bringing this aspect of their behaviour closer to Metal Slug Attack (MSA). Subsequent specials continue to follow the original readiness and cooldown rules. Each unit maintains its own weapon state, including corresponding passengers generated by the Regular Army Truck. Other MSA mechanics remain outside this change.

The current source includes native optimizations for frequently used math, memory, graphics calls, texture conversion, and Vorbis decoding, with bounded asset/audio caches and 30 FPS presentation scheduling. Local validation at 2560×1440 measured approximately 30.00 FPS during 40- and 80-unit combat. Initial resource loading can still exceed the frame budget; performance across all missions and hardware remains under evaluation.

Battle keyboard actions resolve the controller belonging to the currently visible battle panel on each invocation. Event deck switching and controller-index failure scenarios have been checked with isolated saves.

### Controls

| Key | Action |
| --- | --- |
| `1`–`9`, `0` | Deploy the unit in deck slots 1–10, respectively. The numeric keypad is also supported. |
| `Space` | Activate special attacks for all friendly units whose specials are ready, indicated by the blue glow. |
| <kbd>&#96;</kbd> (backtick) | Upgrade AP production. |
| `-` | Launch the Metal Slug attack when charged. |
| `=` | Attempt to deploy each of the ten deck slots from left to right. Continue through the remaining slots when a unit is unaffordable or on cooldown. |
| `F11` / `Alt+Enter` | Switch between borderless fullscreen and windowed mode. |
| `F9` | Toggle mute. |
| `Esc` | Back; pause or resume a battle. |
| `F12` | Save a screenshot. |
| `Alt+F4` | Close the game. |

Mouse controls remain available. Deployment and special attacks follow the game's AP, cooldown, readiness, unit-limit, and pause conditions.

### Run

Open the [project page](https://github.com/sprievs7up/metal-slug-defense-on-Windows-ported-edition), click the green **Code** button, and select **Download ZIP**. Extract the entire archive, open the extracted project folder, and run **MSD WINDOWS S1XLV.exe**. Windows 10/11 x64 is required; the runtime is bundled.

The package starts with an initial save. Units can be purchased with medals, and the original daily and event reward paths are preserved. Save files are created in `play_save/`; existing personal progress is excluded from the distributed package. Full campaign coverage and long-term stability remain under evaluation.

To update an existing installation, close the game, back up all existing `play_save*/` folders, extract the new package into a separate folder, and copy those complete save folders into it. The existing save format remains compatible; initial seeds are used only when the corresponding save does not exist.

### Optional all-units Lv1 save

Run **Start_MSD_All_Units_Level1.vbs** from the extracted game folder. This entry uses the same formal game core and creates an independent save in `play_save_all_units_level1/` on first launch. The normal EXE continues to use `play_save/`; an existing local maximum-level launcher retains its separate save.

The preset owns all 399 original units and the 13 currently registered playable community units at **Lv1**. All nine upgrades under the native army/base customization menu also start at **Lv1**. Maps retain initial progress, no stages are cleared and no prisoners are collected; later stages and worlds require progression. Currency, items and the initial deck follow the formal initial save. World progression and faction-core level limits remain active.

Subsequent launches preserve upgrades, map progress and settings. To use this profile in a new installation, copy its entire `play_save_all_units_level1/` folder. The preset files under `game_data/all_units_level1/` are distributed independently of personal saves.

### Content authoring and networking interfaces

Configurable worlds, registered community enemies, independent scenes and music are documented in [CONTENT_AUTHORING.md](docs/CONTENT_AUTHORING.md). The unfinished world selection interface is temporarily hidden, and `F6` does not open it. The default catalog is empty; the supplied example can be installed with the authoring tool for development.

The self-hosted room and transport preparation is described in [ONLINE_INTERFACE.md](docs/ONLINE_INTERFACE.md). In-game multiplayer battle synchronization remains under development.

## 中文

本项目基于安卓原版 **《合金弹头塔防》（Metal Slug Defense）1.46.0**，将游戏移植至 Windows。游戏核心通过静态重编译生成 Windows x64 代码，并适配本地的图形、音频、输入与存档功能。

本版本新增键盘操控系统，并将画面调整为 **16:9 布局**。通过扩展背景与调整界面位置，保持角色及素材的原有比例，并保留原画面的可见内容。默认采用无边框全屏模式。

**体力每秒恢复 1 点。** 安卓原版的恢复速率为每分钟 1 点。

### 1.46.4 更新

- Windows 显示版本、启动窗口标题及 EXE 文件版本与产品版本统一调整为 **1.46.4**。
- 本次修订沿用当前正式版内容。版本元数据及启动入口声明已核对；完整关卡与长期运行验证仍待开展。

### 1.46.3.1 更新

- 新增七种正规军小兵：**正规军盾牌兵**、**正规军步枪兵**、**正规军反坦克兵**、**正规军加特林机枪兵**、**正规军伞兵**、**正规军冲天火箭弹兵**及**正规军迫击炮兵**。
- 服装采用现有正规军士兵配色，全部归属 PF。AP 为对应叛军单位 AP 加 5；生命值按对应单位的精确倍率 **10/9** 计算并向下取整。攻击伤害、攻击时序、移动速度与生产间隔沿用对应单位的原生行为。
- 盾牌兵、步枪兵、反坦克兵及加特林机枪兵各为 **15 勋章**；伞兵、冲天火箭弹兵及迫击炮兵依次为 **45、55、65 勋章**。**正规军士兵包**包含全部七种单位，售价 **150 勋章**，保留已拥有单位的等级。
- 七种单位及组合包均在初始状态开放购买，无关卡、军队核、活动进度或前置单位限制。已有存档通过商店获取新增兵种。
- 伞兵投放、落地及迫击炮架设过程中保留 PF 身份；商店与强化属性面板读取实际作战单位的生命值。
- 全兵种 Lv1 可替代存档首次创建时包含全部 **13 种可用社区单位**；已有独立存档保留进度。
- 修复马可、胖马可、塔玛、胖塔玛、英里、圣诞英里、菲欧、胖菲欧及圣诞菲欧保留武器时的参数选择错误。后续远程普攻沿用各自原生特殊武器的伤害、范围及命中行为；胖英里的既有激光修订通过回归检查。
- 武器验证及原始移动素材核查见 [专项记录](docs/WEAPON_BEHAVIOUR_1.46.3.1_2026.10.05.md)。
- 发布准备与验证范围见 [1.46.3.1 验证记录](docs/VALIDATION_1.46.3.1_2026.10.05.md)。

### 1.46.2 更新

- 新增 MSD 历史 Event 任务选择功能。
- 支持通过对应 Event 商店及捕虏奖励获取活动单位。
- 新增三个单位：**基 · 寇卡坦克 MK.II**、**基 · 寇卡坦克 MK.III**、**吉利塔 · O MK.II**。
- 修复**未来重装 B 型**的像素错位问题。
- 标题设置、主菜单设置与战斗暂停页增加音乐、音效独立开关，沿用原生按钮并保存设置。进入强化及其他已核验菜单时保留设置状态。
- `Esc` 执行返回及战斗暂停、恢复；修复开幕与结尾动画按钮重叠，并将主菜单设置行居中对齐。
- 玩家单位依据原版世界开放状态确定初期 Lv10/Lv20 上限。Lv20→25、Lv25→30、Lv30→35 分别采用原生 30、50、70 勋章解锁交易；完成 Lv35 阶段并持有对应军队核心后开放 Lv40。当前及后续有效登记的社区单位适用相同规则，已有等级与已完成的解锁阶段保留。核验范围见[等级解锁修复记录](docs/UNIT_LEVEL_UNLOCK_2026.10.05.md)。
- 修复胖子英里强化普攻的大激光参数，恢复原生静止激光与受限伤害行为，保留大激光显示。
- 未登记商店的 Event 隐藏基地与地图 SHOP；已登记商店保留目录与兑换流程，普通单位商店保留原生价格。
- 修订状态报告文件锁异常处理及退出时的渲染线程释放顺序。
- 增加“全兵种 Lv1”可替代存档：399 个原版兵种与 6 个已登记社区兵种初始均已拥有，等级均为 Lv1；“我方阵营”的 9 项强化均为 Lv1。地图保持初始进度，后续关卡按游戏规则自行解锁。
- 发行核验与适用范围见 [VALIDATION_1.46.2_2026.10.04.md](docs/VALIDATION_1.46.2_2026.10.04.md)。

### 1.46.1 更新

- 修复索尔罗卡（Sol Dae Rokker）及其愤怒版持续出现的贴图闪烁与身体部件错位问题。
- 新增三个独立单位：**爆竹红（未来）**、**M-15A 型（未来）**、**未来重装 B 型**。

### 2026.10.02.1 更新

本次发布包含以 **30 FPS** 为目标的性能优化、Event 切换阵容后的键盘绑定修复，以及 **十个单位** 的武器行为调整：马可、塔玛、英里、菲欧、胖马可、胖塔玛、胖英里、胖菲欧、圣诞英里、圣诞菲欧。

上述十个单位每次出击均从手枪状态开始。首次发动绝招后，普通远程攻击保留对应强化武器，使这一行为更接近《合金弹头进攻》（Metal Slug Attack，MSA）；后续绝招继续遵循原版的就绪条件与冷却规则。武器状态按单位实例独立记录，正规军运兵车生成的对应乘员同样适用。此次调整的范围仅包含上述武器行为。

当前源码加入高频数学、内存及图形调用、纹理转换与 Vorbis 解码的原生优化，并采用有容量限制的资源及音频缓存，以及 30 FPS 显示调度。本地 2560×1440 测试中，40 与 80 单位交战均达到平均约 30.00 FPS。首次资源加载仍可能超过单帧预算，全任务及不同硬件条件下的表现仍需持续验证。

战斗快捷键在每次调用时解析当前可见战斗面板所属的控制器。Event 阵容切换及控制器索引失效情形已使用独立存档进行验证。

### 按键操作

| 按键 | 功能 |
| --- | --- |
| `1`–`9`、`0` | 分别出击编队第 1–10 个槽位的单位；支持数字小键盘。 |
| `空格` | 使所有绝招已就绪的友方单位发动绝招，就绪状态以蓝光表示。 |
| <kbd>&#96;</kbd>（反引号） | 升级 AP 生产。 |
| `-` | 在充能完成后发动弹头车攻击。 |
| `=` | 从左至右依次尝试出击全部十个槽位；遇到 AP 不足或冷却中的单位时，继续尝试后续槽位。 |
| `F11` / `Alt+Enter` | 切换无边框全屏与窗口模式。 |
| `F9` | 切换静音状态。 |
| `Esc` | 返回；在战斗中暂停或恢复。 |
| `F12` | 保存截图。 |
| `Alt+F4` | 关闭游戏。 |

保留鼠标操作。出击与绝招均遵守游戏的 AP、冷却、就绪状态、单位数量上限及暂停条件。

### 运行方法

在[项目主页](https://github.com/sprievs7up/metal-slug-defense-on-Windows-ported-edition)点击绿色 **Code** 按钮，选择 **Download ZIP** 下载压缩包。完整解压后，打开解压得到的项目文件夹，启动 **MSD WINDOWS S1XLV.exe**。适用于 Windows 10/11 x64，运行依赖已随包提供。

分发包采用初始存档，玩家可以使用勋章购买单位；原版每日奖励、活动奖励及对应解锁流程均保留。个人进度保存在 `play_save/`，分发包不包含已有个人进度。全关卡覆盖与长期运行稳定性仍需持续验证。

更新已有安装时，请先关闭游戏并备份所有已有的 `play_save*/` 存档目录，将新运行包解压至独立目录，再将这些完整存档目录复制至该目录。现有存档格式保持兼容；初始种子仅在对应存档不存在时使用。

### 全兵种 Lv1 可替代存档

在解压后的游戏目录中启动 **Start_MSD_All_Units_Level1.vbs**。该入口使用同一正式版核心，首次启动时在 `play_save_all_units_level1/` 创建独立存档。普通 EXE 继续使用 `play_save/`；本地既有满级入口继续使用其独立存档。

该预设包含全部 **399 个原版兵种及当前登记的 13 个可用社区兵种**，均已拥有且初始为 **Lv1**。“我方阵营”的 **9 项强化均为 Lv1**。地图采用初始进度，关卡均未通关、捕虏均未收集，后续关卡及世界按游戏规则逐步解锁。货币、道具及初始编队沿用正式版初始存档。世界进度与军队核等级上限继续生效。

再次启动时保留已经完成的升级、地图进度及设置。迁移至新安装目录时，复制完整的 `play_save_all_units_level1/`。预设文件位于 `game_data/all_units_level1/`，发行文件与个人进度分别保存。

### 内容制作与联机预备接口

世界、社区敌军、独立场景和音乐的配置流程见 [CONTENT_AUTHORING.md](docs/CONTENT_AUTHORING.md)。尚未完成的世界选择界面暂时隐藏，`F6` 暂不打开该界面。默认目录保留空世界列表，示例通过内容制作工具安装用于开发。

自有服务器的房间与传输接口见 [ONLINE_INTERFACE.md](docs/ONLINE_INTERFACE.md)。游戏内双人战斗同步保留后续开发状态。

