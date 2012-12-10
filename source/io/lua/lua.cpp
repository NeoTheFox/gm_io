#include "lua.hpp"
#include "object/pathObject.hpp"
#include "object/fileObject.hpp"

namespace io {
	namespace lua {
		LUA_OBJECT_FUNCTION(open) {
			std::string path = LUA->CheckString(1);
			std::string mode = LUA->CheckString(2);

			path = "garrysmod/" + path;

			fileObject* object = new fileObject(path, mode, state);
			object->pushObject();
			return 1;
		}
		LUA_OBJECT_FUNCTION(copy) {
			std::string from = LUA->CheckString(1);
			std::string to   = LUA->CheckString(2);

			from = "garrysmod/" + from;
			to = "garrysmod/" + to;

			LUA->PushBool(io::file::copy(from, to));
			return 1;
		}
		LUA_OBJECT_FUNCTION(move) {
			std::string from = LUA->CheckString(1);
			std::string to   = LUA->CheckString(2);

			from = "garrysmod/" + from;
			to = "garrysmod/" + to;

			LUA->PushBool(io::file::move(from, to));
			return 0;
		}
		LUA_OBJECT_FUNCTION(exists) {
			std::string path = LUA->CheckString(1);

			path = "garrysmod/" + path;

			LUA->PushBool(::io::file::exists(path));
			return 0;
		}
		LUA_OBJECT_FUNCTION(remove) {
			std::string path = LUA->CheckString(1);

			path = "garrysmod/" + path;

			LUA->PushBool(io::file::remove(path));
			return 0;
		}
		LUA_OBJECT_FUNCTION(rename) {
			std::string from = LUA->CheckString(1);
			std::string to   = LUA->CheckString(2);

			from = "garrysmod/" + from;
			to = "garrysmod/" + to;

			LUA->PushBool(io::file::rename(from, to));
			return 1;
		}
	}
}
