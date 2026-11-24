#include "game.ih"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include "keys.h"

Game::Game(size_t width, size_t height, ShaderProgram &&sh) :
    m_width(width),
    m_height(height),
    m_projection(glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f)),
    m_scale(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f))),
    triangleShader(std::move(sh))
{
}

void Game::windowResize(size_t width, size_t height)
{
    m_width = width;
    m_height = height;
    m_projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
}

void Game::ProcessInput(float dt)
{
    if (Keys::getInstance().keys[GLFW_KEY_UP]) {
        m_cat.position -= glm::vec3(0, 1000, 0) * dt;
    }
    if (Keys::getInstance().keys[GLFW_KEY_DOWN]) {
        m_cat.position += glm::vec3(0, 1000, 0) * dt;
    }
}

void Game::Update(float dt)
{
    m_cat.update(dt);
}

void Game::Render()
{
    triangleShader.use();

    triangleShader.setUniformMat4("projection", m_projection);
    triangleShader.setUniformMat4("gameScale", m_scale);

    m_cat.render(triangleShader);

}
