/**
 * @file main.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#include <iostream>

#include "renderer.hpp"
#include "window_callbacks.hpp"

int main()
{
    std::shared_ptr<YB::Window> window{
        new YB::Window("OpenGL_3D_Graphics_Engine",
                       1280,
                       720,
                       true)
    };

    std::shared_ptr<YB::Camera> camera{
        new YB::Camera(glm::vec3(3.0f, 3.0f, 10.0f),
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f))
    };

    std::shared_ptr<YB::Renderer> renderer{new YB::Renderer(window, camera)};

    YB::WindowCallbacks::set_current_renderer(renderer);

    renderer->init_opengl_state();
    renderer->init_models();
    renderer->init_shaders();
    renderer->init_uniforms();

    renderer->render_scene();

    return 0;
}

/* end of file */
