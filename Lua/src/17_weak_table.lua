local results = {
  a = 1,
  b = 2,
  c = 3,
}
setmetatable(results, {__mode = "v"})

collectgarbage()

results.d = 4

-- os.execute("sleep " .. 50)

collectgarbage()
for k, v in pairs(results) do print(v) end