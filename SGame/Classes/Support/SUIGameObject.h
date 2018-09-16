#ifndef __SUIGAME_OBJECT_H__
#define __SUIGAME_OBJECT_H__
#include "SMDGameObject.h"
#include "ClassFactory.h"
#include "SGameScene.h"
#include"cocostudio/CocoStudio.h"
using namespace cocostudio;
class SUIGameObject;
typedef void(*btn_click)(SUIGameObject *, Node *);
class SUIGameObject : public SGameObject
{
public:
	virtual bool init();

	virtual void onLoad() {}

	virtual void onRemove();

	Node *getNode(const std::string name);

	virtual SMDGameObject *createModel() { _pModel = new SMDGameObject(); return _pModel; }

	SMDGameObject *getModel() { return _pModel; }

	void setGameScene(SGameScene *pScene) { _pScene = pScene; }

	SGameScene *getGameScene() { return _pScene; }

	SUIGameObject *createGameUI(const std::string name) { return _pScene->createGameUI(name); }

	void removeGameUI(const std::string name) { _pScene->removeGameUI(name); }

protected:
	virtual void loadFile(const std::string name);

	void pushNodeToMap(Node *pParent);

	void addTouchListener(Node *pNode);

	bool addClickFunc(const std::string name, btn_click bc);

	void respClickFunc(Node *pNode);

	void onDefaultClickFunc(Ref *pSender, ui::Widget::TouchEventType eventName);

private:
	SMDGameObject *_pModel;
	Layout *_pRoot;
	SGameScene *_pScene;
	std::map<std::string, Node *> _nodeReflect;
	std::map<std::string, btn_click> _clickReflect;
};

#endif