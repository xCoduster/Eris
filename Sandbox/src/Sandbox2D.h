#pragma once

#include <Eris.h>

#include <glm/glm.hpp>

class Sandbox2D : public er::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(const er::Timestep& ts) override;
	virtual void OnRender() override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(er::Event& e) override;
private:
	er::ShaderLibrary m_ShaderLibrary;
	er::Ref<er::VertexArray> m_VertexArray;
	glm::vec4 m_SquareColor;

	er::OrthographicCameraController m_CameraController;
};