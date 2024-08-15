/**
 * @file default_world.hpp
 * @author Yasin BASAR
 * @brief Defines the DefaultWorld class which manages a collection of 3D models
 *        and handles their transformations and rendering.
 * @version 1.0.0
 * @date 10/08/2024
 * @copyright (c) 2024 All rights reserved.
 */

#ifndef OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP
#define OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include "world.hpp"
#include "model_3d.hpp"

/*******************************************************************************
 * Third Party Libraries
 ******************************************************************************/

namespace YB
{

    /**
     * @class DefaultWorld
     * @brief Manages a collection of 3D models and handles their transformations
     *        and rendering.
     *
     * This class extends the World class to provide functionality for adding,
     * transforming, and rendering 3D models in the world.
     */
    class DefaultWorld : public World
    {
    public:
    /***************************************************************************
     * Special Members
     **************************************************************************/

        virtual ~DefaultWorld() noexcept = default; /**< Default destructor */
        DefaultWorld(DefaultWorld &&) noexcept = default; /**< Default move constructor */
        DefaultWorld &operator=(DefaultWorld &&) noexcept = default; /**< Default move assignment operator */
        DefaultWorld(const DefaultWorld &) noexcept = default; /**< Default copy constructor */
        DefaultWorld &operator=(DefaultWorld const &) noexcept = default; /**< Default copy assignment operator */

    /***************************************************************************
     * Public Members
     **************************************************************************/

        /**
         * @brief Constructs a DefaultWorld instance.
         *
         * Initializes an empty list of 3D models.
         */
        explicit DefaultWorld();

        /**
         * @brief Adds a 3D model to the world.
         *
         * This function creates a new 3D model and adds it to the collection
         * of models in the world.
         *
         * @param file_name[in] The file name of the model.
         * @param model_name[in] The name of the model.
         * @param position[in] The position of the model in the world.
         * @param rotatable[in] Whether the model can be rotated.
         * @param scalable[in] Whether the model can be scaled.
         */
        void add_model(const std::string& file_name,
                       const std::string& model_name,
                       const glm::vec3& position,
                       bool rotatable,
                       bool scalable) override;

        /**
         * @brief Renders all models in the world.
         *
         * This function iterates through all 3D models and applies the current
         * transformations before drawing them.
         */
        void render_models() override;

        /**
         * @brief Increases the rotation angle for the models.
         *
         * This function updates the rotation angle applied to all models
         * in the world.
         *
         * @param value[in] The amount by which to increase the rotation angle.
         */
        void increase_rotate_angle(float value) override;

        /**
         * @brief Increases the scale factor for the models.
         *
         * This function updates the scale factor applied to all models
         * in the world.
         *
         * @param value[in] The amount by which to increase the scale factor.
         */
        void increase_scale_factor(float value) override;

    /***************************************************************************
     * Private Members
     **************************************************************************/
    private:

        std::vector<YB::Model3D> m_objs; ///< List of 3D models in the world.

    /***************************************************************************
     * Protected Members
     **************************************************************************/
    protected:

        /* Data */

    };

} // namespace YB

#endif //OPENGL_3D_GRAPHICS_ENGINE_DEFAULT_WORLD_HPP

/* End of File */
