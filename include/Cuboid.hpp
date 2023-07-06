//
// Created by L. Nagy on 04/07/2023.
//

#pragma once

#include "Point.hpp"

/**
 * A class to encode the concept of a cuboid - the three dimensional analogue of a rectangle. The cuboid is defined
 * by two three-dimensional coordinates i) a front-bottom-left coordinate, and ii) a back-top-right coordinate.
 */
class Cuboid {

public:

    /**
     * Create a cuboid with center-point <xm, ym, zm> and edge lengths Dx, Dy & Dz.
     */
    Cuboid(double xm, double ym, double zm, double Dx, double Dy, double Dz) {
        set_points(xm, ym, zm, Dx, Dy, Dz);
    }

    /**
     * Create a cuboid with center-point p and edge lengths Dx, Dy & Dz.
     */
    Cuboid(const Point3D &p, double Dx, double Dy, double Dz) {
        set_points(p.x, p.y, p.z, Dx, Dy, Dz);
    }

    /**
     * Retrieve the cuboid's mid point.
     * @return  the cuboid mid point.
     */
    [[nodiscard]] const Point3D &mid() const {
        return _p13;
    }

    /**
     * Retrieve the cuboid's x-length (x-diameter).
     * @return the cuboid's x-length (x-diameter).
     */
    [[nodiscard]] double Dx() const {
        return _Dx;
    }

    /**
     * Retrieve the cuboid's y-length (y-diameter).
     * @return the cuboid's y-length (y-diameter).
     */
    [[nodiscard]] double Dy() const {
        return _Dy;
    }

    /**
     * Retrieve the cuboid's z-length (z-diameter).
     * @return the cuboid's z-length (z-diameter).
     */
    [[nodiscard]] double Dz() const {
        return _Dz;
    }

    [[nodiscard]] bool contains(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x - Dx() / 2 < p.x) && (p.x < m.x + Dx() / 2) && (m.y - Dy() / 2 < p.y) && (p.y < m.y + Dy() / 2) &&
               (m.z - Dz() / 2 < p.z) && (p.z < m.z + Dz() / 2);

    }

    [[nodiscard]] bool contained_in_bottom_back_left(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x - Dx() / 2 < p.x) && (p.x < m.x) && (m.y - Dy() / 2 < p.y) && (p.y < m.y) &&
               (m.z - Dz() / 2 < p.z) && (p.z < m.z);

    }

    [[nodiscard]] bool contained_in_bottom_back_right(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x < p.x) && (p.x < m.x + Dx() / 2) && (m.y - Dy() / 2 < p.y) && (p.y < m.y) &&
               (m.z - Dz() / 2 < p.z) && (p.z < m.z);

    }

    [[nodiscard]] bool contained_in_bottom_front_left(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x - Dx() / 2 < p.x) && (p.x < m.x) && (m.y - Dy() / 2 < p.y) && (p.y < m.y) && (m.z < p.z) &&
               (p.z < m.z + Dz() / 2);

    }

    [[nodiscard]] bool contained_in_bottom_front_right(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x < p.x) && (p.x < m.x + Dx() / 2) && (m.y - Dy() / 2 < p.y) && (p.y < m.y) && (m.z < p.z) &&
               (p.z < m.z + Dz() / 2);

    }

    [[nodiscard]] bool contained_in_top_back_left(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x - Dx() / 2 < p.x) && (p.x < m.x) && (m.y < p.y) && (p.y < m.y + Dy() / 2) &&
               (m.z - Dz() / 2 < p.z) && (p.z < m.z);

    }

    [[nodiscard]] bool contained_in_top_back_right(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x < p.x) && (p.x < m.x + Dx() / 2) && (m.y < p.y) && (p.y < m.y + Dy() / 2) &&
               (m.z - Dz() / 2 < p.z) && (p.z < m.z);

    }

    [[nodiscard]] bool contained_in_top_front_left(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x - Dx() / 2 < p.x) && (p.x < m.x) && (m.y < p.y) && (p.y < m.y + Dy() / 2) && (m.z < p.z) &&
               (p.z < m.z + Dz() / 2);

    }

    [[nodiscard]] bool contained_in_top_front_right(const Point3D &p) const {

        const Point3D m = mid();

        return (m.x < p.x) && (p.x < m.x + Dx() / 2) && (m.y < p.y) && (p.y < m.y + Dy() / 2) && (m.z < p.z) &&
               (p.z < m.z + Dz() / 2);

    }

private:

    void set_points(double xm, double ym, double zm, double Dx, double Dy, double Dz) {

        _Dx = Dx;
        _Dy = Dy;
        _Dz = Dz;

        _p00 = {xm - Dx / 2, ym + Dy / 2, zm + Dz / 2};
        _p01 = {xm - Dx / 2, ym, zm + Dz / 2};
        _p02 = {xm - Dx / 2, ym - Dy / 2, zm + Dz / 2};
        _p03 = {xm, ym + Dy / 2, zm + Dz / 2};
        _p04 = {xm, ym, zm + Dz / 2};
        _p05 = {xm, ym - Dy / 2, zm + Dz / 2};
        _p06 = {xm + Dx / 2, ym + Dy / 2, zm + Dz / 2};
        _p07 = {xm + Dx / 2, ym, zm + Dz / 2};
        _p08 = {xm + Dx / 2, ym - Dy / 2, zm + Dz / 2};

        _p09 = {xm - Dx / 2, ym + Dy / 2, zm};
        _p10 = {xm - Dx / 2, ym, zm};
        _p11 = {xm - Dx / 2, ym - Dy / 2, zm};
        _p12 = {xm, ym + Dy / 2, zm};
        _p13 = {xm, ym, zm};
        _p14 = {xm, ym - Dy / 2, zm};
        _p15 = {xm + Dx / 2, ym + Dy / 2, zm};
        _p16 = {xm + Dx / 2, ym, zm};
        _p17 = {xm + Dx / 2, ym - Dy / 2, zm};

        _p18 = {xm - Dx / 2, ym + Dy / 2, zm - Dz / 2};
        _p19 = {xm - Dx / 2, ym, zm - Dz / 2};
        _p20 = {xm - Dx / 2, ym - Dy / 2, zm - Dz / 2};
        _p21 = {xm, ym + Dy / 2, zm - Dz / 2};
        _p22 = {xm, ym, zm - Dz / 2};
        _p23 = {xm, ym - Dy / 2, zm - Dz / 2};
        _p24 = {xm + Dx / 2, ym + Dy / 2, zm - Dz / 2};
        _p25 = {xm + Dx / 2, ym, zm - Dz / 2};
        _p26 = {xm + Dx / 2, ym - Dy / 2, zm - Dz / 2};

    }

    double _Dx, _Dy, _Dz;

    Point3D _p00;
    Point3D _p01;
    Point3D _p02;
    Point3D _p03;
    Point3D _p04;
    Point3D _p05;
    Point3D _p06;
    Point3D _p07;
    Point3D _p08;
    Point3D _p09;
    Point3D _p10;
    Point3D _p11;
    Point3D _p12;
    Point3D _p13;
    Point3D _p14;
    Point3D _p15;
    Point3D _p16;
    Point3D _p17;
    Point3D _p18;
    Point3D _p19;
    Point3D _p20;
    Point3D _p21;
    Point3D _p22;
    Point3D _p23;
    Point3D _p24;
    Point3D _p25;
    Point3D _p26;

};