///
/// @file renderer.hpp
/// @author Yasin BASAR
/// @brief Declaration of the Renderer class, which manages the rendering pipeline.
/// @version 1.0.0
/// @date 10/08/2024
/// @copyright (c) 2024 All rights reserved.
///

#ifndef OPENGL_3D_GRAPHICS_ENGINE_RENDERER_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_RENDERER_HPP

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "core_components.hpp"
#include "default_world.hpp"
#include "directional_light_shader.hpp"
#include "mouse.hpp"
#include "keyboard.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

namespace YB
{
    ///
    /// @class Renderer
    /// @brief Class responsible for managing the rendering process in an OpenGL context.
    ///
    class Renderer
    {
    public:
    ////////////////////////////////////////////////////////////////////////////
    // Special Members
    ////////////////////////////////////////////////////////////////////////////

        ~Renderer() noexcept = default; /**< Default destructor */
        Renderer(Renderer &&) noexcept = default; /**< Default move constructor */
        Renderer &operator=(Renderer &&) noexcept = default; /**< Default move assignment operator */
        Renderer(const Renderer &) noexcept = default; /**< Default copy constructor */
        Renderer &operator=(Renderer const &) noexcept = default; /**< Default copy assignment operator */

    ////////////////////////////////////////////////////////////////////////////
    // Public Members
    ////////////////////////////////////////////////////////////////////////////

        ///
        /// @brief Constructs a new Renderer object.
        ///
        ///
        explicit Renderer();

        ///
        /// @brief Renders the scene in a loop until the window is closed.
        ///
        void render_scene();

        ///
        /// @brief Initializes the 3D models in the scene.
        ///
        void init_models();

        ///
        /// @brief Handles mouse movement events.
        ///
        /// @param[in] x_pos The x-coordinate of the mouse position.
        /// @param[in] y_pos The y-coordinate of the mouse position.
        ///
        void mouse_movement(float x_pos, float y_pos) const;

        ///
        /// @brief Handles key press events.
        ///
        /// @param[in] window The window where the key press occurred.
        /// @param[in] key The key that was pressed.
        /// @param[in] action The action (press/release) associated with the key.
        ///
        void key_pressed(GLFWwindow* window, int key, int action) const;

    ////////////////////////////////////////////////////////////////////////////
    // Private Members
    ////////////////////////////////////////////////////////////////////////////
    private:

        ///
        /// @brief Initializes the OpenGL state (e.g., clear color, depth test).
        ///
        void init_opengl_state();

        /// 
        /// @brief Sets the callback functions for the window.
        /// 
        static void set_window_callbacks();

        std::shared_ptr<Mouse> m_mouse; /**< Shared pointer to the Mouse object. */
        std::shared_ptr<Keyboard> m_keyboard; /**< Shared pointer to the Keyboard object. */
        std::shared_ptr<World> m_world; /**< Shared pointer to the World object. */
        std::shared_ptr<Shader> m_current_shader; /**< Shared pointer to the Shader object. */
        float m_delta_time_in_seconds; /**< Delta time between frames in milliseconds. */

    ////////////////////////////////////////////////////////////////////////////
    // Protected Members
    ////////////////////////////////////////////////////////////////////////////
    protected:

        // Data

    };
} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_RENDERER_HPP

/* End of File */

