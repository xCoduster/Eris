#pragma once

#include "er/app/Layer.h"
#include "er/events/KeyEvent.h"
#include "er/events/MouseEvent.h"
#include "er/events/ApplicationEvent.h"

namespace er {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	};

}