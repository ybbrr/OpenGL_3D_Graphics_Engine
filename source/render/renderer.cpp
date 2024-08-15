/**
 * @file renderer.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "renderer.hpp"
#include "window_callbacks.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

#include <glad/glad.h>

namespace YB
{

/*******************************************************************************
 * Helper Functions
 ******************************************************************************/

    /**
     * @brief Checks for OpenGL errors and logs them.
     *
     * @param file The file name where the error check is performed.
     * @param line The line number where the error check is performed.
     * @return GLenum The last recorded OpenGL error code.
     */
    GLenum glCheckError_(const char *file, int line)
    {
        GLenum error_code;
        while ((error_code = glGetError()) != GL_NO_ERROR)
        {
            std::string error;
            switch (error_code)
            {
                case GL_INVALID_ENUM:
                    error = "INVALID_ENUM";
                    break;
                case GL_INVALID_VALUE:
                    error = "INVALID_VALUE";
                    break;
                case GL_INVALID_OPERATION:
                    error = "INVALID_OPERATION";
                    break;
                case GL_STACK_OVERFLOW:
                    error = "STACK_OVERFLOW";
                    break;
                case GL_STACK_UNDERFLOW:
                    error = "STACK_UNDERFLOW";
                    break;
                case GL_OUT_OF_MEMORY:
                    error = "OUT_OF_MEMORY";
                    break;
                case GL_INVALID_FRAMEBUFFER_OPERATION:
                    error = "INVALID_FRAMEBUFFER_OPERATION";
                    break;
                default:
                    break;
            }
            std::cout << error << " - error code: " << error_code << " | " << file << " (" << line << ")" << "\n";
        }
        return error_code;
    }
#define glCheckError() glCheckError_(__FILE__, __LINE__)

    Renderer::Renderer()
        : m_mouse{new YB::Mouse(CoreComponents::window->width, CoreComponents::window->height)},
          m_delta_time_in_seconds{0.0f}
    {
        this->init_opengl_state();

        DrawComponents::shader = std::make_shared<YB::DirectionalLightShader>();
        DrawComponents::shader->init_uniforms();

        CoreComponents::world = std::make_shared<YB::DefaultWorld>();

        this->m_keyboard = std::make_shared<YB::Keyboard>();

        this->set_window_callbacks();
    }

    void Renderer::render_scene()
    {
        GLFWwindow* window = CoreComponents::window->get_window();

        float current_time_stamp{};
        float last_time_stamp{};

        glCheckError();

        while (!glfwWindowShouldClose(window))
        {
            current_time_stamp = static_cast<float>(glfwGetTime());
            this->m_delta_time_in_seconds = current_time_stamp - last_time_stamp;

            this->m_keyboard->key_pressed(this->m_delta_time_in_seconds);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClear(GL_STENCIL_BUFFER_BIT);

            if (DrawComponents::shader != nullptr)
            {
                CoreComponents::world->render_models();
            }

            glfwPollEvents();
            glfwSwapBuffers(window);

            glCheckError();

            last_time_stamp = current_time_stamp;
        }
    }

    void Renderer::mouse_movement(float x_pos, float y_pos)
    {
        this->m_mouse->mouse_movement(x_pos,
                                      y_pos,
                                      this->m_delta_time_in_seconds);
    }

    void Renderer::key_pressed(GLFWwindow* window,
                               int key,
                               int action)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }

        this->m_keyboard->key_pressed(key, action);
    }

    void Renderer::init_opengl_state()
    {
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glViewport(0, 0, CoreComponents::window->width, CoreComponents::window->height);
        glEnable(GL_FRAMEBUFFER_SRGB);
        glEnable(GL_DEPTH_TEST); // enable depth-testing
        glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
        glEnable(GL_CULL_FACE); // cull face
        glCullFace(GL_BACK); // cull back face
        glFrontFace(GL_CCW); // GL_CCW for counter clock-wise
    }

    void Renderer::init_models()
    {
        CoreComponents::world->add_model(R"(obj/teapot20segUT.obj)",
                                         "teapot",
                                         glm::vec3(0.0f, 0.0f, 0.0f),
                                         true,
                                         true);

        CoreComponents::world->add_model(R"(obj/cube.obj)",
                                         "cube",
                                         glm::vec3(3.0f, 0.0f, 0.0f),
                                         false,
                                         false);

        CoreComponents::world->add_model(R"(obj/sphere.obj)",
                                         "sphere",
                                         glm::vec3(-3.0f, 0.0f, 2.0f),
                                         false,
                                         false);

        CoreComponents::world->add_model(R"(obj/monkey.obj)",
                                         "monkey",
                                         glm::vec3(-3.0f, 0.0f, -2.0f),
                                         false,
                                         false);

        CoreComponents::world->add_model(R"(obj/plane3.obj)",
                                         "plane3",
                                         glm::vec3(0.0f, -1.0f, 0.0f),
                                         false,
                                         false);
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

    void Renderer::set_window_callbacks()
    {
        GLFWwindow* window = CoreComponents::window->get_window();

        glfwSetWindowSizeCallback(window, WindowCallbacks::window_resize_callback);
        glfwSetKeyCallback(window, WindowCallbacks::keyboard_callback);
        glfwSetCursorPosCallback(window, WindowCallbacks::mouse_callback);

        // hides mouse cursor and doesn't let it leave the window
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
