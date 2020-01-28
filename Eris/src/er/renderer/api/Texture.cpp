#include "er/erpch.h"
#include "Texture.h"

#include "er/renderer/Renderer.h"
#include "er/platform/OpenGL/OpenGLTexture.h"

namespace er {

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: ER_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
		}

		ER_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}