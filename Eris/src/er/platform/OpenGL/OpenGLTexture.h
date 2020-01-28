#pragma once

#include "er/renderer/api/Texture.h"

namespace er {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D();

		virtual uint GetWidth() const override { return m_Width; }
		virtual uint GetHeight() const override { return m_Height; }

		virtual void Bind(uint slot = 0) const override;
	private:
		std::string m_Path;

		uint m_Width, m_Height;
		uint m_RendererID;
	};

}