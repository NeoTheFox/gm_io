#include "pathObject.hpp"

pathObject::pathObject(io::path* path, lua_State* state) : LuaObjectBaseTemplate<pathObject>(state) {
	this->m_path = path;
}
pathObject::~pathObject() {
	delete this->m_path;
}

BEGIN_BINDING(pathObject)
	BIND_FUNCTION("getName", pathObject::getName)
	BIND_FUNCTION("getPath", pathObject::getPath)
	BIND_FUNCTION("getExtension", pathObject::getExtension)
	BIND_FUNCTION("getDirectory", pathObject::getDirectory)
END_BINDING()

int pathObject::getName() {
	MLUA->PushString(this->m_path->getName().c_str());
	return 1;
}
int pathObject::getPath() {
	MLUA->PushString(this->m_path->getPath().c_str());
	return 1;
}
int pathObject::getExtension() {
	MLUA->PushString(this->m_path->getExtension().c_str());
	return 1;
}
int pathObject::getDirectory() {
	MLUA->PushString(this->m_path->getDirectory().c_str());
	return 1;
}