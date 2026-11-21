#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(size_t width, size_t height, std::string title);
    ~Window();
    Window(Window const &) = delete;            // user pointer holds `this`
    Window &operator=(Window const &) = delete;
    int windowShouldClose();
    void swapBuffersAndPollEvents();
private:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    size_t m_width;
    size_t m_height;
    GLFWwindow*  m_window;
};
