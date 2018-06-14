### 背景

- 充分发挥 SSD 性能

### 特点:

- K/V 数据库
- `Key`单条数据的 Key, Hash 会存盘.
- `Primay index`主索引一定放在内存里, `64byte`
  - 重启需要 2-3hour, 遍历 SSD, 重建索引.

> CAP 定理(Consistence, Available, Partition tolerance), 三者不可能同时满足

- AeroSpike 是 `AP` 模型
- 节点迁移, 不需要人工干预.

Smart Client:

- 自动感知, 网络节点变化
- 高性能 TCP 连接池(Good)
