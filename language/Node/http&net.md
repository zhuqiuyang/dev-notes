### HTTP

#### new Agent
- `keepAlive`: 设置成true, socket连接就可以复用.
- `keepAliveMsecs`: specifies the initial delay for TCP Keep-Alive packets. 

### Net

#### socket.setKeepAlive
- Set initialDelay (in milliseconds) to set the delay between the last data packet received and the first keepalive probe. (设置idle socket, 接收到最后一个数据包和发送keepalive probe 的间隔)