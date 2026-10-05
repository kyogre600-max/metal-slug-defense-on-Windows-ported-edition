# 白木乃伊、绿木乃伊及木乃伊召唤箱 MKII 素材

核验日期：2026-10-05。阶段：独立像素素材制作完成；游戏内登记与行为适配待实施。

本目录保存三款单位的透明 PNG 图集、按原生帧顺序排列的完整图集、动作预览、配色映射、原始参考及帧描述。白木乃伊与绿木乃伊采用《合金弹头 X》原始图集中的六级配色；召唤箱采用用户于 2026-10-05 明确确认的红褐色参考。

## 文件入口

| 对象 | 保留原生坐标的图集 | 完整帧排列图 | 本体动作预览 |
| --- | --- | --- | --- |
| 白木乃伊 | `sprites/white_mummy_atlas_0.png`、`white_mummy_atlas_1.png` | `sprites/white_mummy_frames.png` | `previews/white_mummy_body.gif`、`white_mummy_actions.png` |
| 绿木乃伊 | `sprites/green_mummy_atlas_0.png`、`green_mummy_atlas_1.png` | `sprites/green_mummy_frames.png` | `previews/green_mummy_body.gif`、`green_mummy_actions.png` |
| 木乃伊召唤箱 MKII | `sprites/mummy_generator_mk2_atlas.png` | `sprites/mummy_generator_mk2_frames.png` | `previews/mummy_generator_mk2_closed.png`、`mummy_generator_mk2_open.png`、`mummy_generator_mk2_actions.png` |

汇总预览为 `previews/three_units_overview.png`。各完整帧排列图的同名 JSON 记录帧索引、图块编号、单元格坐标、锚点及原生动作脚本。弹球及其消散效果位于 `sprites/rolling_ball.png`；五条悬挂木乃伊虫体动作的图块位于 `sprites/insects.png`，时序与原生锚点见 `sprites/effects.json`。

## 来源与配色依据

1. [Sprite Database：Metal Slug X 木乃伊原始图集](https://spritedatabase.net/files/neogeo/838/Sprite/Mummy.gif)。本地文件为 `source/sdb_Mummy.gif`，849 × 1536 像素。图集署名为 Grim，注明素材来自 Metal Slug X，并要求使用时保留提取者署名。
2. [Retro Game Zone：木乃伊原始图集](https://retrogamezone.co.uk/metalslug/mummy.htm)。本地文件为 `source/retrogamezone_mummy.gif`，用于交叉观察动作和弹体素材。
3. [Metal Slug Wiki：Mummy Generator](https://metalslug.fandom.com/wiki/Mummy_Generator)。红褐色参考通过[原始 Coffin.gif 地址](https://images.wikia.com/metalslug/images/7/7e/Coffin.gif)取得。本地文件为 `source/Coffin.gif`。其与《合金弹头 3》第四关指定配色的对应关系由用户明确确认。配色映射采用原始参考中的十级箱体颜色；蓝色铭牌及原生闪烁色保留。侧壁一项额外暗色映射至参考中已有的深阴影颜色，记录见 `palette_maps.json`。
4. 动作几何与图集坐标来自正式版现有 APK 资源：原生木乃伊 UnitID 61、木乃伊召唤箱 UnitID 64、悬挂木乃伊 UnitID 157 的图片描述和动作脚本。本地只读导出文件位于 `source/native/`；三款新单位尚未分配 UnitID。

Wiki 原始地址返回的部分文件采用无损 WebP 编码，同时保留地址中的 `.gif` 或 `.png` 后缀。读取时应以实际图像编码为依据。目录内其他 Wiki 图片及截图保存为检索参考；正式配色依据为上述 MSX 原始图集与用户确认的 Coffin.gif。

原生图集采用五位颜色扩展。脚本通过相同待机姿态建立颜色对应关系：原始普通木乃伊姿态与本地待机首帧在颜色编码还原后逐像素一致，白色及绿色参考也分别完成逐像素映射验证。完整动作使用本地原生帧几何；本轮验证范围包含参考姿态匹配及完整本地图集保留。

### 眼睛与舌头配色核查 R1（2026-10-05）

用户要求进一步核实白、绿木乃伊眼睛和舌头颜色。初版使用六级本体色进行映射，眼睛与舌头的三项独立颜色沿用原生普通木乃伊。本次对 `source/WhiteMummy.gif` 的 70 帧及 `source/0035.gif` 的 30 帧逐帧解码，以六级本体颜色的像素分布匹配原生相同姿态，白木乃伊取得 26 个匹配姿态，绿木乃伊取得 22 个匹配姿态。

| 色阶 | 原生普通木乃伊 RGB | 白木乃伊参考 RGB | 绿木乃伊参考 RGB |
| --- | --- | --- | --- |
| 深色 | (82, 24, 0) | (80, 24, 72) | (80, 24, 0) |
| 中间色 | (123, 49, 8) | (120, 48, 96) | (120, 48, 8) |
| 亮色 | (172, 98, 0) | (168, 96, 152) | (168, 96, 0) |

白木乃伊眼睛与舌头为紫色系；绿木乃伊保持橙褐色系。绿色动作参考的不透明颜色相对 SDB 原始八步级颜色统一高 2，各通道减 2 后，其六项本体色与 SDB 绿色待机参考完全对应。表内绿色色值采用统一编码结果。白色来源为[WhiteMummy.gif](https://images.wikia.com/metalslug/images/2/20/WhiteMummy.gif)，绿色来源为[0035.gif](https://images.wikia.com/metalslug/images/f/f2/0035.gif)；两份文件分别对应 Wiki 木乃伊条目的 Poison Bullet Mummy 与 Chariot Spitting Mummy。

两种图集分别有 2382 个像素完成三项独立颜色修订。保存后的原生矩形 29 与相同参考姿态完成全部 RGBA 像素匹配；修订前后差异限于表内三项颜色，透明度及投射物、攻击效果检查通过。完整 PNG 图集、动作排列图与本体 GIF 已重新生成。证据为 `eye_tongue_verification_r1.json`，对照图为 `previews/eye_tongue_comparison_r1.png`，初版调色板与图集副本保存在 `source/revisions/before_eye_tongue_r1/`。

素材与角色权利归原权利人所有。原始提取者署名及来源保留于本目录。

## 用户指定的行为参数

| 单位 | 普通攻击 | 绝招及其他规则 |
| --- | --- | --- |
| 白木乃伊 | 使用普通木乃伊绝招的弹球；单球伤害倍率 4/5，滚动距离倍率 3/2 | 连吐 3 球，间隔约 0.33 秒 |
| 绿木乃伊 | 一次吐出 5 只虫；虫体行为参考悬挂木乃伊；释放锚点与普通木乃伊吐气体的坐标一致 | 连吐 3 次，共 15 只虫；绝招距离倍率 2 |
| 木乃伊召唤箱 MKII | 召唤白木乃伊 | 修筑时间与原版相同；颜色采用用户确认的红褐色 |

当前参数机器可读记录见 `behavior_design.json`；正式版集成与修复依据见仓库 `docs/MUMMY_VARIANTS_2026.10.05.md` 第 37.1 节。三者已接入游戏，绿木乃伊绝招间隔为 10 tick；MKII 修筑时长与原版相同。此目录既有 GIF 记录独立本体预览，原生战斗验证截图及报告位于仓库 `verification/mummy_variants_20261005/`。

## 结构及验证结果

- 每款木乃伊保留 2 页原生坐标图集（512 × 512、256 × 256）、262 个矩形、27 个脚本与 240 个完整帧条目；召唤箱保留 256 × 256 图集、56 个矩形、32 个脚本与 52 个帧条目。
- 木乃伊本体按请求改色；弹球、原生攻击效果、透明度、图块位置及帧锚点完成针对性检查。召唤箱的门扇、箱体、损毁及碎片图块完整保留并统一配色。
- 输出原生坐标图集均为索引 PNG，实际使用调色板索引数分别为 59、16、28，符合 256 色上限。完整排列图采用 RGBA 便于检查和裁切。
- 完整帧排列图逐矩形检查画布边界。木乃伊单元格采用 160 × 112、锚点 (80, 96)，覆盖原生相对坐标范围 x = −68…70、y = −63…15，弹球及消散效果均完整容纳。
- 两份本体 GIF 完成全部编码帧解码检查。GIF 编码会合并连续相同画面；对应原生 tick 的持续时间保留，白木乃伊总时长 5900 ms，绿木乃伊总时长 6000 ms。
- 验证记录为 `artwork_verification.json`，复现入口为 `build_sprites.py`。执行方式：使用正式版包内 `windows_runtime/python.exe` 运行该脚本。
- 本轮产物限定于本美术目录与根项目进度文档；游戏核心、注册表、运行资源及个人存档保持原有状态。未执行 SHA-256 计算或哈希一致性核验。

上述集成项目已完成。当前缩略图保留原版木乃伊和木乃伊召唤箱的像素构图、裁切及显示偏移，仅应用单位配色；完整关卡与不同地形覆盖保留专项核验范围。
