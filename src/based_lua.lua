----------------------------------------------------------
--[[
	based_lua
	based_lua.lua
	
	created 01/12/2021 @ 04:02 p.m.
	updated 01/12/2021 @ 04:06 p.m.
	
	this file is nothing but yet another based lib,
	except this one is coded entirely in Lua.
	
	it may provide different features based on version, but
	it will, at the very least, provide a function for loading
	DLLs easily (based_lua.load, all basedlibs are actually DLLs)
	it will try to load the LuaJIT variant if the code detects
	it's being ran in LuaJIT (checks if "jit" exists globally)
	
	version history:
		1.0.0: 01/12/2021 @ 04:06 pm
]]--
----------------------------------------------------------
--// Variables

local based_lua = {VERSION = "1.0.0"};

--// Functions

function based_lua.load(name)
	--[[
		Loads a specific DLL and links with it.
		(http://lua-users.org/wiki/LoadLibrary)
		
		This function will error if the library
		failed to load.
	]]--
	
	if jit then -- If we're on LuaJIT
		assert(package.loadlib("./"..name.."_jit.dll", "based_lib"), "Failed to load JIT DLL "..name)(); -- LuaJIT versions have to be compiled completely different from Lua 5.1 ones.
	else
		assert(package.loadlib("./"..name..".dll", "based_lib"), "Failed to load DLL "..name)(); -- note how we don't pcall despite package.loadlib being able to error; we just assert in case it returns nil (again, this code is meant to run in basically all lua vms, so long as they have package.loadlib)
	end;
	
	return based_lib; -- return the library, in the C code for the basedlibs, luaL_register is called with this and the library functions. yes, all functions provided are a part of the returned table. do note that globals
end;

--// End

return based_lua;
