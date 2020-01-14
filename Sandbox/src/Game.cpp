#include "Game.h"

#include <string>
#include <er/graphics/Sprite.h>

using namespace er;

Game::Game()
	: Application("Sandbox")
{
	m_Entity = new Entity(vec2(0, 0), Sprite("res/test.bmp"));
}

Game::~Game()
{

}

void Game::OnUpdate(const Timestep& ts)
{
	//if (Input::GetInputManager()->IsKeyPressed(VK_W))

	m_Entity->Update(ts);
}

void Game::OnTick()
{
	printf("FPS: %d, UPS: %d\n", m_FPS, m_UPS);
}

void Game::OnRender(Renderer& renderer)
{
	m_Entity->Render(renderer);

	renderer.Render();
}

int main()
{
	Game game;
	game.Start();
	return 0;
}