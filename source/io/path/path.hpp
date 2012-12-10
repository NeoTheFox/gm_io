#ifndef PATH_HPP
#define PATH_HPP

#ifdef WIN32
	#pragma once
#endif

#include "../io.hpp"

namespace io {
	class path {
		public:
			path(std::string _path);

			std::string getName();
			std::string getPath();
			std::string getExtension();
			std::string getDirectory();

			static bool checkPath(lua_State* state, std::string _path);
		private:
			std::string m_path;
	};
}

#endif//PATH_HPP
