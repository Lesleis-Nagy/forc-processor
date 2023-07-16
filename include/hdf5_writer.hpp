//
// Created by L. Nagy on 28/06/2023.
//

#pragma once

#include <string>
#include <vector>

#include <H5Cpp.h>

#include "tecplot_reader.hpp"

namespace mimg {

    class HDF5Writer {

    public:

        void write(const std::string &file_name, const TecplotData &tecplot_data) {

            using namespace H5;

            try {

                Exception::dontPrint();

                H5File file(file_name, H5F_ACC_TRUNC);

                // Create a group for the mesh.
                Group grp_mesh(file.createGroup("/mesh"));

                // Create a group for the magnetizations.
                Group grp_magnetizations(file.createGroup("/magnetizations"));

                // Create a vertices dataset in the mesh group.
                std::cout << "Creating /mesh/vertices dataset.\n";
                hsize_t dim_vertices[2];
                dim_vertices[0] = tecplot_data.n_verts();
                dim_vertices[1] = 3;

                DataSpace dsp_vertices(2, dim_vertices);
                DataSet ds_vertices(file.createDataSet("/mesh/vertices", PredType::NATIVE_DOUBLE, dsp_vertices));

                std::vector<double> vertices(3 * tecplot_data.n_verts());
                for (size_t i = 0; i < tecplot_data.n_verts(); ++i) {
                    vertices[3 * i + 0] = tecplot_data.x()[i];
                    vertices[3 * i + 1] = tecplot_data.y()[i];
                    vertices[3 * i + 2] = tecplot_data.z()[i];
                }

                ds_vertices.write(vertices.data(), PredType::NATIVE_DOUBLE);

                // Create an elements dataset in the mesh group.
                std::cout << "Creating /mesh/elements dataset.\n";
                hsize_t dim_elements[2];
                dim_elements[0] = tecplot_data.n_elems();
                dim_elements[1] = 4;

                DataSpace dsp_elements(2, dim_elements);
                DataSet ds_elements(file.createDataSet("/mesh/elements", PredType::NATIVE_UINT64, dsp_elements));
                ds_elements.write(tecplot_data.tetra_idxs().data(), PredType::NATIVE_UINT64);

                // Create a submesh id dataset in the mesh group.
                std::cout << "Creating /mesh/submesh dataset.\n";
                hsize_t dim_submesh_idxs[2];
                dim_submesh_idxs[0] = tecplot_data.n_elems();
                dim_submesh_idxs[1] = 1;

                DataSpace dsp_submesh_idxs(2, dim_submesh_idxs);
                DataSet ds_submesh_idxs(file.createDataSet("/mesh/submesh", PredType::NATIVE_UINT64, dsp_submesh_idxs));
                ds_submesh_idxs.write(tecplot_data.tetra_submesh_idxs().data(), PredType::NATIVE_UINT64);

                // Create a dataset for each magnetization.
                std::cout << "Creating /magnetizations";
                hsize_t dim_magnetizations[2];
                dim_magnetizations[0] = tecplot_data.n_verts();
                dim_magnetizations[1] = 3;

                for (size_t mag_id = 0; mag_id < tecplot_data.n_zones(); ++mag_id) {
                    std::stringstream ss;
                    ss << "/magnetizations/" << mag_id;

                    DataSpace dsp_magnetization(2, dim_magnetizations);
                    DataSet ds_magnetization(file.createDataSet(ss.str(), PredType::NATIVE_DOUBLE, dsp_magnetization));

                    std::vector<double> m(3 * tecplot_data.n_verts());
                    for (size_t i = 0; i < tecplot_data.n_verts(); ++i) {
                        m[3 * i + 0] = tecplot_data.mx()[mag_id][i];
                        m[3 * i + 1] = tecplot_data.my()[mag_id][i];
                        m[3 * i + 2] = tecplot_data.mz()[mag_id][i];
                    }

                    std::cout << "Writing: '" << ss.str() << "', " << tecplot_data.mx()[mag_id].size() << "\n";
                    ds_magnetization.write(m.data(), PredType::NATIVE_DOUBLE);
                }

                std::cout << "Closing ...\n";
                file.close();

            }

            // catch failure caused by the H5File operations
            catch (FileIException &error) {
                H5::FileIException::printErrorStack();
                return;
            }

            // catch failure caused by the DataSet operations
            catch (DataSetIException &error) {
                H5::DataSetIException::printErrorStack();
                return;
            }

            // catch failure caused by the DataSpace operations
            catch (DataSpaceIException &error) {
                H5::DataSpaceIException::printErrorStack();
                return;
            }

            // catch failure caused by the Attribute operations
            catch (AttributeIException &error) {
                H5::AttributeIException::printErrorStack();
                return;
            }

        }

    };

} // namespace mimg
