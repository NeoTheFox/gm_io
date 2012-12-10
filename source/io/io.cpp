#include "io.hpp"

#define pushByte(_key_, _val_) 		 	 \
	LUA->PushNumber((double)_val_); 	 \
	LUA->SetField(-2, _key_);
#define pushFunction(_func_)			 \
	LUA->PushCFunction(io::lua::_func_); \
	LUA->SetField(-2, #_func_);

GMOD_MODULE_OPEN() {
	LuaOO::instance()->registerPollingFunction(state, "io::poll");
	LuaOO::instance()->registerClasses(state);

	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
		LUA->CreateTable();
			pushFunction(open)
			pushFunction(copy)
			pushFunction(move)
			pushFunction(exists)
			pushFunction(remove)
			pushFunction(rename)

			pushByte("POSITION_END", 0x01);
			pushByte("POSITION_CURRENT", 0x02);
			pushByte("POSITION_BEGINNING", 0x04);
		LUA->SetField(-2, "io");
	LUA->Pop();
	return 0;
}
GMOD_MODULE_CLOSE() {
	LuaOO::shutdown();
	return 0;
}
