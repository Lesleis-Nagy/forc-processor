//
// Created by L. Nagy on 30/06/2023.
//

#pragma once

#include <fstream>
#include <functional>
#include <sstream>
#include <string>

namespace mimg {

    template<typename T>
    long sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

    template<class T>
    inline void hash_combine(size_t &seed, const T &v) {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    std::vector<std::string> regex_split(const std::string &s, const std::regex &sep_regex = std::regex{"\\s+"}) {

        std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
        std::sregex_token_iterator end;

        return {iter, end};
    }

} //  namespace mimg