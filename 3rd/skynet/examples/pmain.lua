local skynet = require "skynet"

skynet.start(function()
    skynet.error("Pmain start")

    local p1 = skynet.newservice("ping")
    local p2 = skynet.newservice("ping")

    skynet.send(p1, "lua", "start", p2)
    skynet.exit()
end)