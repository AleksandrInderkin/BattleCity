#pragma once

#include<glad/glad.h>
#include<string>

namespace Renderer {
	class ShaderProgram {
	public:
		ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		~ShaderProgram();
		bool isCompiled() const { return m_isCompiled; }
		void use() const;

		ShaderProgram() = delete;  // «апрет на конструктор без параметров
		ShaderProgram(ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;
		ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;

	private:
		bool createShader(const std::string& source, const GLenum shadertype, GLuint& shaderID);
		bool m_isCompiled = false;
		GLuint m_ID = 0;




	};
}

