/**
 * @file draw_components.hpp
 * @author Yasin BASAR
 * @brief Declares the DrawComponents class which holds static pointers to drawing-related components of the graphics engine.
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

#include <memory>

namespace YB
{

    /**
     * @class DrawComponents
     * @brief Provides static access to drawing-related components of the graphics engine.
     *
     * The DrawComponents class holds static pointers to the World and Shader objects.
     * It provides a central place to access these components used for rendering in the graphics engine.
     */
    class DrawComponents
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        DrawComponents() noexcept = delete; /**< Deleted default constructor */
        virtual ~DrawComponents() noexcept = delete; /**< Deleted default destructor */
        DrawComponents(DrawComponents &&) noexcept = delete; /**< Deleted default move constructor */
        DrawComponents &operator=(DrawComponents &&) noexcept = delete; /**< Deleted default move assignment operator */
        DrawComponents(const DrawComponents &) noexcept = delete; /**< Deleted default copy constructor */
        DrawComponents &operator=(DrawComponents const &) noexcept = delete; /**< Deleted default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Static pointer to the World component.
         *
         * This static pointer provides access to the World object used for rendering in the graphics engine.
         */
        static std::shared_ptr<YB::World> world;

        /**
         * @brief Static pointer to the Shader component.
         *
         * This static pointer provides access to the Shader object used for rendering in the graphics engine.
         */
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
