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

#include "core_components.hpp"
#include "draw_components.hpp"

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
    /**
     * @class Mouse
     * @brief Handles mouse input events to control various aspects of the graphics engine.
     *
     * The Mouse class processes mouse movements and camera's looking direction.
     */
    class Mouse
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Mouse() = delete; /**< Deleted default constructor */
        virtual ~Mouse() noexcept = default; /**< Default destructor */
        Mouse(Mouse &&) noexcept = default; /**< Default move constructor */
        Mouse &operator=(Mouse &&) noexcept = default; /**< Default move assignment operator */
        Mouse(const Mouse &) noexcept = default; /**< Default copy constructor */
        Mouse &operator=(Mouse const &) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructs a Mouse object with specified window dimensions.
         * @param[in] window_width Width of the window
         * @param[in] window_height Height of the window
         */
        Mouse(int window_width, int window_height);

        /**
         * @brief Processes mouse movement to update camera orientation.
         * @param[in] x_pos Current x position of the mouse
         * @param[in] y_pos Current y position of the mouse
         * @param[in] delta_time_in_seconds Time elapsed since the last frame
         */
        void mouse_movement(float x_pos, float y_pos, float delta_time_in_seconds);

        void mouse_scrool();

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        bool m_is_mouse_centered; /**< Indicates if the mouse is centered */
        float m_x_offset;
        float m_y_offset;
        float m_last_x_pos; /**< Last x position of the mouse */
        float m_last_y_pos; /**< Last y position of the mouse */
        float m_mouse_sensitivity; /**< Sensitivity of the mouse movement */
        float m_yaw; /**< Yaw angle for camera rotation */
        float m_pitch; /**< Pitch angle for camera rotation */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_MOUSE_HPP

/* End of File */
