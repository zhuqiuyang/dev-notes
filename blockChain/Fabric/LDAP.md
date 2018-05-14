### LDAP 特点

* LDAP 的结构用树来表示，而不是用表格。正因为这样，就不能用 SQL 语句了
* LDAP 可以很快地得到查询结果，不过在写方面，就慢得多
* LDAP 提供了静态数据的快速查询方式
* LDAP 是一种开放 Internet 标准，LDAP 协议是跨平台的 的 Interent 协议它是基于 X.500 标准的， 与 X.500 不同，LDAP 支持 TCP/IP(即可以分布式部署)

#### 适合场景

* 数据需要从不同的地点读取，但是不需要经常更新：
  * 公司员工的电话号码簿和组织结构图
  * 公用证书和安全密匙