/**
 * @file mouse.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "mouse.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    void Mouse::mouse_movement(float x_pos,
                               float y_pos,
                               float delta_time_in_millisecs,
                               GLint view_loc,
                               std::shared_ptr<YB::Camera>& camera,
                               std::shared_ptr<YB::Shader>& basic_shader)
    {
        if (this->m_is_mouse_centered)
        {
            this->m_last_x_pos = x_pos;
            this->m_last_y_pos = y_pos;
            this->m_is_mouse_centered = false;
        }

        this->m_x_offset = x_pos - this->m_last_x_pos;
        this->m_y_offset = this->m_last_y_pos - y_pos;
        this->m_last_x_pos = x_pos;
        this->m_last_y_pos = y_pos;

        this->m_sensitivity = 0.1f * delta_time_in_millisecs;
        this->m_x_offset *= this->m_sensitivity;
        this->m_y_offset *= this->m_sensitivity;

        this->m_yaw += this->m_x_offset;
        this->m_pitch += this->m_y_offset;

        camera->rotate(this->m_pitch, this->m_yaw);

        basic_shader->use_shader_program(); //use default shader
        glm::mat4 view = camera->get_view_matrix();
        glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
