local setmetatable = setmetatable

local _M = { _VERSION = '0.1' }

local mt = { __index = _M }

function _M.new(self)
  print(self._VERSION)
  return setmetatable({}, mt)
end

return _M