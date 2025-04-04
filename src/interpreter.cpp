#include <interpreter.hpp>

Interpreter::Interpreter(const std::string& code) {
    this->code = code;
    this->cells.fill(0);
}

void Interpreter::run() {

}
