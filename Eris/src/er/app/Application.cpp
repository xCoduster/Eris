#include "er/erpch.h"
#include "Application.h"

#include "er/Log.h"
#include "er/utils/Timer.h"

#include "Input.h"

#include <glad/glad.h>

namespace er {

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& title)
	{
		ER_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		Log::Init();
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(ER_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

		uint indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
	
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));
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
		Timestep timestep(m_Timer.ElapsedMillis());

		while (m_Running)
		{
			//m_Renderer->ClearWindow();
			float now = m_Timer.ElapsedMillis();
			if (now - updateTimer > updateTick)
			{
				timestep.Update(now);
				//OnUpdate(timestep);

				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);

				updates++;
				updateTimer += updateTick;
			}
			m_Window->OnUpdate();
			{
				Timer frametime;
				//OnRender(*m_Renderer);
				glClearColor(0.1f, 0.1f, 0.1f, 1);
				glClear(GL_COLOR_BUFFER_BIT);

				m_Shader->Bind();
				glBindVertexArray(m_VertexArray);
				glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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
				OnTick();
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}