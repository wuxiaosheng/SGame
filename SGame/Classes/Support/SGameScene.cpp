#include "SGameScene.h"
#include "ClassFactory.h"
#include "SUIGameObject.h"
bool SGameScene::init() {
	bool bRet = SGameObject::init();
	this->onRegisterUIList();
	return bRet;
}

SUIGameObject *SGameScene::createGameUI(const std::string cname) {
	SUIGameObject *pUI = (SUIGameObject *)ClassFactory::getInstance()->createClass(cname);
	if (!pUI) { return nullptr; }
	pUI->setGameScene(this);
	this->addObject(cname, pUI);
	_pRoot->addChild(pUI);
	return pUI;
}

void SGameScene::removeGameUI(const std::string cname) {
	((SUIGameObject *)this->find(cname))->onRemove();
	this->removeObject(cname);
}

void SGameScene::run() {
	_pScene = Scene::create();
	_pScene->addChild(this);
	this->createRoot();
	Director::getInstance()->runWithScene(_pScene);
	this->onStart();
}

void SGameScene::createRoot() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_pRoot = Layout::create();
	_pRoot->setContentSize(visibleSize);
	_pRoot->setAnchorPoint(Vec2(0, 0));
	_pRoot->setPosition(Vec2(0, 0));
	_pScene->addChild(_pRoot);
}