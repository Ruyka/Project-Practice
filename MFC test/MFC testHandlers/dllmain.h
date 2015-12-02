// dllmain.h : Declaration of module class.

class CMFCtestHandlersModule : public ATL::CAtlDllModuleT< CMFCtestHandlersModule >
{
public :
	DECLARE_LIBID(LIBID_MFC testHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MFCTESTHANDLERS, "{863386FD-1BCF-4CB4-BE95-335B0429AB8F}")
};

extern class CMFCtestHandlersModule _AtlModule;
