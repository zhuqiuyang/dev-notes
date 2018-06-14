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

#### Chap 7

### Chap 4: Data Modeling

#### No joins

#### Array 和 embeded Document (\*)

```sh
db.employees.insert({_id: ObjectId( "4d85c7039ab0fd70a117d735"),
  name: 'Chani',
  family: [ {relation:'mother',name: 'Chani'},
    {relation:'father',name: 'Paul'},
    {relation:'brother', name: 'Duncan'}]})
```

单个 document 限制在 16Mb

#### Chap 8

### Chap 5: When To Use Mongo

#### Flexible Schema

> 是 Mongo 的一个重要特性. (允许 collection 存储不同格式的 document)

#### Writes

`capped(有上限的) collection`可以设置 limite, 超出则 purge(清除)

#### Chap 9

### Chap 6 - Aggregating (总数, 聚合) Data

#### Aggregation Pipeline

> 聚合 pipeline 处理

```sh
> db.unicorns.aggregate([{$group:{_id:'$gender', total: {$sum:1}}}])
{ "_id" : "f", "total" : 3 }
{ "_id" : "m", "total" : 4 }
```

#### Chapter 10

### Chapter 7 - Performance and Tools

#### Indexes

> 建立索引, 提升查询速度

```sh
# 1表示升序
db.unicorns.ensureIndex({name: 1});
```

#### explain

查看 query 是否使用了 index, 使用`explain`

```sh
db.unicorns.find().explain()
```

#### replication (不讨论)

#### sharding (不讨论)

cluster

> Combining replication with sharding is the perscribed approach to achieve scaling and high availability.

#### Stats

```js
db.stats();
db.unicorns.stats();
```

#### Profiler (概要, 日志?)

#### Backups and Restore

`mongoexport` and `mongoimport` 用于导入/出 JSON or CSV

> Note that `mongoexport` and `mongoimport` cannot always represent your data. Only `mongodump` and `mongorestore` should ever be used for actual backups

####
