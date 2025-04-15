#pragma once
#include "BGraphicDevice_DX11.h"

namespace blue::graphics
{
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		virtual ~VertexBuffer();

		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();

	private:
	};

}
