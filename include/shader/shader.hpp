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
#include "core_components.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glm/glm.hpp>

#include <glm/glm.hpp> //core glm functionality
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

typedef unsigned int GLuint;
typedef int GLint;

namespace YB
{
    class Shader
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Shader(Shader &&) noexcept = default;

        Shader &operator=(Shader &&) noexcept = default;

        Shader(const Shader &) noexcept = default;

        Shader &operator=(Shader const&) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        Shader();

        ~Shader();

        virtual void use_shader_program();

        virtual void init_uniforms();

        GLuint shader_program;

        glm::mat4 model_matrix;
        glm::mat4 view_matrix;
        glm::mat4 projection_matrix;
        glm::mat3 normal_matrix;

        GLint model_matrix_location;
        GLint view_matrix_location;
        GLint projection_matrix_location;
        GLint normal_matrix_location;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        std::string read_shader_file(const std::string& file_name);

        void shader_compile_log(GLuint shader_id);

        void shader_link_log(GLuint shader_program_id);

        GLuint m_vertex_shader;
        GLuint m_fragment_shader;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        void load_shader(const std::string& vertex_shader_file_name,
                         const std::string& fragment_shader_file_name);
    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_SHADER_HPP

/* End of File */
