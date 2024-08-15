/**
 * @file main.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#include "renderer.hpp"
#include "window_callbacks.hpp"

int main()
{
    YB::CoreComponents::window
        = std::make_shared<YB::Window>("OpenGL_3D_Graphics_Engine",
                                       1280,
                                       720,
                                       true);

    if (YB::CoreComponents::window == nullptr)
    {
        int a = 1;
    }

    YB::CoreComponents::camera
        = std::make_shared<YB::Camera>(glm::vec3(3.0f, 3.0f, 10.0f),
                                       glm::vec3(0.0f, 0.0f, 0.0f),
                                       glm::vec3(0.0f, 1.0f, 0.0f));

    std::shared_ptr<YB::Renderer> renderer{new YB::Renderer()};
    YB::WindowCallbacks::set_current_renderer(renderer);

    renderer->init_models();

    renderer->render_scene();

    return 0;
}

/* end of file */
