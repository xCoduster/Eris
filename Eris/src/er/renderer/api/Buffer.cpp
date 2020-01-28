#include "er/erpch.h"
#include "Buffer.h"

#include "er/renderer/Renderer.h"
#include "er/platform/OpenGL/OpenGLBuffer.h"

namespace er {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: ER_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		}

		ER_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint* indices, uint size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: ER_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLIndexBuffer>(indices, size);
		}

		ER_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}