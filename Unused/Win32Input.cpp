#include "er/erpch.h"
/*#include "er/app/Input.h"

#include <Windows.h>

namespace er {

	extern HWND hWnd;

	InputManager* Input::s_InputManager = nullptr;

	InputManager::InputManager()
	{
		ClearKeys();
		ClearMouseButtons();

		m_MouseGrabbed = true;

		Input::s_InputManager = this;
	}

	void InputManager::Update()
	{
		for (int32 i = 0; i < MAX_BUTTONS; i++)
			m_MouseClicked[i] = m_MouseButtons[i] && !m_MouseState[i];

		memcpy(m_LastKeyState, m_KeyState, MAX_KEYS);
		memcpy(m_MouseState, m_MouseButtons, MAX_BUTTONS);

		POINT mouse;
		GetCursorPos(&mouse);
		ScreenToClient(hWnd, &mouse);

		if (mouse.x != m_MousePos.x || mouse.y != m_MousePos.y)
		{
			m_MousePos.x = mouse.x;
			m_MousePos.y = mouse.y;
		}
	}

	void InputManager::ClearKeys()
	{
		for (int32 i = 0; i < MAX_KEYS; i++)
		{
			m_KeyState[i] = false;
			m_LastKeyState[i] = false;
		}
		m_KeyModifiers = 0;
	}

	void InputManager::ClearMouseButtons()
	{
		for (int32 i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
			m_MouseState[i] = false;
			m_MouseClicked[i] = false;
		}
	}

	bool InputManager::IsKeyPressed(uint keycode) const
	{
		// TODO: Log this!
		if (keycode >= MAX_KEYS)
			return false;

		return m_KeyState[keycode];
	}

	bool InputManager::IsMouseButtonPressed(uint button) const
	{
		// TODO: Log this!
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button];
	}

	bool InputManager::IsMouseButtonClicked(uint button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseClicked[button];
	}

	const vec2& InputManager::GetMousePosition() const
	{
		return m_MousePos;
	}

	const bool InputManager::IsMouseGrabbed() const
	{
		return m_MouseGrabbed;
	}

	void InputManager::SetMouseGrabbed(bool grabbed)
	{
		m_MouseGrabbed = grabbed;
	}

	void KeyCallback(InputManager* inputManager, int32 flags, int32 key, uint message)
	{
		bool pressed = message == WM_KEYDOWN || message == WM_SYSKEYDOWN;
		inputManager->m_KeyState[key] = pressed;

		bool repeat = (flags >> 30) & 1;

		int32 modifier = 0;
		switch (key)
		{
		case VK_CONTROL:
			modifier = MODIFIER_LEFT_CONTROL;
			break;
		case VK_MENU:
			modifier = MODIFIER_LEFT_ALT;
			break;
		case VK_SHIFT:
			modifier = MODIFIER_LEFT_SHIFT;
			break;
		}

		if (pressed)
			inputManager->m_KeyModifiers |= modifier;
		else
			inputManager->m_KeyModifiers &= ~(modifier);
	}

	void MouseButtonCallback(InputManager* inputManager, int32 button, int32 x, int32 y)
	{
		bool down = false;
		switch (button)
		{
		case WM_LBUTTONDOWN:
			SetCapture(hWnd);
			button = VK_LBUTTON;
			down = true;
			break;
		case WM_LBUTTONUP:
			ReleaseCapture();
			button = VK_LBUTTON;
			down = false;
			break;
		case WM_RBUTTONDOWN:
			SetCapture(hWnd);
			button = VK_RBUTTON;
			down = true;
			break;
		case WM_RBUTTONUP:
			ReleaseCapture();
			button = VK_RBUTTON;
			down = false;
			break;
		case WM_MBUTTONDOWN:
			SetCapture(hWnd);
			button = VK_MBUTTON;
			down = true;
			break;
		case WM_MBUTTONUP:
			ReleaseCapture();
			button = VK_MBUTTON;
			down = false;
			break;
		}
		inputManager->m_MouseButtons[button] = down;
		inputManager->m_MousePos.x = x;
		inputManager->m_MousePos.y = y;
	}
}*/