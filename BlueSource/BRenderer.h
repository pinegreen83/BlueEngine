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

	void Initialize();
	void Release();
}
