#pragma once

#include <Eris.h>

class Entity
{
private:
	er::vec2 m_Position, m_Size;
	er::Sprite m_Sprite;
public:
	Entity(er::vec2 position, er::Sprite sprite);

	void Update(const er::Timestep& ts);
	void Render(er::Renderer& renderer);
};