#include "er/erpch.h"
#include "VertexArray.h"

#include "er/renderer/Renderer.h"

#include "er/platform/OpenGL/OpenGLVertexArray.h"

namespace er {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: ER_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>();
		}

		ER_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}