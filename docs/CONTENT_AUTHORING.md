# 扩展世界与社区敌军接口

核验日期：2026-10-04。接口版本：1。运行入口为项目根目录的 `event_trial_launcher.py`。世界目录为 `campaign_content/catalog.json`，社区单位目录为 `community_content/registry.json`。示例配置保存在 `campaign_content/catalog.example.json`；默认目录保留空世界列表。

## 1. 使用流程

在游戏目录执行以下 PowerShell 命令：

```powershell
.\windows_runtime\python.exe content_tool.py install-example
.\windows_runtime\python.exe content_tool.py validate
```

示例登记世界 4、里世界 4及六款现有社区单位，复用原版场景与音乐。2026-10-04 根据用户要求，尚未完成的扩展入口及选择面板暂时隐藏，`F6` 暂不打开该界面。世界、区域、关卡、敌军、场景、音乐及独立进度接口保留，安装示例不会自动启用界面。独立开发预览可显式构造 `CommunityCampaign(p, trial, ui_enabled=True)`；正式启动入口采用默认停用状态。预览面板每页十项，战斗期间禁止打开。

`install-example` 仅适用于当前未登记世界的目录。已有内容通过编辑 JSON 追加。资源和目录修改在下一次正常启动时加载。

## 2. 世界、关卡及稳定内容键

目录格式为 schema 1，包含 `assets`、`scenes`、`music`、`worlds`。`worlds` 下依次登记 `areas` 和 `stages`。世界名称与数量由配置定义，可追加世界 5、里世界 5、世界 6及后续区域。原生固定世界进度数组保持其既有容量；扩展世界使用独立适配器和进度文件。

世界、区域、关卡、场景、音乐均使用 `key`。键长 1–120 字符，允许 ASCII 字母、数字、下划线、点与连字符，并要求目录内及社区单位键之间唯一。建议使用作者前缀，例如 `author.world5.area2.stage8`。修改展示标题或调整关卡顺序可以保留原有键；已发布内容的键应保持稳定。

最小关卡示例：

```json
{
  "schema": 1,
  "assets": {},
  "scenes": [],
  "music": [],
  "worlds": [{
    "key": "author.world5", "title": "世界 5",
    "areas": [{
      "key": "author.world5.area1", "title": "区域 1",
      "stages": [{
        "key": "author.world5.area1.stage1", "title": "关卡 1",
        "template": 1011, "scene": 0, "music": 100,
        "stamina": 0, "enemy_base_hp": 20000, "reward_msp": 100,
        "strength_steps": 0, "enemy_specials": true,
        "enemies": [
          {"unit": "s1xlv.m15a_future", "level": 40},
          {"unit": 3, "level": 40}
        ],
        "waves": [{"tick": 0, "enemy": 0}, {"tick": 90, "enemy": 1}],
        "reward_units": ["s1xlv.di_cokka_mk2"]
      }]
    }]
  }]
}
```

| 字段 | 语义及当前边界 |
| --- | --- |
| `template` | 原生 Mission 模板，默认 1011；模板须存在，保留其评级阈值等基础规则。当前适配执行基地摧毁型关卡。 |
| `scene` | 原版场景整数 ID 0–137，或独立场景稳定键。 |
| `music` | 原版 SoundID 1–1030，或独立音乐稳定键，默认 100。 |
| `stamina` | 消耗体力，0–1000，默认 0；不足时禁止入场。 |
| `enemy_base_hp` | 敌军基地基础 HP，1–100000000，默认 10000。 |
| `reward_msp` | 关卡 MSP 奖励，0–999999，默认 0；实际收益沿用原生战斗计算。 |
| `strength_steps` | 敌军关卡强化参数，0–100，默认 0；生命值与伤害使用 `1 + 0.2 × 参数` 倍率。 |
| `enemy_specials` | 原生敌军绝招决策开关，默认 `true`；冷却、动作状态和攻击距离继续由原生单位处理。 |
| `enemies` | 1–32 条名单；`unit` 使用原版整数 ID 1–399 或社区单位稳定键。 |
| `level` | 敌军配置等级，1–200，默认 40；当前基础参数插值在显示等级 40 达到最终锚点。 |
| `waves` | 明确的出击时序；`enemy` 为名单的从零开始索引。`tick` 严格递增，0–32766；每关最多 8192 条。 |
| `requires` | 世界、区域或关卡的前置通关键列表；相关上级条件同时生效，目录校验拒绝循环依赖。 |
| `reward_units` | 首次胜利解锁单位的列表；已拥有单位保留既有等级，奖励采用正常进度保存流程。 |

当前目录校验上限为 100000 条关卡，扩展场景总容量为 4096。实际战斗按所选世界建立 Mission 表。已验证一万条关卡目录和长链解锁条件；十万条实际运行及大量场景的内存、性能表现仍需专项测量。世界、区域与关卡容量分别评估，原版“五项 Mission 扩展”入口继续保留其历史接口范围。

## 3. 当前与后续社区单位作为敌军

已注册单位的敌军身份由运行注册表解析。新增社区单位沿用 schema 2 的素材、动画、参数、名称、图标和稳定键约定，在关卡中填入其 `key` 即可。敌军名单与出击路径支持当前 1024–1029 及后续登记 ID；接口验证还使用了隔离登记的第七款单位 1030。

社区单位当前容量为 64，ID 范围 1024–1087；单位和图标登记顺序需要连续，已有键与顺序应保留。缺失登记的 ID 继续由原生边界处理。单位注册与关卡登记属于两个步骤，关卡目录不会自动生成单位素材或独立行动类。完整单位素材约定见开发目录的 `CONTENT_EXTENSION_CONTRACT.txt` 与既有社区注册表。

## 4. 新场景、OBM 与 PNG

新增场景可使用独立 OBM 图集。PNG 输入通过统一导入工具转换为原生 OBM：

```powershell
.\windows_runtime\python.exe content_tool.py import-png .\art\author_desert.png .\campaign_content\author_desert.obm
```

工具输出文件名、SHA-256、原始尺寸与运行画布尺寸。将 SHA-256 登记到目录的 `assets`，再登记场景：

```json
{
  "key": "author.desert", "base_id": 0,
  "texture": "author_desert.obm",
  "bounds": [0, 700],
  "terrain": [[0, 338], [1400, 338]],
  "bases": [68, 653],
  "graphics": {
    "rects": [[0, 0, 384, 240, 0, 0, 0, 0]],
    "back": [[0]], "front": []
  }
}
```

`bounds` 沿用原生场景的半宽坐标，实际战场宽度为 `2 × (right - left)`。`terrain` 为覆盖整个实际宽度的 `[x,y]` 折线，x 严格递增；y 使用原生地形坐标。`bases` 沿用 SceneInfo 的半宽基地坐标。地形或基地配置需要同时声明边界。

`graphics.rects` 每条包含八个 int16 字段：图集 x、图集 y、宽、高、锚点 x、锚点 y、翻转字段、保留字段。`back`、`front` 是背景与前景图层列表，每层列出对应图块的动画帧索引。当前支持最多 4096 个图块、每组 64 层、每层 1024 帧。独立图块布局使用通用场景构造器 `base_id: 0`；复用既有布局时可以省略 `graphics` 并指定相应原生 `base_id`。

图块锚点使用原生偏移语义。通用背景构造器的基础绘制纵坐标为 `32 × 原生缩放`；锚点 0 可直接绘制背景。地面纹理可登记为额外图块或前景层，实际行走高度由 `terrain` 决定。该接口支持原生图块层和动画；独立相机、视差速度及新增目标规则仍需对应适配。

PNG 导入要求单帧、通道位深不超过 8 位的 RGB/RGBA、灰度或调色板格式，尺寸不超过 8192×8192。运行格式为 RGBA 调色板和 8 位索引，索引 0 保留透明黑色，调色板总容量 256。超过颜色容量时工具明确拒绝导入，像素颜色调整由作者显式完成。

当前 GLES 场景采样要求二的整数次幂画布。工具补充透明边缘并保持原始图像、像素坐标与 RGBA 数值，执行解码往返检查；已有 OBM 也需符合运行画布约束。隔离验证同时检查了原生显示和 GPU 纹理像素。图块宽高使用原始素材范围，避免将透明边缘计入可见图块。

新增资源要求独立文件名，避免与原生资源或社区资源产生冲突。单文件上限 64 MiB，目录资源合计上限 512 MiB；登记值须匹配文件 SHA-256。PNG、PSD 源稿及其坐标保留在作者素材目录。

## 5. 独立关卡音乐

输入采用 Ogg Vorbis，工具完成原生解码检查后生成 `.msdf` 文件：

```powershell
.\windows_runtime\python.exe content_tool.py import-music .\audio\author_desert.ogg .\campaign_content\author_desert.msdf
```

将输出哈希登记至 `assets`，在 `music` 中登记：

```json
{"key": "author.desert_bgm", "file": "author_desert.msdf", "base_sound_id": 100}
```

关卡的 `music` 填入 `author.desert_bgm`。`base_sound_id` 复用原生音乐描述符的类型参数；可选 `loop_start`、`loop_end` 沿用原生循环时间字段，默认零。独立音乐复用已核验的空闲 SoundID 1031，并在切换时停止播放、释放引用及清除缓存指针；胜负音乐继续采用既有结算流程。已验证两个独立曲目的顺序加载与 PCM 输出。

本轮音效与音乐的独立关闭功能按用户要求暂缓。设置界面和 F9 总静音继续保留现行行为；后续恢复该功能时需要采用原版按钮样式。

## 6. 进度、奖励与验证范围

每个存档目录新增 `campaign_progress.json`，按稳定关卡键记录挑战次数、胜利次数、捕虏数量、评级、最佳用时及首次单位奖励状态。原生 MSP、社区单位进度和扩展关卡进度使用 `campaign_transaction.json` 协调保存；写入失败恢复文件与内存，启动时恢复未完成事务。评级使用模板的原生时间阈值，捕虏数量来自实际战斗结果。独立捕虏编排、捕虏集齐奖励和复杂关卡目标需后续扩展配置。

当前验证覆盖六款敌军的实际波次出击、受控冷却与距离下的原生绝招决策、后续单位登记、独立场景与音乐、受控胜负结算、奖励重启、故障回滚和原生菜单返回。全新增关卡的自然通关、长期运行与不同硬件表现保留待核验状态。证据摘要见 `CONTENT_INTERFACE_VALIDATION.json`。
