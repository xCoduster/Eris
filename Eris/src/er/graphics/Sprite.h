#pragma once

#include "er/utils/FileUtils.h"
#include "er/utils/TimeStep.h"

namespace er {

	class Renderer;

	struct SpriteProps
	{
		int32 x, y;
		uint width, height;
		byte* pixels;
	};

	class Sprite
	{
	private:
		SpriteProps m_Props;
		BMPProps m_BMPProps;
	public:
		Sprite(int32 x, int32 y, std::string filePath);

		void OnRender(Renderer& renderer);

		inline SpriteProps GetProps() const { return m_Props; }
	};
}