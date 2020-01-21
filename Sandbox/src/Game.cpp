#include <Eris.h>

#include <imgui/imgui.h>

using namespace er;

class Test2D : public Layer
{
public:
	Test2D()
		: Layer("Test")
	{
	}

	virtual void OnUpdate(const Timestep& ts) override
	{

	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Working");
		ImGui::End();
	}

	virtual void OnEvent(Event& event) override
	{

	}
};

class Game : public Application
{
public:
	Game()
		: Application("Sandbox")
	{
		PushLayer(new Test2D());
	}

	~Game()
	{

	}
};

int main()
{
	Game game;
	game.Start();
	return 0;
}