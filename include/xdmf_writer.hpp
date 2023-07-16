//
// Created by L. Nagy on 16/07/2023.
//

#pragma once

#include <string>
#include <vector>

#include <rapidxml_ext.hpp>

#include "tecplot_reader.hpp"

namespace mimg {

    class XDMFWriter {

    public:

        XDMFWriter() = default;

        void write(const std::string &hdf_file_name, const std::string &xdmf_file_name, const TecplotData &tecplot_data) {

            using namespace rapidxml;

            std::string nodes_per_element = "4";
            std::string precision = "8";
            std::string format = "HDF";
            std::string dtype_float = "Float";
            std::string dtype_uint = "UInt";

            std::stringstream ss_no_of_verts;
            std::stringstream ss_no_of_elems;

            std::stringstream ss_no_of_verts_x3;
            std::stringstream ss_no_of_elems_x1;
            std::stringstream ss_no_of_elems_x4;

            std::stringstream ss_mesh_elements;
            std::stringstream ss_mesh_vertices;
            std::stringstream ss_mesh_submesh;

            std::stringstream ss_magnetizations;

            ss_no_of_verts << tecplot_data.n_verts();
            ss_no_of_elems << tecplot_data.n_elems();
            ss_no_of_verts_x3 << tecplot_data.n_verts() << " 3";
            ss_no_of_elems_x1 << tecplot_data.n_elems() << " 1";
            ss_no_of_elems_x4 << tecplot_data.n_elems() << " 4";

            ss_mesh_elements << hdf_file_name << ":/mesh/elements";
            ss_mesh_vertices << hdf_file_name << ":/mesh/vertices";
            ss_mesh_submesh << hdf_file_name << ":/mesh/submesh";
            ss_magnetizations << hdf_file_name << ":/magnetizations";

            std::string dim_no_of_verts = ss_no_of_verts.str();
            std::string dim_no_of_elems = ss_no_of_elems.str();

            std::string dim_no_of_verts_x3 = ss_no_of_verts_x3.str();
            std::string dim_no_of_elems_x1 = ss_no_of_elems_x1.str();
            std::string dim_no_of_elems_x4 = ss_no_of_elems_x4.str();

            std::string mesh_elements = ss_mesh_elements.str();
            std::string mesh_vertices = ss_mesh_vertices.str();
            std::string mesh_submesh = ss_mesh_submesh.str();

            std::string magnetizations = ss_magnetizations.str();

            xml_document<> doc;

            // Create a declaration node.
            xml_node <> *decl = doc.allocate_node(rapidxml::node_declaration);
            decl->append_attribute(doc.allocate_attribute("version", "1.0"));
            doc.append_node(decl);

            // Create a doctype.
            xml_node <> *doctype = doc.allocate_node(rapidxml::node_doctype, nullptr, "Xdmf");
            doctype->append_attribute(doc.allocate_attribute("SYSTEM", "Xdmf.dtd"));
            doc.append_node(doctype);

            // Create the root Xdmf node.
            xml_node <> *xdmf = doc.allocate_node(rapidxml::node_element, "Xdmf");
            xdmf->append_attribute(doc.allocate_attribute("Version", "2.0"));
            xdmf->append_attribute(doc.allocate_attribute("xmlns:xi", "http://www.w3.org/2001/XInclude"));
            doc.append_node(xdmf);

            // Create the /Xdmf/Domain node.
            xml_node <> *domain = doc.allocate_node(rapidxml::node_element, "Domain");
            xdmf->append_node(domain);

            // Create the /Xdmf/Domain/Grid node (first grid).
            xml_node <> *mesh_grid = doc.allocate_node(rapidxml::node_element, "Grid");
            mesh_grid->append_attribute(doc.allocate_attribute("Name", "mesh"));
            mesh_grid->append_attribute(doc.allocate_attribute("GridType", "Uniform"));
            domain->append_node(mesh_grid);

            // Create the /Xdmf/Domain/Grid/Topology node.
            xml_node <> *topology = doc.allocate_node(rapidxml::node_element, "Topology");
            topology->append_attribute(doc.allocate_attribute("TopologyType", "Tetrahedron"));
            topology->append_attribute(doc.allocate_attribute("NumberOfElements", dim_no_of_elems.c_str()));
            topology->append_attribute(doc.allocate_attribute("NodesPerElement", nodes_per_element.c_str()));
            mesh_grid->append_node(topology);

            // Create the /Xdmf/Domain/Grid/Topology/DataItem node.
            xml_node <> *topology_dataitem = doc.allocate_node(rapidxml::node_element, "DataItem", mesh_elements.c_str());
            topology_dataitem->append_attribute(doc.allocate_attribute("Format", format.c_str()));
            topology_dataitem->append_attribute(doc.allocate_attribute("DataType", dtype_uint.c_str()));
            topology_dataitem->append_attribute(doc.allocate_attribute("Precision", precision.c_str()));
            topology_dataitem->append_attribute(doc.allocate_attribute("Dimensions", dim_no_of_elems_x4.c_str()));
            topology->append_node(topology_dataitem);

            // Create the /Xdmf/Domain/Grid/Geometry.
            xml_node <> *geometry = doc.allocate_node(rapidxml::node_element, "Geometry");
            geometry->append_attribute(doc.allocate_attribute("GeometryType", "XYZ"));
            mesh_grid->append_node(geometry);

            // Create the /Xdmf/Domain/Grid/Geometry/DataItem node.
            xml_node <> *geometry_dataitem = doc.allocate_node(rapidxml::node_element, "DataItem", mesh_vertices.c_str());
            geometry_dataitem->append_attribute(doc.allocate_attribute("Format", format.c_str()));
            geometry_dataitem->append_attribute(doc.allocate_attribute("DataType", dtype_float.c_str()));
            geometry_dataitem->append_attribute(doc.allocate_attribute("Precision", precision.c_str()));
            geometry_dataitem->append_attribute(doc.allocate_attribute("Dimensions", dim_no_of_verts_x3.c_str()));
            geometry->append_node(geometry_dataitem);

            // Create the /Xdmf/Domain/Grid/Attribute node.
            xml_node <> *mesh_attribute = doc.allocate_node(rapidxml::node_element, "Attribute");
            mesh_attribute->append_attribute(doc.allocate_attribute("Name", "submesh"));
            mesh_attribute->append_attribute(doc.allocate_attribute("Center", "Cell"));
            mesh_grid->append_node(mesh_attribute);

            // Create the /Xdmf/Domain/Grid/Attribute/DataItem node.
            xml_node <> *attribute_dataitem = doc.allocate_node(rapidxml::node_element, "DataItem", mesh_submesh.c_str());
            attribute_dataitem->append_attribute(doc.allocate_attribute("Format", format.c_str()));
            attribute_dataitem->append_attribute(doc.allocate_attribute("DataType", dtype_uint.c_str()));
            attribute_dataitem->append_attribute(doc.allocate_attribute("Precision", precision.c_str()));
            attribute_dataitem->append_attribute(doc.allocate_attribute("Dimensions", dim_no_of_elems_x1.c_str()));
            mesh_attribute->append_node(attribute_dataitem);

            // Create the /Xdmf/Domain/Grid node (second Grid).
            xml_node <> *m_grid = doc.allocate_node(rapidxml::node_element, "Grid");
            m_grid->append_attribute(doc.allocate_attribute("GridType", "Collection"));
            m_grid->append_attribute(doc.allocate_attribute("CollectionType", "Temporal"));
            domain->append_node(m_grid);

            std::vector<std::string> magnetization_with_idx;
            std::vector<std::string> time_value;

            for (size_t midx = 0; midx < tecplot_data.n_zones(); ++midx) {

                std::stringstream ss_magnetization_with_idx;
                ss_magnetization_with_idx << magnetizations << "/" << midx;
                magnetization_with_idx.push_back(ss_magnetization_with_idx.str());

                std::stringstream ss_time_value;
                ss_time_value << midx;
                time_value.push_back(ss_time_value.str());

            }

            for (size_t midx = 0; midx < tecplot_data.n_zones(); ++midx) {

                // Create the /Xdmf/Domain/Grid/Grid node.
                xml_node <> *mm_grid = doc.allocate_node(rapidxml::node_element, "Grid");
                mm_grid->append_attribute(doc.allocate_attribute("Name", "m"));
                mm_grid->append_attribute(doc.allocate_attribute("GridType", "Uniform"));
                m_grid->append_node(mm_grid);

                // Create the /Xdmf/Domain/Grid/Grid/xi:include node.
                xml_node <> *xi_include = doc.allocate_node(rapidxml::node_element, "xi:include");
                xi_include->append_attribute(doc.allocate_attribute("xpointer", "xpointer(/Xdmf/Domain/Grid[@GridType='Uniform'][1]/*[self::Topology or self::Geometry])"));
                mm_grid->append_node(xi_include);

                // Create the /Xdmf/Domain/Grid/Grid/Time node.
                xml_node <> *time = doc.allocate_node(rapidxml::node_element, "Time");
                time->append_attribute(doc.allocate_attribute("Value", time_value[midx].c_str()));
                mm_grid->append_node(time);

                // Create the /Xdmf/Domain/Grid/Grid/Attribute node.
                xml_node <> *mm_grid_attribute = doc.allocate_node(rapidxml::node_element, "Attribute");
                mm_grid_attribute->append_attribute(doc.allocate_attribute("Name", "m"));
                mm_grid_attribute->append_attribute(doc.allocate_attribute("AttributeType", "Vector"));
                mm_grid_attribute->append_attribute(doc.allocate_attribute("Center", "Node"));
                mm_grid->append_node(mm_grid_attribute);

                // Create the /Xdmf/Domain/Grid/Grid/Attribute/DataItem node.
                xml_node <> *mm_grid_attribute_dataitem = doc.allocate_node(rapidxml::node_element, "DataItem", magnetization_with_idx[midx].c_str());
                mm_grid_attribute_dataitem->append_attribute(doc.allocate_attribute("Format", format.c_str()));
                mm_grid_attribute_dataitem->append_attribute(doc.allocate_attribute("DataType", dtype_float.c_str()));
                mm_grid_attribute_dataitem->append_attribute(doc.allocate_attribute("Precision", precision.c_str()));
                mm_grid_attribute_dataitem->append_attribute(doc.allocate_attribute("Dimensions", dim_no_of_verts_x3.c_str()));
                mm_grid_attribute->append_node(mm_grid_attribute_dataitem);

            }

            // Print the XML document to a string
            std::string xmlString;
            rapidxml::print(std::back_inserter(xmlString), doc, rapidxml::print_no_indenting);

            // Save the XML document to a file
            std::ofstream file(xdmf_file_name);
            file << doc;
            file.close();

            // Clean up the memory
            doc.clear();

        }

    };

} // namespace mimg
