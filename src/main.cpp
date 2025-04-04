#include <interpreter.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "no input file provided" << std::endl;
        return 1;
    }

    // read the input file in a buffer
    char* filename = argv[1];
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << "failed to open file " << filename << std::endl;
        return 1;
    }
    std::ostringstream sstr;
    sstr << file.rdbuf();
    file.close();
    std::string code = sstr.str();

    // run the code!
    Interpreter interpreter(code);
    interpreter.run();

    return 0;
}
