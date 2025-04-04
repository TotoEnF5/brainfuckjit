#include <interpreter.hpp>
#include <argparse.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
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
        return 1;
    }

    // read the input file in a buffer
    std::string filename = program.get<std::string>("input file");
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << "failed to open file " << filename << std::endl;
        return 1;
    }
    std::ostringstream sstr;
    sstr << file.rdbuf();
    file.close();
    std::string code = sstr.str();

    // read the input to pass to the program
    std::string input = program.get<std::string>("--input");

    // run the code!
    Interpreter interpreter(code, input);
    interpreter.run();

    return 0;
}
