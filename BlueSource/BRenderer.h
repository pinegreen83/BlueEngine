#pragma once
#include "BCamera.h"
#include "BGraphicDevice_DX11.h"

#include "BConstantBuffer.h"

using namespace blue::math;
using namespace blue::graphics;

namespace blue::renderer
{
	extern Camera* mainCamera;
	extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerStates[(UINT)eSamplerType::End];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRasterizerState::End];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBlendState::End];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDepthStencilState::End];

	void Initialize();
	void Release();
}
