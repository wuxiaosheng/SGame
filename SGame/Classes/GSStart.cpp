#include "GSStart.h"
#include "ClassFactory.h"
#include "UICommonDialog.h"
bool GSStart::init() {
	bool bRet = SGameScene::init();
	return bRet;
}

void GSStart::onRegisterUIList() {
	ClassFactory::getInstance()->registerClass("UICommonDialog", []()->void*{ return UICommonDialog::create(); });
}

void GSStart::onStart() {
	((UICommonDialog *)this->createGameUI("UICommonDialog"))->setContent("²âÊÔÊä³ö");
}