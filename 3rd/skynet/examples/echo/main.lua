local skynet = require "skynet"
local socket = require "skynet.socket"

skynet.start(function()
    local listenfd = socket.listen("0.0.0.0", 8888)
    socket.start(listenfd, connect)
end)

function connect(fd, addr)
    print(fd .. "connected & addr: " .. addr)
    -- 开启数据接收
    socket.start(fd)

    while true do
        local data = socket.read(fd)
        if data ~= nil then
            print(fd .. "recv data: " .. data)
            socket.write(fd, data)
        else
            print(fd .. "close")
            socket.close(fd)
        end
    end
end