# based_lua
based_lua is a basedlib (check out https://github.com/thecarer/basedlibs) that is so fucking large ive decided to make into a whole different repo. this basedlib basically provides a simple Lua interface to the C99 basedlibs.

# Support
based_lua supports both Lua 5.1 and LuaJIT. Lua 5.4 is not currently supported, however, it is planned to be. Soon™.
as for the actual code, based_lua is mostly written in C99, just like the rest of basedlibs. for more information on that, check out GRINDSET.txt in the basedlibs repo.
based_lua also contains a Lua to C interface, which is really just a script with 1 function that makes it easy to load libraries. penis penis penis penis penis.

# Compiling
Because of how Lua libraries work, you must first compile the libraries. instructions on how to do this are provided everywhere, hell, they even are included on a per-file basis. however, if you're so lazy to the point that the phrase "couch potato" isn't fitting because they actually get off the couch to pee, then here's a short explanation:

1. find whatever library you wanna compile
2. start the overwhelmingly complex and hard to achieve devious task of reading the actual code
3. locate the "Compile this library using:" section
4. read it all
5. i said read it all
6. now you know how to compile that library
7. ☻

Note that you must provide a lua and luajit folder, aswell as their .DLLs.
Do NOT use a pre-compiled luajit DLL, I warn you, your computer may completely crash. I am not kidding.

# Using
As mentioned earlier, based_lua contains a simple Lua to C interface. using this interface, loading based_lua modules is easy.
Here is an example that uses based_lua (the Lua to C interface), based_noise, and based_image. this example will create a noise image and store it in disk as a .BMP
```lua
--// load libraries

local bl = require("based_lua");
local bn = bl.load("based_noise");
local bi = bl.load("based_image");

--// "defines"

local RES  = 512;
local ZOOM = 1 / 8;
local RESZ = RES * ZOOM;

--// create image

local image = bi.create(BI_BMP, RES,RES); -- create image

for y = 1, RES, 1 do
	for x = 1, RES, 1 do
		local c = bn.noise2u(x / RESZ, y / RESZ); -- 2D unsigned (0 - 1) noise
		bi.pixel(image, x,y, c,c,c);
	end;
end;

bi.write(image, "noise.bmp"); -- write it to disk
```

# Safety
Since based_lua is nothing more than a large basedlib, it will follow the grindset (so it will tend to avoid checks that should never fail unless you're being an idiot). If you ever, for whatever cursed reason wanna allow third parties you can't trust (users, for example) to use this library, I suggest you either sandbox the hell out of it or just make a wrapper that doesn't allow for any malicious use (this is hard to do because based_image literally allows you to write files to disk so lol).

Otherwise, if you're worried about safety of your own code, then you truly aren't following the sigma grindset and chad points will be deducted from your account. stay sigma kings 💪💪💪💪💪💪💪

# Support for more languages
Cry about it on the basedlibs repo, but not here. This is for Lua only (read the title)

# License
Go read basedlibs. The same legal bullshit applies here.
