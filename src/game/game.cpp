#include "game.ih"

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
    float halfWidth = static_cast<float>(width) / 2.0f;
    float halfHeight = static_cast<float>(height) / 2.0f;
    m_projection = glm::ortho(-halfWidth, halfWidth, halfHeight, -halfHeight, 0.1f, 1.0f);
}

void Game::ProcessInput(float dt)
{
    if (Keys::getInstance().keys[GLFW_KEY_UP]) {
        m_cat.position -= glm::vec2(0, 1000) * dt;
    }
    if (Keys::getInstance().keys[GLFW_KEY_DOWN]) {
        m_cat.position += glm::vec2(0, 1000) * dt;
    }
    if (Keys::getInstance().keys[GLFW_KEY_A]) {
        m_camera.position -= glm::vec2(50, 0) * dt;
    }
    if (Keys::getInstance().keys[GLFW_KEY_D]) {
        m_camera.position += glm::vec2(50, 0) * dt;
    }
}

void Game::Update(float dt)
{
    m_cat.update(dt);

    glm::vec2 cameraDiff = m_cat.position - m_camera.position;
    if (glm::length(cameraDiff) > 100) {
        glm::vec2 cameraDir = glm::normalize(cameraDiff);
        float cameraSpeed = glm::length(cameraDir) / 2.0f;
        m_camera.position += cameraDir * cameraSpeed;
    }
}

void Game::Render()
{
    triangleShader.use();

    triangleShader.setUniformMat4("projection", m_projection);
    triangleShader.setUniformMat4("view", m_camera.viewMatrix());
    triangleShader.setUniformMat4("gameScale", m_scale);

    m_cat.render(triangleShader);

}
