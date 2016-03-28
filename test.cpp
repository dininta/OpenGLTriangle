#include <stdio.h>
#include <stdlib.h>
#include "GLFW/glfw3.h"

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main() {

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Create window
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 0.f, 0.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Red triangle
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex2f(-0.9f, -0.2f);
        glVertex2f(-0.6f, -0.2f);
        glVertex2f(-0.75f, 0.2f);
        glEnd();

        // Green triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.f, 1.f, 0.f);
        glVertex2f(-0.4f, -0.2f);
        glVertex2f(-0.1f, -0.2f);
        glVertex2f(-0.25f, 0.2f);
        glEnd();

        // Blue triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.f, 0.f, 1.f);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.1f, -0.2f);
        glVertex2f(0.25f, 0.2f);
        glEnd();

        // Colorful triangle
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex2f(0.9f, -0.2f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex2f(0.6f, -0.2f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex2f(0.75f, 0.2f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}