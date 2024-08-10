/**
 * @file shader.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "shader.hpp"
#include <iostream>

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

#include <glad/glad.h>

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    /**
     * @brief
     *
     */
    void Shader::load_shader(const std::string &vertex_shader_file_name,
                             const std::string &fragment_shader_file_name)
    {
        //read, parse and compile the vertex shader
        std::string v = this->read_shader_file(vertex_shader_file_name);
        const GLchar* vertex_shader_string = v.c_str();
        GLuint vertex_shader;
        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_string, NULL);
        glCompileShader(vertex_shader);
        //check compilation status
        this->shader_compile_log(vertex_shader);

        //read, parse and compile the fragment shader
        std::string f = this->read_shader_file(fragment_shader_file_name);
        const GLchar* fragment_shader_string = f.c_str();
        GLuint fragment_shader;
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_string, NULL);
        glCompileShader(fragment_shader);
        //check compilation status
        this->shader_compile_log(fragment_shader);

        //attach and link the shader programs
        this->shader_program = glCreateProgram();
        glAttachShader(this->shader_program, vertex_shader);
        glAttachShader(this->shader_program, fragment_shader);
        glLinkProgram(this->shader_program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        //check linking info
        this->shader_link_log(this->shader_program);
    }

    void Shader::use_shader_program()
    {
        glUseProgram(this->shader_program);
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

    std::string Shader::read_shader_file(const std::string &file_name)
    {
        std::ifstream shader_file(file_name.c_str());
        std::stringstream shader_string_stream{};

        shader_string_stream << shader_file.rdbuf();

        shader_file.close();

        return shader_string_stream.str();
    }

    void Shader::shader_compile_log(GLuint shader_id)
    {
        GLint success;
        GLchar* info_log = new GLchar[1024];

        glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            glGetShaderInfoLog(shader_id, 1024, NULL, info_log);
            std::cout << "Shader compilation error\n" << info_log << std::endl;
        }

        delete[] info_log;
    }

    void Shader::shader_link_log(GLuint shader_program_id)
    {
        GLint success;
        GLchar* info_log = new GLchar[1024];

        glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success);

        if(!success)
        {
            glGetProgramInfoLog(this->shader_program, 512, NULL, info_log);
            std::cout << "Shader linking error\n" << info_log << std::endl;
        }

        delete[] info_log;
    }

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // namespace YB

/* End of File */
