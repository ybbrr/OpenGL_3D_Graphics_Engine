/**
 * @file keyboard.hpp
 * @author Yasin BASAR
 * @brief Declares the Keyboard class for handling keyboard input events in the graphics engine.
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_KEYBOARD_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_KEYBOARD_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include "core_components.hpp"
#include "draw_components.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glfw/glfw3.h>

/*******************************************************************************
 * Typedef Declarations
 ******************************************************************************/

typedef unsigned char GLboolean;
typedef int GLint;

namespace YB
{

    /**
     * @class Keyboard
     * @brief Handles keyboard input events to control various aspects of the graphics engine.
     *
     * The Keyboard class processes key presses to control camera movement, object transformations,
     * polygon mode, and shader changes in the graphics engine.
     */
    class Keyboard
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~Keyboard() noexcept = default; /**< Default destructor */
        Keyboard(Keyboard &&) noexcept = default; /**< Default move constructor */
        Keyboard &operator=(Keyboard &&) noexcept = default; /**< Default move assignment operator */
        Keyboard(const Keyboard &) noexcept = default; /**< Default copy constructor */
        Keyboard &operator=(Keyboard const &) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructs a Keyboard instance.
         *
         * Initializes the state of the keyboard with no keys pressed.
         */
        explicit Keyboard();

        /**
         * @brief Processes a key press event.
         *
         * @param[in] key The key code of the pressed or released key.
         * @param[in] action The action (press or release) associated with the key event.
         */
        void key_pressed(int key, int action);

        /**
         * @brief Updates the keyboard state based on the elapsed time.
         *
         * @param[in] delta_time_in_seconds The time elapsed since the last update.
         */
        void key_pressed(float delta_time_in_seconds);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief Handles movement-related key presses.
         *
         * @param[in] delta_time_in_seconds The time elapsed since the last update.
         */
        void movement_key_pressed(float delta_time_in_seconds);

        /**
         * @brief Handles rotation or scaling key presses.
         */
        void rotate_or_scale_key_pressed();

        /**
         * @brief Handles polygon mode change key presses.
         */
        void polygon_mode_change_key_pressed();

        /**
         * @brief Handles shader change key presses.
         */
        void shader_change_key_pressed();

        /**
         * @brief Vector storing the state of each key (pressed or not).
         */
        std::vector<GLboolean> m_pressed_keys;

/***************************************************************************
 * Protected Members
 **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_KEYBOARD_HPP

/* End of File */
