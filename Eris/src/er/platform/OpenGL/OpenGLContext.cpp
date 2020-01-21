#include "er/erpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace er {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ER_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ER_CORE_ASSERT(status, "Falied to initialize glad!");

		ER_CORE_INFO("OpenGL Renderer:");
		ER_CORE_INFO("  Vendor:   {0}", glGetString(GL_VENDOR));
		ER_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ER_CORE_INFO("  Version:  {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}