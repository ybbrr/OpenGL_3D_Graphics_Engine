/**
 * @file Mesh.hpp
 * @author Yasin BASAR
 * @brief
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
    class Mesh
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Mesh() noexcept = delete;

        virtual ~Mesh() noexcept = default;

        Mesh(Mesh &&) noexcept = default;

        Mesh &operator=(Mesh &&) noexcept = default;

        Mesh(const Mesh &) noexcept = default;

        Mesh &operator=(Mesh const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        Mesh(const std::vector<vertex_t>& vertices,
             const std::vector<GLuint>& indices,
             const std::vector<texture_t>& textures);

        buffers_t get_buffers();

        void draw(GLuint shader_program);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        buffers_t m_buffers;

        std::vector<vertex_t> m_vertices;
        std::vector<GLuint> m_indices;
        std::vector<texture_t > m_textures;

        void setup_mesh();

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_MODEL_HPP

/* End of File */
