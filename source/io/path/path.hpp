#ifndef PATH_HPP
#define PATH_HPP

#ifdef WIN32
	#pragma once
#endif

#include "../io.hpp"

namespace io {
	class path {
		public:
			path(std::string _path) {
				std::string slash("/");
				std::regex  match("\\\\");
				this->m_path = std::regex_replace(
					_path,
					match,
					slash
				);
			};

			std::string getName() {
				std::string blank("");
				std::regex  match(this->getDirectory()+"\\/");
				return std::regex_replace(
					this->m_path,
					match,
					blank
				);
			};
			std::string getPath() {
				return this->m_path;
			};
			std::string getExtension() {
				std::string blank("");
				std::regex  match("^[^\\.]+\\.");
				return std::regex_replace(
					this->m_path,
					match,
					blank
				);
			};
			std::string getDirectory() {
				std::string blank("");
				std::regex  match("\\/[^\\/]+$");
				return std::regex_replace(
					this->m_path,
					match,
					blank
				);
			};

			bool isPotentiallyHarmful() {
				std::string extension = this->getExtension();
				//std::string directory = this->getDirectory();

				if(extension == "exe")
					return true;
				if(extension == "bat")
					return true;
				if(extension == "scr")
					return true;
				if(extension == "dll")
					return true;
				if(extension == "com")
					return true;
				if(extension == "pif")
					return true;
				//if(directory != config::get("steam_directory"))
				//	return true;
				return false;
			};
		private:
			std::string m_path;
	};
}

#endif//PATH_HPP