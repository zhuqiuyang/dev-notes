### Getting started with InfluxDB

> https://docs.influxdata.com/
>
> https://docs.influxdata.com/influxdb/v1.5/introduction/getting-started/

* `measurement` as an SQL `table`, where the `primary index` is always time.
* `tags` and `fields` are effectively columns in the table. tags are indexed, and fields are not.
* `tags` 一般用于做查询, 用于筛选条件(indexed)

```sh
influxd

influx -precision rfc3339

> CREATE DATABASE mydb

> SHOW DATABASES

> USE mydb

> INSERT cpu,host=serverA,region=us_west value=0.64

> SELECT "host", "region", "value" FROM "cpu"

> INSERT temperature,machine=unit42,type=assembly external=25,internal=37
>

> SELECT * FROM "temperature"
```
