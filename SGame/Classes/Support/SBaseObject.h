#pragma once
#ifndef __SBASE_OBJECT_H__
#define __SBASE_OBJECT_H__
#include <iostream>
#include <map>


class SBaseObject
{
public:
	SBaseObject() : _id(_scount) {}
	virtual ~SBaseObject() {}

public:
	virtual SBaseObject *find(const std::string name) { return _objects[name]; }

	virtual bool addObject(const std::string name, SBaseObject *pObject);
private:
	static int _scount;
	int _id;
	std::map<const std::string, SBaseObject *> _objects;
};

#endif