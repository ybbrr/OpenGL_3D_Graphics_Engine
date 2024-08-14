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

        virtual ~DefaultWorld() noexcept = default;

        DefaultWorld(DefaultWorld &&) noexcept = default;

        DefaultWorld &operator=(DefaultWorld &&) noexcept = default;

        DefaultWorld(const DefaultWorld &) noexcept = default;

        DefaultWorld &operator=(DefaultWorld const &) noexcept = default;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        explicit DefaultWorld();

        void add_model(const std::string& file_name,
                       const std::string& model_name,
                       const glm::vec3& position,
                       bool rotatable,
                       bool scalable) override;

        void render_models() override;

        void increase_rotate_angle(float value) override;
        void increase_scale_factor(float value) override;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        std::vector<YB::Model3D> m_objs;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP

/* End of File */
