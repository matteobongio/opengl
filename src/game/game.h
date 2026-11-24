#pragma once
#include "camera/camera.h"
#include "cat/cat.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "shader/shader.h"
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
    size_t m_width, m_height;
    Cat m_cat;
    glm::mat4 m_scale;
    Camera m_camera;
};
