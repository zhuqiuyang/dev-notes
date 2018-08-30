## api.lua

### checkups.init(config)

```lua
-- L 83: 不使用 nginx upstream, 则跳过
base.extract_servers_from_upstream(skey, cls)

-- ups_status_sync_enable: 用不到, 不需要同步到 nginx upstream block
```

### prepare_checker(config), create_checker()

- `shd_config_timer_interval`: 共享内存 config 的 `同步interval`
  - [**resty.lock 使用必读**](https://github.com/openresty/lua-resty-lock#for-cache-locks)
  - 同一时间, 只需要`一个worker`, 执行 `hc`, 更新 shd 中的`ups`即可?

### 全局唯一 timer

> https://moonbingbing.gitbooks.io/openresty-best-practices/content/ngx_lua/how_one_instance_time.html

```lua
-- 只在 worker 0 启动 hc
local ok, err = ngx.timer.at(0, heartbeat.active_checkup)
```

## dynamic.lua

### shd_config_syncer

- 功能: 只是定时 **同步** `shd.config`
- `mutex`只用于标识`此worker 同步config timer的状态`, `get_status`时调用.
- `lock`用于从`shd`获取最新的 cluster server 信息, 更新到`base.upstream`
  - [resty.lock](https://github.com/openresty/lua-resty-lock#new): 完成了`wait for lock`的过程;默认 timeout`5s`
  - `base.upstream.checkups[skey]`

```lua
-- L51:
-- 为什么纯 get 设置锁, 这样只有一个 worker 可以更新, 为了防止 shd 中的 server 信息被重写?
local lock, err = base.get_lock(base.SKEYS_KEY)

-- ckey 是 worker 级别的.
local ckey = base.CHECKUP_TIMER_KEY .. ":shd_config:" .. worker_id()

-- mutex 只是用于设定此 worker 的 timer 状态, 便于其他 API check.
local ok, err = mutex:set(ckey, 1, overtime)
```

## health_check.lua

### cluster_heartbeat()

## try.lua

- `select_peer`基于`ready_ok`
- `ready_ok`基于`try.try_cluster(skey, call_back)`
- `iterator`: 是一个 function, 可以与`for`一起使用.
  > https://www.lua.org/pil/7.1.html
- [weight rr](https://www.kancloud.cn/digest/sknginx/130030)

```lua
-- peer_cb 表示节点健康
if peer_cb(idx, srv) then
    -- 1. 上浮: current 代表真实权重, 用于做计算; 未被选取节点, 权重不断增加 !
    srv.current_weight = srv.current_weight + srv.effective_weight
    weight_sum = weight_sum + srv.effective_weight

    -- effective_weight(有效权重), 正常等于 weight, 出错时降低其权重.
    if srv.effective_weight < srv.weight then
        srv.effective_weight = srv.effective_weight + 1
    end

    -- 2. 比拼 真实权重
    if not max_weight or srv.current_weight > max_weight then
        max_weight = srv.current_weight
        best = srv
    end
end

-- 3. 下降: 选取成功, 真实权重降低!(这样所有节点的被选中机会, 会更分散)
best.current_weight = best.current_weight - weight_sum
```
