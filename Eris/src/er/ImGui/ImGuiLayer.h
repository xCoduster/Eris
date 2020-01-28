#pragma once

#include "er/core/Layer.h"
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

		void Begin();
		void End();
	};

}