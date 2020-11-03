## JAVA

### Spring Boot 资源

- 代码示例: `https://github.com/JeffLi1993/springboot-learning-example`
- https://zhuanlan.zhihu.com/p/31015559 ()
- https://www.tutorialspoint.com/mybatis/mybatis_annotations.htm(SpringBoot 快速整合 Mybatis（去 XML 化+注解进阶）)
- JAVA 书籍推荐: http://tengj.top/2017/05/05/javabook/
- Spring Boot 干货汇总: http://tengj.top/2017/04/24/springboot0/

### Spring Boot 工程实战

- Profile-多环境配置
  - `java -jar xxx.jar --spring.profiles.active=dev` 就会使用`application-{profile}.properties`的配置
  - `spring.profiles.include`: 可以用来叠加 profile

### 数据库

- druid(阿里开源): 是 db 连接池管理. (一般生成 dataSource 由 spring 管理, 注入给使用方)
- mybatis: SQL Mapper.
- mysql-connector: 是 mysql 的桥接器.
