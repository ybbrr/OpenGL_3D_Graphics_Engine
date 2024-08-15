/**
 * @file types.hpp
 * @author Yasin BASAR
 * @brief Defines various types and enumerations used in the 3D graphics engine.
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

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace YB
{
    /**
     * @struct vertex_s
     * @brief Defines a vertex with position, normal, and texture coordinates.
     *
     * This structure holds the data for a single vertex including its position,
     * normal, and texture coordinates.
     */
    typedef struct vertex_s
    {
        glm::vec3 Position; ///< The position of the vertex in 3D space.
        glm::vec3 Normal; ///< The normal vector of the vertex.
        glm::vec2 TexCoords; ///< The texture coordinates of the vertex.
    } vertex_t;

    /**
     * @struct texture_s
     * @brief Defines a texture with its ID, type, and path.
     *
     * This structure holds information about a texture, including its OpenGL
     * texture ID, the type of texture (e.g., ambient, diffuse, specular), and
     * the file path to the texture image.
     */
    typedef struct texture_s
    {
        GLuint id; ///< The OpenGL texture ID.
        std::string type; ///< The type of the texture (e.g., ambient, diffuse, specular).
        std::string path; ///< The file path to the texture image.
    } texture_t;

    /**
     * @struct material_s
     * @brief Defines material properties with ambient, diffuse, and specular components.
     *
     * This structure holds the material properties for rendering, including the
     * ambient, diffuse, and specular components of the material.
     */
    typedef struct material_s
    {
        glm::vec3 ambient; ///< The ambient color of the material.
        glm::vec3 diffuse; ///< The diffuse color of the material.
        glm::vec3 specular; ///< The specular color of the material.
    } material_t;

    /**
     * @struct buffers_s
     * @brief Defines buffer objects used in rendering.
     *
     * This structure holds the identifiers for Vertex Array Object (VAO), Vertex
     * Buffer Object (VBO), and Element Buffer Object (EBO) used in OpenGL.
     */
    typedef struct buffers_s
    {
        GLuint VAO; ///< The OpenGL Vertex Array Object ID.
        GLuint VBO; ///< The OpenGL Vertex Buffer Object ID.
        GLuint EBO; ///< The OpenGL Element Buffer Object ID.
    } buffers_t;

    typedef struct fov_s
    {
        float fov_angle;
        float min_fov_angle;
        float max_fov_angle;
    } fov_t;

    typedef struct visible_range_s
    {
        float z_near;
        float z_far;
    } visible_range_t;

    /**
     * @enum MOVE_DIRECTION
     * @brief Enumeration for movement directions.
     *
     * This enumeration defines the possible movement directions used in the
     * application, such as moving forward, backward, right, or left.
     */
    enum class MOVE_DIRECTION
    {
        MOVE_FORWARD, ///< Move in the forward direction.
        MOVE_BACKWARD, ///< Move in the backward direction.
        MOVE_RIGHT, ///< Move in the right direction.
        MOVE_LEFT ///< Move in the left direction.
    };
} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_TYPES_ENUMS_HPP

/* End of File */
