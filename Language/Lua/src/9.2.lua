-- 基础版

file = io.input("a.txt")

repeat
    line = io.read()
    if nil == line then
        break
    end
    print(line)
until (false)

io.close(file)

-- 生产者/消费者

file = io.input("a.txt")

function receive (prod)
  local status, value = coroutine.resume(prod)
  return value
end

function send (x)
  coroutine.yield(x)
end

function producer ()
  return coroutine.create(function ()

    for line in file:lines() do
      send(line)
    end
    file:close()

    -- while true do
    --   local x = io.read()     -- produce new value
    --   if nil == x then
    --     io.close(file)
    --     return nil
    --   end
    --   send(x)
    -- end

  end)
end

function filter (prod)
  return coroutine.create(function ()
    local line = 1
    while true do
      local x = receive(prod)   -- get new value
      -- read end
      if x == nil then
        return nil
      end
      x = string.format("%5d %s", line, x)
      send(x)      -- send it to consumer
      line = line + 1
    end
  end)
end

function consumer (prod)
  while true do
    local x = receive(prod)   -- get new value
    if x == nil then
      print("consumer done.")
      return nil
    end
    io.write(x, "\n")          -- consume new value
  end
end

consumer(filter(producer()))