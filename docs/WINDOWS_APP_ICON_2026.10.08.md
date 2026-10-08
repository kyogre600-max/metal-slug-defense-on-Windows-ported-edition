# Windows 应用图标与启动入口

## 当前素材与尺寸

用户提供的两份 512×512 RGBA PNG 均保留原始文件字节。`custom_content/LOGOAPP.png` 保存第一份设计，`custom_content/LOGOAPP2.png` 保存第二份设计；当前应用图标采用第二份设计。两者的构图、颜色与透明通道保留。

`custom_content/app_icon.ico` 包含 16、20、24、30、32、36、40、48、60、64、72、80、96、128、192、256 px 的正方形 RGBA 图像。各尺寸由 512×512 源图使用 LANCZOS 等比例缩小，完整画布保留。`custom_content/app_icon_192.png` 单独保存用户要求的 192×192 规格；原版 Android APK 与既有原图参考保持。

Windows Win32 图标资源支持在同一 ICO 中存储多个尺寸，系统按显示位置和 DPI 选择资源。[Microsoft 图标规格](https://learn.microsoft.com/en-us/windows/apps/design/iconography/app-icon-construction)、[Win32 图标资源说明](https://learn.microsoft.com/en-us/windows/win32/menurc/about-icons)。

## 用户入口

| EXE 入口 | 既有 Python 入口 | 存档与运行条件 |
| --- | --- | --- |
| `MSD WINDOWS S1XLV.exe` | `portable_launcher.py` | 普通入口与原有参数转发。 |
| `Start_MSD_All_Units_Level1.exe` | `all_units_level1_launcher.py` | 全兵种 Lv1 独立存档。 |
| `Start_MSD_All_Unlocked_Max_Level.exe` | `all_unlocked_max_level_launcher.py` | 全解锁满级独立存档。 |
| `Start_LAB.exe` | `lab_launcher.py` | 独立 LAB 入口，沿用 `--windowed`。 |
| `Start_MSD_Max_Level.exe` | `max_level_launcher.py` | 仅配置已有原满级入口的本地运行目录。 |

各 EXE 以自身目录为工作目录，调用包内 `windows_runtime/pythonw.exe -B -I -S`。原 VBS 文件及其路径保持；VBS 的文件列表图标由 Windows 类型关联控制，具名 EXE 提供独立嵌入图标。[Microsoft 文件类型图标说明](https://learn.microsoft.com/en-us/windows/win32/shell/how-to-assign-a-custom-icon-to-a-file-type)。已有指向 VBS 的快捷方式仅更新 `IconLocation`，其目标、参数与工作目录保持。

`app_icon.py` 统一进程标识 `MSD.Windows.S1XLV`，在共用 `Player.run()` 创建窗口后使用 `WM_SETICON` 设置大、小图标，按窗口 DPI 选取尺寸，退出时恢复原图标并释放自有 HICON。EXE、VBS 和既有 Python 存档入口均使用该窗口路径。root 与 `src` 镜像包含相同宿主与图标资产。

## 资源重建

在项目根目录执行：

```powershell
python src/build_app_icon.py
python src/build_launchers.py
```

图标生成脚本默认使用 `LOGOAPP2.png`；以 `--source custom_content/LOGOAPP.png` 可指定保留的第一份设计。启动器构建脚本采用已有 MinGW 工具链，并只为 `--entry-root` 下存在的 Python 入口生成 EXE；`--output-dir` 可指定候选输出目录。当前统一版本为 1.47.2，更新条目为“新添加本地双人对战功能，可使用键盘/手柄进行对战（手柄操作默认XBOX360操作模式）”。

## 核验范围

PNG 与 ICO 保存重载、全部尺寸及像素核对覆盖资源生成。独立 GLFW/Win32 窗口检查覆盖 DPI、图标句柄、资源缺失与释放；独立命令记录器覆盖五种入口的实际 CreateProcess 路由、中文空格路径与参数转发。验证记录位于 `verification/app_icon_20261008/`。

本轮使用隔离核验窗口与命令记录器；游戏核心、个人存档和用户进程保持。游戏内标题 LOGO 与 LAB 图标保持原有素材。未计算 SHA-256，Git 提交与推送由用户执行。
