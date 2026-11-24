#include "sprite.ih"

Sprite::Sprite(std::string const &file) :
    m_tex(file)
{
    m_halfHeight = static_cast<float>(m_tex.GetHeight()) / 2.0f;
    m_halfWidth = static_cast<float>(m_tex.GetWidth()) / 2.0f;
    float vertices[] = {
        m_halfWidth, m_halfHeight, 1.0f, 1.0f,
        m_halfWidth, -m_halfHeight, 1.0f, 0.0f,
        -m_halfWidth, m_halfHeight, 0.0f, 1.0f,
        m_halfWidth, -m_halfHeight, 1.0f, 0.0f,
        -m_halfWidth, m_halfHeight, 0.0f, 1.0f,
        -m_halfWidth, -m_halfHeight, 0.0f, 0.0f
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &m_VAO);
    // 1. bind Vertex Array Object
    glBindVertexArray(m_VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}
void Sprite::render(ShaderProgram const &sp, glm::vec3 const &position, float angle, glm::vec2 scale) const
{
    glm::mat4 m_model = glm::mat4(1.0f);
    m_model = glm::translate(m_model, position);
    m_model =  glm::rotate(m_model, angle, glm::vec3(0, 0, 1));
    m_model = glm::scale(m_model, glm::vec3(scale, 0));

    glBindVertexArray(m_VAO);
    glActiveTexture(GL_TEXTURE0);
    m_tex.bind();

    sp.setUniformMat4("model", m_model);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}
