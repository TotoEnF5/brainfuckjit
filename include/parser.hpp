#pragma once
#include <string>

class Parser {
public:
    Parser(int argc, char* argv[]);

    const std::string& getInputFile();
    const std::string& getInput();

private:
    std::string inputFile;
    std::string input;
};
