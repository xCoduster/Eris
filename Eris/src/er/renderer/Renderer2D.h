#pragma once

#include "RenderCommand.h"

#include "Camera.h"
#include "Texture.h"

#include <glm/glm.hpp>

namespace er {

	class Renderer2D
	{
	public:
		static void Init();

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void DrawQuad(glm::vec2 position, glm::vec2 size, Texture texture);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}