//
// Created by L. Nagy on 04/07/2023.
//

#pragma once

#include "point.hpp"

namespace mimg {

/**
 * A class to encode the concept of a cuboid - the three dimensional analogue of a rectangle. The cuboid is defined
 * by a midpoint coordinate and the edge lengths Dx, Dy & Dz.
 */
    class Cuboid {

    public:

        /**
         * Create a cuboid with center-point <mx, my> and edge lengths Dx, Dy & Dz.
         */
        Cuboid(double new_mx, double new_my, double new_mz, double new_Dx, double new_Dy, double new_Dz) :
                mx(new_mx), my(new_my), mz(new_mz), Dx(new_Dx), Dy(new_Dy), Dz(new_Dz) {}

        /**
         * Create a cuboid with center-point p and edge lengths Dx, Dy & Dz.
         */
        Cuboid(const Point3D &new_p, double new_Dx, double new_Dy, double new_Dz) :
                mx(new_p.x), my(new_p.y), mz(new_p.z), Dx(new_Dx), Dy(new_Dy), Dz(new_Dz) {}

        /**
         * Test if a point is in the the cuboid.
         * @param p a point in 3D space.
         * @return true if p is in the cuboid, otherwise false.
         */
        [[nodiscard]] bool in(const Point3D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx + Dx / 2) &&
                   (my - Dy / 2 < p.y) && (p.y < my + Dy / 2) &&
                   (mz - Dz / 2 < p.z) && (p.z < mz + Dz / 2);

        }

        /**
         * Test if a point is in the bottom-back-left sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the bottom-back-left sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_bottom_back_left(const Point3D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx) &&
                   (my - Dy / 2 < p.y) && (p.y < my) &&
                   (mz - Dz / 2 < p.z) && (p.z < mz);

        }

        /**
         * Test if a point is in the bottom-back-right sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the bottom-back-right sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_bottom_back_right(const Point3D &p) const {

            return (mx < p.x) && (p.x < mx + Dx / 2) &&
                   (my - Dy / 2 < p.y) && (p.y < my) &&
                   (mz - Dz / 2 < p.z) && (p.z < mz);

        }

        /**
         * Test if a point is in the bottom-front-left sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the bottom-front-left sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_bottom_front_left(const Point3D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx) &&
                   (my - Dy / 2 < p.y) && (p.y < my) &&
                   (mz < p.z) && (p.z < mz + Dz / 2);

        }

        /**
         * Test if a point is in the bottom-front-right sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the bottom-front-right sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_bottom_front_right(const Point3D &p) const {

            return (mx < p.x) && (p.x < mx + Dx / 2) &&
                   (my - Dy / 2 < p.y) && (p.y < my) &&
                   (mz < p.z) && (p.z < mz + Dz / 2);

        }

        /**
         * Test if a point is in the top-back-left sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the top-back-left sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_top_back_left(const Point3D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx) &&
                   (my < p.y) && (p.y < my + Dy / 2) &&
                   (mz - Dz / 2 < p.z) && (p.z < mz);

        }

        /**
         * Test if a point is in the top-back-right sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the top-back-right sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_top_back_right(const Point3D &p) const {

            return (mx < p.x) && (p.x < mx + Dx / 2) &&
                   (my < p.y) && (p.y < my + Dy / 2) &&
                   (mz - Dz / 2 < p.z) && (p.z < mz);

        }

        /**
         * Test if a point is in the top-front-left sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the top-front-left sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_top_front_left(const Point3D &p) const {

            return (mx - Dx / 2 < p.x) && (p.x < mx) &&
                   (my < p.y) && (p.y < my + Dy / 2) &&
                   (mz < p.z) && (p.z < mz + Dz / 2);

        }

        /**
         * Test if a point is in the top-front-right sub-cuboid.
         * @param p a point in 3D space.
         * @return true if p in in the top-front-right sub-cuboid, otherwise false.
         */
        [[nodiscard]] bool in_top_front_right(const Point3D &p) const {

            return (mx < p.x) && (p.x < mx + Dx / 2) &&
                   (my < p.y) && (p.y < my + Dy / 2) &&
                   (mz < p.z) && (p.z < mz + Dz / 2);

        }

        [[nodiscard]] Cuboid bottom_back_left() const {
            return {mx - Dx / 4, my - Dy / 4, mz - Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid bottom_back_right() const {
            return {mx + Dx / 4, my - Dy / 4, mz - Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid bottom_front_left() const {
            return {mx - Dx / 4, my - Dy / 4, mz + Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid bottom_front_right() const {
            return {mx + Dx / 4, my - Dy / 4, mz + Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid top_back_left() const {
            return {mx - Dx / 4, my + Dy / 4, mz - Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid top_back_right() const {
            return {mx + Dx / 4, my + Dy / 4, mz - Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid top_front_left() const {
            return {mx - Dx / 4, my + Dy / 4, mz + Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

        [[nodiscard]] Cuboid top_front_right() const {
            return {mx + Dx / 4, my + Dy / 4, mz + Dz / 4, Dx / 2, Dy / 2, Dz / 2};
        }

    private:

        double mx, my, mz;
        double Dx, Dy, Dz;

    };

} // namespace mimg