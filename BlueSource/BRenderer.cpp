#include "BRenderer.h"
#include "BGraphicDevice_DX11.h"

#include "BResources.h"
#include "BShader.h"

namespace blue::renderer
{
	Camera* mainCamera = nullptr;

	std::vector<graphics::Vertex> vertices = {};
	std::vector<UINT> indices;

	//graphics::VertexBuffer vertexBuffer;
	//graphics::IndexBuffer indexBuffer;
	Mesh* mesh = nullptr;

	graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End] = {};

	ID3D11Buffer* constantBuffer = nullptr;
	ID3D11InputLayout* inputLayouts = nullptr;

	void LoadTriangleMesh()
	{
		mesh = new Mesh();

		renderer::vertices.resize(3);
		renderer::vertices[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		renderer::vertices[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		renderer::vertices[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		renderer::vertices[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		renderer::vertices[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		renderer::vertices[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		mesh->CreateVB(vertices);
		mesh->CreateIB(indices);
	}

	void LoadMeshes()
	{
		LoadTriangleMesh();
	}

	void LoadShaders()
	{
		blue::Resources::Load<graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");
	}

	void LoadConstantBuffers()
	{
		constantBuffers[(UINT)eCBType::Transform].Create(eCBType::Transform, sizeof(Vector4));
	}

	void Initialize()
	{
		LoadMeshes();
		LoadShaders();
		LoadConstantBuffers();
	}

	void Release()
	{
		inputLayouts->Release();
		delete mesh;
	}
}