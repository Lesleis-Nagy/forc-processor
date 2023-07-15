//
// Created by L. Nagy on 27/06/2023.
//

#pragma once

#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <optional>
#include <regex>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "utilities.hpp"
#include "fraction.hpp"

namespace mimg {

    class FORCCurves {

    public:

        FORCCurves() = default;

        [[nodiscard]] size_t n_verts() const {
            return _n_verts.value();
        }

        [[nodiscard]] size_t n_elems() const {
            return _n_elems.value();
        }

        [[nodiscard]] const std::vector<double> &x() const { return _x; }

        [[nodiscard]] const std::vector<double> &y() const { return _y; }

        [[nodiscard]] const std::vector<double> &z() const { return _z; }

        [[nodiscard]] const std::vector<size_t> &tetra_submesh_idxs() const { return _tetra_submesh_idxs; }

        [[nodiscard]] const std::vector<size_t> &tetra_idxs() const { return _tetra_idxs; }

    private:

        std::optional<size_t> _n_verts;
        std::optional<size_t> _n_elems;

        std::optional<size_t> _current_field_idx;

        std::vector<double> _x;
        std::vector<double> _y;
        std::vector<double> _z;

        std::vector<size_t> _tetra_submesh_idxs;
        std::vector<size_t> _tetra_idxs;

        std::vector<std::vector<double>> _mx;
        std::vector<std::vector<double>> _my;
        std::vector<std::vector<double>> _mz;

        std::unordered_map<FractionPair, size_t> _brbb_to_fidx;
        std::unordered_map<size_t, FractionPair> _fidx_to_brbb;

        std::optional<std::string> _brbb_unit;

        friend class TecplotFORCReader;

        [[nodiscard]] bool x_is_full() const {
            return _x.size() >= _n_verts.value();
        }

        [[nodiscard]] bool y_is_full() const {
            return _y.size() >= _n_verts.value();
        }

        [[nodiscard]] bool z_is_full() const {
            return _z.size() >= _n_verts.value();
        }

        [[nodiscard]] bool current_mx_is_full() const {
            return _mx[_current_field_idx.value()].size() >= _n_verts.value();
        };

        [[nodiscard]] bool current_my_is_full() const {
            return _my[_current_field_idx.value()].size() >= _n_verts.value();
        }

        [[nodiscard]] bool current_mz_is_full() const {
            return _mz[_current_field_idx.value()].size() >= _n_verts.value();
        }

        [[nodiscard]] bool tetra_submesh_idx_is_full() const {
            return _tetra_submesh_idxs.size() >= _n_elems.value();
        }

        [[nodiscard]] bool tetra_idx_is_full() const {
            return _tetra_idxs.size() >= _n_elems.value() * 4;
        }

    };

    class TecplotFORCReader {

    public:

        TecplotFORCReader() :
                _regex_zone(R"r(^\s*ZONE\s*T\s*=\s*"([A-Za-z0-9=\-.,;\s]+)"\s*,\s*N\s*=\s*([0-9]+)\s*,\s*E\s*=\s*([0-9]+)\s*$)r"),
                _regex_zone_title(R"r(Br\s*=\s*((-?[0-9]+.[0-9]+)\s*(mT))\s*;\s*Bb\s*=\s*((-?[0-9]+.[0-9]+)\s*(mT)))r"),
                _regex_int_line(R"r(^\s*([0-9]+)(\s+[0-9]+)*\s*$)r"),
                _regex_float_line(R"r(^\s*([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?)(\s+([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?))*\s*$)r") {}

        FORCCurves read_file(const std::string &file_name) {

            FORCCurves forc_curves;

            std::string line;
            std::fstream fin(file_name);

            size_t zone_counter = 0;

            std::smatch match_zone;
            std::smatch match_zone_title;
            std::smatch match_int_line;
            std::smatch match_float_line;

            auto start = std::chrono::high_resolution_clock::now();

            while (std::getline(fin, line)) {

                ///////////////////////////////////////////////////////////////////////////////////////////////////////
                // Handle matching a 'ZONE' line.                                                                    //
                ///////////////////////////////////////////////////////////////////////////////////////////////////////

                if (std::regex_match(line, match_zone, _regex_zone)) {

                    std::string str_n_verts = match_zone[2].str();
                    std::string str_n_elems = match_zone[3].str();

                    std::cout << "Processing zone: " << ++zone_counter << " ";

                    if (zone_counter == 1) {

                        // this is the first zone.

                        forc_curves._n_verts = std::stoi(str_n_verts);
                        forc_curves._n_elems = std::stoi(str_n_elems);

                        forc_curves._tetra_idxs.reserve(forc_curves._n_elems.value());
                        forc_curves._tetra_submesh_idxs.reserve(4 * forc_curves._n_elems.value());

                        forc_curves._x.reserve(forc_curves._n_verts.value());
                        forc_curves._y.reserve(forc_curves._n_verts.value());
                        forc_curves._z.reserve(forc_curves._n_verts.value());

                        forc_curves._current_field_idx = 0;
                        forc_curves._mx.emplace_back();
                        forc_curves._my.emplace_back();
                        forc_curves._mz.emplace_back();

                        forc_curves._mx[forc_curves._current_field_idx.value()].reserve(forc_curves._n_verts.value());
                        forc_curves._my[forc_curves._current_field_idx.value()].reserve(forc_curves._n_verts.value());
                        forc_curves._mz[forc_curves._current_field_idx.value()].reserve(forc_curves._n_verts.value());

                    } else {

                        // This is not the first zone.

                        if ((!forc_curves._n_verts.has_value()) && (!forc_curves._n_elems.has_value())) {
                            throw std::runtime_error(
                                    "Parsing subsequent zone, but no. of vertices/elements is not set.");
                        } else {
                            if (forc_curves._n_verts.value() != std::stoi(str_n_verts)) {
                                throw std::runtime_error("Unexpected number of vertices in zone.");
                            }
                            if (forc_curves._n_elems.value() != std::stoi(str_n_elems)) {
                                throw std::runtime_error("Unexpected number of elements in zone.");
                            }
                        }

                        forc_curves._current_field_idx.value()++;
                        forc_curves._mx.emplace_back();
                        forc_curves._my.emplace_back();
                        forc_curves._mz.emplace_back();

                        forc_curves._mx[forc_curves._current_field_idx.value()].reserve(forc_curves._n_verts.value());
                        forc_curves._my[forc_curves._current_field_idx.value()].reserve(forc_curves._n_verts.value());
                        forc_curves._mz[forc_curves._current_field_idx.value()].reserve(forc_curves._n_verts.value());

                    }

                    // Process the ZONE title that contains Br & Bb field values.

                    std::string str_zone_title = match_zone[1].str();
                    if (std::regex_match(str_zone_title, match_zone_title, _regex_zone_title)) {

                        Fraction br(match_zone_title[2].str());
                        std::string br_unit = match_zone_title[3].str();
                        Fraction bb(match_zone_title[5].str());
                        std::string bb_unit = match_zone_title[6].str();

                        if (zone_counter == 1) {

                            // This is the first zone.

                            if (br_unit != bb_unit) {
                                throw std::runtime_error("Field units do not match.");
                            }

                            forc_curves._brbb_unit = br_unit;

                        } else {

                            // This is not the first zone.

                            if (!forc_curves._brbb_unit.has_value()) {
                                throw std::runtime_error("Expected field unit to be set after 1st zone, but was not.");
                            } else {
                                if (forc_curves._brbb_unit.value() != br_unit) {
                                    throw std::runtime_error("Br field has incorrect unit.");
                                }
                                if (forc_curves._brbb_unit.value() != bb_unit) {
                                    throw std::runtime_error("Bb field has incorrect unit.");
                                }
                            }

                        }

                        std::cout << "Br:" << br << br_unit << "; Bb:" << bb << bb_unit << " (" << line << ")" << "\n";

                        forc_curves._brbb_to_fidx[{br, bb}] = forc_curves._current_field_idx.value();
                        forc_curves._fidx_to_brbb[forc_curves._current_field_idx.value()] = {br, bb};

                    }

                    continue;

                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////
                // Handle matching a line of integer values.                                                        //
                //////////////////////////////////////////////////////////////////////////////////////////////////////

                if (std::regex_match(line, match_int_line, _regex_int_line)) {

                    // std::cout << line << "\n";

                    std::vector<std::string> str_values = regex_split(line);

                    if (zone_counter == 1) {

                        // This is the first zone.

                        for (const auto &str_value: str_values) {
                            if (!str_value.empty()) {
                                if (!forc_curves.tetra_submesh_idx_is_full()) {
                                    forc_curves._tetra_submesh_idxs.push_back(std::stoull(str_value));
                                } else if (!forc_curves.tetra_idx_is_full()) {
                                    forc_curves._tetra_idxs.push_back(std::stoull(str_value) - 1);
                                } else {
                                    throw std::runtime_error("Too many integers for zone.");
                                }
                            }
                        }

                    } else {

                        // This is not the first zone.
                        throw std::runtime_error("Integers should only be found in the first zone.");

                    }

                    continue;

                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////
                // Handle matching a line of floating point values.                                                 //
                //////////////////////////////////////////////////////////////////////////////////////////////////////

                if (std::regex_match(line, match_float_line, _regex_float_line)) {

                    //std::cout << line << "\n";

                    std::vector<std::string> str_values = regex_split(line);

                    if (zone_counter == 1) {

                        // This is the first zone.

                        for (const auto &str_value: str_values) {
                            if (!str_value.empty()) {
                                if (!forc_curves.x_is_full()) {
                                    forc_curves._x.push_back(std::stod(str_value));
                                } else if (!forc_curves.y_is_full()) {
                                    forc_curves._y.push_back(std::stod(str_value));
                                } else if (!forc_curves.z_is_full()) {
                                    forc_curves._z.push_back(std::stod(str_value));
                                } else if (!forc_curves.current_mx_is_full()) {
                                    forc_curves._mx[forc_curves._current_field_idx.value()].push_back(
                                            std::stod(str_value));
                                } else if (!forc_curves.current_my_is_full()) {
                                    forc_curves._my[forc_curves._current_field_idx.value()].push_back(
                                            std::stod(str_value));
                                } else if (!forc_curves.current_mz_is_full()) {
                                    forc_curves._mz[forc_curves._current_field_idx.value()].push_back(
                                            std::stod(str_value));
                                } else {
                                    throw std::runtime_error("Too many doubles for zone.");
                                }
                            }
                        }

                    } else {

                        // This is not the first zone.

                        for (const auto &str_value: str_values) {
                            if (!str_value.empty()) {
                                if (!forc_curves.current_mx_is_full()) {
                                    forc_curves._mx[forc_curves._current_field_idx.value()].push_back(
                                            std::stod(str_value));
                                } else if (!forc_curves.current_my_is_full()) {
                                    forc_curves._my[forc_curves._current_field_idx.value()].push_back(
                                            std::stod(str_value));
                                } else if (!forc_curves.current_mz_is_full()) {
                                    forc_curves._mz[forc_curves._current_field_idx.value()].push_back(
                                            std::stod(str_value));
                                } else {
                                    throw std::runtime_error("Too many doubles for zone.");
                                }
                            }
                        }

                    }

                    continue;

                }

            }

            auto stop = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::minutes>(stop - start);

            return forc_curves;

        }

    private:

        std::regex _regex_zone;
        std::regex _regex_zone_title;
        std::regex _regex_int_line;
        std::regex _regex_float_line;

    };

} // namespace mimg