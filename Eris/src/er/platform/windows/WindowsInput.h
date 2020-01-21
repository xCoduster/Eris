#pragma once

#include "er/app/Input.h"

namespace er {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(KeyCode keyCode) override;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
		virtual vec2 GetMousePosImpl() override;
	};

}