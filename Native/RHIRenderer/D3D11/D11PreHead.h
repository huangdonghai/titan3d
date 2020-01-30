#pragma once
#include "../PreHead.h"
#include "../ShaderReflector.h"
#include "../IPass.h"

#pragma warning(push)
#pragma warning(disable:4005)
#include <d3d11.h>
//#include <d3dx11.h>
#include <d3dcompiler.h>
#pragma warning(pop)

NS_BEGIN

static const DXGI_FORMAT gDX11FormatArray[]=
{
	DXGI_FORMAT_UNKNOWN,
	DXGI_FORMAT_R16_FLOAT,
	DXGI_FORMAT_R16_UINT,
	DXGI_FORMAT_R16_SINT,
	DXGI_FORMAT_R16_UNORM,
	DXGI_FORMAT_R16_SNORM,
	DXGI_FORMAT_R32_UINT,
	DXGI_FORMAT_R32_SINT,
	DXGI_FORMAT_R32_FLOAT,
	DXGI_FORMAT_R8G8B8A8_SINT,
	DXGI_FORMAT_R8G8B8A8_UINT,
	DXGI_FORMAT_R8G8B8A8_UNORM,
	DXGI_FORMAT_R8G8B8A8_SNORM,
	DXGI_FORMAT_R16G16_UINT,
	DXGI_FORMAT_R16G16_SINT,
	DXGI_FORMAT_R16G16_FLOAT,
	DXGI_FORMAT_R16G16_UNORM,
	DXGI_FORMAT_R16G16_SNORM,
	DXGI_FORMAT_R16G16B16A16_UINT,
	DXGI_FORMAT_R16G16B16A16_SINT,
	DXGI_FORMAT_R16G16B16A16_FLOAT,
	DXGI_FORMAT_R16G16B16A16_UNORM,
	DXGI_FORMAT_R16G16B16A16_SNORM,
	DXGI_FORMAT_R32G32B32A32_UINT,
	DXGI_FORMAT_R32G32B32A32_SINT,
	DXGI_FORMAT_R32G32B32A32_FLOAT,
	DXGI_FORMAT_R32G32B32_UINT,
	DXGI_FORMAT_R32G32B32_SINT,
	DXGI_FORMAT_R32G32B32_FLOAT,
	DXGI_FORMAT_R32G32_UINT,
	DXGI_FORMAT_R32G32_SINT,
	DXGI_FORMAT_R32G32_FLOAT,
	DXGI_FORMAT_D24_UNORM_S8_UINT,
	DXGI_FORMAT_D32_FLOAT,
	DXGI_FORMAT_D32_FLOAT_S8X24_UINT,
	DXGI_FORMAT_D16_UNORM,
	DXGI_FORMAT_B8G8R8A8_UNORM,
	DXGI_FORMAT_R11G11B10_FLOAT,
	DXGI_FORMAT_R8G8_UNORM,
	DXGI_FORMAT_R8_UNORM,
	DXGI_FORMAT_R32_TYPELESS,
	DXGI_FORMAT_R32G32B32A32_TYPELESS,
	DXGI_FORMAT_R32G32B32_TYPELESS,
	DXGI_FORMAT_R16G16B16A16_TYPELESS,
	DXGI_FORMAT_R32G32_TYPELESS,
	DXGI_FORMAT_R32G8X24_TYPELESS,
	DXGI_FORMAT_R10G10B10A2_TYPELESS,
	DXGI_FORMAT_R10G10B10A2_UNORM,
	DXGI_FORMAT_R10G10B10A2_UINT,
	DXGI_FORMAT_R8G8B8A8_TYPELESS,
	DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
	DXGI_FORMAT_R16G16_TYPELESS,
	DXGI_FORMAT_R24G8_TYPELESS,
	DXGI_FORMAT_R24_UNORM_X8_TYPELESS,
	DXGI_FORMAT_X24_TYPELESS_G8_UINT,
	DXGI_FORMAT_R8G8_TYPELESS,
	DXGI_FORMAT_R8G8_UINT,
	DXGI_FORMAT_R8G8_SNORM,
	DXGI_FORMAT_R8G8_SINT,
	DXGI_FORMAT_R16_TYPELESS,
	DXGI_FORMAT_R8_TYPELESS,
	DXGI_FORMAT_R8_UINT,
	DXGI_FORMAT_R8_SNORM,
	DXGI_FORMAT_R8_SINT,
	DXGI_FORMAT_A8_UNORM,
	DXGI_FORMAT_B8G8R8X8_UNORM,
	DXGI_FORMAT_B8G8R8A8_TYPELESS,
	DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
	DXGI_FORMAT_B8G8R8X8_TYPELESS,
	DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,
	DXGI_FORMAT_B5G6R5_UNORM,
	DXGI_FORMAT_B4G4R4A4_UNORM,
};

inline DXGI_FORMAT FormatToDXFormat(EPixelFormat pixel_fmt)
{
	UINT32 idx = (UINT)pixel_fmt;
	return gDX11FormatArray[idx];
}

inline EPixelFormat DXFormatToFormat(DXGI_FORMAT pixel_fmt)
{
	switch (pixel_fmt)
	{
	case DXGI_FORMAT_UNKNOWN:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_R32G32B32A32_TYPELESS:
		return PXF_R32G32B32A32_TYPELESS;
	case DXGI_FORMAT_R32G32B32A32_FLOAT:
		return PXF_R32G32B32A32_FLOAT;
	case DXGI_FORMAT_R32G32B32A32_UINT:
		return PXF_R32G32B32A32_UINT;
	case DXGI_FORMAT_R32G32B32A32_SINT:
		return PXF_R32G32B32A32_SINT;
	case DXGI_FORMAT_R32G32B32_TYPELESS:
		return PXF_R32G32B32_TYPELESS;
	case DXGI_FORMAT_R32G32B32_FLOAT:
		return PXF_R32G32B32_FLOAT;
	case DXGI_FORMAT_R32G32B32_UINT:
		return PXF_R32G32B32_UINT;
	case DXGI_FORMAT_R32G32B32_SINT:
		return PXF_R32G32B32_SINT;
	case DXGI_FORMAT_R16G16B16A16_TYPELESS:
		return PXF_R16G16B16A16_TYPELESS;
	case DXGI_FORMAT_R16G16B16A16_FLOAT:
		return PXF_R16G16B16A16_FLOAT;
	case DXGI_FORMAT_R16G16B16A16_UNORM:
		return PXF_R16G16B16A16_UNORM;
	case DXGI_FORMAT_R16G16B16A16_UINT:
		return PXF_R16G16B16A16_UINT;
	case DXGI_FORMAT_R16G16B16A16_SNORM:
		return PXF_R16G16B16A16_SNORM;
	case DXGI_FORMAT_R16G16B16A16_SINT:
		return PXF_R16G16B16A16_SINT;
	case DXGI_FORMAT_R32G32_TYPELESS:
		return PXF_R32G32_TYPELESS;
	case DXGI_FORMAT_R32G32_FLOAT:
		return PXF_R32G32_FLOAT;
	case DXGI_FORMAT_R32G32_UINT:
		return PXF_R32G32_UINT;
	case DXGI_FORMAT_R32G32_SINT:
		return PXF_R32G32_SINT;
	case DXGI_FORMAT_R32G8X24_TYPELESS:
		return PXF_R32G8X24_TYPELESS;
	case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
		return PXF_D32_FLOAT_S8X24_UINT;
	case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_R10G10B10A2_TYPELESS:
		return PXF_R10G10B10A2_TYPELESS;
	case DXGI_FORMAT_R10G10B10A2_UNORM:
		return PXF_R10G10B10A2_UNORM;
	case DXGI_FORMAT_R10G10B10A2_UINT:
		return PXF_R10G10B10A2_UINT;
	case DXGI_FORMAT_R11G11B10_FLOAT:
		return PXF_R11G11B10_FLOAT;
	case DXGI_FORMAT_R8G8B8A8_TYPELESS:
		return PXF_R8G8B8A8_TYPELESS;
	case DXGI_FORMAT_R8G8B8A8_UNORM:
		return PXF_R8G8B8A8_UNORM;
	case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
		return PXF_R8G8B8A8_UNORM_SRGB;
	case DXGI_FORMAT_R8G8B8A8_UINT:
		return PXF_R8G8B8A8_UINT;
	case DXGI_FORMAT_R8G8B8A8_SNORM:
		return PXF_R8G8B8A8_SNORM;
	case DXGI_FORMAT_R8G8B8A8_SINT:
		return PXF_R8G8B8A8_SINT;
	case DXGI_FORMAT_R16G16_TYPELESS:
		return PXF_R16G16_TYPELESS;
	case DXGI_FORMAT_R16G16_FLOAT:
		return PXF_R16G16_FLOAT;
	case DXGI_FORMAT_R16G16_UNORM:
		return PXF_R16G16_UNORM;
	case DXGI_FORMAT_R16G16_UINT:
		return PXF_R16G16_UINT;
	case DXGI_FORMAT_R16G16_SNORM:
		return PXF_R16G16_SNORM;
	case DXGI_FORMAT_R16G16_SINT:
		return PXF_R16G16_SINT;
	case DXGI_FORMAT_R32_TYPELESS:
		return PXF_R32_TYPELESS;
	case DXGI_FORMAT_D32_FLOAT:
		return PXF_D32_FLOAT;
	case DXGI_FORMAT_R32_FLOAT:
		return PXF_R32_FLOAT;
	case DXGI_FORMAT_R32_UINT:
		return PXF_R32_UINT;
	case DXGI_FORMAT_R32_SINT:
		return PXF_R32_SINT;
	case DXGI_FORMAT_R24G8_TYPELESS:
		return PXF_R24G8_TYPELESS;
	case DXGI_FORMAT_D24_UNORM_S8_UINT:
		return PXF_D24_UNORM_S8_UINT;
	case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
		return PXF_R24_UNORM_X8_TYPELESS;
	case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
		return PXF_X24_TYPELESS_G8_UINT;
	case DXGI_FORMAT_R8G8_TYPELESS:
		return PXF_R8G8_TYPELESS;
	case DXGI_FORMAT_R8G8_UNORM:
		return PXF_R8G8_UNORM;
	case DXGI_FORMAT_R8G8_UINT:
		return PXF_R8G8_UINT;
	case DXGI_FORMAT_R8G8_SNORM:
		return PXF_R8G8_SNORM;
	case DXGI_FORMAT_R8G8_SINT:
		return PXF_R8G8_SINT;
	case DXGI_FORMAT_R16_TYPELESS:
		return PXF_R16_TYPELESS;
	case DXGI_FORMAT_R16_FLOAT:
		return PXF_R16_FLOAT;
	case DXGI_FORMAT_D16_UNORM:
		return PXF_D16_UNORM;
	case DXGI_FORMAT_R16_UNORM:
		return PXF_R16_UNORM;
	case DXGI_FORMAT_R16_UINT:
		return PXF_R16_UINT;
	case DXGI_FORMAT_R16_SNORM:
		return PXF_R16_SNORM;
	case DXGI_FORMAT_R16_SINT:
		return PXF_R16_SINT;
	case DXGI_FORMAT_R8_TYPELESS:
		return PXF_R8_TYPELESS;
	case DXGI_FORMAT_R8_UNORM:
		return PXF_R8_UNORM;
	case DXGI_FORMAT_R8_UINT:
		return PXF_R8_UINT;
	case DXGI_FORMAT_R8_SNORM:
		return PXF_R8_SNORM;
	case DXGI_FORMAT_R8_SINT:
		return PXF_R8_SINT;
	case DXGI_FORMAT_A8_UNORM:
		return PXF_A8_UNORM;
	case DXGI_FORMAT_R1_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_R8G8_B8G8_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_G8R8_G8B8_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC1_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC1_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC1_UNORM_SRGB:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC2_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC2_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC2_UNORM_SRGB:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC3_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC3_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC3_UNORM_SRGB:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC4_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC4_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC4_SNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC5_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC5_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC5_SNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_B5G5R5A1_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_B8G8R8A8_UNORM:
		return PXF_B8G8R8A8_UNORM;
	case DXGI_FORMAT_B8G8R8X8_UNORM:
		return PXF_B8G8R8X8_UNORM;
	case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_B8G8R8A8_TYPELESS:
		return PXF_B8G8R8A8_TYPELESS;
	case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
		return PXF_B8G8R8A8_UNORM_SRGB;
	case DXGI_FORMAT_B8G8R8X8_TYPELESS:
		return PXF_B8G8R8X8_TYPELESS;
	case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
		return PXF_B8G8R8X8_UNORM_SRGB;
	case DXGI_FORMAT_BC6H_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC6H_UF16:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC6H_SF16:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC7_TYPELESS:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC7_UNORM:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_BC7_UNORM_SRGB:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_AYUV:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_Y410:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_Y416:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_NV12:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_P010:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_P016:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_420_OPAQUE:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_YUY2:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_Y210:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_Y216:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_NV11:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_AI44:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_IA44:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_P8:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_A8P8:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_B4G4R4A4_UNORM:
		return PXF_B4G4R4A4_UNORM;
	case DXGI_FORMAT_B5G6R5_UNORM:
		return PXF_B5G6R5_UNORM;
	case DXGI_FORMAT_P208:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_V208:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_V408:
		return PXF_UNKNOWN;
	case DXGI_FORMAT_FORCE_UINT:
		return PXF_UNKNOWN;
	default:
		return PXF_UNKNOWN;
	}
}

inline D3D11_TEXTURE_ADDRESS_MODE AddressModeToDX(EAddressMode mode)
{
	switch (mode)
	{
	case ADM_WRAP:
		return D3D11_TEXTURE_ADDRESS_WRAP;
	case ADM_MIRROR:
		return D3D11_TEXTURE_ADDRESS_MIRROR;
	case ADM_CLAMP:
		return D3D11_TEXTURE_ADDRESS_CLAMP;
	case ADM_BORDER:
		return D3D11_TEXTURE_ADDRESS_BORDER;
	case ADM_MIRROR_ONCE:
		return D3D11_TEXTURE_ADDRESS_MIRROR_ONCE;
	}
	return D3D11_TEXTURE_ADDRESS_WRAP;
}

inline D3D11_FILTER FilterToDX(ESamplerFilter fiter)
{
	return (D3D11_FILTER)fiter;
}

inline D3D11_COMPARISON_FUNC CmpModeToDX(EComparisionMode cmp)
{
	switch (cmp)
	{
	case CMP_NEVER:
		return D3D11_COMPARISON_NEVER;
	case CMP_LESS:
		return D3D11_COMPARISON_LESS;
	case CMP_EQUAL:
		return D3D11_COMPARISON_EQUAL;
	case CMP_LESS_EQUAL:
		return D3D11_COMPARISON_LESS_EQUAL;
	case CMP_GREATER:
		return D3D11_COMPARISON_GREATER;
	case CMP_NOT_EQUAL:
		return D3D11_COMPARISON_NOT_EQUAL;
	case CMP_GREATER_EQUAL:
		return D3D11_COMPARISON_GREATER_EQUAL;
	case CMP_ALWAYS:
		return D3D11_COMPARISON_ALWAYS;
	}
	return D3D11_COMPARISON_NEVER;
}

inline D3D_PRIMITIVE_TOPOLOGY PrimitiveTypeToDX(EPrimitiveType type, UINT NumPrimitives, UINT* pCount)
{
	switch (type)
	{
	case EPT_LineList:
		*pCount = NumPrimitives * 2;
		return D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
	case EPT_TriangleList:
		*pCount = NumPrimitives * 3;
		return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	case EPT_TriangleStrip:
		*pCount = NumPrimitives + 2;
		return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
	}
	return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

NS_END