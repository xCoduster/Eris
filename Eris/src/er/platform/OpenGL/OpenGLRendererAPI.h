#pragma once

#include "er/renderer/RendererAPI.h"

namespace er {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;

		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void SetViewPort(uint x, uint y, uint width, uint height) override;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};

}