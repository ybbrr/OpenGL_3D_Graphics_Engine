/**
 * @file shader.cpp
 * @author Yasin BASAR
 * @brief Implements the Shader class for managing and using shaders in OpenGL.
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

    Shader::Shader()
        : shader_program{0},
          model_matrix{1.0f},
          view_matrix{1.0f},
          projection_matrix{1.0f},
          normal_matrix{1.0f},
          model_matrix_location{-1},
          view_matrix_location{-1},
          projection_matrix_location{-1},
          normal_matrix_location{-1},
          m_vertex_shader{0},
          m_fragment_shader{0}
    {
    }

    Shader::~Shader()
    {
        glDetachShader(this->shader_program, this->m_vertex_shader);
        glDetachShader(this->shader_program, this->m_fragment_shader);

        if (this->shader_program != 0)
        {
            glDeleteProgram(this->shader_program);
        }
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

    void Shader::load_shader(const std::string &vertex_shader_file_name,
                             const std::string &fragment_shader_file_name)
    {
        //read, parse and compile the vertex shader
        std::string v = this->read_shader_file(vertex_shader_file_name);
        const GLchar* vertex_shader_string = v.c_str();
        this->m_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(this->m_vertex_shader, 1, &vertex_shader_string, nullptr);
        glCompileShader(this->m_vertex_shader);
        //check compilation status
        this->shader_compile_log(this->m_vertex_shader);

        //read, parse and compile the fragment shader
        std::string f = this->read_shader_file(fragment_shader_file_name);
        const GLchar* fragment_shader_string = f.c_str();
        this->m_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(this->m_fragment_shader, 1, &fragment_shader_string, nullptr);
        glCompileShader(this->m_fragment_shader);
        //check compilation status
        this->shader_compile_log(this->m_fragment_shader);

        //attach and link the shader programs
        this->shader_program = glCreateProgram();
        glAttachShader(this->shader_program, this->m_vertex_shader);
        glAttachShader(this->shader_program, this->m_fragment_shader);
        glLinkProgram(this->shader_program);
        glDeleteShader(this->m_vertex_shader);
        glDeleteShader(this->m_fragment_shader);

        //check linking info
        this->shader_link_log(this->shader_program);

        glUseProgram(this->shader_program);
    }

    void Shader::init_uniforms()
    {
        this->model_matrix = glm::mat4(1.0f);
        this->model_matrix_location = glGetUniformLocation(this->shader_program, "model");
        this->view_matrix = CoreComponents::camera->get_view_matrix();
        this->view_matrix_location = glGetUniformLocation(this->shader_program, "view");
        glUniformMatrix4fv(this->view_matrix_location, 1, GL_FALSE, glm::value_ptr(this->view_matrix));
        this->normal_matrix = glm::mat3(glm::inverseTranspose(this->view_matrix * this->model_matrix));
        this->normal_matrix_location = glGetUniformLocation(this->shader_program, "normalMatrix");
        this->projection_matrix
            = glm::perspective(glm::radians(CoreComponents::camera->fov.fov_angle),
                               static_cast<float>(CoreComponents::window->width) / static_cast<float>(CoreComponents::window->height),
                               CoreComponents::camera->visible_range.z_near,
                               CoreComponents::camera->visible_range.z_far);
        this->projection_matrix_location = glGetUniformLocation(this->shader_program, "projection");
        glUniformMatrix4fv(this->projection_matrix_location, 1, GL_FALSE, glm::value_ptr(this->projection_matrix));
    }

} // namespace YB

/* End of File */
