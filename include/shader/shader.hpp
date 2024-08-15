/**
 * @file shader.hpp
 * @author Yasin BASAR
 * @brief Defines the Shader class for managing and using shaders in OpenGL.
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

#include <glm/glm.hpp> //core glm functionality
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

typedef unsigned int GLuint;
typedef int GLint;

namespace YB
{
    /**
     * @class Shader
     * @brief Handles a most basic shader's features
     *
     * The Shader class processes most basic shader's uniform setting and getting operations.
     */
    class Shader
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Shader(Shader &&) noexcept = default; /**< Default move constructor */
        Shader &operator=(Shader &&) noexcept = default; /**< Default move assignment operator */
        Shader(const Shader &) noexcept = default; /**< Default copy constructor */
        Shader &operator=(Shader const&) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Default constructor for the Shader class.
         */
        Shader();

        /**
         * @brief Destructor for the Shader class.
         */
        ~Shader();

        /**
         * @brief Activates the shader program for use.
         */
        virtual void use_shader_program();

        /**
         * @brief Initializes the shader's uniform variables.
         */
        virtual void init_uniforms();

        GLuint shader_program; /**< ID of the shader program */
        glm::mat4 model_matrix; /**< Model matrix for transformations */
        glm::mat4 view_matrix; /**< View matrix for camera transformations */
        glm::mat4 projection_matrix; /**< Projection matrix for perspective calculations */
        glm::mat3 normal_matrix; /**< Normal matrix for correct normal transformations */

        GLint model_matrix_location; /**< Location of the model matrix uniform */
        GLint view_matrix_location; /**< Location of the view matrix uniform */
        GLint projection_matrix_location; /**< Location of the projection matrix uniform */
        GLint normal_matrix_location; /**< Location of the normal matrix uniform */


    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief Reads the content of a shader file.
         * @param[in] file_name The name of the file to read.
         * @return The content of the file as a string.
         */
        std::string read_shader_file(const std::string& file_name);

        /**
         * @brief Logs compilation errors for a shader.
         * @param[in] shader_id The ID of the shader.
         */
        void shader_compile_log(GLuint shader_id);

        /**
         * @brief Logs linking errors for a shader program.
         * @param[in] shader_program_id The ID of the shader program.
         */
        void shader_link_log(GLuint shader_program_id);

        GLuint m_vertex_shader; /**< ID of the vertex shader */
        GLuint m_fragment_shader; /**< ID of the fragment shader */
    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /**
         * @brief Loads and compiles vertex and fragment shaders, and links them into a shader program.
         * @param[in] vertex_shader_file_name The file name of the vertex shader.
         * @param[in] fragment_shader_file_name The file name of the fragment shader.
         */
        void load_shader(const std::string& vertex_shader_file_name,
                         const std::string& fragment_shader_file_name);
    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_SHADER_HPP

/* End of File */
