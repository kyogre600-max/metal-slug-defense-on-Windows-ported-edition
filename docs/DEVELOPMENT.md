# Development

## English

`src/` contains the Windows host, native runtime support, launcher, and generated C++ translation units corresponding to this release. The original Android application, resource files, bundled dependencies, and runnable binaries are supplied in the separate Windows release package.

For host development, extract that package into a separate writable directory, copy the Python host files from `src/` into its root, and launch `MSD WINDOWS S1XLV.exe`. Use a copy of the package for experiments so that its save directory remains independent from personal progress.

The pre-generated native core can be compiled with Python 3 and MinGW-w64 GCC by running `python src/build.py`. The script currently sets the compiler path to `C:\Program Files\mingw64\bin\g++.exe`; adjust its `COMPILER` value for another installation. Its output is `src/build/msd_aot.dll`. Installing a rebuilt core also requires updating `core_runtime.json` to its filename and SHA-256 digest. This repository records the generated C++ snapshot; regenerating the translation from the Android binary requires the original translation inputs and coverage data.

The executable name remains **MSD WINDOWS S1XLV.exe**. The repository title is **metal slug defense on Windows ported edition**. Replace `custom_content/menu_screen.png` in the extracted package with a **360 × 240 PNG (3:2)** to change the menu monitor's image. Its native static transition and CRT effects remain active; the monitor does not open links.

## 中文

`src/` 包含与本次分发版本对应的 Windows 宿主、原生运行支持、启动器及生成的 C++ 翻译单元。安卓原始应用、资源、运行依赖与可执行文件由独立的 Windows 运行包提供。

修改宿主时，将运行包完整解压至独立且可写的目录，把 `src/` 中的 Python 宿主文件复制至运行包根目录，再启动 `MSD WINDOWS S1XLV.exe`。开发实验应使用独立副本，以保持测试存档与个人进度相互独立。

通过 Python 3 与 MinGW-w64 GCC，可运行 `python src/build.py` 编译已生成的原生核心。脚本当前采用 `C:\Program Files\mingw64\bin\g++.exe`，其他安装位置需调整 `COMPILER`。输出文件为 `src/build/msd_aot.dll`；部署重新编译的核心时，还需同步更新 `core_runtime.json` 中的文件名与 SHA-256。仓库保存本版本生成的 C++ 快照；从安卓二进制重新生成翻译单元还需原始翻译输入与覆盖数据。

启动程序名称继续采用 **MSD WINDOWS S1XLV.exe**，仓库名称为 **metal slug defense on Windows ported edition**。替换运行包中的 `custom_content/menu_screen.png` 可修改主菜单左侧屏幕的图像，建议采用 **360 × 240 PNG，比例 3:2**。保留原生雪花过渡与显像管效果，点击屏幕不触发链接跳转。
