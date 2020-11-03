package com.imooc.test;

import sun.tools.jconsole.Tab;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Test {

    public static void main(String[] args) {
        Filter f1 = new Filter();
        f1.setId(10);

        Filter f2 = new Filter();
        f2.setUserName("lucy");

        Filter f3 = new Filter();
        f3.setEmail("ace@qq.com");

        String sql1 = query(f1);
        String sql2 = query(f2);
        String sql3 = query(f3);

        System.out.println(sql1);
        System.out.println(sql2);
        System.out.println(sql3);
    }

    public static String query(Filter f) {
        StringBuilder sb = new StringBuilder();
        // 1. 获取到class
        // pc: Class c = Filter.class;
        Class c = f.getClass();

        // 2. 获取到Filter Class 上传给注解的参数: table 的名字
        boolean exists = c.isAnnotationPresent(Table.class);
        if (!exists) {
            return null;
        }
        Table t = (Table)c.getAnnotation(Table.class);
        String tableName = t.value();
        sb.append("select * from ")
                .append(tableName)
                .append(" where 1=1");

        // 3. 遍历所有的字段
        Field[] fArray = c.getDeclaredFields();
        for (Field field : fArray) {
            // 4. 增加查询条件
            boolean fExist = field.isAnnotationPresent(Column.class);
            if (!fExist) continue;

            // 4.1 拿到field 上的注解
            Column column = (Column)field.getAnnotation(Column.class);
            String columnName = column.value();

            // 4.2 拿到字段的值
            String fieldName = field.getName();
            String getMethodName = "get" + fieldName.substring(0,1).toUpperCase() + fieldName.substring(1);
            Object fieldValue = null;
            try {
                Method getMethod = c.getMethod(getMethodName);
                fieldValue = getMethod.invoke(f);
            } catch (NoSuchMethodException e) {
                e.printStackTrace();
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (InvocationTargetException e) {
                e.printStackTrace();
            }
            // 4.3 拼装SQL
            if (fieldValue == null || (fieldValue instanceof Integer && (Integer)fieldValue == 0)) continue;
            if (fieldValue instanceof String) {
                fieldValue = String.format("'%s'", fieldValue);
            }
            sb.append(" and ")
                    .append(fieldName)
                    .append("=")
                    .append(fieldValue);
        }
        return sb.toString();
    }
}
