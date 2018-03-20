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