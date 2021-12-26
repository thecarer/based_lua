// ---------------------------------------------------------- //
/*
	based_lua
	based_lua.h
	
	Created 01/12/2021 @ 03:17 p.m.
	Updated 01/12/2021 @ 03:17 p.m.
	
	This file is published under the license inside LICENSE.md.
*/
/*
	Main file for based_lua Lua libraries.
	This just provides basic utility, so that I don't repeat myself.
*/
// ---------------------------------------------------------- //
/* Defines */

#pragma once

//#define LUA_JIT // define this if you wish to compile for luajit (you will need to have a pre-compiled luajit DLL, compile it yourself or expect your whole computer to crash)
#define BL_API

/* Includes */

#ifdef LUA_JIT
	#include "luajit/lua.h"
	#include "luajit/lauxlib.h"
#else
	#include "lua/lua.h"
	#include "lua/lauxlib.h"
#endif

/* Functions */

float bl_clampf(float x, float y, float z) { // Do I have to explain?
	return (x < y) ? y : ((x > z) ? z : x);
};

int bl_clampi(int x, int y, int z) { // dread
	return (x < y) ? y : ((x > z) ? z : x);
};

int bl_start(lua_State *L, const char *lib_name, const luaL_Reg *lib_funcs) { // utility function which in all honesty i wrote while i was drunk so im not sure on how useful this really is but whatever bro just stick with it, it works
	luaL_register(L, lib_name, lib_funcs);
	return 1;
};
