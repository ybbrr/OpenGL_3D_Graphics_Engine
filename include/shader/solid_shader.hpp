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

    /**
     * @class SolidShader
     * @brief Manages shaders for solid color rendering.
     *
     * Inherits from the Shader class and provides additional functionality for
     * handling shaders that render solid colors.
     */
    class SolidShader : public Shader
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~SolidShader() noexcept = default; /**< Default destructor */
        SolidShader(SolidShader &&) noexcept = default; /**< Default move constructor */
        SolidShader &operator=(SolidShader &&) noexcept = default; /**< Default move assignment operator */
        SolidShader(const SolidShader &) noexcept = default; /**< Default copy constructor */
        SolidShader &operator=(SolidShader const &) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructor for the SolidShader class.
         *
         * Initializes the shader program for solid color rendering.
         */
        explicit SolidShader();

        /**
         * @brief Use the shader program for rendering.
         *
         * Overrides the base class implementation to activate this shader program.
         */
        void use_shader_program() override;

        /**
         * @brief Initialize uniform variables for the shader.
         *
         * Overrides the base class implementation to set up the shader's
         * uniform variables.
         */
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
