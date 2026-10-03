"""可独立部署的握手与双人房间参考服务。"""
import socketserver,ssl,threading,uuid,secrets,os,argparse,re,ipaddress
from online_session import encode,receive,validate_command,validate_snapshot,PROTOCOL,MODES

class RoomServer(socketserver.ThreadingTCPServer):
    allow_reuse_address=True;daemon_threads=True
    def __init__(self,address,content_hash,token,tls_context=None):
        if not token:raise ValueError('服务器认证令牌不能为空')
        self.content_hash=content_hash;self.token=token;self.tls_context=tls_context
        self.lock=threading.RLock();self.rooms={};self.peers={}
        super().__init__(address,Peer)
    def get_request(self):
        sock,address=super().get_request();sock.settimeout(30)
        if self.tls_context:
            try:sock=self.tls_context.wrap_socket(sock,server_side=True)
            except Exception:sock.close();raise
        return sock,address

class Peer(socketserver.BaseRequestHandler):
    def send(self,message):
        with self.send_lock:self.request.sendall(encode(message))
    def handle(self):
        server=self.server;self.send_lock=threading.Lock();self.room=None;self.session=str(uuid.uuid4());self.sequence=-1;self.frame=-1
        try:
            hello=receive(self.request)
            token=hello.get('token','')
            if hello.get('type')!='hello' or type(hello.get('protocol')) is not int or hello['protocol']!=PROTOCOL:raise ValueError('协议版本不兼容')
            if not isinstance(token,str) or not secrets.compare_digest(token.encode(),server.token.encode()):raise ValueError('认证失败')
            if hello.get('content_hash')!=server.content_hash:raise ValueError('客户端内容版本不一致')
            with server.lock:server.peers[self.session]=self
            self.send({'type':'welcome','protocol':PROTOCOL,'session_id':self.session,'modes':MODES})
            while True:
                message=receive(self.request);kind=message.get('type')
                if kind=='ping':self.send({'type':'pong'});continue
                with server.lock:
                    if kind=='join':
                        if self.room:raise ValueError('已加入房间')
                        key=message.get('room');mode=message.get('mode')
                        if not isinstance(key,str) or not re.fullmatch(r'[a-zA-Z0-9_.-]{1,64}',key) or mode not in MODES:raise ValueError('房间参数无效')
                        room=server.rooms.setdefault(key,{'mode':mode,'seed':secrets.randbits(32),'peers':[]})
                        if room['mode']!=mode or len(room['peers'])>=2:raise ValueError('房间模式不兼容或容量已满')
                        room['peers'].append(self);self.room=key
                        payload={'type':'room','room':key,'mode':mode,'seed':room['seed'],'participants':[p.session for p in room['peers']]}
                        for peer in room['peers']:peer.send(payload)
                    elif kind=='input':
                        if not self.room:raise ValueError('输入需要已加入房间')
                        validate_command(message)
                        if message['sequence']!=self.sequence+1 or message['frame']<self.frame:raise ValueError('输入序号或帧号不连续')
                        self.sequence=message['sequence'];self.frame=message['frame']
                        payload=dict(message,session_id=self.session)
                        for peer in server.rooms[self.room]['peers']:peer.send(payload)
                    elif kind=='snapshot':
                        if not self.room or server.rooms[self.room]['peers'][0] is not self:raise ValueError('房间状态仅由主持客户端提交')
                        digest=validate_snapshot(message)
                        if message.get('state_hash')!=digest:raise ValueError('状态校验值不一致')
                        for peer in server.rooms[self.room]['peers']:peer.send(dict(message,session_id=self.session))
                    elif kind=='leave':break
                    else:raise ValueError('未知服务器消息')
        except (EOFError,ConnectionError,TimeoutError):pass
        except (ValueError,KeyError,TypeError) as error:
            try:self.send({'type':'rejected','reason':str(error)})
            except OSError:pass
        finally:
            with server.lock:
                server.peers.pop(self.session,None)
                room=server.rooms.get(self.room)
                if room and self in room['peers']:
                    room['peers'].remove(self)
                    for peer in room['peers']:
                        try:peer.send({'type':'participant_left','session_id':self.session})
                        except OSError:pass
                    if not room['peers']:server.rooms.pop(self.room,None)

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--host',default='127.0.0.1');parser.add_argument('--port',type=int,default=14620)
    parser.add_argument('--content-hash',required=True);parser.add_argument('--certificate');parser.add_argument('--private-key')
    args=parser.parse_args();context=None
    if args.certificate and args.private_key:
        context=ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER);context.minimum_version=ssl.TLSVersion.TLSv1_2
        context.load_cert_chain(args.certificate,args.private_key)
    if not context and not ipaddress.ip_address(args.host).is_loopback:raise ValueError('对外监听要求 TLS 证书与私钥')
    with RoomServer((args.host,args.port),args.content_hash,os.environ.get('MSD_SERVER_TOKEN',''),context) as server:server.serve_forever()
if __name__=='__main__':main()
