/**
 * @file model_3d.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 09/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_MODEL_3D_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_MODEL_3D_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <string>
#include "shader.hpp"
#include "mesh.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

    class Model3D
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Model3D() noexcept = delete;

        Model3D(Model3D &&) noexcept = default;

        Model3D &operator=(Model3D &&) noexcept = default;

        Model3D(const Model3D &) noexcept = default;

        Model3D &operator=(Model3D const&) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        explicit Model3D(const std::string& file_path,
                         const std::string& model_name,
                         const glm::vec3& position,
                         bool rotatable,
                         bool scalable);

        ~Model3D();

        void draw(GLuint shader_program);

        glm::vec3 obj_position;
        bool is_rotatable;
        bool is_scalable;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        // Does the parsing of the .obj file and fills in the data structure
        void read_obj(const std::string& file_name, const std::string& base_path);

        // Retrieves a texture associated with the object - by its name and type
        texture_t load_texture(const std::string& path, const std::string& type);

        // Reads the pixel data from an image file and loads it into the video memory
        GLuint read_texture_from_file(const char* file_name);

        // Component meshes - group of objects
        std::vector<YB::Mesh> m_meshes;

        // Associated textures
        std::vector<texture_t> m_loaded_textures;

        std::string m_model_name;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_MODEL_3D_HPP

/* End of File */
