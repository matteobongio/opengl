#include <glad/glad.h>
#include <string>
#include <vector>

class ShaderProgramBuilder;

class ShaderProgram {
public:
    friend class ShaderProgramBuilder;
    ShaderProgram(ShaderProgram const &) = delete;
    ShaderProgram &operator=(ShaderProgram const &) = delete;
    ~ShaderProgram();
    void use();
private:
    ShaderProgram(GLuint shaderProgram);
    GLuint m_shaderProgram;
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
        GLuint m_shader;
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
    GLuint m_shaderProgram;
};
