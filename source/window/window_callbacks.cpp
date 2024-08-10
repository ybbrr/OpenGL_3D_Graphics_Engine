/**
 * @file window_events.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "window_callbacks.hpp"
#include "renderer.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

#include <glad/glad.h>

namespace YB
{

/*******************************************************************************
 * Public Static Members
 ******************************************************************************/

/*******************************************************************************
 * Private Static Members
 ******************************************************************************/

    std::shared_ptr<YB::Renderer> WindowCallbacks::m_renderer = nullptr;

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    void YB::WindowCallbacks::keyboard_callback(GLFWwindow *window,
                                                int key,
                                                int scancode,
                                                int action,
                                                int mode)
    {
        m_renderer->key_pressed(window, key, action);
    }

    void WindowCallbacks::window_resize_callback(GLFWwindow *window,
                                                 int width,
                                                 int height)
    {
        glViewport(0, 0, width, height);
    }

    void WindowCallbacks::mouse_callback(GLFWwindow *window,
                                         double x_pos,
                                         double y_pos)
    {
        m_renderer->mouse_movement(static_cast<float>(x_pos),
                                   static_cast<float>(y_pos));
    }

    void WindowCallbacks::set_current_renderer(std::shared_ptr<YB::Renderer>& renderer)
    {
        m_renderer = renderer;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
