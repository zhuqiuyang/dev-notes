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

#### chap 6

### chap 3 - Master Find

#### Field Selection

```sh
> db.unicorns.find({}, {name: 1, _id: 0})
{ "name" : "Horny" }
{ "name" : "Aurora" }
{ "name" : "Unicrom" }
{ "name" : "Roooooodles" }
{ "name" : "Solnara" }
{ "name" : "Ayna" }
{ "name" : "Kenny" }
```

#### Sorting

> find 返回 cursor, 真正需要才会执行( **Lazy** )
> `db.unicorns.find().sort({weight: -1})`: `-1`降序 (最大在 first)

#### Paging

```sh
# 跳过第一条, 依次查2条
> db.unicorns.find({}, {name: 1, _id: 0}).sort({weight: -1}).limit(2).skip(1)
{ "name" : "Ayna" }
{ "name" : "Kenny" }
```

* limit: 限制查询数量
* skip: 略过前几条

#### Count (计数)
```sh
> db.unicorns.count({vampires: {$gt: 50}})
4
```
