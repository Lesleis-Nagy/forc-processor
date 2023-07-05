//
// Created by L. Nagy on 04/07/2023.
//

#pragma once

#include <cmath>

struct Point3D {

    double x;
    double y;
    double z;

};

Point3D operator+(const Point3D &a, const Point3D &b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Point3D operator-(const Point3D &a, const Point3D &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Point3D operator*(double a, const Point3D &b) {
    return {a * b.x, a * b.y, a * b.z};
}

Point3D operator*(const Point3D &a, double b) {
    return {a.x * b, a.y * b, a.z * b};
}

Point3D operator/(const Point3D &a, double b) {
    return {a.x / b, a.y / b, a.z / b};
}

double dot(const Point3D &a, const Point3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double distance(const Point3D &a, const Point3D &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}