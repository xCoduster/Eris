#pragma once

#include "er/erpch.h"

namespace er {

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint GetWidth() const = 0;
		virtual uint GetHeight() const = 0;

		virtual void Bind(uint slot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(const std::string& path);
	};

}