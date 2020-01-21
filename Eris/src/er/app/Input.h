#pragma once

#include "er/events/KeyCodes.h"
#include "er/events/MouseCodes.h"

namespace er {

	class Input
	{
	public:
		inline static bool IsKeyPressed(KeyCode keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }

		inline static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static vec2 GetMousePos() { return s_Instance->GetMousePosImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(KeyCode keyCode) = 0;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
		virtual vec2 GetMousePosImpl() = 0;
	private:
		static Input* s_Instance;
	};

}