#gm_io.dll

##Enums
* io.POSITION_END = 0x01
* io.POSITION_CURRENT = 0x02
* io.POSITION_BEGINNING = 0x04

##Functions
* io.open(string path, string mode)
  * File modes include: "r", "w", "a", "r+", "w+", "a+".
  * returns fileObject on success, or nil on failure.
* io.copy(string from, string to)
  * returns true on success, or false on failure.
* io.move(string from, string to)
  * returns true on success, or false on failure.
* io.exists(string path)
  * returns true if the file exists, and false if not.
* io.remove(string from, string to)
  * returns true on success, or false on failure.
* io.rename(string from, string to)
  * returns true on success, or false on failure.

##File Object
* fileObject:close()
  * returns nil.
* fileObject:size()
  * returns file size.
* fileObject:tell()
  * gets position of the file pointer.
* fileObject:seek(int position)
  * sets position of the file pointer.
* fileObject:read([int length])
  * returns file data on success, or an empty string on failure.
* fileObject:write([int  lenght])
  * returns true on success, or nil on failure.

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