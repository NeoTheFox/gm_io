#ifndef PATH_OBJECT_HPP
#define PATH_OBJECT_HPP

#ifdef WIN32
	#pragma once
#endif

#include "../lua.hpp"

namespace io {
	class path;
}

class pathObject
	: public LuaObjectBaseTemplate<pathObject, 217> {
	LUA_OBJECT
	public:
		pathObject(io::path* path, lua_State* state);
		~pathObject();

		int getName();
		int getPath();
		int getExtension();
		int getDirectory();
	private:
		io::path* m_path;
};

#endif//PATH_OBJECT_HPP
