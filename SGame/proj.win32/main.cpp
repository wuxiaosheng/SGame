#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"
#include <shellapi.h>

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

#ifdef WIN32
	_tsetlocale(LC_ALL, _T(""));
	::AllocConsole();
	::freopen("conout$", "w", stdout);
	::freopen("CONIN$", "r", stdin);
	::freopen("CONOUT$", "w", stderr);
#endif

    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
