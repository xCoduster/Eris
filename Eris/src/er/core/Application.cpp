#include "er/erpch.h"
#include "Application.h"

#include "er/utils/Timer.h"

#include "er/renderer/Renderer.h"

namespace er {

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& title)
	{
		ER_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		Log::Init();
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(ER_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Start()
	{
		m_Running = true;
		Run();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(ER_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(ER_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run()
	{
		Timer m_Timer;
		float timer = 0.0f;
		float updateTimer = m_Timer.ElapsedMillis();
		float updateTick = 1000.0f / 60.0f;
		uint frames = 0;
		uint updates = 0;
		Timestep timestep(m_Timer.Elapsed());

		while (m_Running)
		{
			float now = m_Timer.ElapsedMillis();
			if (now - updateTimer > updateTick)
			{
				timestep.Update(now / 1000.0f);

				if (!m_Minimized)
				{
					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}

				updates++;
				updateTimer += updateTick;
			}
			m_Window->OnUpdate();
			{
				Timer frametime;

				if (!m_Minimized)
				{
					for (Layer* layer : m_LayerStack)
						layer->OnRender();
				}

				m_ImGuiLayer->Begin();
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
				m_ImGuiLayer->End();

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
				
				for (Layer* layer : m_LayerStack)
					layer->OnTick();

				ER_CORE_TRACE("FPS: {0}, UPS: {1}", m_FPS, m_UPS);
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetSize().x == 0.0f || e.GetSize().y == 0.0f)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		RenderCommand::SetViewPort(0, 0, (uint)e.GetSize().x, (uint)e.GetSize().y);
		return false;
	}
}