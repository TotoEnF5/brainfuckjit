#include <parser.hpp>
#include <interpreter.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    Parser parser(argc, argv);

    // read the input file in a buffer
    std::ifstream file(parser.getInputFile());
    if (!file.good()) {
        std::cerr << "failed to open file " << parser.getInputFile() << std::endl;
        return 1;
    }
    std::ostringstream sstr;
    sstr << file.rdbuf();
    file.close();
    std::string code = sstr.str();

    // run the code!
    Interpreter interpreter(code, parser.getInput());
    interpreter.run();

    return 0;
}
