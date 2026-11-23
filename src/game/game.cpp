#include "game.ih"

Game::Game(size_t width, size_t height, ShaderProgram &&sh) :
    m_width(width),
    m_height(height),
    m_projection(glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f)),
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

}

void Game::Update(float dt)
{
    m_cat.update(dt);
}

void Game::Render()
{
    triangleShader.use();

    triangleShader.setUniformMat4("projection", m_projection);

    m_cat.render(triangleShader);

}
