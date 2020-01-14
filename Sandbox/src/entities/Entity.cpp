#include "Entity.h"

using namespace er;

Entity::Entity(vec2 position, Sprite sprite)
	: m_Position(position), m_Sprite(sprite)
{
	
}

void Entity::Update(const Timestep& ts)
{

}

void Entity::Render(Renderer& renderer)
{
	renderer.DrawSprite(m_Sprite, m_Position);
}