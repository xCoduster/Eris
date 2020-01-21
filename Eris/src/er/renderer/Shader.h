#pragma once

#include "er/erpch.h"

namespace er {

	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint m_RendererID;
	};

}