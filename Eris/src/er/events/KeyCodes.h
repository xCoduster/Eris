#pragma once

#include "er/erpch.h"

namespace er {

	typedef enum KeyCode : uint16
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32>(keyCode);
		return os;
	}
}

// From glfw3.h
#define ER_KEY_SPACE           ::Eris::Key::Space
#define ER_KEY_APOSTROPHE      ::Eris::Key::Apostrophe    /* ' */
#define ER_KEY_COMMA           ::Eris::Key::Comma         /* , */
#define ER_KEY_MINUS           ::Eris::Key::Minus         /* - */
#define ER_KEY_PERIOD          ::Eris::Key::Period        /* . */
#define ER_KEY_SLASH           ::Eris::Key::Slash         /* / */
#define ER_KEY_0               ::Eris::Key::D0
#define ER_KEY_1               ::Eris::Key::D1
#define ER_KEY_2               ::Eris::Key::D2
#define ER_KEY_3               ::Eris::Key::D3
#define ER_KEY_4               ::Eris::Key::D4
#define ER_KEY_5               ::Eris::Key::D5
#define ER_KEY_6               ::Eris::Key::D6
#define ER_KEY_7               ::Eris::Key::D7
#define ER_KEY_8               ::Eris::Key::D8
#define ER_KEY_9               ::Eris::Key::D9
#define ER_KEY_SEMICOLON       ::Eris::Key::Semicolon     /* ; */
#define ER_KEY_EQUAL           ::Eris::Key::Equal         /* = */
#define ER_KEY_A               ::Eris::Key::A
#define ER_KEY_B               ::Eris::Key::B
#define ER_KEY_C               ::Eris::Key::C
#define ER_KEY_D               ::Eris::Key::D
#define ER_KEY_E               ::Eris::Key::E
#define ER_KEY_F               ::Eris::Key::F
#define ER_KEY_G               ::Eris::Key::G
#define ER_KEY_H               ::Eris::Key::H
#define ER_KEY_I               ::Eris::Key::I
#define ER_KEY_J               ::Eris::Key::J
#define ER_KEY_K               ::Eris::Key::K
#define ER_KEY_L               ::Eris::Key::L
#define ER_KEY_M               ::Eris::Key::M
#define ER_KEY_N               ::Eris::Key::N
#define ER_KEY_O               ::Eris::Key::O
#define ER_KEY_P               ::Eris::Key::P
#define ER_KEY_Q               ::Eris::Key::Q
#define ER_KEY_R               ::Eris::Key::R
#define ER_KEY_S               ::Eris::Key::S
#define ER_KEY_T               ::Eris::Key::T
#define ER_KEY_U               ::Eris::Key::U
#define ER_KEY_V               ::Eris::Key::V
#define ER_KEY_W               ::Eris::Key::W
#define ER_KEY_X               ::Eris::Key::X
#define ER_KEY_Y               ::Eris::Key::Y
#define ER_KEY_Z               ::Eris::Key::Z
#define ER_KEY_LEFT_BRACKET    ::Eris::Key::LeftBracket   /* [ */
#define ER_KEY_BACKSLASH       ::Eris::Key::Backslash     /* \ */
#define ER_KEY_RIGHT_BRACKET   ::Eris::Key::RightBracket  /* ] */
#define ER_KEY_GRAVE_ACCENT    ::Eris::Key::GraveAccent   /* ` */
#define ER_KEY_WORLD_1         ::Eris::Key::World1        /* non-US #1 */
#define ER_KEY_WORLD_2         ::Eris::Key::World2        /* non-US #2 */

/* Function keys */
#define ER_KEY_ESCAPE          ::Eris::Key::Escape
#define ER_KEY_ENTER           ::Eris::Key::Enter
#define ER_KEY_TAB             ::Eris::Key::Tab
#define ER_KEY_BACKSPACE       ::Eris::Key::Backspace
#define ER_KEY_INSERT          ::Eris::Key::Insert
#define ER_KEY_DELETE          ::Eris::Key::Delete
#define ER_KEY_RIGHT           ::Eris::Key::Right
#define ER_KEY_LEFT            ::Eris::Key::Left
#define ER_KEY_DOWN            ::Eris::Key::Down
#define ER_KEY_UP              ::Eris::Key::Up
#define ER_KEY_PAGE_UP         ::Eris::Key::PageUp
#define ER_KEY_PAGE_DOWN       ::Eris::Key::PageDown
#define ER_KEY_HOME            ::Eris::Key::Home
#define ER_KEY_END             ::Eris::Key::End
#define ER_KEY_CAPS_LOCK       ::Eris::Key::CapsLock
#define ER_KEY_SCROLL_LOCK     ::Eris::Key::ScrollLock
#define ER_KEY_NUM_LOCK        ::Eris::Key::NumLock
#define ER_KEY_PRINT_SCREEN    ::Eris::Key::PrintScreen
#define ER_KEY_PAUSE           ::Eris::Key::Pause
#define ER_KEY_F1              ::Eris::Key::F1
#define ER_KEY_F2              ::Eris::Key::F2
#define ER_KEY_F3              ::Eris::Key::F3
#define ER_KEY_F4              ::Eris::Key::F4
#define ER_KEY_F5              ::Eris::Key::F5
#define ER_KEY_F6              ::Eris::Key::F6
#define ER_KEY_F7              ::Eris::Key::F7
#define ER_KEY_F8              ::Eris::Key::F8
#define ER_KEY_F9              ::Eris::Key::F9
#define ER_KEY_F10             ::Eris::Key::F10
#define ER_KEY_F11             ::Eris::Key::F11
#define ER_KEY_F12             ::Eris::Key::F12
#define ER_KEY_F13             ::Eris::Key::F13
#define ER_KEY_F14             ::Eris::Key::F14
#define ER_KEY_F15             ::Eris::Key::F15
#define ER_KEY_F16             ::Eris::Key::F16
#define ER_KEY_F17             ::Eris::Key::F17
#define ER_KEY_F18             ::Eris::Key::F18
#define ER_KEY_F19             ::Eris::Key::F19
#define ER_KEY_F20             ::Eris::Key::F20
#define ER_KEY_F21             ::Eris::Key::F21
#define ER_KEY_F22             ::Eris::Key::F22
#define ER_KEY_F23             ::Eris::Key::F23
#define ER_KEY_F24             ::Eris::Key::F24
#define ER_KEY_F25             ::Eris::Key::F25

/* Keypad */
#define ER_KEY_KP_0            ::Eris::Key::KP0
#define ER_KEY_KP_1            ::Eris::Key::KP1
#define ER_KEY_KP_2            ::Eris::Key::KP2
#define ER_KEY_KP_3            ::Eris::Key::KP3
#define ER_KEY_KP_4            ::Eris::Key::KP4
#define ER_KEY_KP_5            ::Eris::Key::KP5
#define ER_KEY_KP_6            ::Eris::Key::KP6
#define ER_KEY_KP_7            ::Eris::Key::KP7
#define ER_KEY_KP_8            ::Eris::Key::KP8
#define ER_KEY_KP_9            ::Eris::Key::KP9
#define ER_KEY_KP_DECIMAL      ::Eris::Key::KPDecimal
#define ER_KEY_KP_DIVIDE       ::Eris::Key::KPDivide
#define ER_KEY_KP_MULTIPLY     ::Eris::Key::KPMultiply
#define ER_KEY_KP_SUBTRACT     ::Eris::Key::KPSubtract
#define ER_KEY_KP_ADD          ::Eris::Key::KPAdd
#define ER_KEY_KP_ENTER        ::Eris::Key::KPEnter
#define ER_KEY_KP_EQUAL        ::Eris::Key::KPEqual

#define ER_KEY_LEFT_SHIFT      ::Eris::Key::LeftShift
#define ER_KEY_LEFT_CONTROL    ::Eris::Key::LeftControl
#define ER_KEY_LEFT_ALT        ::Eris::Key::LeftAlt
#define ER_KEY_LEFT_SUPER      ::Eris::Key::LeftSuper
#define ER_KEY_RIGHT_SHIFT     ::Eris::Key::RightShift
#define ER_KEY_RIGHT_CONTROL   ::Eris::Key::RightControl
#define ER_KEY_RIGHT_ALT       ::Eris::Key::RightAlt
#define ER_KEY_RIGHT_SUPER     ::Eris::Key::RightSuper
#define ER_KEY_MENU            ::Eris::Key::Menu