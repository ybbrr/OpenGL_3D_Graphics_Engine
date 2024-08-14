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

        static void set_shader(std::shared_ptr<YB::Shader>& shader) noexcept;

        static std::shared_ptr<YB::Shader>& get_shader() noexcept;

/***************************************************************************
 * Private Members
 **************************************************************************/
    private:

        static std::shared_ptr<YB::World> m_world;
        static std::shared_ptr<YB::Shader> m_shader;

/***************************************************************************
 * Protected Members
 **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_DRAW_COMPONENTS_HPP

/* End of File */
