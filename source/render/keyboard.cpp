/// 
/// @file keyboard.cpp
/// @author Yasin BASAR
/// @brief Implements the Keyboard class for handling keyboard input events in the graphics engine.
/// @version 1.0.0
/// @date 10/08/2024
/// @copyright (c) 2024 All rights reserved.
/// 

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "keyboard.hpp"
#include "directional_light_shader.hpp"
#include "point_light_shader.hpp"
#include "solid_shader.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

////////////////////////////////////////////////////////////////////////////////
// Forward and Typedef Declarations
////////////////////////////////////////////////////////////////////////////////

namespace YB
{
////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

    Keyboard::Keyboard()
        : m_pressed_keys{std::vector<GLboolean>(512, 0)}
    {
    }

    void Keyboard::key_pressed(int key, int action)
    {
        if (key >= 0 && key < 1024)
        {
            if (action == GLFW_PRESS)
            {
                this->m_pressed_keys[key] = true;
            }
            else if (action == GLFW_RELEASE)
            {
                this->m_pressed_keys[key] = false;
            }
        }
    }

    void Keyboard::key_pressed(float delta_time_in_seconds) const
    {
        this->movement_key_pressed(delta_time_in_seconds);

        this->rotate_or_scale_key_pressed();

        this->polygon_mode_change_key_pressed();

        this->shader_change_key_pressed();
    }

    void Keyboard::movement_key_pressed(float delta_time_in_seconds) const
    {
        if (this->m_pressed_keys[GLFW_KEY_W])
        {
            CoreComponents::camera->move(MOVE_DIRECTION::MOVE_FORWARD,
                                         delta_time_in_seconds);
        }

        if (this->m_pressed_keys[GLFW_KEY_S])
        {
            CoreComponents::camera->move(MOVE_DIRECTION::MOVE_BACKWARD,
                                         delta_time_in_seconds);
        }

        if (this->m_pressed_keys[GLFW_KEY_A])
        {
            CoreComponents::camera->move(MOVE_DIRECTION::MOVE_LEFT,
                                         delta_time_in_seconds);
        }

        if (this->m_pressed_keys[GLFW_KEY_D])
        {
            CoreComponents::camera->move(MOVE_DIRECTION::MOVE_RIGHT,
                                         delta_time_in_seconds);
        }
    }

    void Keyboard::rotate_or_scale_key_pressed() const
    {
        if (this->m_pressed_keys[GLFW_KEY_R])
        {
            DrawComponents::world->increase_rotate_angle(10.0f);
        }

        if (this->m_pressed_keys[GLFW_KEY_Q])
        {
            DrawComponents::world->increase_scale_factor(0.05f);
        }

        if (this->m_pressed_keys[GLFW_KEY_E])
        {
            DrawComponents::world->increase_scale_factor(-0.05f);
        }
    }

    void Keyboard::polygon_mode_change_key_pressed() const
    {
        if (this->m_pressed_keys[GLFW_KEY_T])
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }

        if (this->m_pressed_keys[GLFW_KEY_Y])
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    }

    void Keyboard::shader_change_key_pressed() const
    {
        if (this->m_pressed_keys[GLFW_KEY_J])
        {
            DrawComponents::shader.reset();
            DrawComponents::shader = std::make_shared<DirectionalLightShader>();
            DrawComponents::shader->init_uniforms();
            glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        }

        if (this->m_pressed_keys[GLFW_KEY_K])
        {
            DrawComponents::shader.reset();
            DrawComponents::shader = std::make_shared<PointLightShader>();
            DrawComponents::shader->init_uniforms();
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        }

        if (this->m_pressed_keys[GLFW_KEY_L])
        {
            DrawComponents::shader.reset();
            DrawComponents::shader = std::make_shared<SolidShader>();
            DrawComponents::shader->init_uniforms();
            glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        }
    }

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */
