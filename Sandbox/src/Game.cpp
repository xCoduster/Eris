#include "Game.h"

#include <string>

using namespace er;

Game::Game()
	: Application("Sandbox")
{

}

Game::~Game()
{

}

void Game::OnUpdate(const Timestep& ts)
{

}

void Game::OnTick()
{

}

void Game::OnRender(Renderer& renderer)
{

}

int main()
{
	Game game;
	game.Start();
	return 0;
}