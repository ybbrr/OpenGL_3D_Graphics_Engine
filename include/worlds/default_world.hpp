/**
 * @file default_world.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>

#include "world.hpp"
#include "model_3d.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

    class DefaultWorld : public World
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        DefaultWorld() noexcept = default;

        virtual ~DefaultWorld() noexcept = default;

        DefaultWorld(DefaultWorld &&) noexcept = default;

        DefaultWorld &operator=(DefaultWorld &&) noexcept = default;

        DefaultWorld(const DefaultWorld &) noexcept = default;

        DefaultWorld &operator=(DefaultWorld const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        void add_model(const std::string& file_name,
                       const std::string& model_name,
                       const glm::vec3& position) override;

        void render_models(std::shared_ptr<YB::Shader> shader) override;

        void init_uniforms(std::shared_ptr<YB::Window> window,
                           std::shared_ptr<YB::Camera> camera,
                           std::shared_ptr<YB::Shader> shader) override;

        GLint get_view_loc() override;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        std::vector<YB::Model3D> m_objs;

        // matrices
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 projection;
        glm::mat3 normal_matrix;

        GLint model_loc;
        GLint view_loc;
        GLint projection_loc;
        GLint normal_matrix_loc;

        // light parameters
        glm::vec3 light_dir;
        glm::vec3 light_color;
        glm::vec3 light_position;

        GLint light_dir_loc;
        GLint light_color_loc;
        GLint light_position_loc;

        GLint constant;
        GLint linear;
        GLint quadratic;
        GLuint shadow_map;

        GLfloat angle;
        GLfloat scale;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP

/* End of File */
