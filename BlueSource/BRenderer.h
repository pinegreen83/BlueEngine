#pragma once
#include "BCamera.h"
#include "BGraphicDevice_DX11.h"

#include "BMesh.h"

#include "BConstantBuffer.h"

using namespace blue::math;
using namespace blue::graphics;

namespace blue::renderer
{
	extern Camera* mainCamera;

	extern std::vector<graphics::Vertex> vertices;
	extern std::vector<UINT> indices;

	//extern graphics::VertexBuffer vertexBuffer;
	//extern graphics::IndexBuffer indexBuffer;
	extern Mesh* mesh;

	extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}
