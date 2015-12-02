// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "MFCtestHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CMFCtestHandlersModule _AtlModule;

class CMFCtestHandlersApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMFCtestHandlersApp, CWinApp)
END_MESSAGE_MAP()

CMFCtestHandlersApp theApp;

BOOL CMFCtestHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
	return CWinApp::InitInstance();
}

int CMFCtestHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
