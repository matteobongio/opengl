#include "shader.ih"

ShaderProgram::ShaderProgram(GLuint shaderProgram) :
    m_shaderProgram(shaderProgram)
{

}

ShaderProgram::~ShaderProgram()
{
    if (m_shaderProgram)
        glDeleteProgram(m_shaderProgram);
}

ShaderProgram::ShaderProgram(ShaderProgram &&other) :
    m_shaderProgram(std::exchange(other.m_shaderProgram, 0))
{

}

ShaderProgram &ShaderProgram::operator=(ShaderProgram &&other)
{
    if (this != &other)
        std::swap(m_shaderProgram, other.m_shaderProgram);

    return *this;
}
