#include "game.ih"
#include "shader/shader.h"

Game::Game(size_t width, size_t height, ShaderProgram &&sh) :
    m_projection(glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f)),
    catTex("cat.jpg"),
    triangleShader(std::move(sh))
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 1.0f, 0.0f,
        0.0f,  0.5f, 0.0f, 1.0f
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
}

void Game::windowResize(size_t width, size_t height)
{
    m_projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
}

void Game::ProcessInput(float dt)
{

}

void Game::Update(float dt)
{

}

void Game::Render()
{
    glActiveTexture(GL_TEXTURE0);
    catTex.bind();
    triangleShader.use();
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
