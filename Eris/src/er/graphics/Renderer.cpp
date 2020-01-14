#include "er/erpch.h"
#include "Renderer.h"

namespace er {

	Renderer::Renderer(Window* window)
	{
		m_Window = window;

		m_WindowSize = m_Window->GetSize();

		m_Pixels = (byte*)malloc(m_WindowSize.x * m_WindowSize.y * 4);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::DrawSprite(const Sprite& sprite, vec2 position)
	{
		SpriteProps props = sprite.GetProps();

		for (int32 y0 = 0; y0 < props.size.y; y0++)
		{
			for (int32 x0 = 0; x0 < props.size.x * 4; x0++)
			{
				m_Pixels[(position.x * 4 + x0) + (position.y + y0) * m_WindowSize.x * 4] = props.pixels[x0 + y0 * props.size.x * 4];
			}
		}
	}

	void Renderer::Render()
	{
		m_Window->Render(m_Pixels);
	}

	void Renderer::ClearWindow()
	{
		memset(m_Pixels, 0, m_WindowSize.x * m_WindowSize.y * 4);
	}

	void Renderer::OnUpdate(const Timestep& ts)
	{
		if (m_Window->GetSize() != m_WindowSize)
		{
			m_WindowSize = m_Window->GetSize();

			free(m_Pixels);
			m_Pixels = (byte*)malloc(m_WindowSize.x * m_WindowSize.y * 4);
		}
	}
}