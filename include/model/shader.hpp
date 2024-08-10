/**
 * @file shader.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_SHADER_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_SHADER_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include <fstream>
#include <sstream>

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

typedef unsigned int GLuint;

namespace YB
{
    class Shader
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Shader() noexcept = default;

        virtual ~Shader() noexcept = default;

        Shader(Shader &&) noexcept = default;

        Shader &operator=(Shader &&) noexcept = default;

        Shader(const Shader &) noexcept = delete;

        Shader &operator=(Shader &) noexcept = delete;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        void load_shader(const std::string& vertex_shader_file_name,
                         const std::string& fragment_shader_file_name);

        void use_shader_program();

        GLuint shader_program;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        std::string read_shader_file(const std::string& file_name);

        void shader_compile_log(GLuint shader_id);

        void shader_link_log(GLuint shader_program_id);

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_SHADER_HPP

/* End of File */
