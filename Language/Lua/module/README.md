### : 测试

```lua
local module = require('m')

-- :new 默认使用的self, 其实是 module 自身(即其内部的_M)
module:new()
```
