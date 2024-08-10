/**
 * @file mesh.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "mesh.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{
/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    Mesh::Mesh(const std::vector<vertex_t>& vertices,
               const std::vector<GLuint>& indices,
               const std::vector<texture_t>& textures)
       : vertices{vertices},
         indices{indices},
         textures{textures},
         m_buffers{}
    {
        this->setup_mesh();
    }

    buffers_t Mesh::get_buffers()
    {
        return this->m_buffers;
    }

    void Mesh::draw(const std::shared_ptr<YB::Shader>& shader)
    {
        shader->use_shader_program();

        //set textures
        for (GLuint idx = 0; idx < textures.size(); idx++)
        {
            glActiveTexture(GL_TEXTURE0 + idx);

            GLuint uniform_location
                = glGetUniformLocation(shader->shader_program, this->textures[idx].type.c_str());

            glUniform1i(uniform_location, idx);

            glBindTexture(GL_TEXTURE_2D, this->textures[idx].id);
        }

        glBindVertexArray(this->m_buffers.VAO);
        glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, (GLvoid*)0);
        glBindVertexArray(0);

        for(GLuint i = 0; i < this->textures.size(); i++)
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
        glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(vertex_t), &this->vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_buffers.EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

        // Set the vertex attribute pointers
        // Vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (GLvoid*)0);
        // Vertex Normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (GLvoid*)offsetof(vertex_t, Normal));
        // Vertex Texture Coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (GLvoid*)offsetof(vertex_t, TexCoords));

        glBindVertexArray(0);
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
