#ifndef LUA_HPP
#define LUA_HPP

#ifdef WIN32
	#pragma once
#endif

#include "../io.hpp"
#include "object/pathObject.hpp"
#include "object/fileObject.hpp"

namespace io {
	namespace lua {
		LUA_OBJECT_FUNCTION(open);
		LUA_OBJECT_FUNCTION(copy);
		LUA_OBJECT_FUNCTION(move);
		LUA_OBJECT_FUNCTION(exists);
		LUA_OBJECT_FUNCTION(remove);
		LUA_OBJECT_FUNCTION(rename);
	}
}

#endif//LUA_HPP
