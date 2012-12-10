#ifndef FILE_HPP
#define FILE_HPP

#ifdef WIN32
	#pragma once
#endif

#include "../io.hpp"

namespace io {
	namespace position {
		enum  position {
			end 	  = 0x01,
			current   = 0x02,
			beginning = 0x04
		};
	}
	class file {
		public:
			file(void);
			~file(void);

			void close();
			bool size(int& size);
			bool tell(int& position);
			bool seek(position::position position);
			bool read (std::string& data);
			bool write(std::string& data);
			bool read (std::string& data, int length);
			bool write(std::string& data, int length);
			bool open (std::string& path, std::string& mode);

			static bool copy(std::string& from, std::string& to);
			static bool move(std::string& from, std::string& to);
			static bool exists(std::string& path);
			static bool remove(std::string& path);
			static bool rename(std::string& from, std::string& to);

			bool is_open();
		private:
			std::fstream* m_stream;
	};
}

#endif//FILE_HPP
