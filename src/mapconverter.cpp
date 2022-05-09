#include <stdint.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <emscripten.h>

int main(void)
{
    GLFWwindow* window;
    if(!glfwInit()){
        exit(1);
    }
    int SCREEN_WIDTH = 800;
    int SCREEN_HEIGHT = 600;
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "window", NULL, NULL);
    glfwMakeContextCurrent(window);


    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);

    GLfloat lineVertices[] = {
        200, 100, 0,
        100, 300, 0
    };

   while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, lineVertices);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate( );
    return 0;

}