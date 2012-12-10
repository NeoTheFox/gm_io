#ifndef FILE_OBJECT_HPP
#define FILE_OBJECT_HPP

#ifdef WIN32
	#pragma once
#endif

#include "../lua.hpp"

namespace io {
	class file;
}

class fileObject : public LuaObjectBaseTemplate<fileObject, 218> {
	LUA_OBJECT
	public:
		fileObject(std::string path, std::string mode, lua_State* state);
		~fileObject();

		int close();
		int read();
		int write();
		int size();
		int tell();
		int seek();
	private:
		io::file* m_file;
};

#endif//FILE_OBJECT_HPP
