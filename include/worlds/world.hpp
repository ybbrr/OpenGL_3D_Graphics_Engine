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
#include "window.hpp"
#include "camera.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glm/glm.hpp>

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
                               const glm::vec3& position,
                               bool rotatable,
                               bool scalable);

        virtual void render_models();

        virtual void increase_rotate_angle(float value);
        virtual void increase_scale_factor(float value);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /* Data */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        float m_rotate_angle = 5.0f;
        float m_scale_factor = 0.0f;

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP

/* End of File */
