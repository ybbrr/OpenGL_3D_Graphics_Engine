/**
 * @file camera.cpp
 * @author Yasin BASAR
 * @brief This file contains the implementation of the Camera class.
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "camera.hpp"

#include <cmath>

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{
/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    /**
     * @brief
     *
     */
    Camera::Camera(glm::vec3 camera_position,
                   glm::vec3 camera_target,
                   glm::vec3 camera_up)
        : m_camera_position{camera_position},
          m_camera_target{camera_target},
          m_camera_up_direction{camera_up},
          m_camera_front_direction{},
          m_camera_right_direction{},
          m_view_matrix{glm::mat4(1.0f)},
          m_camera_speed{10.f}
    {
        this->m_camera_front_direction
            = glm::normalize(this->m_camera_target - this->m_camera_position);

        this->m_camera_right_direction
            = glm::normalize(glm::cross(this->m_camera_up_direction,
                                        this->m_camera_front_direction));

        this->m_view_matrix = glm::lookAt(this->m_camera_position,
                                          this->m_camera_target,
                                          this->m_camera_up_direction);
    }

    /**
     * @brief
     *
     */
    void Camera::move(const MOVE_DIRECTION direction, const float delta_time_in_seconds)
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);

        if (direction == YB::MOVE_DIRECTION::MOVE_FORWARD)
        {
            this->m_camera_position += delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_front_direction;
        }
        else if (direction == YB::MOVE_DIRECTION::MOVE_BACKWARD)
        {
            this->m_camera_position -= delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_front_direction;
        }
        else if (direction == YB::MOVE_DIRECTION::MOVE_RIGHT)
        {
            this->m_camera_position -= delta_time_in_seconds *
                                       this->m_camera_speed *
                                       this->m_camera_right_direction;
        }
        else if (direction == YB::MOVE_DIRECTION::MOVE_LEFT)
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

    /**
     * @brief
     *
     */
    void Camera::rotate(float pitch, float yaw)
    {
        glm::vec3 camera_rotate_direction;

        camera_rotate_direction.x = std::cos(yaw) * std::cos(pitch);
        camera_rotate_direction.y = std::sin(pitch);
        camera_rotate_direction.z = std::sin(yaw) * std::cos(pitch);

        {
            std::lock_guard<std::mutex> lock(this->m_mutex);

            this->m_camera_front_direction = glm::normalize(camera_rotate_direction);

            this->m_view_matrix = glm::lookAt(this->m_camera_position,
                                              this->m_camera_position + this->m_camera_front_direction,
                                              this->m_camera_up_direction);
        }
    }

    /**
     * @brief
     *
     */
    glm::mat4 Camera::get_view_matrix() noexcept
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);

        return this->m_view_matrix;
    }

    glm::vec3 Camera::get_camera_direction() noexcept
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);

        return this->m_camera_front_direction;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */