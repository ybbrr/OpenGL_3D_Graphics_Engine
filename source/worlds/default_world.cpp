/**
 * @file default_world.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "default_world.hpp"
#include "draw_components.hpp"

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

    DefaultWorld::DefaultWorld()
        : m_objs{},
          m_camera{CoreComponents::get_camera()},
          m_shader{DrawComponents::get_shader()}
    {

    }

    void DefaultWorld::add_model(const std::string &file_name,
                                 const std::string& model_name,
                                 const glm::vec3& position,
                                 bool rotatable,
                                 bool scalable)
    {
        this->m_objs.emplace_back(file_name, model_name, position, rotatable, scalable);
    }

    void DefaultWorld::render_models()
    {
        for (auto & obj : this->m_objs)
        {
            this->m_shader->use_shader_program();

            this->m_shader->model_matrix = glm::translate(glm::mat4(1.0f), obj.obj_position);

            if (obj.is_rotatable)
            {
                this->m_shader->model_matrix = glm::rotate(this->m_shader->model_matrix,
                                                   glm::radians(this->m_rotate_angle),
                                                   glm::vec3(0, 1, 0));
            }

            if (obj.is_scalable)
            {
                this->m_shader->model_matrix = glm::scale(this->m_shader->model_matrix,
                                                  this->m_scale_factor + glm::vec3(1.0f, 1.0f, 1.0f));
            }

            this->m_shader->view_matrix = this->m_camera->get_view_matrix();

            this->m_shader->normal_matrix = glm::mat3(glm::inverseTranspose(this->m_shader->view_matrix * this->m_shader->model_matrix));

            glUniformMatrix4fv(this->m_shader->model_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_shader->model_matrix));
            glUniformMatrix3fv(this->m_shader->normal_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_shader->normal_matrix));
            glUniformMatrix4fv(this->m_shader->view_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_shader->view_matrix));

            obj.draw(this->m_shader->shader_program);
        }
    }

    void DefaultWorld::increase_rotate_angle(float value)
    {
        World::increase_rotate_angle(value);
    }

    void DefaultWorld::increase_scale_factor(float value)
    {
        World::increase_scale_factor(value);
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
