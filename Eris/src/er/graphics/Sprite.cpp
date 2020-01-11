#include "er/erpch.h"
#include "Sprite.h"

#include "Renderer.h"

namespace er {

	Sprite::Sprite(int32 x, int32 y, std::string filePath)
	{
		m_BMPProps = LoadBMP(filePath);
		m_Props.x = x;
		m_Props.y = y;
		m_Props.width = m_BMPProps.width;
		m_Props.height = m_BMPProps.height;
		m_Props.pixels = m_BMPProps.pixels;
	}

	void Sprite::OnRender(Renderer& renderer)
	{
		renderer.DrawSprite(*this);
	}
}