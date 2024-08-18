///
/// @file window_callbacks.cpp
/// @author Yasin BASAR
/// @brief Implements the window event callback functions.
/// @version 1.0.0
/// @date 10/08/2024
/// @copyright (c) 2024 All rights reserved.
///

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "window_callbacks.hpp"
#include "renderer.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

#include <glad/glad.h>

namespace YB
{

    std::shared_ptr<Renderer> WindowCallbacks::m_renderer{nullptr};

////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

    void WindowCallbacks::keyboard_callback(GLFWwindow *window,
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

    void WindowCallbacks::set_current_renderer(const std::shared_ptr<Renderer>& renderer)
    {
        m_renderer = renderer;
    }

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */
