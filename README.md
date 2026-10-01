# metal slug defense on Windows ported edition

## English

An unofficial Windows port based on the Android version of **Metal Slug Defense 1.46.0**. The game core is statically recompiled for Windows x64, with local adaptations for graphics, audio, input, and saving.

This edition adds keyboard controls and a **16:9 layout** with expanded backgrounds and adjusted interface positions. Sprites retain their proportions, and the layout preserves the original visible content. Borderless fullscreen is enabled by default.

**Stamina regenerates at 1 point per second.** The original Android version regenerates 1 point per minute.

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
| `F12` | Save a screenshot. |
| `Alt+F4` | Close the game. |

Mouse controls remain available. Deployment and special attacks follow the game's AP, cooldown, readiness, unit-limit, and pause conditions.

### Run

Download the Windows package from [Releases](https://github.com/sprievs7up/metal-slug-defense-on-Windows-ported-edition/releases), extract the complete archive, and run **MSD WINDOWS S1XLV.exe**. Windows 10/11 x64 is required; the runtime is bundled.

The package starts with an initial save. Units can be purchased with medals, and the original daily and event reward paths are preserved. Save files are created in `play_save/`; existing personal progress is excluded from the distributed package. Full campaign coverage and long-term stability remain under evaluation.

## 中文

本项目基于安卓原版 **《合金弹头塔防》（Metal Slug Defense）1.46.0**，将游戏移植至 Windows。游戏核心通过静态重编译生成 Windows x64 代码，并适配本地的图形、音频、输入与存档功能。

本版本新增键盘操控系统，并将画面调整为 **16:9 布局**。通过扩展背景与调整界面位置，保持角色及素材的原有比例，并保留原画面的可见内容。默认采用无边框全屏模式。

**体力每秒恢复 1 点。** 安卓原版的恢复速率为每分钟 1 点。

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
| `F12` | 保存截图。 |
| `Alt+F4` | 关闭游戏。 |

保留鼠标操作。出击与绝招均遵守游戏的 AP、冷却、就绪状态、单位数量上限及暂停条件。

### 运行方法

从 [Releases](https://github.com/sprievs7up/metal-slug-defense-on-Windows-ported-edition/releases) 下载 Windows 运行包，完整解压后启动 **MSD WINDOWS S1XLV.exe**。适用于 Windows 10/11 x64，运行依赖已随包提供。

分发包采用初始存档，玩家可以使用勋章购买单位；原版每日奖励、活动奖励及对应解锁流程均保留。个人进度保存在 `play_save/`，分发包不包含已有个人进度。全关卡覆盖与长期运行稳定性仍需持续验证。
