#include "er/erpch.h"
#include "Application.h"

#include "er/utils/Timer.h"

namespace er {

	Application::Application(const std::string& title)
	{
		m_Window = new Window(title);
		m_Renderer = new Renderer(m_Window);
	}

	Application::~Application()
	{
		delete(m_Renderer);
		delete(m_Window);
	}

	void Application::Start()
	{
		m_Running = true;
		Run();
	}

	void Application::Run()
	{
		Timer m_Timer;
		float timer = 0.0f;
		float updateTimer = m_Timer.ElapsedMillis();
		float updateTick = 1000.0f / 60.0f;
		uint frames = 0;
		uint updates = 0;
		Timestep timestep(m_Timer.ElapsedMillis());

		while (m_Running)
		{
			m_Renderer->ClearWindow();
			float now = m_Timer.ElapsedMillis();
			if (now - updateTimer > updateTick)
			{
				timestep.Update(now);
				OnUpdate(timestep);
				updates++;
				updateTimer += updateTick;
			}
			m_Window->Update();
			{
				Timer frametime;
				OnRender(*m_Renderer);
				frames++;
				m_Frametime = frametime.ElapsedMillis();
			}
			if (m_Timer.Elapsed() - timer > 1.0f)
			{
				timer += 1.0f;
				m_FPS = frames;
				m_UPS = updates;
				frames = 0;
				updates = 0;
				OnTick();
			}

			if (m_Window->Closed())
				m_Running = false;
		}
	}
}