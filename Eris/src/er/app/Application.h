#pragma once

#include "er/erpch.h"

#include "Window.h"
#include "Layer.h"
#include "LayerStack.h"

#include "er/graphics/Renderer.h"

#include "er/utils/TimeStep.h"
#include "er/events/ApplicationEvent.h"
#include "er/ImGui/ImGuiLayer.h"

#include "er/renderer/Shader.h"

namespace er {

	class Application
	{
	public:
		Application(const std::string& title);
		~Application();

		void Start();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() const { return *m_Window; }
		
		static inline Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		virtual void OnUpdate(const Timestep& ts) {};	// Gets called 60 times per second
		virtual void OnTick() {};						// Gets called once per second
		virtual void OnRender(Renderer& renderer) {};
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running;
		LayerStack m_LayerStack;
		Renderer* m_Renderer;

		uint m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	protected:
		uint m_FPS, m_UPS;
		float m_Frametime;
	private:
		static Application* s_Instance;
	};
}