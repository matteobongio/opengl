#include "shader.ih"

ShaderProgramBuilder::ShaderProgramBuilder()
{
    m_shaderProgram = glCreateProgram();
}

void ShaderProgramBuilder::addShader(std::string const & source)
{
    m_shaders.push_back(Shader(source));
}

ShaderProgram ShaderProgramBuilder::build()
{
    for (auto &shader : m_shaders)
    {
        glAttachShader(m_shaderProgram, shader.m_shader);
        if (GLenum e = glGetError(); e != GL_NO_ERROR)
            std::cerr << "attach failed: 0x" << std::hex << e << '\n';
    }
    glLinkProgram(m_shaderProgram);

    int ok;
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[1024];
        glGetProgramInfoLog(m_shaderProgram, sizeof log, nullptr, log);
        throw std::runtime_error(std::string("Program link error:\n") + log);
    }

    return ShaderProgram(m_shaderProgram);
}

ShaderProgramBuilder::~ShaderProgramBuilder()
{
    glDeleteProgram(m_shaderProgram);
}
