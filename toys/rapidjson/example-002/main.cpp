//
// Created by L. Nagy on 15/07/2023.
//

#include <fstream>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/ostreamwrapper.h>

using namespace rapidjson;
using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cout << "Must supply an example json file." << endl;
        exit(1);
    }

    cout << "Writing output file: '" << argv[1] << "'" << endl;

    // Generate document: {"text": "Hello JSON!"}
    Document doc;
    doc.SetObject(); // Make doc an object !
    doc.AddMember("text", "Hello JSON!", doc.GetAllocator());
    // Write to stdout

    fstream fout;
    fout.open(argv[1], ios::out);

    OStreamWrapper out(fout);
    Writer<OStreamWrapper> writer(out);
    doc.Accept(writer);
    fout.close();

}
