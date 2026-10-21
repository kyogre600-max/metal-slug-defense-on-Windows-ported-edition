# IRON SENTINEL（钢铁哨兵）复刻调研

2026-10-20。范围：用户提供《合金弹头6》（MS6）与《Metal Slug Attack》（MSA）中 Iron Sentinel 的素材表，要求检索 YouTube 上该单位的运作方式，作为复刻依据。本文记录调研结果；用户要求以 MSA 为主要依据，MS6 首领战作为补充。同日用户对第 5.1 节作出决定，单位已制作加入本体，决定、实现与验证见 `docs/IRON_SENTINEL_2026-10-20.md`（第 5 节保留调研时的待决定事项与初步方向，其中屏障不做、近战按第二形态巨型导弹换算、未使用 op22 弹体等以该文档为准）。

## 1. 资料来源

### 1.1 素材表

| 文件 | 规格 | 来源标注 | 工作区副本 |
| --- | --- | --- | --- |
| `F:\egg\MS6\Mobile - Metal Slug Attack - Units_ Rebel Army - Iron Sentinel.png` | PNG 3698×2717，RGBA，alpha 只有 0 / 255，1158 色 | “METAL SLUG ATTACK - IRON SENTINEL / CREDIT TO MIDIAN-P FOR SPRITE RIP / CREDIT TO DIVISION 六 FOR PLACEMENT REFERENCE / ARRANGED BY PATCHWORKS” | `artwork/iron_sentinel_20261020/source/MSA_Iron_Sentinel.png` |
| `F:\egg\MS6\Arcade - Metal Slug 6 - Enemies & Bosses - Iron Sentinel.png` | PNG 1803×3450，RGBA，alpha 只有 0 / 255，193 色 | “RIPPED BY DIVISION 6 / 6TH-DIVISIONS-DEN.COM” | `artwork/iron_sentinel_20261020/source/MS6_Iron_Sentinel.png` |

- 对话中上传的两张图为上述 PNG 的有损 WebP 缩小版（MSA 1500×1102，约 ×0.41；MS6 1045×2000，约 ×0.58；边缘有半透明像素，颜色约 16 万种），不作制作素材。
- 比例：MSA 第一形态整车帧 360×258–265，MS6 素材表中 REFERENCES 整车宽约 362，两者为 1:1（与 IRON CAB、巨型 Hunter Walker 的核对结果一致，第 169 节）。
- 倾斜：两份素材的车体均按下坡方向斜置。以车身红色条带拟合直线，MSA 车体 BODY 与第一形态帧约 20.3°，第一形态第 2 行约 21.3°，第二形态帧约 21.5°（右端较低）。MSA Wiki 记载 MSA 在运行时把图像旋转成水平。

### 1.2 录像（内置浏览器静音截帧，未下载、未保存音频）

| 录像 | 用途 | 截帧 |
| --- | --- | --- |
| Lindermann「Metal Slug Attack : All Rebel Army Units (Action and description)」https://www.youtube.com/watch?v=2Jss8QCG2dA ，Iron Sentinel 段 7:40–8:02 | MSA 单位动作浏览器：信息页、Neutral、Long Range Attack、Special Attack（只演示第一形态）；720p | `verification/iron_sentinel_20261020/video_frames/msa_viewer_*` |
| Eliox「Metal Slug Attack \| Iron Sentinel VS Bosses」https://www.youtube.com/watch?v=fdcqqIWDZzk ，6:00–6:15、7:15–7:54 | 1 对 1 实战：第一形态攻击、形态转换、第二形态巨型导弹；720p | `msa_vs_*` |
| Jithra Rufure「Metal Slug Attack- Iron Sentinel Four/4* Second Form」https://www.youtube.com/watch?v=jnfl7klQAx4 ，0:28–1:08 | 多单位实战，出场与远程攻击的落弹 | `msa_4star_*` |
| crazyghostchannel「Metal Slug 6 (PSP) - All Bosses」https://www.youtube.com/watch?v=ESNuIgO5t3Q ，2:13–3:48 | MS6 首领战（PSP 版） | `ms6_psp_*` |

辅助查看过的录像（画面中大型单位重叠，未作为依据）：https://www.youtube.com/watch?v=nhWQG_aXC8g 。

### 1.3 文字资料

- Metal Slug Wiki「Iron Sentinel」https://metalslug.fandom.com/wiki/Iron_Sentinel （MS6 第 2 关首领的攻击描述）。
- Metal Slug Attack Wiki「Iron Sentinel」https://snk-msa.fandom.com/wiki/Iron_Sentinel 、「Iron Vermilion」https://snk-msa.fandom.com/wiki/Iron_Vermilion （MSA 数值、技能与改版记录）。

## 2. 素材表分区

### 2.1 MSA 素材表（坐标为原始 PNG 像素；格子以洋红边框分隔，背景绿色）

| 区块 | 位置与格子 | 内容 | 对应动作 |
| --- | --- | --- | --- |
| BODY | y≈86–240，279×152 ×2、237×152 等 | 车体（无武器）、车底板、小零件 | 合成用部件 |
| TREADS | x≈1556–2580，y≈45–240，160×92 ×6、168×94 ×6 | 前后两组履带，各 6 帧 | 行走 |
| DESTROYED | x≈2589–3370，y≈16–240 | 损毁车体 | 死亡 |
| UNIT ICON | x 3380，48×48 | 出兵栏头像 | 头像 |
| FIRST FORM (PARTIAL ASSEMBLY) | y≈257–990；279×198 ×4、279×155 ×2、200×99 ×2，整车 360×258 ×6、360×265 ×6 | 车体 + 履带，以及车体 + 主炮的整车帧（各 6 帧，履带滚动） | 第一形态行走 / 待机 |
| ASSEMBLY GUIDE | x≈2345–3060，y≈705–1500；整车 388×214、387×213 等 | 合成参考：完整第一形态；侧面舱口全开、导弹竖起并标出侧炮 1（蓝）2（红）位置的参考；整体偏红的整车（推测为受击闪色参考，未核实） | 合成坐标 |
| MAIN CANNON | x≈2350–3700，y≈1400–1660 | 主炮 2 帧待机 + 8 帧射击后坐；炮弹 2 帧；带尾焰的大型导弹 14 帧 | 绝招：主炮连射 |
| MISSILE LAUNCHERS | x≈2350–3400，y≈1630–1850 | 侧面红黑舱口开启、小火箭自舱内升起（18 格 ×2 行）；小火箭飞行帧 18 帧；圆顶小炮塔转动帧；小橙色弹 | 远程攻击 |
| SIDE CANNONS | x≈2347–3540，y≈1851–2186，蓝框组 1、红框组 2，各 2 行约 24 帧 | 侧面红 X 方箱翻开，变为双管炮并射击 | 绝招：侧炮抛射 |
| SECOND FORM (PARTIAL ASSEMBLY) | y≈1007–2190；289×204、289×182、360×264 ×6、360×242 ×6 | 去掉主炮后的车体，发射臂折叠 / 抬起的各阶段 | 第二形态行走 / 攻击 |
| FORM CHANGE | y≈2200–2290 | 主炮炸飞碎块 3 帧、顶板与平板碎片、发射臂部件 | 形态转换 |
| ROCKET SILO | y≈2295–2717 | 发射臂抬起 8 帧；巨型导弹由平放转为竖直约 20 帧；点火与尾焰；导弹竖直帧；导弹解体；火柱大爆炸序列；烟柱；地面残骸与烟尘 | 第二形态：巨型导弹 |

素材表右上另有两艘蓝色飞行战舰与一个粉色小型飞行器（x≈2800–3698，y≈705–1135），不属于 Iron Sentinel，来源未识别，不纳入本单位。

### 2.2 MS6 素材表（Division 6 提取）

区块标签依次为 CANNON（主炮与炮弹）、BODY PARTS、EXHAUST FUMES（排气烟）、TURRETS（侧面舱口与圆顶炮塔、瞄准框）、ROCKETS（小火箭）、SECOND PHASE（裂纹闪光、发射臂抬起）、GIANT MISSILE（发射臂、火花循环、巨型导弹转动、尾焰）、烟尘与爆炸序列、DESTROYED、CRASHED、REFERENCES（整车参考）。橙色单帧（主炮、发射架）为受击闪色。MSA 素材的部件与 MS6 一一对应，MSA 增加了侧炮（SIDE CANNONS）与形态转换碎片等帧。

## 3. MSA 中的运作方式

### 3.1 信息与数值

- 动作浏览器信息页（2Jss8QCG2dA 7:42，`msa_viewer_..._7m42_stats_lv50.png`）：Lv50、4 星，AP 720，HP 872428；Attack Damage：Near 17599、Far 7207、Special 86881。动作菜单为 Neutral、Close Range Attack（灰色，无此动作）、Long Range Attack、Special Attack。
- 说明文字：“This ultra-giant size missile tank was created in cooperation with Mars People. Gen. Morden himself is aboard. Has a high-performance barrier based on Mars' latest technology.”
- MSA Wiki（全部道具与技能计入，与录像信息页的版本不同，仅作比例参考）：AP 900 / 810 / 720（随星级），最佳距离 Long；远程攻击距离 680、绝招距离 680，移动 4.85；技能为全攻击力 +20%、生命 +20%、常驻屏障（三种属性的伤害 −15% 起，Wiki 以图标表示属性）、FORM CHANGE（被击败一次后以最大生命 20%（每级 +1.6%）复活为第二形态，第二形态不受硬直）。改版：2.13.0、3.9.0 增强；4.11.0 以屏障替换暴击技能，第二形态免疫硬直，大型导弹改为贯穿弹（不被护盾抵消）。
- 量产型 Iron Vermilion（MSA 2.4.0）：远程为主炮 5 枚中型导弹，绝招为侧面 10 枚（技能后 20/21 枚）追踪小导弹，无第二形态。用户素材表中无该单位的专用帧。

### 3.2 朝向、出场与移动

- 朝右行进：车头（红圈 X 标志）在右，主炮炮管朝右上（fdcqqIWDZzk 6:09–6:13）。自本方据点一侧进入画面，前进到射程后停下攻击（jnfl7klQAx4 0:28–0:29、fdcqqIWDZzk 7:16）。画面中 MSA 已把车体旋转成水平。
- 体积：1280×720 录像中车体约占画面宽度的 1/3。

### 3.3 Neutral

整车静置，履带与车体无明显动作（2Jss8QCG2dA 7:45.0–7:46.5）。

### 3.4 远程攻击（Long Range Attack）

- 动作浏览器（7:47.4–7:53，`msa_viewer_..._long_*`、`..._long_hatch_*`）：主炮不动作。车身红色条带上的侧面舱口逐个打开（开口处有橙色闪光），小火箭自舱内竖直升起，略向前倾，经过炮塔旁飞出画面上方；各次发射来自不同舱口，间隔约 0.3–0.6 秒，演示中循环播放，单轮枚数未能确定。
- 实战（fdcqqIWDZzk 6:09–6:13；jnfl7klQAx4 0:30.5–0:32.5）：小火箭升空后落到前方敌人附近，地面连续出现多处小爆炸，即 Wiki 所称 “Missile (Spread)”。与 IRON CAB 的导弹（升空后竖直落下，第 169 节）属同一类轨迹。

### 3.5 绝招（Special Attack）

- 动作浏览器（7:54.4 选中，7:54.8–约 7:58.5，约 3.6–4 秒，`msa_viewer_..._special_*`）：
  - 主炮带炮口闪光与后坐连续发射带尾焰的大型导弹，水平飞向右方，间隔约 0.4 秒，约 8 发。
  - 车身后部侧炮同时向右上方抛射橙色炮弹，形成弧线弹道。
  - 射程端出现爆炸（7:57.6、7:58.4）。
- 实战（fdcqqIWDZzk 7:24.6–7:26.6）：主炮闪光、大型导弹高空飞行、橙色炮弹与小导弹落在敌人身上与地面，伤害数字约 6600–10000 一组。Wiki 描述为 “Big Missile (Spread) — 主炮发射较大导弹，侧面投下炸弹”。

### 3.6 受击与屏障

- 受击时整车短暂变为橙红色（fdcqqIWDZzk 7:24、7:44.9、7:48.2 等，敌方首领受击时同样）。
- 受击时车体上出现蓝白色电光（fdcqqIWDZzk 7:28–7:33；jnfl7klQAx4 0:35、0:58.6），推测为 4.11.0 加入的屏障效果；素材表中未找到对应帧，未核实。

### 3.7 形态转换（FORM CHANGE）

fdcqqIWDZzk 7:43.5–7:48.2（`msa_vs_..._form_change.png`）：

1. 7:45.0：第一形态生命归零，车体被白色烟团覆盖。
2. 7:45.3–7:45.6：车体各处连续爆炸。
3. 7:45.9：主炮消失，车体以第二形态（顶部为折叠的发射臂）继续存在，位置不变。
4. 7:46.5–7:47.1：顶部再次爆炸，发射臂带着巨型导弹从约 45° 抬起。
5. 7:47.4：巨型导弹竖直，进入第二形态攻击。

### 3.8 第二形态攻击（巨型导弹）

fdcqqIWDZzk 7:47.4–7:53.4（`msa_vs_..._giant_missile.png`），周期约 5–6 秒：

1. 7:48.4：导弹竖立在发射臂上，底部点火。
2. 7:48.8：导弹向上飞出画面，发射臂保持竖直。
3. 7:49.6–7:50.8：导弹自画面上方头朝下竖直落到敌人前方。
4. 7:51.2–7:51.6：落地后爆炸为约 6 道并列火柱，宽约 400 像素（1280 宽录像，约为画面的 1/3）。
5. 7:52.0：火柱转为烟团。
6. 7:52.4：发射臂放下；7:53.4 下一枚导弹竖立。

第二形态在被击败前未观察到其他攻击方式；第二形态的被击败过程不在所截片段中。

## 4. MS6 首领战（补充）

- Wiki：弱点为顶部大炮；攻击为大炮发射 3 枚中型火箭落地（Easy 模式无此攻击）、侧面炮塔的弧线弹、侧面小导弹向多个方向飞出；大炮被毁后露出巨型火箭发射架，发射时溅出可被击落的火花，巨型火箭飞出画面后落下造成大爆炸，有时掉落 HMG 等道具；起火后发射加快；受到足够伤害后撞上山坡。
- PSP 录像（ESNuIgO5t3Q）：2:34 自玩家身后（画面左侧）撞断树木冲出，此后车体沿下坡与画面同步下滑；2:40–2:48 小导弹水平飞过、主炮开火；2:49–2:56 主炮区域连续爆炸后被毁，露出暗褐色发射架；3:01–3:08 巨型导弹竖直升空、自上方落到车前地面、左下方出现大片火柱；之后循环；3:36–3:39 车体起火解体，撞入山坡。

MS6 版为卷轴下坡战，素材的斜置角度来源于此；MSA 将其改为水平的据点战单位，玩法上以 MSA 为准。

## 5. 复刻要点与待决定事项

以下为依据现有单位做法整理的方案要点，尚未实施或验证。

### 5.1 待用户决定

1. **尺寸**：1:1 时整车约 360×260 精灵像素（斜置），水平化后长约 360 精灵像素，约合 720 世界单位。IRON CAB 实测标准战场地面以上只有约 140 精灵像素在上方 HUD 之下可见（第 169 节，用户最终选择 1:1）；Iron Sentinel 1:1 时主炮与竖起的巨型导弹（导弹格高 162）将部分位于 HUD 之下。可选：沿用 1:1；或整体缩小（IRON CAB R1 的缩小在游戏中显得模糊，已被用户否决）。
2. **倾斜**：素材斜置约 20–21.5°。可选：离线把合成后的每帧旋转为水平（需采用适合像素画的旋转方法并吸附回素材色板，部件须先合成再旋转，避免各部件分别取整而错位）；或保持斜置原样。
3. **第二形态**：是否实现 FORM CHANGE（第一形态被击败后以 20% 生命变为巨型导弹形态）。
4. **屏障**：MSA 的属性减伤在本作的对应方式（舍去，或折算进生命）。
5. **数值**：按 IRON CAB 的做法由代理起草、用户确认（参考值见第 3.1 节；MSA 的 Far 与 Special 之比约 1:12）。

### 5.2 实现方向（待核实）

- 动作类：沿用 IRON CAB 的基准僵尸（青年）UnitID 313。远程攻击的小火箭使用与 IRON CAB 导弹相同的 op22 弹体（升空、横移、竖直落下），落点按射程内分散。
- 绝招：主炮水平导弹与侧炮弧线弹同在绝招槽中发射；弧线弹的轨迹能否由现有弹体参数表达，需查看现有抛射类单位的脚本后确定。
- 第二形态：行为库 `hp_stage_animations`（适用基准 313）可按生命比例换档并经状态 80 播放过渡动作（槽 12+16k），第 1 档使用槽 原生槽号+16。若第二形态生命为第一形态的 20%，换档比例为总生命的 1/6；`stage_knockback_animation` 可避免击退时重播过渡。第二形态免疫硬直在现有行为库中没有按档位生效的参数（`no_knockback` 作用于整个单位，且不能与 `stage_knockback_animation` 同用），可能需要在 C++ 行为库新增参数（项目规则：特殊行为只由 C++ 行为库实现）。
- 巨型导弹：升空后落在目标上方、竖直落下，命中后播放 ROCKET SILO 的火柱爆炸，范围伤害目标数取大值（IRON CAB 激光为 99）。
- 音效：MS6 第 2 关音效库有 `SE_BS2_MISSILE`（2.66 秒）与 `SE_BS2_CONFLICT`（2.95 秒），按名称推测分别用于巨型导弹与撞击，尚未与录像比对。

## 6. 未覆盖事项

- MSA 远程攻击单轮的火箭枚数、绝招主炮的确切发数与各段伤害分配。
- MSA 的移动速度、出击冷却、第二形态被击败的动作。
- 蓝白电光效果与屏障的对应关系；ASSEMBLY GUIDE 中偏红整车的用途。
- MSA 实际音效（未做频谱比对）。
- 录像为 720p 有损压缩，动作时长按 0.1–0.4 秒截帧估计。
