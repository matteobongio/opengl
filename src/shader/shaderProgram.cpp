#include "shader.ih"

ShaderProgram::ShaderProgram(GLuint shaderProgram) :
    m_shaderProgram(shaderProgram)
{

}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_shaderProgram);
}

void ShaderProgram::use()
{
    glUseProgram(m_shaderProgram);
}
