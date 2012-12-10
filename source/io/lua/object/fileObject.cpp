#include "fileObject.hpp"
#include "../../file/file.hpp"

fileObject::fileObject(std::string path, std::string mode, lua_State* state)
	: ::LuaObjectBaseTemplate<fileObject>(state) {
	this->m_file = new io::file();
	this->m_file->open(path, mode);

	MLUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
		MLUA->GetField(-1, "print");
		MLUA->PushBool(this->m_file->is_open());
		MLUA->Call(1, 0);
	MLUA->Pop();
}
fileObject::~fileObject() {
	delete this->m_file;
}

BEGIN_BINDING(fileObject)
	BIND_FUNCTION("close", fileObject::close)
	BIND_FUNCTION("read", fileObject::read)
	BIND_FUNCTION("write", fileObject::write)
	BIND_FUNCTION("size", fileObject::size)
END_BINDING()

int fileObject::close() {
	this->m_file->close();
	return 0;
}
int fileObject::read() {
	std::string data;
	if(!this->m_file->read(data))
		return 0;
	MLUA->PushString(data.c_str());
	return 1;
}
int fileObject::write() {
	if(!checkArgument(2, GarrysMod::Lua::Type::STRING))
		return 0;
	bool failed = true;
	std::string data = "";

	data = MLUA->GetString(2);
	if(!this->m_file->write(data))
		return 0;
	MLUA->PushBool(true);
	return 1;
}
int fileObject::size() {
	int size;
	this->m_file->size(size);
	MLUA->PushNumber((double)size);
	return 1;
}
int fileObject::tell() {
	int position;
	this->m_file->tell(position);
	MLUA->PushNumber((double)position);
	return 1;
}
int fileObject::seek() {
	if(!checkArgument(2, GarrysMod::Lua::Type::NUMBER))
		return 0;
	switch((int)MLUA->GetNumber(2)) {
		case 0x01:
			MLUA->PushBool(this->m_file->seek(io::position::end));
		break;
		case 0x02:
			MLUA->PushBool(this->m_file->seek(io::position::current));
		break;
		case 0x04:
			MLUA->PushBool(this->m_file->seek(io::position::beginning));
		break;
		default:
			return 0;
	}
	return 1;
}
