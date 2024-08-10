/**
 * @file window.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include <iostream>
#include "window.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    Window::Window(const char *window_name,
                   int window_width,
                   int window_height,
                   bool cap_to_screen_frame_rate)
    {
        this->m_window_dims.width = window_width;
        this->m_window_dims.height = window_height;

        // initialize the library
        if (!glfwInit())
        {
            throw std::runtime_error("Could not start GLFW3!");
        }

        // window hints
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // for sRGB framebuffer
        glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);

        // for multisampling/anti-aliasing
        glfwWindowHint(GLFW_SAMPLES, 4);

        /* Create a windowed mode window and its OpenGL context */
        this->m_window = glfwCreateWindow(window_width,
                                          window_height,
                                          window_name,
                                          nullptr,
                                          nullptr);

        if (!this->m_window)
        {
            glfwTerminate();
            throw std::runtime_error("Could not create GLFW3 window!");
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(this->m_window);

        if (cap_to_screen_frame_rate)
        {
            glfwSwapInterval(1); // set 1 to limit fps to the screen's framerate
        }
        else
        {
            glfwSwapInterval(0); // set 0 for un-limited fps
        }

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            printf("\nFailed to initialize GLAD\n");
            return;
        }

        // get version info
        const GLubyte* gpu = glGetString(GL_RENDERER); // get renderer string
        const GLubyte* version = glGetString(GL_VERSION); // version as a string
        std::cout << "GPU: " << gpu << std::endl;
        std::cout << "OpenGL Version: " << version << std::endl;
    }

    Window::~Window()
    {
        if (this->m_window)
        {
            glfwDestroyWindow(this->m_window);
        }

        //close GL context and any other GLFW resources
        glfwTerminate();
    }

    GLFWwindow* Window::get_window()
    {
        return this->m_window;
    }

    window_dims_t Window::get_window_dimensions()
    {
        return this->m_window_dims;
    }

    void Window::set_window_dimensions(const window_dims_t window_dims)
    {
        this->m_window_dims = window_dims;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
