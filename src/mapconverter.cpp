#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(800,  600, "window", NULL, NULL);
    glfwMakeContextCurrent(window);
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate( );
    return 0;

}