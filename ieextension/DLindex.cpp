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

	//����DOMDocument����

	HRESULT hr = pDoc.CreateInstance(_uuidof(MSXML2::DOMDocument40));

	if (FAILED(hr))

	{

		MessageBoxA(NULL,"�޷�����DOM�ļ����󣬼���Ƿ�װMS XML Parser���п�","error",0);

		return 0;

	}
	return 0;

}
