///
/// @file model_3d.cpp
/// @author Yasin BASAR
/// @brief Implementation of the Model3D class methods.
/// @version 1.0.0
/// @date 09/08/2024
/// @copyright (c) 2024 All rights reserved.
///

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <filesystem>
#include "model_3d.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

#include <tiny_obj_loader.h>
#include <stb_image.h>

namespace YB
{
////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

    Model3D::Model3D(const std::string& file_path,
                     const std::string& model_name,
                     const glm::vec3& position,
                     const bool rotatable,
                     const bool scalable)
        : obj_position{position},
          is_rotatable{rotatable},
          is_scalable{scalable},
          m_model_name{model_name}
    {
        std::string filepath = file_path;
        std::replace(filepath.begin(), filepath.end(), '\\', '/');

        const std::filesystem::path path(filepath);
        std::filesystem::path canonical_path = std::filesystem::weakly_canonical(path);
        filepath = canonical_path.make_preferred().string();
        std::string basepath = canonical_path.remove_filename().string();

        this->read_obj(filepath, basepath);
    }

    Model3D::~Model3D()
    {
        for (auto& m_loaded_texture: this->m_loaded_textures)
        {
            glDeleteTextures(1, &m_loaded_texture.id);
        }

        for (auto& mesh: this->m_meshes)
        {
            GLuint VBO = mesh.get_buffers().VBO;
            GLuint EBO = mesh.get_buffers().EBO;
            GLuint VAO = mesh.get_buffers().VAO;
            glDeleteBuffers(1, &VBO);
            glDeleteBuffers(1, &EBO);
            glDeleteVertexArrays(1, &VAO);
        }
    }

    void Model3D::draw(GLuint shader_program)
    {
        for (auto& mesh: this->m_meshes)
        {
            mesh.draw(shader_program);
        }
    }

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

    void Model3D::read_obj(const std::string& file_path,
                           const std::string& base_path)
    {
        std::cout << "Loading : " << file_path << "\n";
        tinyobj::attrib_t attrib{};
        std::vector<tinyobj::shape_t> shapes{};
        std::vector<tinyobj::material_t> materials{};

        std::string err{};
        bool ret = tinyobj::LoadObj(&attrib,
                                    &shapes,
                                    &materials,
                                    &err,
                                    file_path.c_str(),
                                    base_path.c_str(),
                                    GL_TRUE);

        if (!err.empty())
        {
            std::cerr << err << std::endl;
        }

        if (!ret)
        {
            exit(1);
        }

        int shapes_size = static_cast<int>(shapes.size());
        int materials_count = static_cast<int>(materials.size());

        std::cout << "# of shapes    : " << shapes_size << "\n";
        std::cout << "# of materials : " << materials_count << "\n";

        // Loop over shapes
        for (int s = 0; s < shapes_size; s++)
        {
            std::vector<vertex_t> vertices{};
            std::vector<GLuint> indices{};
            std::vector<texture_t> textures{};

            // Loop over faces(polygon)
            size_t index_offset = 0;

            size_t number_of_vertices_per_face
                    = shapes[s].mesh.num_face_vertices.size();

            for (size_t f = 0; f < number_of_vertices_per_face; f++)
            {
                int fv = shapes[s].mesh.num_face_vertices[f];

                // Loop over vertices in the face.
                for (int v = 0; v < fv; v++)
                {
                    // access to vertex
                    tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

                    float vx = attrib.vertices[3 * idx.vertex_index + 0];
                    float vy = attrib.vertices[3 * idx.vertex_index + 1];
                    float vz = attrib.vertices[3 * idx.vertex_index + 2];
                    float nx = attrib.normals[3 * idx.normal_index + 0];
                    float ny = attrib.normals[3 * idx.normal_index + 1];
                    float nz = attrib.normals[3 * idx.normal_index + 2];
                    float tx = 0.0f;
                    float ty = 0.0f;

                    if (idx.texcoord_index != -1)
                    {
                        tx = attrib.texcoords[2 * idx.texcoord_index + 0];
                        ty = attrib.texcoords[2 * idx.texcoord_index + 1];
                    }

                    glm::vec3 vertex_position(vx, vy, vz);
                    glm::vec3 vertex_normal(nx, ny, nz);
                    glm::vec2 vertex_texture_coords(tx, ty);

                    vertex_t current_vertex{};
                    current_vertex.Position = vertex_position;
                    current_vertex.Normal = vertex_normal;
                    current_vertex.TexCoords = vertex_texture_coords;

                    vertices.push_back(current_vertex);

                    indices.push_back(index_offset + v);
                }

                index_offset += fv;
            }

            // get material id
            // Only try to read materials if the .mtl file is present
            size_t a = shapes[s].mesh.material_ids.size();

            if (a > 0 && materials_count > 0)
            {
                for (int material_id = 0; material_id < materials_count; material_id++)
                {
                    if (material_id != -1)
                    {
                        material_t current_material;

                        current_material.ambient
                            = glm::vec3(materials[material_id].ambient[0],
                                        materials[material_id].ambient[1],
                                        materials[material_id].ambient[2]);

                        current_material.diffuse
                            = glm::vec3(materials[material_id].diffuse[0],
                                        materials[material_id].diffuse[1],
                                        materials[material_id].diffuse[2]);

                        current_material.specular
                            = glm::vec3(materials[material_id].specular[0],
                                        materials[material_id].specular[1],
                                        materials[material_id].specular[2]);

                        //ambient texture
                        std::string& ambient_texture_path = materials[material_id].ambient_texname;

                        if (!ambient_texture_path.empty())
                        {
                            texture_t current_texture
                                = this->load_texture(base_path + ambient_texture_path,
                                                     "ambientTexture");

                            textures.push_back(current_texture);
                        }

                        //diffuse texture
                        std::string& diffuse_texture_path = materials[material_id].diffuse_texname;
                        if (!diffuse_texture_path.empty())
                        {
                            texture_t current_texture
                                = this->load_texture(base_path + diffuse_texture_path,
                                                     "diffuseTexture");

                            textures.push_back(current_texture);
                        }

                        //specular texture
                        std::string& specular_texture_path = materials[material_id].specular_texname;
                        if (!specular_texture_path.empty())
                        {
                            texture_t current_texture
                                = this->load_texture(base_path + specular_texture_path,
                                                     "specularTexture");

                            textures.push_back(current_texture);
                        }
                    }
                }
            }

            this->m_meshes.emplace_back(vertices, indices, textures);
        }
    }

    texture_t Model3D::load_texture(const std::string& path, const std::string& type)
    {
        const size_t loaded_textures_size = this->m_loaded_textures.size();

        for (size_t idx = 0; idx < loaded_textures_size; idx++)
        {
            if (this->m_loaded_textures[idx].path == path)
            {
                //already loaded texture
                return this->m_loaded_textures[idx];
            }
        }

        texture_t current_texture;
        current_texture.id = this->read_texture_from_file(path.c_str());
        current_texture.type = type;
        current_texture.path = path;

        this->m_loaded_textures.push_back(current_texture);

        return current_texture;
    }

    GLuint Model3D::read_texture_from_file(const char* file_name)
    {
        int x, y, n;
        int force_channels = 4;
        uint8_t* image_data = stbi_load(file_name, &x, &y, &n, force_channels);

        if (!image_data)
        {
            fprintf(stderr, "ERROR: could not load %s\n", file_name);
            return false;
        }

        // NPOT check
        if ((x & (x - 1)) != 0 || (y & (y - 1)) != 0)
        {
            fprintf(stderr, "WARNING: texture %s is not power-of-2 dimensions\n", file_name);
        }

        int width_in_bytes = x * 4;
        unsigned char* top = nullptr;
        unsigned char* bottom = nullptr;
        unsigned char temp = 0;
        int half_height = y / 2;

        for (int row = 0; row < half_height; row++)
        {
            top = image_data + row * width_in_bytes;
            bottom = image_data + (y - row - 1) * width_in_bytes;

            for (int col = 0; col < width_in_bytes; col++)
            {
                temp = *top;
                *top = *bottom;
                *bottom = temp;
                top++;
                bottom++;
            }
        }

        GLuint texture_id;
        glGenTextures(1, &texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_SRGB,
            //GL_SRGB,//GL_RGBA,
            x,
            y,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            image_data
        );

        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);

        return texture_id;
    }

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */
