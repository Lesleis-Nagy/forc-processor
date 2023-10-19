//
// Created by L. Nagy on 04/07/2023.
//

#pragma once

#include <iostream>
#include <cmath>

namespace mimg {

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 2D-Cartesian displacements/vectors and positions with associated operations.                                  //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // A 2D-Cartesian point location in two-dimensional space.
    struct Point2D {

        double x; // The x-component of the position.
        double y; // The y-component of the position.

    };

    // A 2D-Cartesian vector/displacement in two-dimensional space.
    struct Vector2D {

        double x; // The x-component of the vector/displacement.
        double y; // The y-component of the vector/displacement.

    };

    // Adding a 2D-Cartesian vector to a 2D-Cartesian position results in a new 2D-Cartesian position.
    inline Point2D operator+(const Point2D &a, const Vector2D &b) {
        return {a.x + b.x, a.y + b.y};
    }

    // Adding a 2D-Cartesian vector to a 2D-Cartesian position results in a new 2D-Cartesian position.
    inline Point2D operator+(const Vector2D &a, const Point2D &b) {
        return {a.x + b.x, a.y + b.y};
    }

    // Adding a 2D-Cartesian vector to another 2D-Cartesian vector results in a new 2D-Cartesian vector.
    inline Vector2D operator+(const Vector2D &a, const Vector2D &b) {
        return {a.x + b.x, a.y + b.y};
    }

    // Subtracting a 2D-Cartesian position from a 2D-Cartesian position results in a new 2D-Cartesian vector.
    inline Vector2D operator-(const Point2D &a, const Point2D &b) {
        return {a.x - b.x, a.y - b.y};
    }

    // Subtracting a 2D-Cartesian vector from a 2D-Cartesian position results in a new 2D-Cartesian position.
    inline Point2D operator-(const Point2D &a, const Vector2D &b) {
        return {a.x - b.x, a.y - b.y};
    }

    // Subtracting a 2D-Cartesian vector from a 2D-Cartesian position results in a new 2D-Cartesian position.
    inline Point2D operator-(const Vector2D &a, const Point2D &b) {
        return {a.x - b.x, a.y - b.y};
    }

    // Subtracting a 2D-Cartesian vector from another 2D-Cartesian vector results in a new 2D-Cartesian vector.
    inline Vector2D operator-(const Vector2D &a, const Vector2D &b) {
        return {a.x - b.x, a.y - b.y};
    }

    // Scaling a 2D-Cartesian vector results in a new 2D-Cartesian vector..
    inline Vector2D operator*(double a, const Vector2D &b) {
        return {a * b.x, a * b.y};
    }

    // Scaling a 2D-Cartesian vector results in a new 2D-Cartesian vector..
    inline Vector2D operator*(const Vector2D &a, double b) {
        return {a.x * b, a.y * b};
    }

    // Scaling a 2D-Cartesian vector by a scalar inverse results in a new 2D-Cartesian vector..
    inline Vector2D operator/(const Vector2D &a, double b) {
        return {a.x / b, a.y / b};
    }

    // The dot product between two 2D-Cartesian vectors.
    inline double dot(const Vector2D &a, const Vector2D &b) {
        return a.x * b.x + a.y * b.y;
    }

    // The distance between two 2D-Cartesian points.
    inline double distance(const Point2D &a, const Point2D &b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    // The magnitude of a 2D-Cartesian vector.
    inline double norm(const Vector2D &a) {
        return sqrt(a.x * a.x + a.y * a.y);
    }

    // The direction of a 2D-Cartesian vector.
    inline Vector2D direction(const Vector2D &a) {
        double l = norm(a);
        return {a.x / l, a.y / l};
    }

    // Display a 2D-Cartesian vector.
    inline std::ostream &operator<<(std::ostream &out, const Vector2D &v) {
        out << "<" << v.x << ", " << v.y << ">";
        return out;
    }

    // Display a 2D-Cartesian position.
    inline std::ostream &operator<<(std::ostream &out, const Point2D &v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 3D-Cartesian displacements/vectors and positions with associated operations.                                  //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // A 3D-Cartesian point location in two-dimensional space.
    struct Point3D {

        double x; // The x-component of the position.
        double y; // The y-component of the position.
        double z; // The z-component of the position.

    };

    // A 3D-Cartesian vector/displacement in two-dimensional space.
    struct Vector3D {

        double x; // The x-component of the vector/displacement.
        double y; // The y-component of the vector/displacement.
        double z; // The z-component of the vector/displacement.

    };

    // Adding a 3D-Cartesian vector to a 3D-Cartesian position results in a new 3D-Cartesian position.
    inline Point3D operator+(const Point3D &a, const Vector3D &b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    // Adding a 3D-Cartesian vector to a 3D-Cartesian position results in a new 3D-Cartesian position.
    inline Point3D operator+(const Vector3D &a, const Point3D &b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    // Adding a 3D-Cartesian vector to another 3D-Cartesian vector results in a new 3D-Cartesian vector.
    inline Vector3D operator+(const Vector3D &a, const Vector3D &b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    // Subtracting a 3D-Cartesian position from a 3D-Cartesian position results in a new 3D-Cartesian vector.
    inline Vector3D operator-(const Point3D &a, const Point3D &b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    // Subtracting a 3D-Cartesian vector from a 3D-Cartesian position results in a new 3D-Cartesian position.
    inline Point3D operator-(const Point3D &a, const Vector3D &b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    // Subtracting a 3D-Cartesian vector from a 3D-Cartesian position results in a new 3D-Cartesian position.
    inline Point3D operator-(const Vector3D &a, const Point3D &b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    // Subtracting a 3D-Cartesian vector from another 3D-Cartesian vector results in a new 3D-Cartesian vector.
    inline Vector3D operator-(const Vector3D &a, const Vector3D &b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    // Scaling a 3D-Cartesian vector results in a new 3D-Cartesian vector..
    inline Vector3D operator*(double a, const Vector3D &b) {
        return {a * b.x, a * b.y, a * b.z};
    }

    // Scaling a 3D-Cartesian vector results in a new 3D-Cartesian vector..
    inline Vector3D operator*(const Vector3D &a, double b) {
        return {a.x * b, a.y * b, a.z * b};
    }

    // Scaling a 3D-Cartesian vector by a scalar inverse results in a new 3D-Cartesian vector..
    inline Vector3D operator/(const Vector3D &a, double b) {
        return {a.x / b, a.y / b, a.z / b};
    }

    // The dot product between two 3D-Cartesian vectors.
    inline double dot(const Vector3D &a, const Vector3D &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    // The cross-product between two 3D-Cartesian vectors.
    inline Vector3D cross(const Vector3D &a, const Vector3D &b) {
        return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
    }

    // The distance between two 3D-Cartesian points.
    inline double distance(const Point3D &a, const Point3D &b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    }

    // The magnitude of a 3D-Cartesian vector.
    inline double norm(const Vector3D &a) {
        return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    }

    // The direction of a 3D-Cartesian vector.
    inline Vector3D direction(const Vector3D &a) {
        double l = norm(a);
        return {a.x / l, a.y / l, a.z / l};
    }

    // Display a 3D-Cartesian vector.
    inline std::ostream &operator<<(std::ostream &out, const Vector3D &v) {
        out << "<" << v.x << ", " << v.y << ", " << v.z << ">";
        return out;
    }

    // Display a 3D-Cartesian position.
    inline std::ostream &operator<<(std::ostream &out, const Point3D &v) {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }

} // namespace mimg