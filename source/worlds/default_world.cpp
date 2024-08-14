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

    void DefaultWorld::add_model(const std::string &file_name,
                                 const std::string& model_name,
                                 const glm::vec3& position)
    {
        this->m_objs.emplace_back(file_name, model_name, position);
    }

    void DefaultWorld::render_models(std::shared_ptr<YB::Shader>& shader)
    {
        for (auto & obj : this->m_objs)
        {
            shader->use_shader_program();

            this->m_model_matrix = glm::translate(glm::mat4(1.0f), obj.obj_position);
//            this->m_model_matrix = glm::rotate(this->m_model_matrix, glm::radians(this->m_angle), glm::vec3(0.0f, 1.0f, 0.0f));
//            this->m_model_matrix = glm::scale(this->m_model_matrix, this->m_scale + glm::vec3(1.0f, 1.0f, 1.0f));

            this->m_view_matrix = this->m_camera->get_view_matrix();

            this->m_normal_matrix = glm::mat3(glm::inverseTranspose(this->m_view_matrix * this->m_model_matrix));

            glUniformMatrix4fv(this->m_model_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_model_matrix));
            glUniformMatrix3fv(this->m_normal_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_normal_matrix));
            glUniformMatrix4fv(this->m_view_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_view_matrix));

            obj.draw(shader);
        }
    }

    void DefaultWorld::init_uniforms(std::shared_ptr<YB::Window>& window,
                                     std::shared_ptr<YB::Camera>& camera,
                                     std::shared_ptr<YB::Shader>& shader)
    {

        this->m_camera = camera;
        shader->use_shader_program();

        // create model matrix for teapot
//        this->m_model_matrix = glm::rotate(glm::mat4(1.0f), glm::radians(this->m_angle), glm::vec3(0.0f, 0.0f, 0.0f));
        this->m_model_matrix = glm::mat4(1.0f);
        this->m_model_matrix_location = glGetUniformLocation(shader->shader_program, "model");

        // get view matrix for current camera
        this->m_view_matrix = camera->get_view_matrix();
        this->m_view_matrix_location = glGetUniformLocation(shader->shader_program, "view");
        // send view matrix to shader
        glUniformMatrix4fv(this->m_view_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_view_matrix));

        // compute normal matrix for teapot
        this->m_normal_matrix = glm::mat3(glm::inverseTranspose(this->m_view_matrix * this->m_model_matrix));
        this->m_normal_matrix_location = glGetUniformLocation(shader->shader_program, "normalMatrix");

        // create projection matrix
        this->m_projection_matrix
            = glm::perspective(glm::radians(45.0f),
                               static_cast<float>(window->width) / static_cast<float>(window->height),
                               0.1f,
                               40.0f);

        this->m_projection_matrix_location = glGetUniformLocation(shader->shader_program, "projection");
        // send projection matrix to shader
        glUniformMatrix4fv(this->m_projection_matrix_location, 1, GL_FALSE, glm::value_ptr(this->m_projection_matrix));

        // set the light direction (direction towards the light)
        this->m_light_dir = glm::vec3(2.0f, 2.0f, 2.0f);
        this->m_light_dir_location = glGetUniformLocation(shader->shader_program, "lightDir");
        // send light dir to shader
        glUniform3fv(this->m_light_dir_location, 1, glm::value_ptr(this->m_light_dir));

        // set light color
        this->m_light_color = glm::vec3(1.0f, 1.0f, 1.0f); //white light
        this->m_light_dir_location = glGetUniformLocation(shader->shader_program, "lightColor");
        // send light color to shader
        glUniform3fv(this->m_light_dir_location, 1, glm::value_ptr(this->m_light_color));

        this->m_light_position = glm::vec3(-2.0f, 10.0f, -1.0f);
        this->m_light_position_location = glGetUniformLocation(shader->shader_program, "lightPosition");
        /*send light position to shader*/
        glUniform3fv(this->m_light_position_location, 1, glm::value_ptr(this->m_light_position));

        this->m_constant = glGetUniformLocation(shader->shader_program, "constant");
        glUniform1f(this->m_constant, 1.0f);

        this->m_linear = glGetUniformLocation(shader->shader_program, "linear_");
        glUniform1f(this->m_linear, 0.22f);

        this->m_quadratic = glGetUniformLocation(shader->shader_program, "quadratic");
        glUniform1f(this->m_quadratic, 0.20f);
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
