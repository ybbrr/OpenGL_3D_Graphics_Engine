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

    Mouse::Mouse(int window_width, int window_height)
        : m_is_mouse_centered{true},
          m_last_x_pos{static_cast<float>(window_width) / 2.0f},
          m_last_y_pos{static_cast<float>(window_height) / 2.0f},
          m_mouse_sensitivity{10.0f}
    {
        glm::vec3 camera_direction = CoreComponents::camera->get_camera_direction();
        this->m_yaw = glm::degrees(std::atan2(camera_direction.z, camera_direction.x));
        this->m_pitch = glm::degrees(std::asin(camera_direction.y));
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

        this->m_x_offset = x_pos - this->m_last_x_pos;
        this->m_y_offset = this->m_last_y_pos - y_pos;
        this->m_last_x_pos = x_pos;
        this->m_last_y_pos = y_pos;

        float move_velocity = this->m_mouse_sensitivity * delta_time_in_seconds;
        this->m_x_offset *= move_velocity;
        this->m_y_offset *= move_velocity;

        this->m_yaw += this->m_x_offset;
        this->m_pitch += this->m_y_offset;

        this->m_pitch = glm::clamp(this->m_pitch, -89.9f, 89.9f);

        CoreComponents::camera->rotate(glm::radians(this->m_pitch),
                                       glm::radians(this->m_yaw));
    }

    void Mouse::mouse_scrool()
    {
        CoreComponents::camera->fov.fov_angle -= 1.0f;

        CoreComponents::camera->fov.fov_angle
            = glm::clamp(CoreComponents::camera->fov.fov_angle,
                         CoreComponents::camera->fov.min_fov_angle,
                         CoreComponents::camera->fov.max_fov_angle);

        DrawComponents::shader->projection_matrix
            = glm::perspective(glm::radians(CoreComponents::camera->fov.fov_angle),
                               static_cast<float>(CoreComponents::window->width) / static_cast<float>(CoreComponents::window->height),
                               CoreComponents::camera->visible_range.z_near,
                               CoreComponents::camera->visible_range.z_far);

        glUniformMatrix4fv(DrawComponents::shader->projection_matrix_location,
                           1,
                           GL_FALSE,
                           glm::value_ptr(DrawComponents::shader->projection_matrix));
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
