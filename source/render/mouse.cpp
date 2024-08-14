/**
 * @file mouse.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "mouse.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    Mouse::Mouse(std::shared_ptr<YB::Window>& window,
                 std::shared_ptr<YB::Camera>& camera)
        : m_camera{camera},
          m_is_mouse_centered{true},
          m_last_x_pos{static_cast<float>(window->width) / 2.0f},
          m_last_y_pos{static_cast<float>(window->height) / 2.0f},
          m_yaw{-90.0f},
          m_pitch{0.0f},
          m_mouse_sensitivity{10.0f}
    {
    }

    void Mouse::mouse_movement(float x_pos,
                               float y_pos,
                               float delta_time_in_seconds)
    {
        if (this->m_is_mouse_centered)
        {
            this->m_last_x_pos = x_pos;
            this->m_last_y_pos = y_pos;
            this->m_is_mouse_centered = false;
        }

        float x_offset = x_pos - this->m_last_x_pos;
        float y_offset = this->m_last_y_pos - y_pos;
        this->m_last_x_pos = x_pos;
        this->m_last_y_pos = y_pos;

        float move_velocity = this->m_mouse_sensitivity * delta_time_in_seconds;
        x_offset *= move_velocity;
        y_offset *= move_velocity;

        this->m_yaw += x_offset;
        this->m_pitch += y_offset;

        this->m_pitch = glm::clamp(this->m_pitch, -89.9f, 89.9f);

        this->m_camera->rotate(glm::radians(this->m_pitch),
                               glm::radians(this->m_yaw));
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
