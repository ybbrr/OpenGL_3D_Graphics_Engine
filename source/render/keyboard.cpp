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

    Keyboard::Keyboard(std::shared_ptr<YB::Camera> &camera,
                       std::shared_ptr<YB::Shader> &basic_shader,
                       std::shared_ptr<YB::World>& world)
        : m_camera{camera},
          m_basic_shader{basic_shader},
          m_world{world},
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

    void Keyboard::movement_key_pressed(float delta_time_in_seconds)
    {
        glm::mat4 view_matrix = this->m_camera->get_view_matrix();

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


/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
