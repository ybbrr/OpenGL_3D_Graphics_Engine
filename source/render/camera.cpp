///
/// @file camera.cpp
/// @author Yasin BASAR
/// @brief This file contains the implementation of the Camera class.
/// @version 1.0.0
/// @date 09/08/2024
/// @copyright (c) 2024 All rights reserved.
///

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include "camera.hpp"
#include <cmath>

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

namespace YB
{
////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

    Camera::Camera(const glm::vec3& camera_position,
                   const glm::vec3& camera_target,
                   const glm::vec3& camera_up)
        : m_camera_position{camera_position},
          m_camera_up_direction{camera_up},
          m_camera_front_direction{},
          m_camera_right_direction{},
          m_view_matrix{1.0f},
          m_camera_speed{10.f}
    {
        this->m_camera_front_direction
            = glm::normalize(camera_target - this->m_camera_position);

        this->m_camera_right_direction
            = glm::normalize(glm::cross(this->m_camera_up_direction,
                                        this->m_camera_front_direction));

        this->m_view_matrix = glm::lookAt(this->m_camera_position,
                                          camera_target,
                                          this->m_camera_up_direction);
    }

    void Camera::move(MOVE_DIRECTION direction, float delta_time_in_seconds)
    {
        std::lock_guard lock(this->m_mutex);

        if (direction == MOVE_DIRECTION::MOVE_FORWARD)
        {
            this->m_camera_position += delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_front_direction;
        }
        else if (direction == MOVE_DIRECTION::MOVE_BACKWARD)
        {
            this->m_camera_position -= delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_front_direction;
        }
        else if (direction == MOVE_DIRECTION::MOVE_RIGHT)
        {
            this->m_camera_position -= delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_right_direction;
        }
        else if (direction == MOVE_DIRECTION::MOVE_LEFT)
        {
            this->m_camera_position += delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_right_direction;
        }

        this->m_camera_right_direction
            = glm::normalize(glm::cross(this->m_camera_up_direction,
                                        this->m_camera_front_direction));

        this->m_view_matrix = glm::lookAt(this->m_camera_position,
                                          this->m_camera_position + this->m_camera_front_direction,
                                          this->m_camera_up_direction);
    }

    void Camera::rotate(float pitch, float yaw)
    {
        glm::vec3 camera_rotate_direction;

        camera_rotate_direction.x = std::cos(yaw) * std::cos(pitch);
        camera_rotate_direction.y = std::sin(pitch);
        camera_rotate_direction.z = std::sin(yaw) * std::cos(pitch);

        {
            std::lock_guard lock(this->m_mutex);

            this->m_camera_front_direction = glm::normalize(camera_rotate_direction);

            this->m_view_matrix = glm::lookAt(this->m_camera_position,
                                              this->m_camera_position + this->m_camera_front_direction,
                                              this->m_camera_up_direction);
        }
    }

    glm::mat4 Camera::get_view_matrix() noexcept
    {
        std::lock_guard lock(this->m_mutex);

        return this->m_view_matrix;
    }

    glm::vec3 Camera::get_camera_direction() noexcept
    {
        std::lock_guard lock(this->m_mutex);

        return this->m_camera_front_direction;
    }

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */