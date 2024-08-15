/**
 * @file world.hpp
 * @author Yasin BASAR
 * @brief Defines the World class which serves as a base class for managing
 *        3D models, their transformations, and rendering.
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

#include <glm/glm.hpp>

typedef int GLint;

namespace YB
{
    /**
     * @class World
     * @brief Base class for managing 3D models, including their transformations
     *        and rendering.
     *
     * This class provides virtual methods to add models, render them, and apply
     * transformations such as rotation and scaling.
     */
    class World
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        World() noexcept = default; /**< Default default constructor */
        virtual ~World() noexcept = default; /**< Default destructor */
        World(World &&) noexcept = default; /**< Default move constructor */
        World &operator=(World &&) noexcept = default; /**< Default move assignment operator */
        World(const World &) noexcept = default; /**< Default copy constructor */
        World &operator=(World const &) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Adds a 3D model to the world.
         *
         * This function is intended to be overridden by derived classes to
         * add a 3D model to the world.
         *
         * @param file_name[in] The file name of the model.
         * @param model_name[in] The name of the model.
         * @param position[in] The position of the model in the world.
         * @param rotatable[in] Whether the model can be rotated.
         * @param scalable[in] Whether the model can be scaled.
         */
        virtual void add_model(const std::string& file_name,
                               const std::string& model_name,
                               const glm::vec3& position,
                               bool rotatable,
                               bool scalable);

        /**
         * @brief Renders all models in the world.
         *
         * This function is intended to be overridden by derived classes to
         * render all models in the world.
         */
        virtual void render_models();

        /**
         * @brief Increases the rotation angle for the models.
         *
         * This function is intended to be overridden by derived classes to
         * update the rotation angle applied to all models in the world.
         *
         * @param value[in] The amount by which to increase the rotation angle.
         */
        virtual void increase_rotate_angle(float value);

        /**
         * @brief Increases the scale factor for the models.
         *
         * This function is intended to be overridden by derived classes to
         * update the scale factor applied to all models in the world.
         *
         * @param value[in] The amount by which to increase the scale factor.
         */
        virtual void increase_scale_factor(float value);

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        /* Data */

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        float m_rotate_angle = 5.0f;
        float m_scale_factor = 0.0f;

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_WORLD_HPP

/* End of File */
