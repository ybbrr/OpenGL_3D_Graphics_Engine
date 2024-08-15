/**
 * @file core_components.cpp
 * @author Yasin BASAR
 * @brief Implements the static members of the CoreComponents class.
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

    /**
     * @brief Static member initialization for the Window component.
     */
    std::shared_ptr<YB::Window> CoreComponents::window{nullptr};

    /**
     * @brief Static member initialization for the Camera component.
     */
    std::shared_ptr<YB::Camera> CoreComponents::camera{nullptr};

    /**
     * @brief Static member initialization for the World component.
     */
    std::shared_ptr<YB::World> CoreComponents::world{nullptr};

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
