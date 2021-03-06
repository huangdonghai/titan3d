#pragma once
#include "IRenderResource.h"

NS_BEGIN

struct IVertexBufferDesc
{
	IVertexBufferDesc()
	{
		CPUAccess = 0;
		ByteWidth = 0;
		Stride = 0;
		InitData = nullptr;
	}
	UINT			CPUAccess;
	UINT			ByteWidth;
	UINT			Stride;
	void*			InitData;
};

class IRenderContext;
class ICommandList;
class IVertexBuffer : public IRenderResource
{
public:
	IVertexBuffer();
	~IVertexBuffer();

	virtual void GetBufferData(IRenderContext* rc, IBlobObject* data) = 0;
	virtual void UpdateGPUBuffData(ICommandList* cmd, void* ptr, UINT size) = 0;

	void UpdateDrawPass(ICommandList* cmd, vBOOL bImm);
	virtual void DoSwap(IRenderContext* rc) override;
	virtual void SetDebugInfo(const char* info)
	{
		
	}
public:
	IVertexBufferDesc		mDesc;
	/*std::vector<BYTE>		mVertices;
	bool					mHasPushed;
	UINT					GpuBufferSize;*/
};

NS_END