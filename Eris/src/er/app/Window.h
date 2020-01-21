#pragma once

#include "er/erpch.h"

#include "er/events/Event.h"

namespace er {

	struct WindowProps
	{
		std::string Title;
		vec2 Size;

		WindowProps(std::string title = "Eris Application", 
					unsigned int width = 1280, 
					unsigned int height = 720)
			: Title(title), Size(vec2(1280, 720))
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual const vec2& GetSize() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}