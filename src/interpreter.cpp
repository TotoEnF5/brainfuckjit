#include <interpreter.hpp>
#include <iostream>
#include <cstring>

Interpreter::Interpreter(const std::string& code, const std::string& input) {
    this->code = code;
    this->input = input;
    this->cells.fill(0);
}

void Interpreter::run() {
    while (this->programCounter < this->code.length()) {
        bool incrementProgramCounter = true;
        char c = this->code.at(this->programCounter);

        switch (c) {
        case '+': // increment value
            this->cells.at(this->cellCounter)++;
            break;
        case '-': // decrement value
            this->cells.at(this->cellCounter)--;
            break;
        case '>': // increment cc
            this->cellCounter++;
            break;
        case '<': // decrement cc
            this->cellCounter--;
            break;
        case '.': // output to stdout
            std::cout << (char)this->cells.at(this->cellCounter);
            break;
        case ',': // take input
            if (this->input.empty()) {
                this->cells.at(this->cellCounter) = EOF;
            }
            else {
                this->cells.at(this->cellCounter) = this->input.at(0);
                this->input.erase(0);
            }
            break;
        case '[': // loop begin
            // if zero, break loop and go to the command after the matching ']'
            // else do nothing and proceed to the next command
            if (this->cells.at(this->cellCounter) == 0) {
                this->programCounter = this->findMatchingLoopEnd() + 1;
                incrementProgramCounter = false;
            }
            break;
        case ']': // loop end
            // if nonzero, go to the command after thematching '['
            // else do nothing and proceed to the next command
            if (this->cells.at(this->cellCounter) != 0) {
                this->programCounter = this->findMatchingLoopBegin() + 1;
                incrementProgramCounter = false;
            }
            break;
        }

        if (incrementProgramCounter) {
            this->programCounter++;
        }
    }
}

uint32_t Interpreter::findMatchingLoopEnd() {
    uint32_t pos = this->programCounter + 1;
    uint32_t loopsFound = 0;
    do {
        if (this->code.at(pos) == '[') {
            loopsFound++;
        }

        if (this->code.at(pos) == ']') {
            if (loopsFound == 0) {
                return pos;
            }
            else {
                loopsFound--;
            }
        }
    } while ((++pos) < this->code.length());

    // if we get here, it means the matching ']' was not found
    // this is a syntax error
    std::cerr << "syntax error: no matching ] at pos "  << this->programCounter << std::endl;
    exit(1);
}

uint32_t Interpreter::findMatchingLoopBegin() {
    uint32_t pos = this->programCounter - 1;
    uint32_t loopsFound = 0;
    do {
        if (this->code.at(pos) == ']') {
            loopsFound++;
        }

        if (this->code.at(pos) == '[') {
            if (loopsFound == 0) {
                return pos;
            }
            else {
                loopsFound--;
            }
        }
    } while ((--pos) < this->code.length());

    // if we get here, it means the matching '[' was not found
    // this is a syntax error
    std::cerr << "syntax error: no matching [ at pos "  << this->programCounter << std::endl;
    exit(1);
}
