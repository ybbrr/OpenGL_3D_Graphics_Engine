/**
 * @file draw_components.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 14/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "draw_components.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{
    std::shared_ptr<YB::Shader> DrawComponents::m_shader{nullptr};

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

    void DrawComponents::set_shader(std::shared_ptr<YB::Shader> &shader) noexcept
    {
        m_shader = shader;
    }

    std::shared_ptr<YB::Shader> &DrawComponents::get_shader() noexcept
    {
        return m_shader;
    }

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

} // YB

/* End of File */
