#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window/window.h"
#include "shader/shader.h"
#include "texture/texture.h"

int main() {
    Window window(800, 600, "Learn OpenGL");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 1.0f, 0.0f,
        0.0f,  0.5f, 0.0f, 1.0f
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    ShaderProgramBuilder triangleBuilder;
    triangleBuilder.addShader("triangle.vert");
    triangleBuilder.addShader("triangle.frag");

    ShaderProgram triangleShader = triangleBuilder.build();

    Texture2D catTex("cat.jpg");

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    while(!window.windowShouldClose())
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        catTex.bind();
        triangleShader.use();
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffersAndPollEvents();
    }
    return 0;
}
