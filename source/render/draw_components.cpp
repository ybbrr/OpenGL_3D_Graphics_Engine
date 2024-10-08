///
/// @file draw_components.cpp
/// @author Yasin BASAR
/// @brief Implements the static members of the DrawComponents class.
/// @version 1.0.0
/// @date 14/08/2024
/// @copyright (c) 2024 All rights reserved.
///

////////////////////////////////////////////////////////////////////////////////
// Project Includes
////////////////////////////////////////////////////////////////////////////////

#include "draw_components.hpp"

////////////////////////////////////////////////////////////////////////////////
// Third Party Includes
////////////////////////////////////////////////////////////////////////////////

namespace YB
{
    ///
    /// @brief Static member initialization for the World component.
    ///
    std::shared_ptr<World> DrawComponents::world{nullptr};

    ///
    /// @brief Static member initialization for the Shader component.
    ///
    std::shared_ptr<Shader> DrawComponents::shader{nullptr};

////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Protected Functions
////////////////////////////////////////////////////////////////////////////////

} // namespace YB

/* End of File */
