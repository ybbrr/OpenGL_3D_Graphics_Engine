/**
 * @file types.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_TYPES_ENUMS_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_TYPES_ENUMS_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include <vector>
#include "shader.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace YB
{
    enum class MOVE_DIRECTION
    {
        MOVE_FORWARD,
        MOVE_BACKWARD,
        MOVE_RIGHT,
        MOVE_LEFT
    };

    typedef struct vertex_s
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    } vertex_t;

    typedef struct texture_s
    {
        GLuint id;
        //ambientTexture, diffuseTexture, specularTexture
        std::string type;
        std::string path;
    } texture_t;

    typedef struct material_s
    {
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
    } material_t;

    typedef struct buffers_s
    {
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
    } buffers_t;

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_TYPES_ENUMS_HPP

/* end of file */
