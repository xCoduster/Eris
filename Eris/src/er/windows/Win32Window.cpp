#include "er/erpch.h"
#include "er/app/Window.h"

#include <Windows.h>
#include <Windowsx.h>

#include "er/app/Input.h"

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

namespace er {

	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HINSTANCE hInstance;
	HDC hDc;
	HWND hWnd;

	static PIXELFORMATDESCRIPTOR GetPixelFormat()
	{
		PIXELFORMATDESCRIPTOR result = {};
		result.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		result.nVersion = 1;
		result.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DRAW_TO_BITMAP | PFD_DOUBLEBUFFER;
		result.iPixelType = PFD_TYPE_RGBA;
		result.cColorBits = 32;
		result.dwVisibleMask = RGB(0, 0, 0);
		return result;
	}

	bool Window::PlatformInit()
	{
		hInstance = (HINSTANCE)&__ImageBase;

		WNDCLASS wc = { };

		wc.lpfnWndProc = (WNDPROC)WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = L"Eris Win32 Window";
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);

		RegisterClass(&wc);

		LPWSTR title = L"";
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, m_Title.c_str(), -1, title, 0);

		hWnd = CreateWindowEx(
			0,								// Optional window styles
			wc.lpszClassName,				// Window class
			title,							// Window text
			WS_POPUP | WS_VISIBLE,			// Window style

			// Position and Size
			0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),

			NULL,		// Parent window
			NULL,		// Menu
			hInstance,	// Instance handle
			NULL		// Additional application data
		);

		if (hWnd == NULL)
			return false;

		RegisterWindowClass(hWnd, this);

		hDc = GetDC(hWnd);
		PIXELFORMATDESCRIPTOR pfd = GetPixelFormat();
		int32 pixelFormat = ChoosePixelFormat(hDc, &pfd);
		SetPixelFormat(hDc, pixelFormat, &pfd);

		ShowWindow(hWnd, SW_SHOW);
		SetFocus(hWnd);

		RECT rect;
		GetWindowRect(hWnd, &rect);
		ResizeCallback(this, rect.right, rect.bottom);

		return true;
	}

	void Window::PlatformUpdate()
	{
		MSG msg = { };
		while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_Closed = true;
				return;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		m_InputManager->Update();
	}

	/*void Window::Render(uint* pixels)
	{
		BITMAPINFO info;
		ZeroMemory(&info, sizeof(BITMAPINFO));
		info.bmiHeader.biBitCount = 32;
		info.bmiHeader.biWidth = m_Properties.width;
		info.bmiHeader.biHeight = -(int)(m_Properties.height);
		info.bmiHeader.biPlanes = 1;
		info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		info.bmiHeader.biSizeImage = m_Properties.width * m_Properties.height * 4;
		info.bmiHeader.biCompression = BI_RGB;


		//SetDIBitsToDevice(dc, 0, 0, m_Properties.width, m_Properties.height, 0, 0, 0, m_Properties.height, pixels, &info, DIB_RGB_COLORS);
		StretchDIBits(hDc, 0, 0, m_Properties.width, m_Properties.height, 0, 0, m_Properties.width, m_Properties.height, pixels, &info, DIB_RGB_COLORS, SRCCOPY);
	}*/

	void Window::Render(byte* pixels)
	{
		HBITMAP map = CreateBitmap(m_Properties.width, m_Properties.height, 1, 32, pixels);

		HDC src = CreateCompatibleDC(hDc);
		SelectObject(src, map);
		BitBlt(hDc, 0, 0, m_Properties.width, m_Properties.height, src, 0, 0, SRCCOPY);

		DeleteObject(map);
		DeleteDC(src);
	}

	void ResizeCallback(Window* window, int32 width, int32 height)
	{
		window->m_Properties.width = width;
		window->m_Properties.height = height;
	}

	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = NULL;
		Window* window = Window::GetWindowClass(hWnd);
		if (window == nullptr)
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		InputManager* inputManager = window->GetInputManager();
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_SIZE:
			ResizeCallback(window, LOWORD(lParam), HIWORD(lParam));
			break;
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			KeyCallback(inputManager, (int32)lParam, (int32)wParam, uMsg);
			break;
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
			MouseButtonCallback(inputManager, uMsg, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;
		default:
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}

		return result;
	}
}