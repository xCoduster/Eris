#pragma once

#include "er/erpch.h"
#include <glm/glm.hpp>

namespace er {

	struct BMPProps
	{
		byte* pixels;
		glm::vec2 size;
		byte BPP;
	};

	BMPProps LoadBMP(std::string filePath);
}