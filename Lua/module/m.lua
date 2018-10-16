local setmetatable = setmetatable

local _M = { _VERSION = '0.1' }

local x = 5
_M.x = 5

function _M.add()
  _M.x = _M.x + 1
end

local mt = { __index = _M }

function _M.new(self)
  print(self._VERSION)
  return setmetatable({}, mt)
end

return _M