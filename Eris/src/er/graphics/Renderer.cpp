#include "er/erpch.h"
#include "Renderer.h"

namespace er {

	Renderer::Renderer(Window* window)
	{
		m_Window = window;

		m_Width = m_Window->GetWidth();
		m_Height = m_Window->GetHeight();

		m_Pixels = (byte*)malloc(m_Width * m_Height * 4);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::DrawSprite(const Sprite& sprite)
	{
		SpriteProps props = sprite.GetProps();
		uint x = props.x;
		uint y = props.y;

		for (uint y0 = 0; y0 < props.height; y0++)
		{
			for (uint x0 = 0; x0 < props.width * 4; x0++)
			{
				m_Pixels[(x * 4 + x0) + (y + y0) * m_Width * 4] = props.pixels[x0 + y0 * props.width * 4];
			}
		}
	}

	void Renderer::Render()
	{
		m_Window->Render(m_Pixels);
	}

	void Renderer::ClearWindow()
	{
		memset(m_Pixels, 0, m_Width * m_Height * 4);
	}

	void Renderer::OnUpdate(const Timestep& ts)
	{
		if (m_Window->GetWidth() != m_Width || m_Window->GetHeight() != m_Height)
		{
			m_Width = m_Window->GetWidth();
			m_Height = m_Window->GetHeight();

			free(m_Pixels);
			m_Pixels = (byte*)malloc(m_Width * m_Height * 4);
		}
	}
}