#pragma once

#include <string>
#include "er/Types.h"
#include "er/maths/Math.h"

namespace er {

	struct BMPProps
	{
		byte* pixels;
		vec2 size;
		byte BPP;
	};

	BMPProps LoadBMP(std::string filePath);
}