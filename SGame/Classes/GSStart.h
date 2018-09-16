#ifndef __GS_START_H__
#define __GS_START_H__
#include "SGameScene.h"
class GSStart : public SGameScene {
public:
	virtual bool init();

	CREATE_FUNC(GSStart);
protected:
	virtual void onRegisterUIList();

	virtual void onStart();
};

#endif
