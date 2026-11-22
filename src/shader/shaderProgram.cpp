#include "shader.ih"

ShaderProgram::ShaderProgram(GLuint shaderProgram) :
    m_shaderProgram(shaderProgram)
{

}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_shaderProgram);
}
