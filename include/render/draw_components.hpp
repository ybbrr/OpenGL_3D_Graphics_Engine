/**
 * @file draw_components.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 14/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_DRAW_COMPONENTS_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_DRAW_COMPONENTS_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "shader.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

    class DrawComponents
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        DrawComponents() noexcept = delete;

        virtual ~DrawComponents() noexcept = delete;

        DrawComponents(DrawComponents &&) noexcept = delete;

        DrawComponents &operator=(DrawComponents &&) noexcept = delete;

        DrawComponents(const DrawComponents &) noexcept = delete;

        DrawComponents &operator=(DrawComponents const &) noexcept = delete;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        static std::shared_ptr<YB::World> world;
        static std::shared_ptr<YB::Shader> shader;

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

#endif //OPENGL_3D_GRAPHICS_ENGINE_DRAW_COMPONENTS_HPP

/* End of File */
