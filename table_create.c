// ---------------------------------------------------------- //
/*
	based_lua
	table_create.c
	
	Created 26/12/2021 @ 05:22 a.m.
	Updated 26/12/2021 @ 05:34 a.m.
	
	Hello Timer
*/
/*
	Compile this library using:
	
	LuaJIT:
	gcc "table_create.c" -Ofast -s -c -fPIC
	gcc "table_create.o" -shared -Ofast -s -o "table_create_jit.dll" -lluajit
	luajit "test.lua"
	
	Lua 5.1:
	gcc "table_create.c" -Ofast -s -c -fPIC
	gcc "table_create.o" -shared -Ofast -s -o "table_create.dll" -"llua5.1"
	lua51 "test.lua"
	
	This will output a .DLL. You just drag this into your Lua
	project folder, and the based_lua.lua importer will handle
	the rest.
*/
// ---------------------------------------------------------- //
/* Includes */

#include "based_lua.h"
#include "../based_noise/noise.h"

/* Functions */

static int tcreate(lua_State *L) { /* creates a table of the specified size */
	/* the point of this function is that it's way faster to initialise a table in C than it is in Lua.
	 * pre-allocating the entries of the table prevents reallocs
	 */
	
	int num = luaL_checknumber(L, 1); // this gets the first variable used to call this function, checks if it's a number, and returns it. if the variable doesn't exist or the variable isn't the right type, this function will error in the Lua side. this variable is the number of elements to initialise the table with
	lua_createtable(L, num, 0); // this creates a table of the specified size, and puts it in the stack. the stack contains values returned by this function
	
	return 1;
};

/* Main */

int based_lib(lua_State* L) { // entry point for all based libs is "int based_lib". the Lua importer takes care of the rest
	/* Library functions */
	
	static const struct luaL_Reg lib_funcs[] = { // here go library function declarations
		{"new", tcreate},
		{NULL, NULL}
	};
	
	return bl_start(L, "based_lib", lib_funcs); // all based libs must "return" this "based_lib" string, it's used to identify them (see based_lua.lua)
};
