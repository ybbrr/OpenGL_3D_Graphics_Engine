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
        while ((error_code = glGetError()) != GL_NO_ERROR) {
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
            std::cout << error << " | " << file << " (" << line << ")" << "\n";
        }
        return error_code;
    }
#define glCheckError() glCheckError_(__FILE__, __LINE__)

    Renderer::Renderer(std::shared_ptr<YB::Window>& window,
                       std::shared_ptr<YB::Camera>& camera)
        : m_window{window},
          m_camera{camera},
          m_mouse{new YB::Mouse()},
          m_keyboard{new YB::Keyboard()},
          m_world(new YB::DefaultWorld()),
          m_basic_shader{new YB::Shader()},
          m_delta_time_in_millisecs{}
    {
        this->set_window_callbacks();
    }

    void Renderer::render_scene()
    {
        GLFWwindow* window = this->m_window->get_window();

        float current_time_stamp{};
        float last_time_stamp{};

        glCheckError();

        while (!glfwWindowShouldClose(window))
        {
            current_time_stamp = 1000.0f * static_cast<float>(glfwGetTime()) / 20.0f;
            this->m_delta_time_in_millisecs = current_time_stamp - last_time_stamp;

            GLint view_loc = this->m_world->get_view_loc();

            this->m_keyboard->movement_key_pressed(this->m_delta_time_in_millisecs,
                                                   view_loc,
                                                   this->m_camera,
                                                   this->m_basic_shader);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClear(GL_STENCIL_BUFFER_BIT);

            this->m_world->render_models(this->m_basic_shader);

            glfwPollEvents();
            glfwSwapBuffers(window);

            glCheckError();

            last_time_stamp = current_time_stamp;
        }
    }

    void Renderer::mouse_movement(float x_pos, float y_pos)
    {
        GLint view_loc = this->m_world->get_view_loc();

        this->m_mouse->mouse_movement(x_pos,
                                      y_pos,
                                      this->m_delta_time_in_millisecs,
                                      view_loc,
                                      this->m_camera,
                                      this->m_basic_shader);
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

    void Renderer::init_uniforms()
    {
        this->m_world->init_uniforms(this->m_window,
                                     this->m_camera,
                                     this->m_basic_shader);
    }

    void Renderer::init_opengl_state()
    {
        window_dims_t window_dims = this->m_window->get_window_dimensions();

        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glViewport(0, 0, window_dims.width, window_dims.height);
        glEnable(GL_FRAMEBUFFER_SRGB);
        glEnable(GL_DEPTH_TEST); // enable depth-testing
        glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
        glEnable(GL_CULL_FACE); // cull face
        glCullFace(GL_BACK); // cull back face
        glFrontFace(GL_CCW); // GL_CCW for counter clock-wise
    }

    void Renderer::init_models()
    {
        this->m_world->add_model(R"(..\__resources__\obj\teapot20segUT.obj)",
                                 "the_teapot",
                                 glm::vec3(0.0f, 0.0f, 0.0f));

        this->m_world->add_model(R"(..\__resources__\obj\cube.obj)",
                                 "the_cube",
                                 glm::vec3(3.0f, 0.0f, 0.0f));

        this->m_world->add_model(R"(..\__resources__\obj\sphere.obj)",
                                 "the_sphere",
                                 glm::vec3(-3.0f, 0.0f, 2.0f));

        this->m_world->add_model(R"(..\__resources__\obj\monkey.obj)",
                                 "the_monkey",
                                 glm::vec3(-3.0f, 0.0f, -2.0f));

        this->m_world->add_model(R"(..\__resources__\obj\plane3.obj)",
                                 "the_plane3",
                                 glm::vec3(0.0f, -1.0f, 0.0f));
    }

    void Renderer::init_shaders()
    {
        this->m_basic_shader->load_shader(R"(../__resources__/shader/basic_vert_directional_light.glsl)",
                                          R"(../__resources__/shader/basic_frag_directional_light.glsl)");
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

    void Renderer::set_window_callbacks()
    {
        GLFWwindow* window = this->m_window->get_window();

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
