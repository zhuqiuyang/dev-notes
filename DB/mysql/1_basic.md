### Basic

### 查看
- `SHOW tables`: 显示DB中的表名称
- `use database_name`: 选择使用某个数据库
- `DESC table_name`: 查看数据库中某个表的结构

### CREATE
- NOT NULL, 插入时需要赋值, 否则报错.

```sql
CREATE TABLE users(
id int NOT NULL AUTO_INCREMENT,
username varchar(30) NOT NULL,
PRIMARY KEY(id)
);
```

> 表中用于表示所属关系的Column的名字, 叫做**外键**, 通常是另一个表的主键.

### 修改表
```sql
ALTER TABLE users ADD email varchar(20)
ALTER TABLE users DROP email
DROP TABLE users
RENAME TABLE users TO superusers
```

### 修改数据
```sql
INSERT INTO users (name, email) VALUES ('peter', 'peter@peter.com')
UPDATE users SET name='happypeter' WHERE id=1;
```
删除一条数据:
```sql
DELETE FROM users WHERE id=12
```

### 导入导出
```sql
mysqldump -uroot -p111111 forum>forum.sql
mysql -uroot -p111111 forum<forum.sql
```