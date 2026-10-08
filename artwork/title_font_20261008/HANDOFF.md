# 原生标题字体复刻：交接说明（2026-10-08）

本目录为本地双人对战任务中顺带开始的标题字体工作（VERSUS 子页面标题等）。用户评估：当前结果未达到复刻程度，后续在独立对话中作为“游戏内素材替换”项目继续。开工前阅读 `F:\egg\AGENTS.md`（文首摘要、第 1、2、9、10、12.1 节）。

## 1. 已知事实
- 原生标题图：`game_data/assets/com.snkplaymore.android003/menu.obm` 底行（导出 PNG：`F:\egg\MSD_封面素材\UI图标_20261007\完整图集\menu.png`，第 484–501 行），文字为 CUSTOMIZE LANGUAGE OPTION MENU SHOP，相邻字母轮廓相接、无间隔。
- 字形结构：18 行高（第 484、501 行为上下轮廓，485–500 为 16 行填充）；竖笔宽 5 px；填充色逐行渐变（同一行所有字母同色，取值见 `title_font.py` 的 FILL）；左侧首列明显变暗；轮廓为黑色，透明度按方向与字母变化（上下 0xff，左侧约 0xdd/0x66，右侧约 0xbb/0x96，斜角 0x52–0x96），部分曲线处另有第二圈淡轮廓。
- 原生字母只有 15 个：A C E G H I L M N O P S T U Z。TO、LA、PT 三组填充相连，按 `extract_native.py` 的 RANGES 切分。
- OBM 解码：`F:\egg\research\metal_slug_defense\windows_native\modding_feasibility_20261002\obm_tool.py` 的 `parse`（部分 OI 格式不支持，如 asc.obm、network_mars.obm）。PIL 需先 `import portable_launcher`（设置 DLL 目录）。

## 2. 现有产物与不足
- `extract_native.py`：提取 15 个原生字母的填充区域（二值）→ `native_masks.json`；部分字母混入相邻字母轮廓列。
- `title_font.py`：A–Z 位图 + 规则渲染器（`--verify` 对照原生、`--sheet` 生成图集、`"TEXT"` 生成标题）。
- 不足（用户确认未达复刻）：
  1. 原生字母未使用原生像素，而是以简化规则重绘；对照原生只有 65–85% 的填充像素误差 ≤3（`--verify`），右侧与曲线内侧暗边、逐字母的轮廓透明度、第二圈淡轮廓未还原。
  2. B D F J K Q R V W X Y 为本任务设计的新字形（W 为 M 上下翻转），非原生。
  3. 只查了 menu.obm 一行；其他图集可能存在同一字体的标题（如 RANKING、STAGE、DECK、ACHIEVEMENT、MEDAL、MISSION、ITEM / MSP / UNIT 标签等），可提供更多原生字母。

## 3. 建议路线
1. 全量搜索：解码全部 UI 类 OBM（`game_data/assets/com.snkplaymore.android003/*.obm` 与原始 APK），找出与本字体同风格（18 行高、银色逐行渐变、黑色轮廓）的所有标题与标签，整理原生字母表（含不同字号版本，如商店卡标签约 14–17 行高）。
2. 原生字母一律直接使用原生 RGBA 像素（逐字母裁切，处理相接轮廓），不重新渲染。
3. 缺失字母优先以原生笔画像素拼接（如 R = P + 斜腿、F = E 去下横、B/D 由 P/O 组合），保留原生的边缘暗化与轮廓；必要时再按原生像素统计出的“到边缘距离 → 亮度”模型补画。
4. 排字规则按原生实测（相接轮廓的重叠方式），以 CUSTOMIZE / LANGUAGE 等原生整词逐像素对照验证。
5. 产物：字体图集 PNG + 度量 JSON + 生成工具；所需标题（当前用途：VERSUS 子页面标题，商店式卡片标签 LOCAL / LAN / ONLINE）。
6. 范围扩展（用户提出“游戏内有挺多素材要替换”）：具体替换清单由用户在新对话中确定；替换进游戏需遵守 AGENTS.md 第 10 节像素素材规则（原画布、透明度、OBM 往返一致、≤256 色约束等）。

## 4. 相关但独立的规格
- 商店式图片卡（VERSUS 子页面）：卡框 112×144、褐色底板 98×130、插画 98×102（用户绘制），见 `docs/lab/local_versus_design_2026-10-06.md` 第 5.6 节。
- 出兵格素材与光标范围：`F:\egg\MSD_封面素材\出兵格_20261008\`。

## 5. R2：原生像素路线（2026-10-08，本轮）
第 2 节的规则重绘产物已移入 `superseded_r1/`（未删除），由本节产物取代。本轮仅生成预览素材，未修改游戏文件、核心、注册表、运行目录或个人存档；未计算 SHA-256，未暂存、提交或推送。

### 5.1 全量搜索
- `scan_obm.py`（obm_tool.parse）解码 917 个图集；其余 26 个为 4 位调色板与 16 位直接色，`obm_extra.py`/`decode_extra.py` 补齐，943 个全部解码（解码 PNG 置于会话临时目录，未入库）。
- 两遍搜索：`search_font.py`（竖列渐变 + 上下黑轮廓特征）与 `search_colors.py`（三种字号的原生渐变色，容差 6）。结果 `search_hits.json`、`search_colors_hits.json`。
- 同一字体共三种字号，35 个原生词（`native_font.py` 的 WORDS）：
  - 16 行填充（28 词）：menu（CUSTOMIZE LANGUAGE OPTION MENU SHOP）、login_bonus（LOGIN BONUS、PRESENT、COLLABORATION）、medal_shop（MEDAL SHOP）、menu_mission（MISSION）、pause_menu（PAUSE MENU）、prisoner_list（POW LIST）、profile（Wi-Fi VERSUS、PROFILE）、shop（SHOP、BASE、ITEMS、CUSTOMIZE）、stageselect_01（STAGE SELECT、AREA SELECT）、unit（DECK）。
  - 12 行填充（5 词，商店卡片标签）：shop（UNIT、MSP、ITEM）、icon_mov（VIDEO、AD）。
  - 8 行填充（2 词）：shop（NEXT、BACK）。
  - 另有 2on2button 的 12 行数字与小写（1on、2on2）未纳入字母表；profile 第 201 行为 Wi-Fi VERSUS 的另一版本（12 行带）未纳入。
- 原生字母：16 行 A B C D E F G H I K L M N O P R S T U V W Z 及 i、-；12 行 A D E I M N O P S T U V；8 行 A B C E K N T X。
- VERSUS 为 profile.obm 的原生整词；LOCAL、LAN、ONLINE 的全部字母在 16 行字号均为原生。

### 5.2 切分（`native_font.py extract`）
- 亮度 ≥121 的填充核心按 4 连通分量分字母（i 的点等列重叠分量合并）；填充相连的 9 处用 CUTS 指定切分列。
- 其余像素按各字母的 8 连通步数归属：暗化填充边缘归最近字母；黑色轮廓归所有步数 ≤max(2,最小值) 且距该字母自身填充 ≤1.5 px 的字母（相邻字母共用的 1 列轮廓同时存于两个字形）。
- 产物：`glyphs/<字号>/*.png`（每个原生实例一个 RGBA 字形，原生像素未改动）、`glyphs.json`（填充左右列、图集坐标、字距、相连标记）、`segmentation_<字号>.png`（左：原生像素，右：按字母着色）。

### 5.3 拼接（`composites.py`）
所有像素值取自原生字形，行号不变（逐行渐变保持）；仅黑色轮廓像素允许移行。配方与来源见 `composites.json` 的 notes。
- 16 行 Y：V 上半两臂 + T 竖笔 + T 横笔下轮廓移至接合行。
- 16 行 J：U（MENU 词尾）去左竖笔上段，钩顶写入 U 的原生上轮廓。
- 16 行 Q：O + R 右下腿第 14–19 行作尾巴。
- 16 行 X：V 上半 + K 右下腿 + 同一腿的水平镜像作左下腿。**镜像为位置变换**，左右暗边方向随之互换，待用户判断。
- 12 行 L：E 底横与左竖笔 + 小号 I 的右暗边与右外轮廓。
- 12 行 C：小号 O 右笔第 7–10 行打开，用 O 自身的内孔轮廓值收口，上收笔末行取 S 同行暗化像素。
- 方法对照（`method_check.py`）：同法以原生 E + I 拼 16 行 L，与 9 个原生 L 比较，最小差异 43/168 像素（均为边缘）；原生 L 实例彼此差异中位数 76（1–93）。
- 仍缺：12 行 B F G H J K Q R W X Y Z（VERSUS 12 行因缺 R 未生成）；8 行除 A B C E K N T X 外的字母。

### 5.4 整词对照（`native_font.py verify`，`verify_report.json`、`verify_summary.json`、`verify_<字号>.png`）
- 自重排（本词字形 + 本词字距）：35/35 词与原图逐像素一致，切分无损。
- 交叉重排（每个字母取其他词的原生实例，按上下文选取；字距取其他词统计）：16 行词差异像素约为总像素的 15–60%，集中于边缘。原因经核查为原生标题本身的边缘变体：同一字母在不同词中形状相同，暗化边缘与轮廓 alpha 不同；例如 M 有 3 种变体（CUSTOMIZE×2 一致，MENU/MEDAL/MISSION 一致）。164 个字母中 27 个在其他词有逐像素相同的实例，中位差异 88 像素。
- 最优变体上限（每个字母取其他词中差异最小的实例）：SHOP 2、BONUS 9、BASE 12、AREA 12、PAUSE 22 像素；其他词因无相同变体而保留数百像素差异。
- 字距：原生字距为 0/1/2 列且随词变化；规则（原生同字母对众数，否则 1）与 149 处原生字距中的 105 处一致。
- 8 行仅 NEXT、BACK 两词，交叉重排只能使用本词字形，0 差异不构成独立验证。

### 5.5 预览产物（待用户确认，尚未放入游戏）
- `font_atlas_{16,12,8}.png` 与 `_6x` 放大版（* 为拼接字母）；`font_metrics.json`（矩形、fl/fr、来源、全部变体、字距表）。
- `titles/`：VERSUS_16_native（原生整词像素）、VERSUS_16_typeset（对照）、LOCAL/LAN/ONLINE 的 16 行与 12 行；`titles_report.json` 记录每个字母所用实例与字距来源。
- `titles_preview_6x.png`：放大预览，红条标记拼接字母（12 行 LOCAL 的 L、C、L，LAN 的 L，ONLINE 的 L）。
- 放入游戏前待定：采用的字号（卡片标签 12 行或 16 行）、目标图集与位置、16 行 X 是否接受镜像腿。
