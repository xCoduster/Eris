#include "Sandbox2D.h"

#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

#include <er/platform/OpenGL/OpenGLShader.h>

Sandbox2D::Sandbox2D()
	: er::Layer("Sandbox2D"), m_CameraController(16.0f / 9.0f), m_SquareColor(0.2f, 0.3f, 0.8f, 1.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_VertexArray = er::VertexArray::Create();

	float squareVertices[] = {
		-0.5f, -0.5f, 0.0f,	0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,	1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,	1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,	0.0f, 1.0f
	};

	er::Ref<er::VertexBuffer> squareVB;
	squareVB = er::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
	squareVB->SetLayout({
		{ er::ShaderDataType::Float3, "a_Position" },
		{ er::ShaderDataType::Float2, "a_TexCoord" }
						});
	m_VertexArray->AddVertexBuffer(squareVB);

	uint squareIndices[] = { 0, 1, 2, 2, 3, 0 };
	er::Ref<er::IndexBuffer> squareIB;
	squareIB = er::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint));
	m_VertexArray->SetIndexBuffer(squareIB);

	m_ShaderLibrary.Load("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(const er::Timestep& ts)
{
	m_CameraController.OnUpdate(ts);
}

void Sandbox2D::OnRender()
{
	er::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	er::RenderCommand::Clear();

	er::Renderer::BeginScene(m_CameraController.GetCamera());

	auto flatColorShader = m_ShaderLibrary.Get("FlatColor");

	flatColorShader->Bind();
	std::dynamic_pointer_cast<er::OpenGLShader>(flatColorShader)->SetUniformFloat4("u_Color", m_SquareColor);

	er::Renderer::Submit(flatColorShader, m_VertexArray, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	er::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(er::Event& e)
{
	m_CameraController.OnEvent(e);
}