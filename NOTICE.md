# Notices

## English

This is an unofficial port of Metal Slug Defense. The original game, branding, artwork, and other game materials retain their existing ownership and notices. Upstream runtime components retain their respective licenses; the Windows package includes those notices in `windows_runtime/licenses/`. The generated native game code derives from the original Android game library. This repository does not assign a new blanket license to those materials.

The native Vorbis decoder includes stb_vorbis 1.22 under its MIT license. Its source and license are included in `src/third_party/`, and the Windows package includes `licenses/stb_vorbis.txt`.

The deterministic sin/cos used by netplay and replays (`src/netplay.cpp`) are ported from musl libc (MIT), which derives them from fdlibm (Sun Microsystems notice). Both notices are included in `licenses/fdlibm_musl.txt`.

The Plants vs. Zombies units (`community_content/pvz_*`) use materials from the Nintendo DS version of Plants vs. Zombies, taken from The Spriters Resource: https://www.spriters-resource.com/ds_dsi/pvszds/ . Those materials retain their existing ownership.

The PVZ EVENT background music (`community_content/bgm_pvz_watery_graves.msdf`) is a Metal Slug style remix of "Watery Graves" from Plants vs. Zombies, published on Bilibili as "【NEOGEO×PVZ】后庭泳池-白天主题曲——《Watery Graves》（合金弹头风格Remix）". The composition and the remix retain their existing ownership.

The PVZ EVENT background music for the fifth area (`community_content/bgm_pvz_zombotany.msdf`) is a Metal Slug style remix of the unused Plants vs. Zombies track "Zombotany", published on Bilibili as "【NEOGEO×PVZ】废弃音乐《Zombotany》（合金弹头风格Remix）". The composition and the remix retain their existing ownership.

## 中文

本项目为《合金弹头塔防》的非官方移植。原游戏、标识、美术及其他游戏内容保留原有归属和权利说明。运行依赖继续适用各自的许可，相关说明随 Windows 运行包保存在 `windows_runtime/licenses/` 中。生成的原生游戏代码源于安卓原游戏库。本仓库未为上述内容统一指定新的许可。

原生 Vorbis 解码器包含采用 MIT 许可的 stb_vorbis 1.22。源码与许可位于 `src/third_party/`，Windows 运行包中的对应说明为 `licenses/stb_vorbis.txt`。

联机与回放使用的确定性 sin/cos（`src/netplay.cpp`）移植自 musl libc（MIT 许可），其实现源于 fdlibm（Sun Microsystems 许可说明）。两份说明见 `licenses/fdlibm_musl.txt`。

植物大战僵尸单位（`community_content/pvz_*`）使用 DS 版《植物大战僵尸》的素材，取材自 The Spriters Resource：https://www.spriters-resource.com/ds_dsi/pvszds/ 。这些素材保留原有归属。

PVZ EVENT 配乐（`community_content/bgm_pvz_watery_graves.msdf`）为《植物大战僵尸》“Watery Graves”的合金弹头风格混音，取自 Bilibili 发布的“【NEOGEO×PVZ】后庭泳池-白天主题曲——《Watery Graves》（合金弹头风格Remix）”。原曲与混音保留原有归属。

PVZ EVENT 第五大关配乐（`community_content/bgm_pvz_zombotany.msdf`）为《植物大战僵尸》未使用曲目“Zombotany”的合金弹头风格混音，取自 Bilibili 发布的“【NEOGEO×PVZ】废弃音乐《Zombotany》（合金弹头风格Remix）”。原曲与混音保留原有归属。
