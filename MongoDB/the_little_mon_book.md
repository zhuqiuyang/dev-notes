### chap3

```sh
mkdir db

mongod --config ./mongodb.config

mongo

db
# test, 默认使用的db

show dbs
# 列出可用的db
```

* 如果`insert`的 collection 不存在, 会先进行创建
* `use <db>`, 切换 database, 不存在会创建

### schema-less

> 迁移及修改方便, `ALTER TABLE`耗时
>
> https://www.mongodb.com/blog/post/why-schemaless
