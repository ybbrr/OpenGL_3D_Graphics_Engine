/**
 * @file world.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include "shader.hpp"
#include "window.hpp"
#include "camera.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

typedef int GLint;

namespace YB
{
    class World
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        World() noexcept = default;

        virtual ~World() noexcept = default;

        World(World &&) noexcept = default;

        World &operator=(World &&) noexcept = default;

        World(const World &) noexcept = default;

        World &operator=(World const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        virtual void add_model(const std::string& file_name,
                               const std::string& model_name,
                               const glm::vec3& position);

        virtual void render_models(std::shared_ptr<YB::Shader>& shader);

        virtual void init_uniforms(std::shared_ptr<YB::Window>& window,
                                   std::shared_ptr<YB::Camera>& camera,
                                   std::shared_ptr<YB::Shader>& shader);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /* Data */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP

/* End of File */
