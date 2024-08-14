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

        static void set_window(std::shared_ptr<YB::Window>& window) noexcept;
        static void set_camera(std::shared_ptr<YB::Camera>& camera) noexcept;
        static void set_world(std::shared_ptr<YB::World>& world) noexcept;

        static std::shared_ptr<YB::Window>& get_window() noexcept;
        static std::shared_ptr<YB::Camera>& get_camera() noexcept;
        static std::shared_ptr<YB::World>& get_world() noexcept;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        static std::shared_ptr<YB::Window> m_window;
        static std::shared_ptr<YB::Camera> m_camera;
        static std::shared_ptr<YB::World> m_world;

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP

/* End of File */
