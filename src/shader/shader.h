#pragma once
#include <glm/gtc/type_ptr.hpp>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float3.hpp"
#include <glad/glad.h>
#include <string>
#include <vector>

class ShaderProgramBuilder;

class ShaderProgram {
public:
    friend class ShaderProgramBuilder;
    ShaderProgram(ShaderProgram &&);
    ShaderProgram(ShaderProgram const &) = delete;
    ShaderProgram &operator=(ShaderProgram const &) = delete;
    ShaderProgram &operator=(ShaderProgram &&);
    ~ShaderProgram();
    void use() const;
    GLuint getUniformLocation(std::string const &uniform) const;
    void setUniformMat4(std::string const &name, glm::mat4 const &mat4) const;
    void setUniformVec3(std::string const &name, glm::vec3 const &vec3) const;
    void setUniformi(std::string const &name, int i) const;
    void setUniformf(std::string const &name, float f) const;
private:
    ShaderProgram(GLuint shaderProgram);
    GLuint m_shaderProgram = 0;
};

class ShaderProgramBuilder {
private:
    class Shader {
    public:
        friend class ShaderProgramBuilder;
        Shader(std::string const & sourceFile);
        Shader(Shader const &) = delete;
        Shader &operator=(Shader const &) = delete;
        Shader(Shader &&other);
        ~Shader();
    private:
        GLuint m_shader = 0;
    };
public:
    ShaderProgramBuilder();
    void addShader(std::string const & source);
    ShaderProgram build();
    ShaderProgramBuilder(ShaderProgramBuilder const &) = delete;
    ShaderProgramBuilder &operator=(ShaderProgramBuilder const &) = delete;
    ~ShaderProgramBuilder();

private:
    std::vector<Shader> m_shaders;
    GLuint m_shaderProgram = 0;
};



inline void ShaderProgram::use() const
{
    glUseProgram(m_shaderProgram);
}

inline GLuint ShaderProgram::getUniformLocation(std::string const &uniform) const
{
    return glGetUniformLocation(m_shaderProgram, uniform.c_str());
}

inline void ShaderProgram::setUniformMat4(std::string const &name, glm::mat4 const &mat4) const
{
    glUniformMatrix4fv(getUniformLocation(name), 1, false, glm::value_ptr(mat4));
}

inline void ShaderProgram::setUniformVec3(std::string const &name, glm::vec3 const &vec3) const
{
    glUniform3fv(getUniformLocation(name), 1, glm::value_ptr(vec3));
}

inline void ShaderProgram::setUniformi(std::string const &name, int i) const
{
    glUniform1i(getUniformLocation(name), i);
}

inline void ShaderProgram::setUniformf(std::string const &name, float f) const
{
    glUniform1f(getUniformLocation(name), f);
}
