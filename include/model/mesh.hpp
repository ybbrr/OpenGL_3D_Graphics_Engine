/**
 * @file mesh.hpp
 * @author Yasin BASAR
 * @brief Declaration of the Mesh class, which represents a 3D model mesh and handles its rendering.
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_MODEL_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_MODEL_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include <vector>
#include "shader.hpp"
#include "types_enums.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace YB
{
    /**
     * @class Mesh
     * @brief Represents a 3D mesh with vertices, indices, and textures.
     *
     * The Mesh class handles the creation and rendering of a 3D model mesh. It stores the vertex data,
     * index data, and texture information and provides methods to draw the mesh using OpenGL.
     */
    class Mesh
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Mesh() noexcept = delete; /**< Default default constructor */
        virtual ~Mesh() noexcept = default; /**< Default destructor */
        Mesh(Mesh &&) noexcept = default; /**< Default move constructor */
        Mesh &operator=(Mesh &&) noexcept = default; /**< Default move assignment operator */
        Mesh(const Mesh &) noexcept = default; /**< Default copy constructor */
        Mesh &operator=(Mesh const &) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructs a Mesh object with given vertices, indices, and textures.
         * @param[in] vertices A vector of vertex data.
         * @param[in] indices A vector of index data.
         * @param[in] textures A vector of texture data.
         */
        Mesh(const std::vector<vertex_t>& vertices,
             const std::vector<GLuint>& indices,
             const std::vector<texture_t>& textures);

        /**
         * @brief Gets the buffers associated with this mesh.
         * @return A structure containing the vertex array object (VAO), vertex buffer object (VBO),
         *         and element buffer object (EBO) used for rendering the mesh.
         */
        buffers_t get_buffers() const noexcept;

        /**
         * @brief Draws the mesh using the specified shader program.
         * @param [in] shader_program The ID of the shader program to use for rendering.
         */
        void draw(GLuint shader_program) const;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief Sets up the mesh by generating and configuring OpenGL buffers.
         */
        void setup_mesh();

        std::vector<vertex_t> m_vertices; /**< Vertex data for the mesh. */
        std::vector<GLuint> m_indices; /**< Index data for the mesh. */
        std::vector<texture_t > m_textures; /**< Texture data for the mesh. */
        buffers_t m_buffers; /**< Buffers for rendering the mesh. */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_MODEL_HPP

/* End of File */
