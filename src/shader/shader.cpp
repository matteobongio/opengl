#include "shader.ih"
#include <stdexcept>
#include <utility>
#include <iostream>

std::string readShader(std::string const &relPath)
{
    std::filesystem::path full = std::filesystem::path(SHADER_DIR) / relPath;

    std::ifstream file(full);
    if (!file)
        throw std::runtime_error("Cannot open shader: " + full.string());

    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

void compileShader(GLuint &shader, const char *shaderSource) {
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::string err = "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n";
        err.append(infoLog);
        throw std::runtime_error(std::move(err));
    }
}

GLenum stageFromPath(std::filesystem::path const &p)
{
    auto ext = p.extension().string();
    if (ext == ".vert") return GL_VERTEX_SHADER;
    if (ext == ".frag") return GL_FRAGMENT_SHADER;
    if (ext == ".geom") return GL_GEOMETRY_SHADER;
    if (ext == ".comp") return GL_COMPUTE_SHADER;
    throw std::runtime_error("Unknown shader extension: " + ext);
}

ShaderProgramBuilder::Shader::Shader(std::string const & sourceFile)
{
    std::string sourceString = readShader(sourceFile);
    const char *source = sourceString.c_str();
    m_shader = glCreateShader(stageFromPath(sourceFile));
    compileShader(m_shader, source);
}

ShaderProgramBuilder::Shader::~Shader()
{
    if (m_shader)
        glDeleteShader(m_shader);
}

ShaderProgramBuilder::Shader::Shader(Shader &&other) :
    m_shader(std::exchange(other.m_shader, 0))
{

}
