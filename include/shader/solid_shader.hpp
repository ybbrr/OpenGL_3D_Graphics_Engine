/**
 * @file solid_shader.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 15/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_SOLID_SHADER_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_SOLID_SHADER_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "draw_components.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

    class SolidShader : public Shader
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~SolidShader() noexcept = default;

        SolidShader(SolidShader &&) noexcept = default;

        SolidShader &operator=(SolidShader &&) noexcept = default;

        SolidShader(const SolidShader &) noexcept = default;

        SolidShader &operator=(SolidShader const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        explicit SolidShader();

        void use_shader_program() override;

        void init_uniforms() override;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /* Data */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_SOLID_SHADER_HPP

/* End of File */
