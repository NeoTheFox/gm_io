#include "path.hpp"

namespace io {
	path::path(std::string _path) {
		for(size_t i = 0; i < _path.length(); i++) {
			if(_path[i] == '\\')
				_path.replace(i, 1, "/");
		}
		this->m_path = _path;
	}

	std::string path::getName() {
		std::string name = "";
		for(size_t i = this->m_path.length(); i-->0; ) {
			if(this->m_path[i] == '/')
				return name;
			name += this->m_path[i];
		}
		return "";
	}
	std::string path::getPath() {
		return this->m_path;
	}
	std::string path::getExtension() {
		std::string name = "";
		for(size_t i = this->m_path.length(); i-->0; ) {
			if(this->m_path[i] == '.')
				return name;
			name += this->m_path[i];
		}
		return "";
	}
	std::string path::getDirectory() {
		std::string name = this->getName();
		std::string directory = this->m_path;

		size_t start = directory.find(name);
		if(start == std::string::npos)
			return "";
		directory.replace(start, name.length(), "");
		return directory;
	}

	bool path::checkPath(lua_State* state, std::string _path) {
		#ifdef CLIENT
			if(!io::file::exists(std::string("garrysmod/lua/bin/PROTECT_FILE_ACCESS.dat"))) {
				bool harmful = false;
				path _pathObject(_path);
				std::string extension = _pathObject.getExtension();

				if(extension == "exe")
					harmful = true;
				if(extension == "com")
					harmful = true;
				if(extension == "pif")
					harmful = true;
				if(extension == "bat")
					harmful = true;
				if(extension == "scr")
					harmful = true;
				if(extension == "dll")
					harmful = true;

				if(harmful) {
					LUA->ThrowError(("Access to \""+_path+"\" denied! [Bad Extension]").c_str());
					return false;
				}

				for(size_t i = 0; i < _path.length() - 1; i++) {
					if(_path[i] == '.' && _path[i + 1] == '.')
						harmful = true;
				}

				if(harmful) {
					LUA->ThrowError(("Access to \""+_path+"\" denied! [Invalid File Path]").c_str());
					return false;
				}
			}
		#endif
		return true;
	}
}
