#pragma once

#include "er/erpch.h"

namespace er {

	typedef enum MouseCode : uint16
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32>(mouseCode);
		return os;
	}
}

#define ER_MOUSE_BUTTON_0      ::Eris::Mouse::Button0
#define ER_MOUSE_BUTTON_1      ::Eris::Mouse::Button1
#define ER_MOUSE_BUTTON_2      ::Eris::Mouse::Button2
#define ER_MOUSE_BUTTON_3      ::Eris::Mouse::Button3
#define ER_MOUSE_BUTTON_4      ::Eris::Mouse::Button4
#define ER_MOUSE_BUTTON_5      ::Eris::Mouse::Button5
#define ER_MOUSE_BUTTON_6      ::Eris::Mouse::Button6
#define ER_MOUSE_BUTTON_7      ::Eris::Mouse::Button7
#define ER_MOUSE_BUTTON_LAST   ::Eris::Mouse::ButtonLast
#define ER_MOUSE_BUTTON_LEFT   ::Eris::Mouse::ButtonLeft
#define ER_MOUSE_BUTTON_RIGHT  ::Eris::Mouse::ButtonRight
#define ER_MOUSE_BUTTON_MIDDLE ::Eris::Mouse::ButtonMiddle