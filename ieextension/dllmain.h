// dllmain.h : 模块类的声明。

class CieextensionModule : public CAtlDllModuleT< CieextensionModule >
{
public :
	DECLARE_LIBID(LIBID_ieextensionLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_IEEXTENSION, "{64E8D7C8-FC73-40A5-A660-BD8EFE7A5891}")
};

extern class CieextensionModule _AtlModule;
