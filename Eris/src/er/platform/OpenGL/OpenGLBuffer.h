#pragma once

#include "er/erpch.h"
#include "er/renderer/api/Buffer.h"

namespace er {

	// ---VertexBuffer---

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
	private:
		uint m_RendererID;
		BufferLayout m_Layout;
	};

	// ---IndexBuffer---

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint* indices, uint count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual uint GetCount() const { return m_Count; }
	private:
		uint m_RendererID;
		uint m_Count;
	};

}