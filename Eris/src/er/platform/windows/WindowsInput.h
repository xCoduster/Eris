#pragma once

#include "er/core/Input.h"

namespace er {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(KeyCode keyCode) override;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
		virtual glm::vec2 GetMousePosImpl() override;
	};

}