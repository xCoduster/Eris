#pragma once

#include "er/Types.h"
#include "er/maths/Math.h"

namespace er {

#define MAX_KEYS	1024
#define MAX_BUTTONS 32

	class InputManager
	{
	private:
		bool m_KeyState[MAX_KEYS];
		bool m_LastKeyState[MAX_KEYS];

		bool m_MouseButtons[MAX_BUTTONS];
		bool m_MouseState[MAX_BUTTONS];
		bool m_MouseClicked[MAX_BUTTONS];
		bool m_MouseGrabbed;
		int32 m_KeyModifiers;

		vec2 m_MousePos;
	public:
		InputManager();

		void Update();

		bool IsKeyPressed(uint keycode) const;
		bool IsMouseButtonPressed(uint button) const;
		bool IsMouseButtonClicked(uint button) const;

		const vec2& GetMousePosition() const;
		void SetMousePosition(vec2 position);
		const bool IsMouseGrabbed() const;
		void SetMouseGrabbed(bool grabbed);

		void ClearKeys();
		void ClearMouseButtons();
	private:
		friend void KeyCallback(InputManager* inputManager, int32 flags, int32 key, uint message);
		friend void MouseButtonCallback(InputManager* inputManager, int32 button, int32 x, int32 y);
	};

	class Input
	{
	private:
		friend class InputManager;
	private:
		static InputManager* s_InputManager;
	public:
		inline static bool IsKeyPressed(uint keycode) { return s_InputManager->IsKeyPressed(keycode); }
		inline static bool IsMouseButtonPressed(uint button) { return s_InputManager->IsMouseButtonPressed(button); }
		inline static bool IsMouseButtonClicked(uint button) { return s_InputManager->IsMouseButtonClicked(button); }

		inline static const vec2& GetMousePosition() { return s_InputManager->GetMousePosition(); }

		inline static InputManager* GetInputManager() { return s_InputManager; }
	};
}

#define MODIFIER_LEFT_CONTROL	BIT(0)
#define MODIFIER_LEFT_ALT		BIT(1)
#define MODIFIER_LEFT_SHIFT		BIT(2)
#define MODIFIER_RIGHT_CONTROL	BIT(3)
#define MODIFIER_RIGHT_ALT		BIT(4)
#define MODIFIER_RIGHT_SHIFT	BIT(5)

#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A