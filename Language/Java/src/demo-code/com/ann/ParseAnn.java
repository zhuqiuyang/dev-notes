package com.ann;

import java.lang.reflect.Method;

public class ParseAnn {
    public static void main(String[] args) {
        // 1. 使用class 装载器

        try {
            Class c = Class.forName("com.ann.Person");
            // 2. find annotation

            boolean isExist = c.isAnnotationPresent(Description.class);

            if (isExist) {
                // 3. 拿到注解实例
                Description d = (Description)c.getAnnotation(Description.class);
                System.out.println(d.value());
            }
            Method[] ms = c.getMethods();
            for (Method m : ms) {
                boolean isMExist = m.isAnnotationPresent(Description.class);
                if (isMExist) {
                    Description d = (Description)m.getAnnotation(Description.class);
                    System.out.println(d.value());
                }
            }

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }
}