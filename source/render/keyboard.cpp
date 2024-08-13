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
        : m_pressed_keys{std::vector<GLboolean>(1024, 0)}
    {

    }

    void Keyboard::key_pressed(int key,
                               int action)
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

    void Keyboard::movement_key_pressed(float delta_time_in_millisecs,
                                        GLint view_loc,
                                        std::shared_ptr<YB::Camera> &camera,
                                        std::shared_ptr<YB::Shader> &basic_shader,
                                        std::shared_ptr<YB::World>& world)
    {
        glm::mat4 view = camera->get_view_matrix();
        glm::mat4 model = world->get_model_matrix();
        glm::mat3 normal_matrix{0.0f};

        if (this->m_pressed_keys[GLFW_KEY_W])
        {
            camera->move(YB::MOVE_DIRECTION::MOVE_FORWARD, camera->camera_speed * delta_time_in_millisecs);
            view = camera->get_view_matrix();
            basic_shader->use_shader_program();
            glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
            normal_matrix = glm::mat3(glm::inverseTranspose(view * model));
            world->set_normal_matrix(normal_matrix);
        }

        if (this->m_pressed_keys[GLFW_KEY_S])
        {
            camera->move(YB::MOVE_DIRECTION::MOVE_BACKWARD, camera->camera_speed * delta_time_in_millisecs);
            view = camera->get_view_matrix();
            basic_shader->use_shader_program();
            glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
            normal_matrix = glm::mat3(glm::inverseTranspose(view * model));
            world->set_normal_matrix(normal_matrix);
        }

        if (this->m_pressed_keys[GLFW_KEY_A])
        {
            camera->move(YB::MOVE_DIRECTION::MOVE_LEFT, camera->camera_speed * delta_time_in_millisecs);
            view = camera->get_view_matrix();
            basic_shader->use_shader_program();
            glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
            normal_matrix = glm::mat3(glm::inverseTranspose(view * model));
            world->set_normal_matrix(normal_matrix);
        }

        if (this->m_pressed_keys[GLFW_KEY_D])
        {
            camera->move(YB::MOVE_DIRECTION::MOVE_RIGHT, camera->camera_speed * delta_time_in_millisecs);
            view = camera->get_view_matrix();
            basic_shader->use_shader_program();
            glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
            normal_matrix = glm::mat3(glm::inverseTranspose(view * model));
            world->set_normal_matrix(normal_matrix);
        }
    }


/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
