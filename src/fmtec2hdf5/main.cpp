//
// Created by L. Nagy on 28/06/2023.
//

#include <string>

#include <args.hxx>

#include "tecplot_reader.hpp"
#include "hdf5_writer.hpp"
#include "xdmf_writer.hpp"

using namespace mimg;

int main(int argc, char *argv[]) {

    args::ArgumentParser parser("A small utility to convert MERRILL Tecplot files to HDF5.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Positional<std::string> input_file(parser, "input", "the input MERRILL file.");
    args::Positional<std::string> output_hdf5(parser, "output_hdf5", "the output HDF5 file.");
    args::Positional<std::string> output_xdmf(parser, "output_xdmf", "the output XDMF file.");

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

    if (input_file && output_hdf5 && output_xdmf) {
        std::cout << "Input file: " << args::get(input_file) << std::endl;
        std::cout << "Output HDF5 file: " << args::get(output_hdf5) << std::endl;
        std::cout << "Output XDMF file: " << args::get(output_xdmf) << std::endl;
    } else {
        std::cerr << "Required input & output HDF5/XDMF files." << std::endl;
        std::cerr << parser;
        return 1;
    }

    TecplotReader reader;
    TecplotData curves = reader.read_file(args::get(input_file));

    HDF5Writer hdf5_writer;
    hdf5_writer.write(args::get(output_hdf5), curves);

    XDMFWriter xdmf_writer;
    xdmf_writer.write(args::get(output_hdf5), args::get(output_xdmf), curves);

}
