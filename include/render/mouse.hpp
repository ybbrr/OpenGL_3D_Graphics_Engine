/**
 * @file mouse.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_MOUSE_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_MOUSE_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "camera.hpp"
#include "shader.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glm/glm.hpp> //core glm functionality
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

/*******************************************************************************
 * Typedef Declarations
 ******************************************************************************/

typedef int GLint;

namespace YB
{
    class Mouse
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Mouse() = delete;

        virtual ~Mouse() noexcept = default;

        Mouse(Mouse &&) noexcept = default;

        Mouse &operator=(Mouse &&) noexcept = default;

        Mouse(const Mouse &) noexcept = default;

        Mouse &operator=(Mouse const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

    Mouse(int window_width, int window_height);

    void mouse_movement(float x_pos,
                        float y_pos,
                        float delta_time_in_millisecs,
                        GLint view_loc,
                        std::shared_ptr<YB::Camera>& camera,
                        std::shared_ptr<YB::Shader>& basic_shader);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief
         *
         */
        bool m_is_mouse_centered;

        /**
         * @brief
         *
         */
        float m_last_x_pos;

        /**
         * @brief
         *
         */
        float m_last_y_pos;

        /**
         * @brief
         *
         */
        float m_sensitivity;

        /**
         * @brief
         *
         */
        float m_yaw;

        /**
         * @brief
         *
         */
        float m_pitch;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_MOUSE_HPP

/* End of File */
