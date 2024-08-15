/**
 * @file model_3d.hpp
 * @author Yasin BASAR
 * @brief Defines the Model3D class for handling 3D models, including loading from files and rendering.
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
    /**
     * @class Model3D
     * @brief Represents a 3D model with meshes and textures, capable of loading from files and rendering.
     *
     * The Model3D class handles the loading of 3D model data from files, including parsing `.obj` files,
     * and manages textures. It also provides methods for rendering the model.
     */
    class Model3D
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        Model3D() noexcept = delete; /**< Deleted default constructor */
        Model3D(Model3D &&) noexcept = default; /**< Default move constructor */
        Model3D &operator=(Model3D &&) noexcept = default; /**< Default move assignment operator */
        Model3D(const Model3D &) noexcept = default; /**< Default copy constructor */
        Model3D &operator=(Model3D const&) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructs a Model3D object by loading a model from a file.
         * @param [in] file_path Path to the model file.
         * @param [in] model_name Name of the model.
         * @param [in] position Initial position of the model.
         * @param [in] rotatable Whether the model can be rotated.
         * @param [in] scalable Whether the model can be scaled.
         */
        explicit Model3D(const std::string& file_path,
                         const std::string& model_name,
                         const glm::vec3& position,
                         bool rotatable,
                         bool scalable);

        /**
         * @brief Destructor that cleans up resources.
         */
        ~Model3D();

        /**
         * @brief Draws the 3D model using the provided shader program.
         * @param [in] shader_program The ID of the shader program to use for rendering.
         */
        void draw(GLuint shader_program);

        glm::vec3 obj_position; /**< The position of the model in world coordinates. */
        bool is_rotatable; /**< Flag indicating if the model can be rotated. */
        bool is_scalable; /**< Flag indicating if the model can be scaled. */

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /**
         * @brief Reads and parses a .obj file to extract model data.
         * @param [in] file_name The name of the .obj file.
         * @param [in] base_path The base path for texture files.
         */
        void read_obj(const std::string& file_name, const std::string& base_path);

        /**
         * @brief Loads a texture from a file.
         * @param [in] path The path to the texture file.
         * @param [in] type The type of texture (e.g., "ambientTexture").
         * @return The loaded texture.
         */
        texture_t load_texture(const std::string& path, const std::string& type);

        /**
         * @brief Reads pixel data from an image file and loads it into OpenGL.
         * @param [in] file_name The name of the image file.
         * @return The ID of the generated texture.
         */
        GLuint read_texture_from_file(const char* file_name);

        std::vector<YB::Mesh> m_meshes; /**< Collection of meshes in the model. */
        std::vector<texture_t> m_loaded_textures; /**< Collection of loaded textures. */
        std::string m_model_name; /**< Name of the model. */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_MODEL_3D_HPP

/* End of File */
