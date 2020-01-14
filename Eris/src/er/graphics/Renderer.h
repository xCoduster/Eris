#pragma once

#include "er/Types.h"
#include "er/maths/Math.h"

#include "er/app/Window.h"
#include "Sprite.h"

namespace er {

	class Renderer
	{
	private:
		Window* m_Window;
		byte* m_Pixels;

		vec2 m_WindowSize;
	public:
		Renderer(Window* window);
		~Renderer();

		void DrawSprite(const Sprite& sprite, vec2 position);

		void Render();
		void ClearWindow();
		void OnUpdate(const Timestep& ts);
	};
}