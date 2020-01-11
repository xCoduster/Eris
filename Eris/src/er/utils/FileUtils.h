#pragma once

namespace er {

	struct BMPProps
	{
		byte* pixels;
		uint width, height;
		byte BPP;
	};

	BMPProps LoadBMP(std::string filePath);
}