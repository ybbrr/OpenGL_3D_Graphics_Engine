/**
 * @file window.hpp
 * @author Yasin BASAR
 * @brief Defines the `Window` class for managing a GLFW window and OpenGL context.
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_WINDOW_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_WINDOW_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "types_enums.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

struct GLFWwindow;

namespace YB
{

    /**
     * @class Window
     * @brief Manages a GLFW window and OpenGL context.
     *
     * This class initializes GLFW, creates a window, sets up OpenGL context, and manages
     * the window properties.
     */
    class Window
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Window() noexcept = delete; /**< Deleted default destructor */
        Window(Window &&) noexcept = default; /**< Default move constructor */
        Window &operator=(Window &&) noexcept = default; /**< Default move assignment operator */
        Window(const Window &) noexcept = default; /**< Default copy constructor */
        Window &operator=(Window const&) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructs a `Window` instance and initializes GLFW and OpenGL context.
         *
         * @param p_window_name[in] The name of the window.
         * @param t_window_width[in] The width of the window.
         * @param t_window_height[in] The height of the window.
         * @param t_cap_to_screen_frame_rate[in] If true, caps the framerate to the screen's refresh rate.
         */
        explicit Window(const char* p_window_name,
                        int t_window_width,
                        int t_window_height,
                        bool t_cap_to_screen_frame_rate);

        /**
         * @brief Destroys the `Window` instance and cleans up resources.
         */
        virtual ~Window();

        /**
         * @brief Returns the GLFW window pointer.
         *
         * @return Pointer to the GLFW window.
         */
        GLFWwindow* get_window();

        int width;  /**< The width of the window. */
        int height; /**< The height of the window. */

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        GLFWwindow* m_window; /**< The internal GLFW window pointer. */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif // OPENGL_3D_GRAPHICS_ENGINE_WINDOW_HPP

/* End of File */
