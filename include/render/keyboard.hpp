/**
 * @file keyboard.hpp
 * @author Yasin BASAR
 * @brief
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
#include "camera.hpp"
#include "shader.hpp"
#include "world.hpp"

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

    class Keyboard
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~Keyboard() noexcept = default;

        Keyboard(Keyboard &&) noexcept = default;

        Keyboard &operator=(Keyboard &&) noexcept = default;

        Keyboard(const Keyboard &) noexcept = default;

        Keyboard &operator=(Keyboard const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        Keyboard();

        void key_pressed(int key,
                         int action);

        void movement_key_pressed(float delta_time_in_millisecs,
                                  GLint view_loc,
                                  std::shared_ptr<YB::Camera>& camera,
                                  std::shared_ptr<YB::Shader>& basic_shader,
                                  std::shared_ptr<YB::World>& world);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

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
