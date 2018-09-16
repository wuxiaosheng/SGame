#ifndef __CLASS_FACTORY_H__
#define __CLASS_FACTORY_H__
#include <iostream>
#include <string>
#include <map>
typedef void* (*func_ptr)();
class ClassFactory
{
private:
	ClassFactory() {}
	~ClassFactory() {}

public:
	static ClassFactory *getInstance();

	bool registerClass(const std::string cname, func_ptr fp);

	void *createClass(const std::string cname);
private:
	static ClassFactory *_pInstance;

	std::map<const std::string, func_ptr> _reflect;
};

#endif
