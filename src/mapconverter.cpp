#include <stdint.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

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

    GLfloat lineVertices2[] = {
        200, 100, 0,
        000, 200, 0
    };
    GLfloat* lines[] = {lineVertices, lineVertices2};

    while(!glfwWindowShouldClose(window)){
       // for (int i = 0; i++ ; i < 2){
            glClear(GL_COLOR_BUFFER_BIT);
            glEnableClientState(GL_VERTEX_ARRAY);

            glVertexPointer(3, GL_FLOAT, 0, lines[1]);
            glVertexPointer(3, GL_FLOAT, 0, lines[0]);
            glDrawArrays(GL_LINES, 0, 2);
            glDisableClientState(GL_VERTEX_ARRAY);
            glfwSwapBuffers(window);
            glfwPollEvents();   
        //}
        
        
    }
    glfwTerminate( );
    return 0;

}