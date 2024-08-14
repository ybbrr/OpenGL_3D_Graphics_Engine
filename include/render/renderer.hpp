/**
 * @file renderer.hpp
 * @author Yasin BASAR
 * @brief Declaration of the Renderer class, which manages the rendering pipeline.
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_RENDERER_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_RENDERER_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "window.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include "model_3d.hpp"
#include "mouse.hpp"
#include "keyboard.hpp"
#include "default_world.hpp"
#include "core_components.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{
    /**
     * @brief Class responsible for managing the rendering process in an OpenGL context.
     */
    class Renderer
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~Renderer() noexcept = default;

        Renderer(Renderer &&) noexcept = default;

        Renderer &operator=(Renderer &&) noexcept = default;

        Renderer(const Renderer &) noexcept = default;

        Renderer &operator=(Renderer const &) noexcept = default;

    /****************************************************************************
     * Public Members
     ***************************************************************************/
    public:

        /**
         * @brief Constructs a new Renderer object.
         *
         * @param window A shared pointer to the Window object.
         * @param camera A shared pointer to the Camera object.
         */
        explicit Renderer();

        /**
         * @brief Renders the scene in a loop until the window is closed.
         */
        void render_scene();

        /**
         * @brief Initializes uniform variables for the shaders.
         */
        void init_uniforms();

        /**
         * @brief Initializes the OpenGL state (e.g., clear color, depth test).
         */
        void init_opengl_state();

        /**
         * @brief Initializes the 3D models in the scene.
         */
        void init_models();

        /**
         * @brief Initializes the shaders used for rendering.
         */
        void init_shaders();

        /**
         * @brief Handles mouse movement events.
         *
         * @param x_pos The x-coordinate of the mouse position.
         * @param y_pos The y-coordinate of the mouse position.
         */
        void mouse_movement(float x_pos, float y_pos);

        /**
         * @brief Handles key press events.
         *
         * @param window The window where the key press occurred.
         * @param key The key that was pressed.
         * @param action The action (press/release) associated with the key.
         */
        void key_pressed(GLFWwindow* window,
                         int key,
                         int action);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief Sets the callback functions for the window.
         */
        void set_window_callbacks();

        std::shared_ptr<YB::Window> m_window; /**< Shared pointer to the Window object. */
        std::shared_ptr<YB::Camera> m_camera; /**< Shared pointer to the Camera object. */
        std::shared_ptr<YB::Mouse> m_mouse; /**< Shared pointer to the Mouse object. */
        std::shared_ptr<YB::Keyboard> m_keyboard; /**< Shared pointer to the Keyboard object. */
        std::shared_ptr<YB::World> m_world; /**< Shared pointer to the World object. */
        std::shared_ptr<YB::Shader> m_current_shader; /**< Shared pointer to the Shader object. */
        float m_delta_time_in_seconds; /**< Delta time between frames in milliseconds. */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_RENDERER_HPP

/* End of File */

