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

    void DefaultWorld::render_models(std::shared_ptr<YB::Shader> shader)
    {
        for (auto & obj : this->m_objs)
        {
            shader->use_shader_program();

            this->m_model = glm::translate(glm::mat4(1.0f), obj.obj_position);
//            this->m_model = glm::rotate(this->m_model, glm::radians(this->m_angle), glm::vec3(0.0f, 1.0f, 0.0f));
//            this->m_model = glm::scale(this->m_model, this->m_scale + glm::vec3(1.0f, 1.0f, 1.0f));

            this->m_view = this->m_camera->get_view_matrix();

            this->m_normal_matrix = glm::mat3(glm::inverseTranspose(this->m_view * this->m_model));

            //send teapot model matrix data to shader
            glUniformMatrix4fv(this->m_model_loc, 1, GL_FALSE, glm::value_ptr(this->m_model));

            //send teapot normal matrix data to shader
            glUniformMatrix3fv(this->m_normal_matrix_loc, 1, GL_FALSE, glm::value_ptr(this->m_normal_matrix));

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
        this->m_model = glm::rotate(glm::mat4(1.0f), glm::radians(this->m_angle), glm::vec3(0.0f, 1.0f, 0.0f));
        this->m_model_loc = glGetUniformLocation(shader->shader_program, "model");

        // get view matrix for current camera
        this->m_view = camera->get_view_matrix();
        this->m_view_loc = glGetUniformLocation(shader->shader_program, "view");
        // send view matrix to shader
        glUniformMatrix4fv(this->m_view_loc, 1, GL_FALSE, glm::value_ptr(this->m_view));

        // compute normal matrix for teapot
        this->m_normal_matrix = glm::mat3(glm::inverseTranspose(this->m_view * this->m_model));
        this->m_normal_matrix_loc = glGetUniformLocation(shader->shader_program, "normalMatrix");

        // create projection matrix
        this->m_projection = glm::perspective(glm::radians(45.0f),
                                              (float)window->width / (float)window->height,
                                              0.1f,
                                              40.0f);

        this->m_projection_loc = glGetUniformLocation(shader->shader_program, "projection");
        // send projection matrix to shader
        glUniformMatrix4fv(this->m_projection_loc, 1, GL_FALSE, glm::value_ptr(this->m_projection));

        // set the light direction (direction towards the light)
        this->light_dir = glm::vec3(2.0f, 2.0f, 2.0f);
        this->light_dir_loc = glGetUniformLocation(shader->shader_program, "lightDir");
        // send light dir to shader
        glUniform3fv(this->light_dir_loc, 1, glm::value_ptr(this->light_dir));

        // set light color
        this->light_color = glm::vec3(1.0f, 1.0f, 1.0f); //white light
        this->light_dir_loc = glGetUniformLocation(shader->shader_program, "lightColor");
        // send light color to shader
        glUniform3fv(this->light_dir_loc, 1, glm::value_ptr(this->light_color));

        this->light_position = glm::vec3(-2.0f, 10.0f, -1.0f);
        this->light_position_loc = glGetUniformLocation(shader->shader_program, "lightPosition");
        /*send light position to shader*/
        glUniform3fv(this->light_position_loc, 1, glm::value_ptr(this->light_position));

        constant = glGetUniformLocation(shader->shader_program, "constant");
        glUniform1f(constant, 1.0f);

        linear = glGetUniformLocation(shader->shader_program, "linear_");
        glUniform1f(linear, 0.22f);

        quadratic = glGetUniformLocation(shader->shader_program, "quadratic");
        glUniform1f(quadratic, 0.20f);
    }

    GLint DefaultWorld::get_view_loc()
    {
        return this->m_view_loc;
    }

    glm::mat4 DefaultWorld::get_model_matrix()
    {
        return this->m_model;
    }

    void DefaultWorld::set_normal_matrix(const glm::mat3& normal_matrix)
    {
        this->m_normal_matrix = normal_matrix;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
