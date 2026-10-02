# Release validation — 2026.10.02.1

## English

The distributed archive was extracted into an independent path containing Chinese characters and spaces. All 1,886 manifest entries passed file-size and SHA-256 verification. The package loads the Windows x64 core with SHA-256 `a613dfe9a40291cbeed1046eed24804694ad2a165c5e96566d253a4c0c995975`. Personal saves and maximum-level profiles are absent from the archive.

### Presentation and combat

Conditions: Intel Core i9-13900HX, NVIDIA GeForce RTX 4080 Laptop GPU, ANGLE / Direct3D 11, 2560 × 1440. The actual Win32 borderless window was hidden during automated testing. Real waveOut mixing and output were retained with device gain set to zero. Mission, return to menu, world map and battle navigation preceded the 40- and 80-unit combat samples. All ten modified character types were included in the generated combat groups.

| Units | Frames | Mean FPS | Mean processing, ms | Processing p99, ms | Display interval p99, ms | Intervals > 50 ms |
| --- | --- | --- | --- | --- | --- | --- |
| 40 | 480 | 30.000 | 3.064 | 6.986 | 39.759 | 0 |
| 80 | 330 | 29.997 | 5.191 | 12.650 | 42.150 | 0 |

These observations establish the measured behaviour of this release on the stated hardware. They do not establish a universal frame-time bound. Earlier validation of the same core measured first-battle resource-loading peaks of approximately 66–103 ms. Initial graphics setup, uncached audio, synchronous screenshots and OS scheduling can still create brief delays. All missions, all army combinations and extended sessions have not been validated.

### Functional checks

- The actual distributed executable completed a hidden 215-frame startup, submitted its save and exited without an error. It loaded the core and host from the extracted package.
- A pristine seed contained units 5 and 70, zero medals and zero MSP. First-start rewards reached the main menu and unlocked event unit 257 through the original reward flow.
- The fresh reward-claimed profile acquired 330 medals through BUY. Buying unit 398 consumed 300 medals, leaving 55. DECK listed 5, 70, 257 and 398; ownership and balance survived restart. Twenty-one purchase, insufficient-funds, menu, DECK and persistence checks passed. Test writes remained inside isolated profiles.
- The same core's prior native-script validation passed all ten target IDs: 16–19, 96–99, 344 and 362. Checks covered pistol initial state, first special, retained ordinary weapon, later specials, independent instances and battle snapshot restoration. Native truck spawning and four corresponding passenger types were also checked. The changes use existing per-instance state and require no save-format extension.
- Prior validation of this exact core/host combination passed Event → stage → Deck → DECK 2 → Event → NPC-supported battle and keyboard deployment. Fault injection with an invalid general controller selection also passed through the current visible battle panel's controller. The original naturally occurring failure was not reproduced on that route.
- Texture conversion passed 30 format/size comparisons with byte-identical pixels. Native import contracts passed 43 checks. Two representative Vorbis files differed by at most one 16-bit PCM sample value from the original decoder.
- Release preparation did not overwrite either existing personal profile. All audited test save writes targeted independent directories. Community-content prototypes are excluded from this release.

## 中文

分发压缩包在包含中文与空格的独立路径中解压。清单中的 1,886 个文件均通过大小及 SHA-256 核对。运行包加载上述校验值对应的 Windows x64 核心；压缩包不包含个人进度及满级存档配置。

### 显示与战斗

条件：Intel Core i9-13900HX、NVIDIA GeForce RTX 4080 Laptop GPU、ANGLE / Direct3D 11、2560 × 1440。自动验证使用实际 Win32 无边框窗口，并隐藏窗口以避免干扰操作；保留真实 waveOut 混音与输出，设备增益设为零。在 40 与 80 单位交战样本之前，依次验证 Mission、返回菜单、世界地图及战斗入口。生成的交战单位包含此次修改的全部十类角色。具体指标见上表。

上述结果适用于所列硬件与测试样本。相同核心此前测得首次战斗资源加载峰值约为 66–103 毫秒。首次图形初始化、尚未缓存的音频、同步截图及系统调度仍可产生短暂延迟。全任务、全部兵种组合及长期连续运行仍需持续验证。

### 功能验证

- 实际分发 EXE 完成隐藏窗口启动、215 帧运行、存档提交及正常退出；核心与宿主均从解压目录加载。
- 初始种子仅持有单位 5、70，勋章与 MSP 为零。首次奖励流程正常进入主菜单，并通过原版奖励解锁活动单位 257。
- 本轮新建的奖励领取后存档通过 BUY 取得 330 勋章，购买单位 398 消耗 300，余额为 55。DECK 显示 5、70、257、398，重启后单位及余额保留。共 21 项购买、余额不足、菜单、DECK 与保存检查通过；测试写入限定于独立存档目录。
- 相同核心此前通过十个目标 ID（16–19、96–99、344、362）的原生脚本验证，覆盖手枪起始、首次绝招、强化普通攻击保留、后续绝招、实例独立性及战斗快照恢复；同时验证原生运兵车生成及四类对应乘员。修改使用原有实例字段，无需扩展存档格式。
- 相同核心与宿主此前通过 Event → 关卡 → Deck → DECK 2 → Event → NPC 配合战斗及键盘出击验证。通用控制器选择失效的故障注入通过当前可见战斗面板所属控制器继续执行。原始自然失效在该路线中未复现。
- 纹理转换的 30 组格式及尺寸比较均保持像素字节一致；原生调用契约通过 43 项检查；两份代表性 Vorbis 音频与原解码器相比，16 位 PCM 样本值最大差异为 1。
- 发布准备未覆盖已有普通或满级个人存档；全部已核对的测试存档写入均位于独立目录。本次发布不包含社区内容实验原型。
