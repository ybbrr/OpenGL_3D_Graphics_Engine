/**
 * @file core_components.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 14/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "core_components.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{

    std::shared_ptr<YB::Window> CoreComponents::m_window{nullptr};
    std::shared_ptr<YB::Camera> CoreComponents::m_camera{nullptr};
    std::shared_ptr<YB::World> CoreComponents::m_world{nullptr};

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    void YB::CoreComponents::set_window(std::shared_ptr<YB::Window> &window) noexcept
    {
        m_window = window;
    }

    void CoreComponents::set_camera(std::shared_ptr<YB::Camera> &camera) noexcept
    {
        m_camera = camera;
    }

    void CoreComponents::set_world(std::shared_ptr<YB::World> &world) noexcept
    {
        m_world = world;
    }

    std::shared_ptr<YB::Window> &CoreComponents::get_window() noexcept
    {
        return m_window;
    }

    std::shared_ptr<YB::Camera> &CoreComponents::get_camera() noexcept
    {
        return m_camera;
    }

    std::shared_ptr<YB::World> &CoreComponents::get_world() noexcept
    {
        return m_world;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
