///
/// @file mesh.cpp
/// @author Yasin BASAR
/// @brief Implementation of the Mesh class methods.
/// @version 1.0.0
/// @date 09/08/2024
/// @copyright (c) 2024 All rights reserved.
///

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include "mesh.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

namespace YB
{
////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

    Mesh::Mesh(const std::vector<vertex_t>& vertices,
               const std::vector<GLuint>& indices,
               const std::vector<texture_t>& textures)
       : m_vertices{vertices},
         m_indices{indices},
         m_textures{textures},
         m_buffers{}
    {
        this->setup_mesh();
    }

    buffers_t Mesh::get_buffers() const noexcept
    {
        return this->m_buffers;
    }

    void Mesh::draw(GLuint shader_program) const
    {
        GLint textures_size = static_cast<GLint>(this->m_textures.size());

        //set textures
        for (GLint idx = 0; idx < textures_size; idx++)
        {
            glActiveTexture(GL_TEXTURE0 + idx);

            GLint uniform_location
                = glGetUniformLocation(shader_program, this->m_textures[idx].type.c_str());

            glUniform1i(uniform_location, idx);

            glBindTexture(GL_TEXTURE_2D, this->m_textures[idx].id);
        }

        glBindVertexArray(this->m_buffers.VAO);
        glDrawElements(GL_TRIANGLES, this->m_indices.size(), GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        for(GLint i = 0; i < textures_size; i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
    }

    void Mesh::setup_mesh()
    {
        // Create buffers/arrays
        glGenVertexArrays(1, &this->m_buffers.VAO);
        glGenBuffers(1, &this->m_buffers.VBO);
        glGenBuffers(1, &this->m_buffers.EBO);

        glBindVertexArray(this->m_buffers.VAO);
        // Load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, this->m_buffers.VBO);
        glBufferData(GL_ARRAY_BUFFER, this->m_vertices.size() * sizeof(vertex_t), &this->m_vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_buffers.EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(GLuint), &this->m_indices[0], GL_STATIC_DRAW);

        // Set the vertex attribute pointers
        // Vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), nullptr);

        // Vertex Normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,
                              3,
                              GL_FLOAT,
                              GL_FALSE,
                              sizeof(vertex_t),
                              reinterpret_cast<GLvoid*>(offsetof(vertex_t, Normal)));

        // Vertex Texture Coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2,
                              2,
                              GL_FLOAT,
                              GL_FALSE,
                              sizeof(vertex_t),
                              reinterpret_cast<GLvoid*>(offsetof(vertex_t, TexCoords)));

        glBindVertexArray(0);
    }

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */
