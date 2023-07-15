//
// Created by L. Nagy on 15/07/2023.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "rapidxml_ext.hpp"

using namespace rapidxml;
using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cout << "Must supply an example xml file." << endl;
        std::exit(1);
    }

    cout << "Parsing my beer journal..." << endl;
    cout << "File: '" << argv[1] << "'" << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile (argv[1]);
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("MyBeerJournal");
    // Iterate over the brewerys
    for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
    {
        printf("I have visited %s in %s. ",
               brewery_node->first_attribute("name")->value(),
               brewery_node->first_attribute("location")->value());
        // Interate over the beers
        for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
        {
            printf("On %s, I tried their %s which is a %s. ",
                   beer_node->first_attribute("dateSampled")->value(),
                   beer_node->first_attribute("name")->value(),
                   beer_node->first_attribute("description")->value());
            printf("I gave it the following review: %s", beer_node->value());
        }
        cout << endl;
    }
}