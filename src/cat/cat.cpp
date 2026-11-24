#include "cat.ih"

Cat::Cat() :
    m_sprite("cat.jpg"),
    position(0, 0),
    len(100),
    angle(0.0f)
{
}

void Cat::render(ShaderProgram const &sp)
{
    m_sprite.render(sp, glm::vec3(position, 0), angle);
}

void Cat::update(float dt)
{
    // float freq = 0.5f;
    // angle += 2 * static_cast<float>(std::numbers::pi) * dt * freq;
}
