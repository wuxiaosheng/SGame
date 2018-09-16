#ifndef __SGAME_SCENE_H__
#define __SGAME_SCENE_H__
#include "SGameObject.h"
class SUIGameObject;
class SGameScene : public SGameObject
{
public:
	virtual bool init();

	SUIGameObject *createGameUI(const std::string cname);

	void run();

protected:
	virtual void onStart() {}

	virtual void onRegisterUIList() = 0;

private:
	void createRoot();

private:
	Scene *_pScene;
	Layout *_pRoot;
};

#endif
