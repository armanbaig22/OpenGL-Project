#include <GLFW/glfw3.h>
#include "render.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /*create render class object*/
    render ren;

    float center[3] = { 0.0f, 0.0f, 0.0f };
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        glClearColor(0.0, 0.0, 0.0, 1);

        glClear(GL_COLOR_BUFFER_BIT);

        /*
        floata[3] = {-0.9,-0.6,0.0};
        floatb[3] = {0.4,-0.8,0.0};
        floatc[3] = {0.0,0.6,0.0};
        ren.triangle(a,b,c);
        */

        
        float radius = 0.5f;
        int sections = 100;
        
        ren.circle(center, radius, sections);
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}