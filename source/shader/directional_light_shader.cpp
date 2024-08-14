/**
 * @file directional_light_shader.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 14/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "directional_light_shader.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

    DirectionalLightShader::DirectionalLightShader()
    {
        this->load_shader(R"(shader/basic_vert_directional_light.glsl)",
                          R"(shader/basic_frag_directional_light.glsl)");
    }

    void DirectionalLightShader::use_shader_program()
    {
        Shader::use_shader_program();
    }


    void DirectionalLightShader::init_uniforms()
    {
        Shader::init_uniforms();

        // set the light direction (direction towards the light)
        this->m_light_dir = glm::vec3(2.0f, 2.0f, 2.0f);
        this->m_light_dir_location = glGetUniformLocation(this->shader_program, "lightDir");
        // send light dir to shader
        glUniform3fv(this->m_light_dir_location, 1, glm::value_ptr(this->m_light_dir));

        // set light color
        this->m_light_color = glm::vec3(1.0f, 1.0f, 1.0f); //white light
        this->m_light_dir_location = glGetUniformLocation(this->shader_program, "lightColor");
        // send light color to shader
        glUniform3fv(this->m_light_dir_location, 1, glm::value_ptr(this->m_light_color));

        this->m_light_position = glm::vec3(-2.0f, 10.0f, -1.0f);
        this->m_light_position_location = glGetUniformLocation(this->shader_program, "lightPosition");
        /*send light position to shader*/
        glUniform3fv(this->m_light_position_location, 1, glm::value_ptr(this->m_light_position));

        this->m_constant = glGetUniformLocation(this->shader_program, "constant");
        glUniform1f(this->m_constant, 1.0f);

        this->m_linear = glGetUniformLocation(this->shader_program, "linear_");
        glUniform1f(this->m_linear, 0.22f);

        this->m_quadratic = glGetUniformLocation(this->shader_program, "quadratic");
        glUniform1f(this->m_quadratic, 0.20f);
    }
} // YB

/* End of File */
