#pragma once

#include "er/Types.h"
#include "er/maths/Math.h"

#include "er/utils/FileUtils.h"
#include "er/utils/TimeStep.h"

namespace er {

	class Renderer;

	struct SpriteProps
	{
		vec2 size;
		byte* pixels;
	};

	class Sprite
	{
	private:
		SpriteProps m_Props;
		BMPProps m_BMPProps;
	public:
		Sprite(std::string filePath);

		void Render(Renderer& renderer, vec2 position);

		inline SpriteProps GetProps() const { return m_Props; }
	};
}