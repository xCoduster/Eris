#pragma once

#include "er/erpch.h"

#include "Window.h"
#include "Layer.h"
#include "LayerStack.h"

#include "er/utils/TimeStep.h"
#include "er/events/ApplicationEvent.h"
#include "er/ImGui/ImGuiLayer.h"

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
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
	protected:
		uint m_FPS, m_UPS;
		float m_Frametime;
	private:
		static Application* s_Instance;
	};
}