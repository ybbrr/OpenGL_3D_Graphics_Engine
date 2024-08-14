/**
 * @file world.cpp
 * @author Yasin BASAR
 * @brief
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */


/*******************************************************************************
 * Includes 
 ******************************************************************************/

#include "world.hpp"

/*******************************************************************************
 * Third Party Libraries 
 ******************************************************************************/

namespace YB
{

/*******************************************************************************
 * Public Functions
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Protected Functions
 ******************************************************************************/

    void World::add_model(const std::string &file_name,
                          const std::string &model_name,
                          const glm::vec3 &position,
                          bool rotatable,
                          bool scalable)
    {

    }

    void World::render_models(std::shared_ptr<YB::Shader>& shader)
    {

    }

    void World::init_uniforms(std::shared_ptr<YB::Window> &window,
                              std::shared_ptr<YB::Camera> &camera,
                              std::shared_ptr<YB::Shader> &shader)
    {

    }

    void World::increase_rotate_angle(float value)
    {
        this->m_rotate_angle += value;
    }

    void World::increase_scale_factor(float value)
    {
        this->m_scale_factor += value;
    }
} // YB

/* End of File */
