#include "UICommonDialog.h"

bool UICommonDialog::init() {
	bool bRet = SUIGameObject::init();
	return bRet;
}

void UICommonDialog::onLoad() {
	this->loadFile("ui/common/uiCommonDialog.csb");

	this->addClickFunc("btn_close", [](SUIGameObject *pSelf, Node *pNode){ ((UICommonDialog*)pSelf)->clickBtnClose(pNode); });
	this->addClickFunc("btn_sure", [](SUIGameObject *pSelf, Node *pNode){ ((UICommonDialog*)pSelf)->clickBtnSure(pNode); });
	this->addClickFunc("btn_cancel", [](SUIGameObject *pSelf, Node *pNode){ ((UICommonDialog*)pSelf)->clickBtnCancel(pNode); });

	this->getNode("text_desc")->setVisible(false);
	((ui::Button *)this->getNode("btn_cancel"))->setSwallowTouches(true);
}

void UICommonDialog::setContent(std::string content) {
	this->getNode("text_desc")->setVisible(true);
	((ui::Text *)this->getNode("text_desc"))->setString(content);
}

void UICommonDialog::clickBtnClose(Ref *pSender) {
	this->removeGameUI("UICommonDialog");
}

void UICommonDialog::clickBtnSure(Ref *pSender) {

}

void UICommonDialog::clickBtnCancel(Ref *pSender) {
	this->removeGameUI("UICommonDialog");
}