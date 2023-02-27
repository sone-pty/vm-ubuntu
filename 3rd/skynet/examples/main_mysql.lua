local skynet = require "skynet"
local mysql = require "skynet.db.mysql"


skynet.start(function()
	local db = mysql.connect({host="127.0.0.1", port=3306, database="sone", user="puty", password="123456", max_packet_size=1024*1024, on_connect=nil})
	res = db:query("select * from message_board")

	for i, v in pairs(res) do
		print(i, " ", v.id, " ", v.text)
	end
	skynet.exit()
end)