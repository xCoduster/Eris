#pragma once

#include <Eris.h>

#include "entities/Entity.h"

class Game : public er::Application
{
private:
	Entity* m_Entity;
public:
	Game();
	~Game();

	virtual void OnUpdate(const er::Timestep& ts) override;
	virtual void OnTick() override;
	virtual void OnRender(er::Renderer& renderer) override;
};