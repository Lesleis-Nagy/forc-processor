//
// Created by L. Nagy on 28/06/2023.
//

#include <string>

#include <args.hxx>

#include "tecplot_forc_reader.hpp"
#include "hdf5_forc_writer.hpp"

int main(int argc, char *argv[]) {

    args::ArgumentParser parser("A small utility to convert MERRILL Tecplot files to HDF5.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Positional<std::string> input_file(parser, "input", "the input MERRILL file.");
    args::Positional<std::string> output_file(parser, "output", "the output MERRILL file.");
    try {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help) {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e) {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e) {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    if (input_file && output_file) {
        std::cout << "Input file: " << args::get(input_file) << std::endl;
        std::cout << "Output file: " << args::get(output_file) << std::endl;
    } else {
        std::cerr << "Required input & output file." << std::endl;
        std::cerr << parser;
        return 1;
    }

    TecplotFORCReader reader;
    FORCCurves curves = reader.read_file(args::get(input_file));

    HDF5FORCWriter writer;
    writer.write(args::get(output_file), curves);

}
