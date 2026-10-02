# 2026.10.02.1

## English

This release combines the 30 FPS performance update, ten unit weapon changes, and the Event deck-switch keyboard fix.

- Native math, memory and graphics calls, texture conversion, Vorbis decoding, bounded caches and frame scheduling reduce menu loading and dense-combat processing costs. At 2560 × 1440 on an i9-13900HX / RTX 4080 Laptop GPU, the validated 40- and 80-unit combat samples averaged approximately 30.00 FPS. Initial resource loads can still cause brief frame-time peaks; all missions and hardware configurations have not been validated.
- Marco, Tarma, Eri, Fio, Fat Marco, Fat Tarma, Fat Eri, Fat Fio, Christmas Eri and Christmas Fio begin each deployment with a pistol. After their first special, ordinary ranged attacks retain the strengthened weapon. This behaviour follows the requested MSA reference. Later specials retain the original readiness and cooldown rules. Weapon state is independent for each instance and applies to corresponding Regular Army Truck passengers.
- Keyboard actions resolve the controller of the current battle panel, preserving operation after Event deck switching and controller-index changes.

Download and fully extract `MSD.WINDOWS.S1XLV_2026.10.02.1.zip`, then run `MSD WINDOWS S1XLV.exe`. Windows 10/11 x64 is required; runtime dependencies are bundled.

The distribution retains an initial save with SOLDIER and SANDBAG, both level 1, initial base levels and zero medals/MSP. Daily rewards and event-unit unlocking remain available. Existing personal and maximum-level save formats remain compatible. To migrate ordinary progress, close the game, back up the complete `play_save/` folder, and copy it into the newly extracted package. Personal saves are excluded from the archive.

Keyboard controls, the 16:9 layout, borderless fullscreen, the custom monitor with its original static/CRT effects, and stamina regeneration at **1 point per second** remain available. Detailed controls and measured validation results are documented in the README and `docs/VALIDATION_2026.10.02.1.md`.

## 中文

本次发布包含以 30 FPS 为目标的性能优化、十个单位的武器行为调整，以及 Event 切换阵容后的键盘绑定修复。

- 原生数学、内存及图形调用、纹理转换、Vorbis 解码、有容量限制的缓存与帧调度降低了菜单加载及密集交战的处理开销。在 i9-13900HX / RTX 4080 Laptop GPU、2560 × 1440 条件下，已验证的 40 与 80 单位交战样本均达到平均约 30.00 FPS。首次资源加载仍可能出现短暂耗时峰值；全任务与不同硬件配置仍需持续验证。
- 马可、塔玛、英里、菲欧、胖马可、胖塔玛、胖英里、胖菲欧、圣诞英里、圣诞菲欧每次出击均从手枪状态开始。首次发动绝招后，普通远程攻击保留强化武器，使这一行为贴近用户指定的 MSA 参考。后续绝招继续遵循原版的就绪条件与冷却规则。武器状态按单位实例独立记录，正规军运兵车生成的对应乘员同样适用。
- 键盘操作解析当前战斗面板所属的控制器，适用于 Event 切换阵容及控制器索引变化后的操作。

下载并完整解压 `MSD.WINDOWS.S1XLV_2026.10.02.1.zip`，启动 `MSD WINDOWS S1XLV.exe`。适用于 Windows 10/11 x64，运行依赖已随包提供。

分发包采用初始存档：仅持有等级 1 的 SOLDIER 与 SANDBAG，基地为初始等级，勋章与 MSP 均为 0。每日奖励与活动单位解锁流程保持可用。现有个人及满级存档格式保持兼容。迁移普通进度时，请先关闭游戏，备份完整的 `play_save/` 文件夹，再将其复制至新运行包目录。压缩包不包含个人存档。

继续保留键盘操作、16:9 布局、无边框全屏、自定义屏幕的原版雪花及显像管效果，以及 **每秒恢复 1 点体力**。README 与 `docs/VALIDATION_2026.10.02.1.md` 提供详细按键及实测验证结果。
