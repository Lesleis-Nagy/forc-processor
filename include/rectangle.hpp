//
// Created by L. Nagy on 06/07/2023.
//

#pragma once

#include "point.hpp"

namespace mimg {

    /**
     * A class to encode the concept of a rectangle. The rectangle is defined by a midpoint and the edge lengths
     * Dx & Dy.
     */
    class Rectangle {

    public:

        /**
         * Create a rectangle with center-point <mx, my>.
         */
        Rectangle(double new_mx, double new_my, double new_Dx, double new_Dy) :
                mx(new_mx), my(new_my), Dx(new_Dx), Dy(new_Dy) {}

        /**
         * Create a rectangle with center-point p and edge lengths Dx & Dy.
         */
        Rectangle(const Point2D &new_p, double new_Dx, double new_Dy) :
                mx(new_p.x), my(new_p.y), Dx(new_Dx), Dy(new_Dy) {}

        /**
         * Test if a point is in the rectangle.
         * @param p a point in 3D space.
         * @return true if p is in the rectangle, otherwise false.
         */
        [[nodiscard]] bool in(const Point2D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx + Dx / 2) &&
                   (my - Dy / 2 < p.y) && (p.y < my + Dy / 2);

        }

        /**
         * Test if a point is in the bottom-left sub-rectangle.
         * @param p a point in 2D space.
         * @return true if p is in the bottom-left sub-rectangle, otherwise false.
         */
        [[nodiscard]] bool in_bottom_left(const Point2D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx) &&
                   (my - Dy / 2 < p.y) && (p.y < my);

        }

        /**
         * Test if a point is in the bottom-right sub-rectangle.
         * @param p a point in 2D space.
         * @return true if p is in the bottom-right sub-rectangle, otherwise false.
         */
        [[nodiscard]] bool in_bottom_right(const Point2D &p) const {

            return (mx < p.x) && (p.x < mx + Dx / 2) &&
                   (my - Dy / 2 < p.y) && (p.y < my);

        }

        /**
         * Test if a point is in the top-left sub-rectangle.
         * @param p a point in 2D space.
         * @return true if p is in the top-left sub-rectangle, otherwise false.
         */
        [[nodiscard]] bool in_top_left(const Point2D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx) &&
                   (my < p.y) && (p.y < my + Dy / 2);

        }

        /**
         * Test if a point is in the top-right sub-rectangle.
         * @param p a point in 2D space.
         * @return true if p is in the top-right sub-rectangle, otherwise false.
         */
        [[nodiscard]] bool in_top_right(const Point2D &p) const {

            return (mx < p.x) && (p.x < mx + Dx / 2) &&
                   (my < p.y) && (p.y < my + Dy / 2);

        }

        /**
         * Retrieve the bottom-left sub-rectangle.
         * @return the bottom-left sub-rectangle as a new Rectangle object.
         */
        [[nodiscard]] Rectangle bottom_left() const {

            return {mx - Dx / 4, my - Dx / 4, Dx / 2, Dy / 2};

        }

        /**
         * Retrieve the bottom-right sub-rectangle.
         * @return the bottom-right sub-rectangle as a new Rectangle object.
         */
        [[nodiscard]] Rectangle bottom_right() const {

            return {mx + Dx / 4, my - Dx / 4, Dx / 2, Dy / 2};

        }

        /**
         * Retrieve the top-left sub-rectangle.
         * @return the top-left sub-rectangle as a new Rectangle object.
         */
        [[nodiscard]] Rectangle top_left() const {

            return {mx - Dx / 4, my + Dx / 4, Dx / 2, Dy / 2};

        }

        /**
         * Retrieve the top-right sub-rectangle.
         * @return the top-right sub-rectangle as a new Rectangle object.
         */
        [[nodiscard]] Rectangle top_right() const {

            return {mx + Dx / 4, my + Dx / 4, Dx / 2, Dy / 2};

        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Member variables.                                                                                        //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////

        double mx, my;
        double Dx, Dy;

    };

} // namespace mimg