/**
 * @file directional_light_shader.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 14/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_DIRECTIONAL_LIGHT_SHADER_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_DIRECTIONAL_LIGHT_SHADER_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "shader.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

    class DirectionalLightShader : public Shader
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~DirectionalLightShader() noexcept = default;

        DirectionalLightShader(DirectionalLightShader &&) noexcept = default;

        DirectionalLightShader &operator=(DirectionalLightShader &&) noexcept = default;

        DirectionalLightShader(const DirectionalLightShader &) noexcept = default;

        DirectionalLightShader &operator=(DirectionalLightShader const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        explicit DirectionalLightShader();

        void use_shader_program() override;

        void init_uniforms() override;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        glm::vec3 m_light_dir;
        glm::vec3 m_light_color;
        glm::vec3 m_light_position;

        GLint m_light_dir_location;
        GLint m_light_color_location;
        GLint m_light_position_location;

        GLint m_constant;
        GLint m_linear;
        GLint m_quadratic;
        GLuint m_shadow_map;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_DIRECTIONAL_LIGHT_SHADER_HPP

/* End of File */
