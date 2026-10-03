# 自有服务器联机预备接口

核验日期：2026-10-04。协议版本：1。实现入口：`online_session.py`、`room_server.py`。当前游戏宿主初始化一个断开状态的 `OnlineClient`，可由后续游戏流程调用连接、入房、输入与状态接口。该连接直接访问自有服务器，不依赖 Google Play 登录或原版十位 UID 协议。

## 1. 已实现的边界

| 能力 | 当前状态 |
| --- | --- |
| 独立 TCP/TLS 客户端与参考服务器 | 已实现；外部地址要求 TLS，回环地址可用于明文隔离测试。 |
| 认证、版本与内容核验 | 已实现；握手包含令牌、协议版本及内容指纹。 |
| 双人房间、模式和随机种子 | 已实现；支持 `coop`、`pvp` 模式字段及参与者进出消息。 |
| 社区单位身份 | 使用 uint32 `unit_id` 与稳定 `unit_key`；状态另含 uint32 实例 ID。 |
| 战斗输入 | 已登记出击、绝招、AP 升级、弹头车、暂停与恢复命令，验证帧号和递增序号。 |
| 状态消息 | 检查单位数量、身份、阵营、HP、有限坐标及 SHA-256。房间首位参与者可提交状态。 |
| 游戏内双人战斗 | 待实现；当前命令与状态消息尚未接入原生战斗执行和一致性恢复。 |

服务器当前承担握手、房间和消息转发。正式联机阶段还需要服务器战斗裁决、地图与阵容协商、随机过程同步、输入应用、状态纠偏、断线重连和匹配流程。合作与对战字段已完成协议验证，实际玩法需要分别实施。租用服务器后可继续使用本协议和稳定内容键。

## 2. 服务启动

先在游戏目录取得内容指纹：

```powershell
.\windows_runtime\python.exe content_tool.py validate
```

输出 `online_content_hash` 包含社区注册表、世界目录、战斗契约版本及实际核心 DLL 的 SHA-256。目录顺序、资源哈希或核心版本发生变化后需要重新取得指纹，并让所有参与者使用相同内容。

本机参考服务命令：

```powershell
$env:MSD_SERVER_TOKEN = '<自定义认证令牌>'
.\windows_runtime\python.exe room_server.py --host 127.0.0.1 --port 14620 --content-hash '<online_content_hash>'
```

在独立服务器上使用 Python 3 运行相同的两个模块；监听外部地址时提供证书与私钥：

```powershell
python room_server.py --host 0.0.0.0 --port 14620 --content-hash '<online_content_hash>' --certificate '<certificate.pem>' --private-key '<private_key.pem>'
```

令牌通过 `MSD_SERVER_TOKEN` 环境变量提供。客户端执行常规证书验证，自签名测试证书可通过 `ca_file` 指定信任来源。凭据与私钥不写入关卡配置或内容指纹。公网部署、证书续期、并发容量及跨网络延迟尚未验证。

## 3. 客户端调用

```python
from online_session import OnlineClient

client = OnlineClient(content_hash)
client.connect('server.example.com', 14620, token, tls=True)
client.join('author.room1', mode='coop')
client.input(120, 'deploy', unit_id=1029,
             unit_key='s1xlv.girida_o_mk2', slot=0)
messages = client.poll()
client.send({'type': 'ping'})
client.close()
```

连接与握手可以阻塞至超时，需要由后续连接流程的工作线程管理。网络线程接收的数据应先进入队列，原生对象操作由游戏所有者线程执行。`poll()` 使用有界缓冲接收消息；服务端空闲连接超时为 30 秒，可定期发送 `ping`。当前宿主默认不连接服务器，也不改变单机输入的执行路径。

协议消息采用四字节网络字节序长度及 UTF-8 JSON，单包最多 64 KiB；拒绝非有限数值和无效结构。`frame`、`sequence` 为非负 int32 范围整数，序号从 0 开始逐次增加。状态消息最多 160 个单位，实例身份以阵营和实例 ID 组合识别。

## 4. 验证

隔离回环服务器已完成两个客户端的合作和对战入房、满房拒绝、社区 ID 1029 的输入转发、状态校验及内容版本不匹配拒绝。自动测试入口为 `tests/test_content_interfaces.py`。公网连通、真实双人战斗、服务器裁决和长期运行尚待后续验证。
