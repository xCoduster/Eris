#pragma once

#include "Window.h"
#include "er/graphics/Renderer.h"
#include "er/utils/TimeStep.h"

namespace er {

	class Application
	{
	private:
		Window* m_Window;
		Renderer* m_Renderer;

		bool m_Running;
		uint m_FPS, m_UPS;
		float m_Frametime;
	public:
		Application(const std::string& title);
		~Application();

		void Start();
	private:
		void Run();

		virtual void OnUpdate(const Timestep& ts) {};	// Gets called 60 times per second
		virtual void OnTick() {};						// Gets called once per second
		virtual void OnRender(Renderer& renderer) {};
	};
}