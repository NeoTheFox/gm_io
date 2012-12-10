#gm_io.dll

A Garry's Mod module that allows further file access.


##Enums
* __io__.POSITION_END = 0x01
* __io__.POSITION_CURRENT = 0x02
* __io__.POSITION_BEGINNING = 0x04

##Functions
* __io__.open(string path, string mode)
  * File modes include: "r", "w", "a", "r+", "w+", "a+".
  * _returns_ fileObject on success, or nil on failure.
* __io__.copy(string from, string to)
  * Copys a file to another path. 
  * _returns_ true on success, or false on failure.
* __io__.move(string from, string to)
  * Moves a file to another path.
  * _returns_ true on success, or false on failure.
* __io__.exists(string path)
  * returns true if the file exists, and false if not.
* __io__.remove(string from, string to)
  * Removes a file. 
  * _returns_ true on success, or false on failure.
* __io__.rename(string from, string to)
  * Renames a file.
  * _returns_ true on success, or false on failure.

##File Object
* __fileObject__:close()
  * Closes fileObject.
  * _returns_ nil.
* __fileObject__:size()
  * _returns_ file size.
* __fileObject__:tell()
  * _returns_ position of the file pointer.
* __fileObject__:seek(int position)
  * Sets position of the file pointer.
  * _returns_ true on success, or false on failure.
* __fileObject__:read([int length])
  * _returns_ file data on success, or an empty string on failure.
* __fileObject__:write([int  lenght])
  * _returns_ true on success, or nil on failure.

##Examples

###Read/Write
```lua
local out = io.open("lua/test.lua", "w")
out:write("test":rep(50))
out:close()

local in = io.open("lua/test.lua", "r")
print(in:read())
in:close()
```

###Fetching file size using seek+tell
```lua
function size(path)
  local size = 0
  local object = io.open(path, "r")
  object:seek(io.POSITION_END)
  size = object:tell()
  object:close()
  return size
end
```