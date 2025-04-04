#include <interpreter.hpp>
#include <iostream>

Interpreter::Interpreter(const std::string& code) {
    this->code = code;
    this->cells.fill(0);
}

void Interpreter::run() {
    while (this->programCounter < this->code.length()) {
        bool incrementProgramCounter = true;
        char c = this->code.at(this->programCounter);

        switch (c) {
        case '+': // increment value
            break;
        case '-': // decrement value
            break;
        case '<': // increment cc
            break;
        case '>': // decrement cc
            break;
        case '.': // output to stdout
            break;
        case ',': // take input from stdin
            break;
        case '[': // loop begin
            break;
        case ']': // loop end
            incrementProgramCounter = false;
            break;
        }

        if (incrementProgramCounter) {
            this->programCounter++;
        }
    }
}
