#ifndef __SGAME_OBJECT_H__
#define __SGAME_OBJECT_H__
#include "SBaseObject.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

class SGameObject : public SBaseObject, public Node
{
public:
	virtual bool init();

protected:
	
};

#endif