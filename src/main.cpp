#include "window/window.h"
#include "shader/shader.h"

int main() {
    Window window(800, 600, "Learn OpenGL");

    ShaderProgramBuilder triangleBuilder;
    triangleBuilder.addShader("triangle.vert");
    triangleBuilder.addShader("triangle.frag");

    Game game(800, 600, triangleBuilder.build());

    window.attachGame(game);

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    while(!window.windowShouldClose())
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        game.ProcessInput(deltaTime);

        game.Update(deltaTime);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.Render();

        window.swapBuffersAndPollEvents();
    }
    return 0;
}
