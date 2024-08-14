/**
 * @file core_components.hpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 14/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "window.hpp"
#include "camera.hpp"
#include "world.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <memory>

namespace YB
{

    class CoreComponents
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        CoreComponents() noexcept = delete;

        virtual ~CoreComponents() noexcept = delete;

        CoreComponents(CoreComponents &&) noexcept = delete;

        CoreComponents &operator=(CoreComponents &&) noexcept = delete;

        CoreComponents(const CoreComponents &) noexcept = delete;

        CoreComponents &operator=(CoreComponents const &) noexcept = delete;

    /***************************************************************************
     * Public Members
     **************************************************************************/

        static std::shared_ptr<YB::Window> window;
        static std::shared_ptr<YB::Camera> camera;
        static std::shared_ptr<YB::World> world;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP

/* End of File */
