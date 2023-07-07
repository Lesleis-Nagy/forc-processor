//
// Created by L. Nagy on 28/06/2023.
//

#pragma once

#include <string>
#include <vector>

#include <H5Cpp.h>

#include "tecplot_forc_reader.hpp"

class HDF5FORCWriter {

public:

    void write(const std::string &file_name, const FORCCurves &forc_curves) {

        using namespace H5;

        try {
            Exception::dontPrint();

            H5File file(file_name, H5F_ACC_TRUNC);

            // Create a group for the mesh.
            Group grp_mesh(file.createGroup("/mesh"));

            // Create a vertices dataset in the mesh group.
            hsize_t dim_vertices[2];
            dim_vertices[0] = forc_curves.n_verts();
            dim_vertices[1] = 3;

            DataSpace dsp_vertices(2, dim_vertices);
            DataSet ds_vertices(file.createDataSet("/mesh/vertices", PredType::NATIVE_DOUBLE, dsp_vertices));

            std::vector<double> vertices(forc_curves.n_verts()*3);
            for (size_t i = 0; i < forc_curves.n_verts(); ++i) {
                vertices[3*i + 0] = forc_curves.x()[i];
                vertices[3*i + 1] = forc_curves.y()[i];
                vertices[3*i + 2] = forc_curves.z()[i];
            }

            ds_vertices.write(vertices.data(), PredType::NATIVE_DOUBLE);

            // Create an elements dataset in the mesh group.
            hsize_t dim_elements[2];
            dim_elements[0] = forc_curves.n_elems();
            dim_elements[1] = 4;

            DataSpace dsp_elements(2, dim_elements);
            DataSet ds_elements(file.createDataSet("/mesh/elements", PredType::NATIVE_UINT64, dsp_elements));
            ds_elements.write(forc_curves.tetra_idxs().data(), PredType::NATIVE_UINT64);

        }

        // catch failure caused by the H5File operations
        catch(FileIException &error) {
            H5::FileIException::printErrorStack();
            return;
        }
        // catch failure caused by the DataSet operations
        catch(DataSetIException &error) {
            H5::DataSetIException::printErrorStack();
            return;
        }
        // catch failure caused by the DataSpace operations
        catch(DataSpaceIException &error) {
            H5::DataSpaceIException::printErrorStack();
            return;
        }
        // catch failure caused by the Attribute operations
        catch(AttributeIException &error) {
            H5::AttributeIException::printErrorStack();
            return;
        }

    }

};
