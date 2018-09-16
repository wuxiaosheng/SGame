#pragma once
#ifndef __SBASE_OBJECT_H__
#define __SBASE_OBJECT_H__
#include <iostream>
#include <string>
#include <map>


class SBaseObject
{
public:
	SBaseObject() : _id(_scount) {}
	virtual ~SBaseObject() {}

public:
	virtual SBaseObject *find(const std::string name);

	virtual bool addObject(const std::string name, SBaseObject *pObject);

	virtual void removeObject(const std::string name);
private:
	static int _scount;
	int _id;
	std::map<const std::string, SBaseObject *> _objects;
};

#endif