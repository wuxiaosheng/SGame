#include "SBaseObject.h"

int SBaseObject::_scount = 0;

bool SBaseObject::addObject(const std::string name, SBaseObject *pObject) {
	auto iter = _objects.find(name);
	if (iter != _objects.end()) {
		std::cout << "object name repeat!" << std::endl;
		return false;
	}
	_objects.insert(std::pair<const std::string, SBaseObject *>(name, pObject));
	_scount++;
	return true;
}