///
/// @file camera.hpp
/// @author Yasin BASAR
/// @brief This file contains the definition of the Camera class.
/// @version 1.0.0
/// @date 09/08/2024
/// @copyright (c) 2024 All rights reserved.
///

#ifndef OPENGL_3D_GRAPHICS_ENGINE_CAMERA_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_CAMERA_HPP

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include <mutex>
#include "types_enums.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

namespace YB
{
    /// 
    /// @class Camera
    /// @brief Represents a camera in a 3D graphics engine.
    ///
    /// The Camera class handles the position, direction, and movement of a camera in a 3D space.
    /// It allows for updating the camera's position and orientation and obtaining the view matrix.
    ///
    class Camera
    {
    public:
    ////////////////////////////////////////////////////////////////////////////
    // Special Members
    ////////////////////////////////////////////////////////////////////////////

        Camera() noexcept = delete; /**< Deleted default constructor */
        ~Camera() noexcept = default; /**< Default destructor */
        Camera(Camera &&) noexcept = delete; /**< Deleted move constructor */
        Camera &operator=(Camera &&) noexcept = delete; /**< Deleted move assignment operator */
        Camera(const Camera &) noexcept = delete; /**< Deleted default copy constructor */
        Camera &operator=(Camera &) noexcept = delete; /**< Deleted default copy assignment operator */

    ////////////////////////////////////////////////////////////////////////////
    // Public Members
    ////////////////////////////////////////////////////////////////////////////

        ///
        /// @brief Constructs a Camera object with specified position, target, and up vector.
        ///
        /// @param[in] camera_position The position of the camera in 3D space.
        /// @param[in] camera_target The target point that the camera is looking at.
        /// @param[in] camera_up The up direction vector of the camera.
        ///
        Camera(const glm::vec3& camera_position,
               const glm::vec3& camera_target,
               const glm::vec3& camera_up);

        ///
        ///@brief Updates the camera's position based on movement direction.
        ///
        ///@param[in] direction The direction of movement (forward, backward, right, left).
        ///@param[in] delta_time_in_seconds The time elapsed since the last update.
        ///
        void move(MOVE_DIRECTION direction, float delta_time_in_seconds);

        ///
        /// @brief Rotates the camera based on pitch and yaw angles.
        ///        Accepts pitch and yaw values in Radians.
        ///
        /// @param[in] pitch The angle(radians) of rotation around the y-axis.
        /// @param[in] yaw The angle(radians) of rotation around the x-axis.
        ///
        void rotate(float pitch, float yaw);

        ///
        /// @brief Gets the view matrix of the camera.
        ///
        /// @return The view matrix.
        ///
        glm::mat4 get_view_matrix() noexcept;

        /// 
        /// @brief Gets the direction the camera is facing.
        /// 
        /// @return The camera's front direction vector.
        /// 
        glm::vec3 get_camera_direction() noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // Private Members
    ////////////////////////////////////////////////////////////////////////////
    private:

        glm::vec3 m_camera_position; /**< The current position of the camera. */
        glm::vec3 m_camera_up_direction; /**< The up direction of the camera. */
        glm::vec3 m_camera_front_direction; /**< The direction the camera is facing. */
        glm::vec3 m_camera_right_direction; /**< The right direction of the camera. */
        glm::mat4 m_view_matrix; /**< The view matrix of the camera. */
        float m_camera_speed; /**< The movement speed of the camera. */
        std::mutex m_mutex; /**< Mutex for thread-safe access to camera data. */

    ////////////////////////////////////////////////////////////////////////////
    // Protected Members
    ////////////////////////////////////////////////////////////////////////////
    protected:

        // Data

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_CAMERA_HPP

/* End of File */