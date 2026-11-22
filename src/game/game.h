#pragma once

#include "shader/shader.h"
#include "texture/texture.h"
#include <glm/mat4x4.hpp>

class Game {
public:
    Game(size_t width, size_t height, ShaderProgram &&sh);

    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void windowResize(size_t width, size_t height);
private:
    glm::mat4 m_projection;
    ShaderProgram triangleShader;

    Texture2D catTex;

    unsigned int VAO;
};
