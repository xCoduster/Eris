#include "er/erpch.h"
#include "Window.h"

namespace er {

	Window::Window(std::string title)
		: m_Title(title), m_Handle(nullptr), m_Closed(false)
	{
		Init();

		m_InputManager = new InputManager();
	}

	Window::~Window()
	{
		delete(m_InputManager);
	}

	void Window::Update()
	{
		PlatformUpdate();
	}

	bool Window::Init()
	{
		PlatformInit();
		return true;
	}

	bool Window::Closed() const
	{
		return m_Closed;
	}

	std::map<void*, Window*> Window::s_Handles;

	void Window::RegisterWindowClass(void* handle, Window* window)
	{
		s_Handles[handle] = window;
	}

	Window* Window::GetWindowClass(void* handle)
	{
		return s_Handles[handle];
	}

}