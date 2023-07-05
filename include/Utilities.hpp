//
// Created by L. Nagy on 30/06/2023.
//

#pragma once

template <typename T> long sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template <class T>
inline void hash_combine(size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}
