### 反射

- 通过`Class.forName()`, 可以动态(runtime)创建一个`类`

```java
package com.test.demo;
/**
 * 定义person类
 */
public class Person {

}

package com.test.demo;

public class ReflectTest {
    public static void main(String[] args) throws ClassNotFoundException {

        Person p1 = new Person();
        Class cc = p1.getClass();
        System.out.println(cc);

        Class cc2 = Person.class;
        System.out.println(cc2);

        Class cc3 = Class.forName("com.test.demo.Person");
        System.out.println(cc3);

        System.out.println(cc==cc2);
        System.out.println(cc2==cc3);
    }
}

class com.test.demo.Person
class com.test.demo.Person
class com.test.demo.Person
true
true
```

Class 中有获取其他 Class 的方法，列举如下：

`Class.getSuperclass()`：获取该类的父类
`Class.getClasses()`：获取该类所有公共类、接口、枚举组成的 Class 数组，包括继承的
`Class.getDeclaredClasses()`：获取该类显式声明的所有类、接口、枚举组成的 Class 数组
`(Class/Field/Method/Constructor).getDeclaringClass()`：获取该类/属性/方法/构造函数所在的类
