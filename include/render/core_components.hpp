///
/// @file core_components.hpp
/// @author Yasin BASAR
/// @brief Defines the CoreComponents class which holds static pointers to core components of the graphics engine.
/// @version 1.0.0
/// @date 14/08/2024
/// @copyright (c) 2024 All rights reserved.
///

#ifndef OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "window.hpp"
#include "camera.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

#include <memory>

namespace YB
{

    ///
    /// @class CoreComponents
    /// @brief Provides static access to core components of the graphics engine.
    ///
    /// The CoreComponents class holds static pointers to the Window, Camera, and World objects.
    /// It provides a central place to access these components throughout the application.
    ///
    class CoreComponents
    {
    public:
    ////////////////////////////////////////////////////////////////////////////
    // Special Members
    ////////////////////////////////////////////////////////////////////////////

        CoreComponents() noexcept = delete; /**< Deleted default constructor */
        ~CoreComponents() noexcept = delete; /**< Deleted default destructor */
        CoreComponents(CoreComponents &&) noexcept = delete; /**< Deleted default move constructor */
        CoreComponents &operator=(CoreComponents &&) noexcept = delete; /**< Deleted default move assignment operator */
        CoreComponents(const CoreComponents &) noexcept = delete; /**< Deleted default copy constructor */
        CoreComponents &operator=(CoreComponents const &) noexcept = delete; /**< Deleted default copy assignment operator */

    ////////////////////////////////////////////////////////////////////////////
    // Public Members
    ////////////////////////////////////////////////////////////////////////////

        ///
        /// @brief Static pointer to the Window component.
        ///
        /// This static pointer provides access to the Window object used in the graphics engine.
        ///
        static std::shared_ptr<Window> window;

        ///
        /// @brief Static pointer to the Camera component.
        ///
        /// This static pointer provides access to the Camera object used in the graphics engine.
        ///
        static std::shared_ptr<Camera> camera;


    ////////////////////////////////////////////////////////////////////////////
    // Private Members
    ////////////////////////////////////////////////////////////////////////////
    private:

        // Data

    ////////////////////////////////////////////////////////////////////////////
    // Protected Members
    ////////////////////////////////////////////////////////////////////////////
    protected:

        // Data

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_CORE_COMPONENTS_HPP

/* End of File */
