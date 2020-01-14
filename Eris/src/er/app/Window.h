#pragma once

#include <map>
#include "er/Types.h"
#include "er/maths/Math.h"

#include "Input.h"

namespace er {

	struct WindowProperties
	{
		vec2 size;
		bool fullscreen;
		bool vsync;
	};

	class Window
	{
	private:
		static std::map<void*, Window*> s_Handles;
	private:
		std::string m_Title;
		WindowProperties m_Properties;
		bool m_Closed;
		void* m_Handle;

		InputManager* m_InputManager;
	public:
		Window(std::string title);
		~Window();

		void Update();
		void Render(byte* pixels); // Renders a provided array of pixels

		bool Closed() const;

		inline const vec2& GetSize() const { return m_Properties.size; }

		inline InputManager* GetInputManager() const { return m_InputManager; }
	private:
		bool Init();

		bool PlatformInit();
		void PlatformUpdate();

		friend void ResizeCallback(Window* window, int32 width, int32 height);
	public:
		static void RegisterWindowClass(void* handle, Window* window);
		static Window* GetWindowClass(void* handle);
	};

}