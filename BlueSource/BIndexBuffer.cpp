#include "BIndexBuffer.h"

namespace blue::graphics
{
	IndexBuffer::IndexBuffer()
	{
	}

	IndexBuffer::~IndexBuffer()
	{
	}

	bool IndexBuffer::Create(const std::vector<UINT>& indices)
	{
		desc.ByteWidth = sizeof(UINT) * (UINT)indices.size();
		desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_INDEX_BUFFER;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA sub = {};
		sub.pSysMem = indices.data();

		if (!GetDevice()->CreateBuffer(&desc, &sub, buffer.GetAddressOf()))
			assert(NULL && "Create indices buffer failed");

		return true;
	}

	void IndexBuffer::Bind() const
	{
		GetDevice()->BindIndexBuffer(buffer.Get(), DXGI_FORMAT_R32_UINT, 0);
	}
}