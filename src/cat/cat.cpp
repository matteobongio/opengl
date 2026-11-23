#include "cat.ih"
#include "glm/ext/matrix_transform.hpp"
#include <numbers>

Cat::Cat() :
    catTex("cat.jpg"),
    x(800),
    y(600),
    len(100)
{
    float vertices[] = {
        len, len, 1.0f, 1.0f,
        len, 0.0f, 1.0f, 0.0f,
        0.0f,  len, 0.0f, 1.0f,
        len, 0.0f, 1.0f, 0.0f,
        0.0f,  len, 0.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 0.0f
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // m_model = glm::scale(m_model, glm::vec3(800, 600, 0));
    m_model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0));
}

void Cat::render(ShaderProgram const &sp)
{
    glBindVertexArray(VAO);
    glActiveTexture(GL_TEXTURE0);
    catTex.bind();

    sp.setUniformMat4("model", m_model);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Cat::update(float dt)
{
    angle += 2 * static_cast<float>(std::numbers::pi) * dt;
    m_model = glm::translate(glm::mat4(1.0f), glm::vec3(x + len/2, y + len/2, 0)) *
    glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0, 0, 1)) *
    glm::translate(glm::mat4(1.0f), glm::vec3(-len/2, -len/2, 0));
}
