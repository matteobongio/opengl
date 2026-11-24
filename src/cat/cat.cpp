#include "cat.ih"

Cat::Cat() :
    m_sprite("cat.jpg"),
    position(800, 600, 0),
    len(100),
    angle(0.0f)
{
    // m_model = glm::scale(m_model, glm::vec3(800, 600, 0));
    // m_model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0));
}

void Cat::render(ShaderProgram const &sp)
{
    m_sprite.render(sp, position, angle);
    // m_model = glm::translate(glm::mat4(1.0f), glm::vec3(x + len/2, y + len/2, 0))
    // * glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0, 0, 1))
    // * glm::translate(glm::mat4(1.0f), glm::vec3(-len/2, -len/2, 0));

}

void Cat::update(float dt)
{
    angle += 2 * static_cast<float>(std::numbers::pi) * dt;
}
