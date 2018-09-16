#include "SUIGameObject.h"

bool SUIGameObject::init() {
	bool bRet = SGameObject::init();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_pRoot = Layout::create();
	_pRoot->setContentSize(Size(0, 0));
	_pRoot->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(_pRoot);
	this->onLoad();
	return bRet;
}

void SUIGameObject::onRemove() {
	_pScene = nullptr;
	this->removeChild(_pRoot);
	_pRoot = nullptr;
	this->removeFromParentAndCleanup(true);
}

void SUIGameObject::loadFile(const std::string name) {
	Node *pNode = CSLoader::createNode(name);
	this->pushNodeToMap(pNode);
	_pRoot->addChild(pNode);
}

void SUIGameObject::pushNodeToMap(Node *pParent) {
	for (auto val : pParent->getChildren()) {
		this->_nodeReflect[val->getName()] = val;
		this->addTouchListener(val);
		this->pushNodeToMap(val);
	}
}

Node *SUIGameObject::getNode(const std::string name) {
	return this->_nodeReflect[name];
}

void SUIGameObject::addTouchListener(Node *pNode) {
	std::string typeName = pNode->getDescription();
	if (typeName == "Button") {
		((Button *)pNode)->addTouchEventListener(CC_CALLBACK_2(SUIGameObject::onDefaultClickFunc, this));
	}
}

bool SUIGameObject::addClickFunc(const std::string name, btn_click bc) {
	auto iter = _clickReflect.find(name);
	if (iter != _clickReflect.end()) {
		std::cout << "btn click func repeat!" << std::endl;
		return false;
	}
	_clickReflect.insert(std::pair<std::string, btn_click>(name, bc));
	return true;
}

void SUIGameObject::respClickFunc(Node *pNode) {
	std::string name = pNode->getName();
	auto iter = _clickReflect.find(name);
	if (iter != _clickReflect.end()) {
		iter->second(this, pNode);
		return;
	}

	std::cout << "cannot find name:" << name << " click func" << std::endl;
	return;
}

void SUIGameObject::onDefaultClickFunc(Ref *pSender, ui::Widget::TouchEventType eventName) {
	if (eventName == ui::Widget::TouchEventType::ENDED) {
		std::cout << "on click" << std::endl;
		this->respClickFunc((Node *)pSender);
	}
}