### 2-2 创建项目和依赖

> https://www.imooc.com/video/11704

1. 创建 maven webapp project

```sh
# https://maven.apache.org/archetypes/maven-archetype-webapp/
mvn archetype:generate -DgroupId=org.seckill -DartifactId=seckill -DarchetypeArtifatId=maven-archetype-webapp
```

2. IDEA import project

- 修改`servlet`版本

> 本地JAVA PATH: /Library/Java/JavaVirtualMachines/jdk1.8.0_77.jdk/Contents/Home