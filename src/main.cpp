#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{

    // Init gl
    if (!glfwInit())
    {
        printf("GLFW initialization failed!");
        glfwTerminate();
        return 1;
    }

    // Setup window props
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Core profile means no backward compatibility. Only modern gl code.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    auto *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Playground", NULL, NULL);
    if (!mainWindow)
    {
        printf("GLFW window creation failed.");
        glfwTerminate();
        return 1;
    }

    // Grab opengl window buffer
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLFW to use
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extensions
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        printf("GLEW initialization failed.");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup viewport
    glViewport(0, 0, bufferWidth, bufferHeight);

    while (!glfwWindowShouldClose(mainWindow))
    {
        // Handle glfw events
        glfwPollEvents();

        glClearColor(1.0, 0.8, 0.2, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}