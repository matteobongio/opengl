#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "shader/shader.h"
#include "texture/texture.h"

class Cat {
public:
    Cat();
    void update(float dt);
    void render(ShaderProgram const &sp);
private:
    Texture2D catTex;
    glm::mat4 m_model;
    unsigned int VAO;
    int x, y;
    float len, angle;
};
