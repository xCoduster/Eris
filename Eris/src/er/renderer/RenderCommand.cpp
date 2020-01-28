#include "er/erpch.h"
#include "RenderCommand.h"

#include "er/platform/OpenGL/OpenGLRendererAPI.h"

namespace er {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}