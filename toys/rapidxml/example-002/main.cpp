//
// Created by L. Nagy on 15/07/2023.
//

#include <iostream>
#include <fstream>

#include "rapidxml_ext.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "Must supply an example xml file." << std::endl;
        std::exit(1);
    }

    std::cout << "Writing output file: '" << argv[1] << "'" << std::endl;

    // Create an XML document
    rapidxml::xml_document<> doc;

    // Create a declaration node
    rapidxml::xml_node<>* decl = doc.allocate_node(rapidxml::node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
    doc.append_node(decl);

    // Create a root node
    rapidxml::xml_node<>* root = doc.allocate_node(rapidxml::node_element, "root");
    doc.append_node(root);

    // Create a child node under the root
    rapidxml::xml_node<>* child = doc.allocate_node(rapidxml::node_element, "child", "Hello, XML!");
    root->append_node(child);

    // Create an attribute for the child node
    child->append_attribute(doc.allocate_attribute("attribute", "value"));

    // Print the XML document to a string
    std::string xmlString;
    rapidxml::print(std::back_inserter(xmlString), doc, rapidxml::print_no_indenting);

    // Print the XML string
    std::cout << xmlString << std::endl;

    // Save the XML document to a file
    std::ofstream file(argv[1]);
    file << doc;
    file.close();

    // Clean up the memory
    doc.clear();

    return 0;

}