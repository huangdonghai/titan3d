#include "ID11VertexShader.h"
#include "ID11RenderContext.h"
#include "ID11CommandList.h"
#include "ID11ConstantBuffer.h"

#define new VNEW

NS_BEGIN

ID11VertexShader::ID11VertexShader()
{
	mShader = nullptr;
}

ID11VertexShader::~ID11VertexShader()
{
	Safe_Release(mShader);
}

bool ID11VertexShader::Init(ID11RenderContext* rc, const IShaderDesc* desc)
{
	auto hr = rc->mDevice->CreateVertexShader(&desc->GetCodes()[0], desc->GetCodes().size(), NULL, &mShader);
	if (FAILED(hr))
		return false;
	
	mDesc = (IShaderDesc*)desc;
	mDesc->AddRef();
#ifdef _DEBUG
	mShader->SetPrivateData(WKPDID_D3DDebugObjectName, 0, NULL);
	static UINT UniqueId = 0;
	auto debuginfo = VStringA_FormatV("VS_%u", UniqueId++);
	mShader->SetPrivateData(WKPDID_D3DDebugObjectName, (UINT)debuginfo.length(), debuginfo.c_str());
#endif
	return true;
}

NS_END