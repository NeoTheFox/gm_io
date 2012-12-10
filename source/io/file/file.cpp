#include "file.hpp"

namespace io {
	file::file() : m_stream(NULL) {
		this->m_stream = new std::fstream();
	}
	file::~file() {
		delete this->m_stream;
	}

	void file::close() {
		if(this->is_open()) {
			this->m_stream->close();
		}
	}
	bool file::size(int& size) {
		if(!this->is_open()) {
			size = -1;
			return false;
		}
		if(this->seek(position::end) &&
		   this->tell(size)	&&
		   this->seek(position::beginning))
			this->m_stream->clear();
			return true;
		return false;
	}
	bool file::tell(int& position) {
		if(!this->is_open()) {
			position = -1;
			return false;
		}
		int get = this->m_stream->tellg();
		int put = this->m_stream->tellp();

		this->m_stream->clear();

		if(get != -1 && put != -1) {
			position = (get + put) / 2;
			return true;
		}
		position = -1;
		return false;
	}
	bool file::seek(position::position position) {
		if(!this->is_open())
			return false;
		try {
			switch(position) {
				case position::end:
					this->m_stream->seekg(std::ios::end);
					this->m_stream->seekp(std::ios::end);
				break;
				case position::current:
					this->m_stream->seekg(std::ios::cur);
					this->m_stream->seekp(std::ios::cur);
				break;
				case position::beginning:
					this->m_stream->seekg(std::ios::beg);
					this->m_stream->seekp(std::ios::beg);
				break;
				default:
					return false;
			}
			this->m_stream->clear();
			return true;
		} catch(int _unused_) {
			this->m_stream->clear();
			return false;
		}
	}
	bool file::read (std::string& data) {
		if(!this->is_open())
			return false;
		if(!this->seek(position::beginning))
			return false;
		try {
			data = std::string(
				(std::istreambuf_iterator<char>(this->m_stream->rdbuf())),
				 std::istreambuf_iterator<char>()
			);
			this->m_stream->clear();
			return true;
		} catch(int _unused_) {
			data = "";
			return false;
		}
	}
	bool file::write(std::string& data) {
		if(!this->is_open())
			return false;
		try {
			this->m_stream->write(data.c_str(), data.length());
			this->m_stream->clear();
			return true;
		} catch(int _unused_) {
			return false;
		}
	}
	bool file::read (std::string& data, int length) {
		if(!this->is_open())
			return false;
		try {
			char* buffer = new char[length];
			this->m_stream->read(buffer, length);
			this->m_stream->clear();

			data = std::string(buffer);
			return true;
		} catch(int _unused_) {
			data = "";
			return false;
		}
	}
	bool file::write(std::string& data, int length) {
		if(!this->is_open())
			return false;
		try {
			this->m_stream->write(data.c_str(), length);
			this->m_stream->clear();
			return true;
		} catch(int _unused_) {
			return false;
		}
	}
	bool file::open (std::string& path, std::string& mode) {
		if(mode == "r")
			this->m_stream->open(path.c_str(), std::ios::in);
		else if(mode == "w")
			this->m_stream->open(path.c_str(), std::ios::out | std::ios::trunc);
		else if(mode == "a")
			this->m_stream->open(path.c_str(), std::ios::out | std::ios::app);
		else if(mode == "r+")
			this->m_stream->open(path.c_str(), std::ios::in | std::ios::out);
		else if(mode == "w+")
			this->m_stream->open(path.c_str(), std::ios::in | std::ios::out | std::ios::trunc);
		else if(mode == "a+")
			this->m_stream->open(path.c_str(), std::ios::in | std::ios::out | std::ios::app);
		else
			return false;
		if(this->is_open())
			return true;
		return false;
	}

	bool file::copy(std::string& from, std::string& to) {
		std::string data;
		file* to_   = new file();
		file* from_ = new file();

		if(!(
			to_->open(to, std::string("w+"))	&&
			from_->open(from, std::string("r+"))
		))
			return false;
		if(!(
			from_->read(data) &&
			to_->write(data)
		))
			return false;
		to_->close();
		from_->close();
		return true;
	}
	bool file::move(std::string& from, std::string& to) {
		std::string data;
		file* to_   = new file();
		file* from_ = new file();

		if(!(
			to_->open(to, std::string("w+"))	&&
			from_->open(from, std::string("r+"))
		))
			return false;
		if(!(
			from_->read(data) &&
			to_->write(data)
		))
			return false;
		to_->close();
		from_->close();
		return file::remove(from);
	}
	bool file::exists(std::string& path) {
		bool  ret = false;
		file* tmp = new file();
		tmp->open(path, std::string("r"));
		ret = tmp->is_open();
		tmp->close();
		return ret;
	}
	bool file::remove(std::string& path) {
		return std::remove(path.c_str()) == 0;
	}
	bool file::rename(std::string& from, std::string& to) {
		return std::rename(from.c_str(), to.c_str()) == 0;
	}

	bool file::is_open() {
		if(this->m_stream && this->m_stream->good()) {
			if(this->m_stream->fail()) {
				//return false;
				this->m_stream->clear();
			}
			return true;
		}
		return false;
	}
}
