#include "ClassFactory.h"

ClassFactory *ClassFactory::_pInstance = nullptr;
ClassFactory *ClassFactory::getInstance() {
	if (_pInstance == nullptr) {
		_pInstance = new ClassFactory();
	}

	return _pInstance;
}

bool ClassFactory::registerClass(const std::string cname, func_ptr fp) {
	auto iter = _reflect.find(cname);
	if (iter != _reflect.end()) {
		std::cout << "class name repeat!" << std::endl;
		return false;
	}
	_reflect.insert(std::pair<const std::string, func_ptr>(cname, fp));
	return true;
}

void *ClassFactory::createClass(const std::string cname) {
	auto iter = _reflect.find(cname);
	if (iter != _reflect.end()) {
		return iter->second();
	}
	std::cout << "class does not exist!" << std::endl;
	return nullptr;
}