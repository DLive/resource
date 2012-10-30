#include "StdAfx.h"
#include "DLindex.h"

CDLindex::CDLindex(void)
{

}

CDLindex::~CDLindex(void)
{
}

int CDLindex::initxml(){
	MSXML2::IXMLDOMDocumentPtr pDoc;

	MSXML2::IXMLDOMElementPtr xmlRoot;

	//创建DOMDocument对象

	HRESULT hr = pDoc.CreateInstance(_uuidof(MSXML2::DOMDocument40));

	if (FAILED(hr))

	{

		MessageBoxA(NULL,"无法创建DOM文件对象，检查是否安装MS XML Parser运行库","error",0);

		return 0;

	}
	return 0;

}
