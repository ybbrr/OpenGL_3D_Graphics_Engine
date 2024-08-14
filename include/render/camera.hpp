/**
 * @file camera.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_CAMERA_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_CAMERA_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <mutex>
#include <string>
#include "types_enums.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace YB
{
    class Camera
    {
    public:
        /***************************************************************************
         * Special Members
         **************************************************************************/

        Camera() noexcept = delete;

        virtual ~Camera() noexcept = default;

        Camera(Camera &&) noexcept = default;

        Camera &operator=(Camera &&) noexcept = default;

        Camera(const Camera &) noexcept = delete;

        Camera &operator=(Camera &) noexcept = delete;

        /***************************************************************************
         * Public Members
         **************************************************************************/

        /**
         * @brief Camera constructor
         *
         */
        Camera(glm::vec3 camera_position,
               glm::vec3 camera_target,
               glm::vec3 camera_up);

        /**
         * @brief Update the camera internal parameters following a camera move event
         *
         */
        void move(MOVE_DIRECTION direction, float delta_time_in_seconds);

        /**
         * @brief Update the camera internal parameters following a camera rotate event
         *
         * @param[in] pitch Camera rotation around the y axis
         * @param[in] yaw Camera rotation around the x axis
         */
        void rotate(float pitch, float yaw);

        /**
         * @brief
         *
         */
        glm::mat4 get_view_matrix() noexcept;

        glm::vec3 get_camera_direction() noexcept;

        /***************************************************************************
         * Private Members
         **************************************************************************/
    private:

        glm::vec3 m_camera_position;
        glm::vec3 m_camera_target;
        glm::vec3 m_camera_front_direction;
        glm::vec3 m_camera_right_direction;
        glm::vec3 m_camera_up_direction;

        glm::mat4 m_view_matrix;

        float m_camera_speed;

        std::mutex m_mutex;

        /***************************************************************************
         * Protected Members
         **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_CAMERA_HPP

/* End of File */