///
/// @file default_world.cpp
/// @author Yasin BASAR
/// @brief Implements the DefaultWorld class which manages a collection of 3D models
///        and handles their transformations and rendering.
/// @version 1.0.0
/// @date 10/08/2024
/// @copyright (c) 2024 All rights reserved.
///

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "default_world.hpp"
#include "draw_components.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

#include <glm/glm.hpp> // Core GLM functionality
#include <glm/gtc/matrix_transform.hpp> // GLM extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> // GLM extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> // GLM extension for accessing the internal data structure of GLM types

namespace YB
{

////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

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
            DrawComponents::shader->use_shader_program();

            // Apply transformations to the model matrix.
            DrawComponents::shader->model_matrix = glm::translate(glm::mat4(1.0f), obj.obj_position);

            if (obj.is_rotatable)
            {
                DrawComponents::shader->model_matrix
                    = glm::rotate(DrawComponents::shader->model_matrix,
                                  glm::radians(this->m_rotate_angle),
                                  glm::vec3(0, 1, 0));
            }

            if (obj.is_scalable)
            {
                DrawComponents::shader->model_matrix
                    = glm::scale(DrawComponents::shader->model_matrix,
                                 this->m_scale_factor + glm::vec3(1.0f, 1.0f, 1.0f));
            }

            DrawComponents::shader->view_matrix = CoreComponents::camera->get_view_matrix();

            glm::mat4 inverse_transpose
                = glm::inverseTranspose(DrawComponents::shader->view_matrix * DrawComponents::shader->model_matrix);

            DrawComponents::shader->normal_matrix = glm::mat3(inverse_transpose);

            // Send matrices to the shader.
            glUniformMatrix4fv(DrawComponents::shader->model_matrix_location,
                               1,
                               GL_FALSE,
                               glm::value_ptr(DrawComponents::shader->model_matrix));

            glUniformMatrix3fv(DrawComponents::shader->normal_matrix_location,
                               1,
                               GL_FALSE,
                               glm::value_ptr(DrawComponents::shader->normal_matrix));

            glUniformMatrix4fv(DrawComponents::shader->view_matrix_location,
                               1,
                               GL_FALSE,
                               glm::value_ptr(DrawComponents::shader->view_matrix));

            obj.draw(DrawComponents::shader->shader_program);
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

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */
