#pragma once
#include "game/game.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <optional>

class Window {
public:
    Window(size_t width, size_t height, std::string title);
    ~Window();
    Window(Window const &) = delete;            // user pointer holds `this`
    Window &operator=(Window const &) = delete;
    int windowShouldClose() const;
    void swapBuffersAndPollEvents() const;
    void attachGame(Game &game);
private:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    size_t m_width;
    size_t m_height;
    GLFWwindow*  m_window;
    std::optional<Game &> m_game;
};


inline int Window::windowShouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

inline void Window::swapBuffersAndPollEvents() const
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}
