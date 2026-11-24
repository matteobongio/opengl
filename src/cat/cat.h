#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "shader/shader.h"
#include "sprite/sprite.h"

class Cat {
public:
    Cat();
    void update(float dt);
    void render(ShaderProgram const &sp);
    glm::vec3 position;
private:
    Sprite m_sprite;
    glm::mat4 m_model;
    unsigned int VAO;
    float len, angle;
};
