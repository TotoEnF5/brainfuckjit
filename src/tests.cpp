#include <interpreter.hpp>
#include <tests/io.hpp>
#include <tests/arraySize.hpp>
#include <tests/bounds.hpp>
#include <tests/obscure.hpp>
#include <iostream>

int main() {
    std::cout << "IO_TEST (set input)" << std::endl;
    Interpreter interpreter(IO_TEST, "\n");
    interpreter.run();

    std::cout << "ARRAY_SIZE_TEST" << std::endl;
    interpreter = Interpreter(ARRAY_SIZE_TEST);
    interpreter.run();

    // std::cout << "BOUNDS_TEST" << std::endl;
    // interpreter = Interpreter(BOUNDS_TEST);
    // interpreter.run();

    std::cout << "OBSCURE_TEST" << std::endl;
    interpreter = Interpreter(OBSCURE_TEST);
    interpreter.run();

    return 0;
}
