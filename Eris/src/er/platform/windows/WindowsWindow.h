#pragma once

#include "er/app/Window.h"
#include "er/renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace er {

	class WindowsWindow : public Window
	{
	
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline const vec2& GetSize() const { return m_Data.Size; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			vec2 Size;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};


}