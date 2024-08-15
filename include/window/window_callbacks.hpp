/**
 * @file window_events.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_WINDOW_CALLBACKS_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_WINDOW_CALLBACKS_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <memory>
#include <vector>

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

struct GLFWwindow;

/*******************************************************************************
 * Typedef Declarations
 ******************************************************************************/

typedef unsigned char GLboolean;

namespace YB
{
    /**
     * @class Renderer
     * @brief Forward declaration of actual Renderer class.
     */
    class Renderer;

    /**
     * @class WindowCallbacks
     * @brief Contains static callback functions for window events.
     *
     * This class handles window-related callbacks such as keyboard input,
     * window resizing, and mouse movements. It also manages the current
     * renderer instance.
     */
    class WindowCallbacks
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        WindowCallbacks() noexcept = delete; /**< Deleted default constructor */
        virtual ~WindowCallbacks() noexcept = delete; /**< Deleted default destructor */
        WindowCallbacks(WindowCallbacks &&) noexcept = delete; /**< Deleted default move constructor */
        WindowCallbacks &operator=(WindowCallbacks &&) noexcept = delete; /**< Deleted default move assignment operator */
        WindowCallbacks(const WindowCallbacks &) noexcept = delete; /**< Deleted default copy constructor */
        WindowCallbacks &operator=(WindowCallbacks const &) noexcept = delete; /**< Deleted default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Handles keyboard input events.
         *
         * This function is called when a key is pressed or released. It
         * processes the key events and updates the state accordingly.
         *
         * @param window[in] The GLFW window where the event occurred.
         * @param key[in] The key code of the pressed/released key.
         * @param scancode[in] The system-specific scancode of the key.
         * @param action[in] The action performed (GLFW_PRESS, GLFW_RELEASE).
         * @param mode[in] The modifier keys used.
         */
        static void keyboard_callback(GLFWwindow* window,
                                      int key,
                                      int scancode,
                                      int action,
                                      int mode);

        /**
         * @brief Handles window resize events.
         *
         * This function is called when the window is resized. It updates
         * the viewport to match the new window dimensions.
         *
         * @param window[in] The GLFW window that was resized.
         * @param width[in] The new width of the window.
         * @param height[in] The new height of the window.
         */
        static void window_resize_callback(GLFWwindow* window,
                                           int width,
                                           int height);

        /**
         * @brief Handles mouse movement events.
         *
         * This function is called when the mouse moves within the window.
         * It updates the state of the mouse position.
         *
         * @param window[in] The GLFW window where the event occurred.
         * @param x_pos[in] The new x-coordinate of the mouse cursor.
         * @param y_pos[in] The new y-coordinate of the mouse cursor.
         */
        static void mouse_callback(GLFWwindow* window,
                                   double x_pos,
                                   double y_pos);

        /**
         * @brief Sets the current renderer instance.
         *
         * This function sets the renderer instance that will be used by
         * the callback functions.
         *
         * @param renderer[in] The shared pointer to the renderer instance.
         */
        static void set_current_renderer(std::shared_ptr<YB::Renderer>& renderer);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        static std::vector<GLboolean> m_pressed_keys; ///< Stores the state of pressed keys.
        static std::shared_ptr<YB::Renderer> m_renderer; ///< Shared pointer to the current renderer.

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_WINDOW_CALLBACKS_HPP

/* End of File */
