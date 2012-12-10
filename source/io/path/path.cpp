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

	bool path::isPotentiallyHarmful(std::string _path) {
		path _pathObject(_path);
		std::string extension = _pathObject.getExtension();

		if(extension == "exe")
			return true;
		if(extension == "com")
			return true;
		if(extension == "pif")
			return true;
		if(extension == "bat")
			return true;
		if(extension == "scr")
			return true;
		if(extension == "dll")
			return true;

		for(size_t i = 0; i < _path.length() - 1; i++) {
			if(_path[i] == '.' && _path[i + 1] == '.')
				return true;
		}

		return false;
	}
}
