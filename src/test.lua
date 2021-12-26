
--[[
	Hello Timer
	
	this is an example Lua script that uses the table_create library
	to use this, you must first compile table_create.c into a DLL (read the file for more info)
	based_lua.lua will load the DLL and allow you to use it
	
	something i should've noted before is that based_lua.lua supports using multiple
	libraries at the same time (it may not look like it because of how it returns but it does support it)
	
	this example benchmarks using table_create vs doing it in pure lua
	the difference both in LuaJIT and Lua 5.1 is pretty dramatic
	i have not tested with Lua 5.4 or Luau because i fear the VMs may not be compatible with this
	you are free to test with those
]]--

--// libraries

local bl = require("based_lua");
local tc = bl.load("table_create");

--// ☻

local clock		= os.clock; -- ☻
local trealloc	= table.insert; -- ☻

--// variables

local iters = 1e5;	-- benchmark iterations
local size  = 2048;	-- size of each table

--// benchmark

local start = clock();

for i = 1, iters, 1 do
	local t = {};
	
	for x = 1, size, 1 do
		trealloc(t, nil);
	end;
end;

print("naïve", clock() - start, "seconds");
start = clock();

for i = 1, iters, 1 do
	local t = tc.new(size);
end;

print("tcreate", clock() - start, "seconds");
