#include <Eris.h>

#include <imgui/imgui.h>

#include <er/platform/OpenGL/OpenGLShader.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class Test2D : public er::Layer
{
private:
	er::ShaderLibrary m_ShaderLibrary;
	er::Ref<er::VertexArray> m_SquareVA;
	er::Ref<er::Texture2D> m_Texture;
	er::Ref<er::Texture2D> m_SlimeTexture;

	er::OrthographicCameraController m_CameraController;

	glm::vec4 squareColor;
public:
	Test2D()
		: Layer("Test"), m_CameraController(16.0f/9.0f), squareColor(0.2f, 0.3f, 0.8f, 1.0f)
	{
		m_SquareVA = er::VertexArray::Create();

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
		m_SquareVA->AddVertexBuffer(squareVB);

		uint squareIndices[] = { 0, 1, 2, 2, 3, 0 };
		er::Ref<er::IndexBuffer> squareIB;
		squareIB = er::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint));
		m_SquareVA->SetIndexBuffer(squareIB);

		m_ShaderLibrary.Load("assets/shaders/FlatColor.glsl");

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = er::Texture2D::Create("assets/textures/Checkerboard.png");
		m_SlimeTexture = er::Texture2D::Create("assets/textures/Transparent.png");

		std::dynamic_pointer_cast<er::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<er::OpenGLShader>(textureShader)->SetUniformInt("u_Texture", 0);
	}

	virtual void OnUpdate(const er::Timestep& ts) override
	{
		m_CameraController.OnUpdate(ts);
	}

	virtual void OnRender() override
	{
		er::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		er::RenderCommand::Clear();

		er::Renderer::BeginScene(m_CameraController.GetCamera());

		static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		auto flatColorShader = m_ShaderLibrary.Get("FlatColor");

		std::dynamic_pointer_cast<er::OpenGLShader>(flatColorShader)->Bind();
		std::dynamic_pointer_cast<er::OpenGLShader>(flatColorShader)->SetUniformFloat4("u_Color", squareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;

				er::Renderer::Submit(flatColorShader, m_SquareVA, transform);
			}
		}
		
		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		er::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_SlimeTexture->Bind();
		er::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		//er::Renderer::Submit(m_Shader, m_VertexArray);

		er::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Square Color", glm::value_ptr(squareColor));
		ImGui::End();
	}

	virtual void OnEvent(er::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}
};

class Game : public er::Application
{
public:
	Game()
		: er::Application("Sandbox")
	{
		//PushLayer(new Test2D());
		PushLayer(new Sandbox2D());
	}

	~Game()
	{

	}
};

int main()
{
	Game game;
	game.Start();
	return 0;
}