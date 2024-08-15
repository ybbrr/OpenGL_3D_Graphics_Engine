/**
 * @file solid_shader.cpp
 * @author Yasin BASAR
 * @brief Implements the SolidShader class.
 * @version 1.0.0
 * @date 15/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "solid_shader.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    SolidShader::SolidShader()
    {
        this->load_shader(R"(shader/solid_vert.glsl)",
                          R"(shader/solid_frag.glsl)");
    }

    void SolidShader::use_shader_program()
    {
        Shader::use_shader_program();
    }

    void SolidShader::init_uniforms()
    {
        Shader::init_uniforms();
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
