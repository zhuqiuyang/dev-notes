## AOP

- AOP 是一种思想: 切面, 拦截
  - 通过`切面`来`新增逻辑`
  - 通过`代理`操作对象, 保证`Object`的纯净, 不含本身无关的逻辑
- AOP 可以新建**切面**(代理层)
  - 1. 通过`xml`配置, 实现 class 的加载(`注解`出现之前, pc 更灵活)
  - 2. (**注解**), 更易读, 但没有`配置文件方式`灵活.
- 反射, 提供了`动态`拿到`注解信息`的功能.

### Reflection (反射)

- 反射是工具, 提供了通过`实例化对象`逆流而上, 拿到其`Class`的动态功能.

## Imooc-JAVA 注解详解

> https://www.imooc.com/learn/456

### 4. 自定义注解

#### 4.4 解析注解

```java
//1、使用类加载器加载类
Class c = Class.forName("com.ann.test.Child");
//2、找到类上面的注解
boolean isExit = c.isAnnotationPersent(Description.class);
if(isExit){
  //3、拿到注解实例
  Description d = (Description)c.getAnnotation(Description.class);
  System.out.println(d.value);
}
```

- 通过`getAnnotation`拿到**注解实例**

### 5. 注解实战

1. 需求: `SQL`查询用户表

```java
// 告诉 Filter 使用的 Table
@Table("user")
public class Filter {
  // 字段名也可以用注解
  @Column("id")
  private int id;
}
```

### 6. 总结

- 作用范围`@Target`
  - package, class, field, method...
- 生命周期`@Retention`
  - src, 编译 class, runtime
