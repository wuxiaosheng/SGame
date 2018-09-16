#ifndef __UICOMMON_DIALOG_H__
#define __UICOMMON_DIALOG_H__
#include "SUIGameObject.h"
class UICommonDialog : public SUIGameObject
{
public:
	virtual bool init();

	virtual void onLoad();

	void setContent(std::string content);

	void clickBtnClose(Ref *pSender);
	void clickBtnSure(Ref *pSender);
	void clickBtnCancel(Ref *pSender);

	CREATE_FUNC(UICommonDialog);
};

#endif
