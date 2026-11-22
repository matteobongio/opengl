#include "window.ih"

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (self->m_game) {
        self->m_game.value().windowResize(width, height);
    }
    self->m_height = height;
    self->m_width = width;
    glViewport(0, 0, width, height);
}


Window::Window(size_t width, size_t height, std::string title):
m_height(height),
m_width(width)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, title.c_str(), nullptr, nullptr);
    if (!m_window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glViewport(0, 0, m_width, m_height);
    glfwSetWindowUserPointer(m_window, this); //give access to object for callback
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

Window::~Window() {
    if (m_window)
        glfwDestroyWindow(m_window);
    glfwTerminate();
}



void Window::attachGame(Game &game)
{
    m_game = game;
}
