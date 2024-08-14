/**
 * @file keyboard.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "keyboard.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

#include <glm/glm.hpp> //core glm functionality
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    Keyboard::Keyboard()
        : m_camera{CoreComponents::get_camera()},
          m_world{CoreComponents::get_world()},
          m_current_shader{DrawComponents::get_shader()},
          m_pressed_keys{std::vector<GLboolean>(512, 0)}
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

    void Keyboard::key_pressed(float delta_time_in_seconds)
    {
        glm::mat4 view_matrix = this->m_camera->get_view_matrix();

        this->movement_key_pressed(delta_time_in_seconds);

        this->rotate_or_scale_key_pressed();

        this->polygon_mode_change_key_pressed();
    }

    void Keyboard::movement_key_pressed(float delta_time_in_seconds)
    {
        if (this->m_pressed_keys[GLFW_KEY_W])
        {
            this->m_camera->move(YB::MOVE_DIRECTION::MOVE_FORWARD,
                                 delta_time_in_seconds);
        }

        if (this->m_pressed_keys[GLFW_KEY_S])
        {
            this->m_camera->move(YB::MOVE_DIRECTION::MOVE_BACKWARD,
                                 delta_time_in_seconds);
        }

        if (this->m_pressed_keys[GLFW_KEY_A])
        {
            this->m_camera->move(YB::MOVE_DIRECTION::MOVE_LEFT,
                                 delta_time_in_seconds);
        }

        if (this->m_pressed_keys[GLFW_KEY_D])
        {
            this->m_camera->move(YB::MOVE_DIRECTION::MOVE_RIGHT,
                                 delta_time_in_seconds);
        }
    }

    void Keyboard::rotate_or_scale_key_pressed()
    {
        if (this->m_pressed_keys[GLFW_KEY_R])
        {
            this->m_world->increase_rotate_angle(10.0f);
        }

        if (this->m_pressed_keys[GLFW_KEY_Q])
        {
            this->m_world->increase_scale_factor(0.05f);
        }

        if (this->m_pressed_keys[GLFW_KEY_E])
        {
            this->m_world->increase_scale_factor(-0.05f);
        }
    }

    void Keyboard::polygon_mode_change_key_pressed()
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

    void Keyboard::shader_change_key_pressed()
    {
        //TO-DO
    }


/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
