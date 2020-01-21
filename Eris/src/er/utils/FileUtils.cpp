#include "er/erpch.h"
#include "FileUtils.h"

namespace er {

	BMPProps LoadBMP(std::string filePath)
	{
		FILE* file;
		byte info[150];
		byte* data;
		long fSize;
		size_t result;
		BMPProps props;
		props.pixels = nullptr;
		props.size = NULL;
		props.BPP = NULL;

		int pixelArrayOffset;
		byte BPP;
		int width, height;

		fopen_s(&file, filePath.c_str(), "r");
		if (file == NULL)
		{
			printf("Failed to open file: %s\n", filePath.c_str());
			return props;
		}

		fseek(file, 0, SEEK_END);
		fSize = ftell(file);
		rewind(file);

		fread(info, 1, 150, file);

		if (info[0] != 0x42 && info[1] != 0x4D)
		{
			printf("%s is not a BMP file\n", filePath.c_str());
			return props;
		}

		pixelArrayOffset = *(int*)&info[0xA];
		width = *(int*)&info[0x12];
		height = *(int*)&info[0x16];
		BPP = *(int*)&info[0x1C];

		int size = BPP * width * height;
		data = new byte[size];
		result = fread(data, 1, size, file);
		if (result != fSize - 150)
		{
			printf("Failed to read file: %s\n", filePath.c_str());
			return props;
		}

		fclose(file);

		byte* tmp;
		tmp = new byte[size];

		for (int32 y = 0; y < height; y++)
		{
			for (int32 x = 0; x < width * 4; x++)
			{
				tmp[x + y * width * 4] = data[x + (height - y) * width * 4];
			}
		}

		props.pixels = tmp;
		props.size.x = (float)width;
		props.size.y = (float)height;
		props.BPP = BPP;

		return props;
	}
}