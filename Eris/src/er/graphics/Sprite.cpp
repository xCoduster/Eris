#include "er/erpch.h"
#include "Sprite.h"

#include "Renderer.h"

namespace er {

	Sprite::Sprite(std::string filePath)
	{
		m_BMPProps = LoadBMP(filePath);
		m_Props.size = m_BMPProps.size;
		m_Props.pixels = m_BMPProps.pixels;
	}

	void Sprite::Render(Renderer& renderer, vec2 position)
	{
		renderer.DrawSprite(*this, position);
	}
}