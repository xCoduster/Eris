#include "er/erpch.h"
#include "OpenGLShader.h"

#include <fstream>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace er {

	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "compute")
			return GL_COMPUTE_SHADER;
		if (type == "fragment")
			return GL_FRAGMENT_SHADER;
		if (type == "geometry")
			return GL_GEOMETRY_SHADER;
		if (type == "pixel")
			return GL_FRAGMENT_SHADER;
		if (type == "vertex")
			return GL_VERTEX_SHADER;

		ER_CORE_ASSERT(false, "Unknown shader type '{0}'", type);
		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string& filepath)
	{
		std::string source = ReadFile(filepath);
		std::unordered_map<GLenum, std::string> shaderSources = PreProcess(source);
		CompileShader(shaderSources);

		size_t lastSlash = filepath.find_last_of("/\\");
		lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
		size_t lastDot = filepath.rfind(".");
		size_t count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
		m_Name = filepath.substr(lastSlash, count);
	}

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
		: m_Name(name)
	{
		std::unordered_map<GLenum, std::string> shaderSources;
		shaderSources[GL_VERTEX_SHADER] = vertexSrc;
		shaderSources[GL_FRAGMENT_SHADER] = fragmentSrc;
		CompileShader(shaderSources);
	}

	void OpenGLShader::CompileShader(std::unordered_map<GLenum, std::string> shaderSources)
	{
		GLuint program = glCreateProgram();
		
		ER_CORE_ASSERT(shaderSources.size() <= 2, "Only support for 2 shaders is currently implemented!");
		std::array<GLuint, 2> glShaderIDs;
		int glShaderIDIndex = 0;

		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);

			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);

			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				ER_CORE_ERROR("{0}", infoLog.data());
				ER_CORE_ASSERT(false, "Shader failed to compile!");
				break;
			}

			glAttachShader(program, shader);
			glShaderIDs[glShaderIDIndex++] = shader;
		}

		m_RendererID = program;

		glLinkProgram(m_RendererID);

		GLint isLinked = 0;
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int *)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(m_RendererID);
			for (GLuint shader : glShaderIDs)
				glDeleteShader(shader);

			ER_CORE_ERROR("{0}", infoLog.data());
			ER_CORE_ASSERT(false, "Shader link failure!");

			return;
		}

		for (GLuint shader : glShaderIDs)
			glDetachShader(m_RendererID, shader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	std::string OpenGLShader::ReadFile(const std::string& filepath)
	{
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			result.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
		}
		else
			ER_CORE_ERROR("Could not open file \"{0}\"", filepath);

		return result;
	}

	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
	{
		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0);
		while (pos != std::string::npos)
		{
			size_t eol = source.find_first_of("\r\n", pos);
			ER_CORE_ASSERT(eol != std::string::npos, "Syntax Error!");
			size_t begin = pos + typeTokenLength + 1;
			std::string type = source.substr(begin, eol - begin);

			size_t nextLinePos = source.find_first_not_of("\r\n", eol);
			pos = source.find(typeToken, nextLinePos);
			shaderSources[ShaderTypeFromString(type)] = 
				source.substr(nextLinePos, 
				pos - (nextLinePos == std::string::npos ? source.size() - 1 : nextLinePos)
			);
		}

		return shaderSources;
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	// Uniforms

	void OpenGLShader::SetUniformInt(const std::string& name, int value)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniform1i(m_UniformHashMap.at(name), value);
	}

	void OpenGLShader::SetUniformFloat(const std::string& name, float values)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniform1f(m_UniformHashMap.at(name), values);
	}

	// vec2, vec3, vec4

	void OpenGLShader::SetUniformFloat2(const std::string& name, glm::vec2 value)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniform2f(m_UniformHashMap.at(name), value.x, value.y);
	}

	void OpenGLShader::SetUniformFloat3(const std::string& name, glm::vec3 value)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniform3f(m_UniformHashMap.at(name), value.x, value.y, value.z);
	}

	void OpenGLShader::SetUniformFloat4(const std::string& name, glm::vec4 value)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniform4f(m_UniformHashMap.at(name), value.x, value.y, value.z, value.w);
	}

	// 3x3 and 4x4 Matricies

	void OpenGLShader::SetUniformMat3(const std::string& name, glm::mat3 matrix)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniformMatrix4fv(m_UniformHashMap.at(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	void OpenGLShader::SetUniformMat4(const std::string& name, glm::mat4 matrix)
	{
		if (m_UniformHashMap.find(name) == m_UniformHashMap.end())
		{
			GLint location = glGetUniformLocation(m_RendererID, name.c_str());
			m_UniformHashMap.emplace(name, location);
		}

		glUniformMatrix4fv(m_UniformHashMap.at(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

}