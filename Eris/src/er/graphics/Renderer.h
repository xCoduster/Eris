#pragma once

#include "er/app/Window.h"
#include "Sprite.h"

namespace er {

	class Renderer
	{
	private:
		Window* m_Window;
		byte* m_Pixels;

		uint m_Width, m_Height;
	public:
		Renderer(Window* window);
		~Renderer();

		void DrawSprite(const Sprite& sprite);

		void Render();
		void ClearWindow();
		void OnUpdate(const Timestep& ts);
	};
}