#pragma once
#include "shader/shader.h"
#include "texture/texture.h"
#include <string>

class Sprite {
public:
    Sprite(std::string const &file);
    void render(ShaderProgram const &sp, glm::vec3 const &position, float angle, glm::vec2 scale = glm::vec2(1.0f, 1.0f)) const;
private:
    Texture2D m_tex;
    unsigned int m_VAO;
    float m_halfHeight;
    float m_halfWidth;
};
