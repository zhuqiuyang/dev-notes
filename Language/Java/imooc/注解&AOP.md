## AOP

- AOP 是一种思想: 切面, 拦截
  - 通过`切面`来`新增逻辑`
  - 通过`代理`操作对象, 保证`Object`的纯净, 不含本身无关的逻辑
- AOP 通过 `Annotation`(**注解**) 来实现
  - 通过`注解配置`, 可以新建**切面**(代理层)
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
