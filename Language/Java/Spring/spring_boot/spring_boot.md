> https://content.pivotal.io/springone-platform-2017/from-zero-to-hero-with-spring-boot-brian-clozel

- spring-initializr: https://start.spring.io/

### 2

#### 2.4 Reactive Libraries

> https://www.imooc.com/video/16353

Reactive Flux 或者 Mono 是**异步**处理:

- Web Flux (0..N) (集合基本上是同步处理)
- Mono (0..1) 类似 `Optinal`, `非阻塞`
- `flux/Mono`都是`publisher`

- `@Configuration` 是 `spring 3` 以后提供出来的, 用于替代 JAVA 的 XML 配置

##### 回顾 Servlet

- 请求接口: ServletRequest 或者 HttpServletRequest
- 响应接口: ServletResponse 或者 HttpServletResponse

`Spring 5` 重新定了服务端的请求和响应接口:

- 请求接口: ServerRequest
- 响应接口: ServerResponse
- 既可支持 Servlet 规范, 也可支持自定义规范, 比如 Netty Web Server
