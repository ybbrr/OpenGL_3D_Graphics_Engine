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
    class Renderer;

    class WindowCallbacks
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        WindowCallbacks() noexcept = delete;

        virtual ~WindowCallbacks() noexcept = delete;

        WindowCallbacks(WindowCallbacks &&) noexcept = delete;

        WindowCallbacks &operator=(WindowCallbacks &&) noexcept = delete;

        WindowCallbacks(const WindowCallbacks &) noexcept = delete;

        WindowCallbacks &operator=(WindowCallbacks const &) noexcept = delete;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Press ESC to close the window.
         *
         */
        static void keyboard_callback(GLFWwindow* window,
                                      int key,
                                      int scancode,
                                      int action,
                                      int mode);

        /**
         * @brief Window resize callback.
         *
         */
        static void window_resize_callback(GLFWwindow* window,
                                           int width,
                                           int height);

        /**
         * @brief
         *
         */
        static void mouse_callback(GLFWwindow* window,
                                   double x_pos,
                                   double y_pos);

        /**
         * @brief
         *
         */
        static void set_current_renderer(std::shared_ptr<YB::Renderer>& renderer);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief
         *
         */
        static std::vector<GLboolean> m_pressed_keys;

        /**
         * @brief
         *
         */
        static std::shared_ptr<YB::Renderer> m_renderer;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_WINDOW_CALLBACKS_HPP

/* End of File */
