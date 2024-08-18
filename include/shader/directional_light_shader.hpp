///
/// @file directional_light_shader.hpp
/// @author Yasin BASAR
/// @brief Provides the class for handling shaders with directional lighting.
/// @version 1.0.0
/// @date 14/08/2024
/// @copyright (c) 2024 All rights reserved.
///

#ifndef OPENGL_3D_GRAPHICS_ENGINE_DIRECTIONAL_LIGHT_SHADER_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_DIRECTIONAL_LIGHT_SHADER_HPP

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "shader.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

namespace YB
{
    ///
    /// @class DirectionalLightShader
    /// @brief Handles shaders specific to directional lighting.
    ///
    /// Inherits from the Shader class and extends its functionality to include
    /// lighting properties specific to directional lights.
    ///
    class DirectionalLightShader final : public Shader
    {
    public:
    ////////////////////////////////////////////////////////////////////////////
    // Special Members
    ////////////////////////////////////////////////////////////////////////////

        ~DirectionalLightShader() noexcept override = default; /**< Default destructor */
        DirectionalLightShader(DirectionalLightShader &&) noexcept = default; /**< Default move constructor */
        DirectionalLightShader &operator=(DirectionalLightShader &&) noexcept = default; /**< Default move assignment operator */
        DirectionalLightShader(const DirectionalLightShader &) noexcept = default; /**< Default copy constructor */
        DirectionalLightShader &operator=(DirectionalLightShader const &) noexcept = default; /**< Default copy assignment operator */

    ////////////////////////////////////////////////////////////////////////////
    // Public Members
    ////////////////////////////////////////////////////////////////////////////

        ///
        /// @brief Constructor for the DirectionalLightShader class.
        ///
        /// Initializes the shader program and its uniform variables.
        ///
        explicit DirectionalLightShader();

        ///
        /// @brief Use the shader program for rendering.
        ///
        /// Overrides the base class implementation to activate this shader program.
        ///
        void use_shader_program() override;

        ///
        /// @brief Initialize uniform variables for the shader.
        ///
        /// Overrides the base class implementation to set up the directional light
        /// properties.
        ///
        void init_uniforms() override;

    ////////////////////////////////////////////////////////////////////////////
    // Private Members
    ////////////////////////////////////////////////////////////////////////////
    private:

        glm::vec3 m_light_dir; /**< Direction of the light. */
        glm::vec3 m_light_color; /**< Color of the light. */
        glm::vec3 m_light_position; /**< Position of the light. */

        GLint m_light_dir_location; /**< Location of the light direction uniform in the shader. */
        GLint m_light_color_location; /**< Location of the light color uniform in the shader. */
        GLint m_light_position_location; /**< Location of the light position uniform in the shader. */

        GLint m_constant; /**< Location of the constant attenuation uniform in the shader. */
        GLint m_linear; /**< Location of the linear attenuation uniform in the shader. */
        GLint m_quadratic; /**< Location of the quadratic attenuation uniform in the shader. */
        GLuint m_shadow_map; /**< ID of the shadow map texture. */

    ////////////////////////////////////////////////////////////////////////////
    // Protected Members
    ////////////////////////////////////////////////////////////////////////////
    protected:

        // Data

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_DIRECTIONAL_LIGHT_SHADER_HPP

/* End of File */
