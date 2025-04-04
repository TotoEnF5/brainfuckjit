#include <parser.hpp>
#include <argparse.hpp>

Parser::Parser(int argc, char* argv[]) {
    argparse::ArgumentParser program("brainfuckjit");
    program.add_argument("input file")
        .help("the file to read the brainfuck program from");
    program.add_argument("-i", "--input")
        .default_value("")
        .help("the input to pass to the brainfuck program");

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << program;

        exit(EXIT_FAILURE);
    }

    this->inputFile = program.get<std::string>("input file");
    this->input = program.get<std::string>("--input");
}

const std::string& Parser::getInputFile() {
    return this->inputFile;
}

const std::string& Parser::getInput() {
    return this->input;
}
