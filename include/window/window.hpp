/**
 * @file Window.hpp
 * @author Yasin BASAR
 * @brief
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

    class Window
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Window() noexcept = delete;

        Window(Window &&) noexcept = default;

        Window &operator=(Window &&) noexcept = default;

        Window(const Window &) noexcept = default;

        Window &operator=(Window const&) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief It creates GLFW context.
         *
         * @param p_window_name[in] Window Name
         * @param t_window_width[in] Window Width
         * @param t_window_height[in] Window Height
         * @param t_cap_to_screen_frame_rate[in] Set false this parameter for unlimited framerate,
         * otherwise window's framerate will be capped to the screen's framerate.
         */
        Window(const char* p_window_name,
               int t_window_width,
               int t_window_height,
               bool t_cap_to_screen_frame_rate);

        virtual ~Window();

        GLFWwindow* get_window();

        int width;
        int height;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        GLFWwindow* m_window;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif // OPENGL_3D_GRAPHICS_ENGINE_WINDOW_HPP

/* End of File */
