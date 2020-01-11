#pragma once

#include <Eris.h>

class Game : public er::Application
{
public:
	Game();
	~Game();

	virtual void OnUpdate(const er::Timestep& ts) override;
	virtual void OnTick() override;
	virtual void OnRender(er::Renderer& renderer) override;
};