/**
 * @file camera.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "camera.hpp"

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
          m_camera_rotate_direction{},
          m_camera_speed{10.f}
    {
        this->m_camera_front_direction
            = glm::normalize(this->m_camera_position - this->m_camera_target);

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
    void Camera::move(MOVE_DIRECTION direction, float delta_time_in_seconds)
    {
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
        this->m_camera_rotate_direction.x = cos(yaw) * cos(pitch);
        this->m_camera_rotate_direction.y = sin(pitch);
        this->m_camera_rotate_direction.z = sin(yaw) * cos(pitch);

        this->m_camera_front_direction = glm::normalize(this->m_camera_rotate_direction);

        this->m_view_matrix = glm::lookAt(this->m_camera_position,
                                          this->m_camera_position + this->m_camera_front_direction,
                                          this->m_camera_up_direction);
    }

    /**
     * @brief
     *
     */
    glm::mat4 Camera::get_view_matrix()
    {
        return this->m_view_matrix;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
