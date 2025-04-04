#pragma once
#include <string>
#include <array>
#include <cstdint>

class Interpreter {
public:
    Interpreter(const std::string& code, const std::string& input = "");
    void run();

private:
    uint32_t findMatchingLoopEnd();
    uint32_t findMatchingLoopBegin();

private:
    uint32_t programCounter = 0;
    uint16_t cellCounter = 0;
    std::array<uint8_t, 65536> cells;
    std::string code;
    std::string input;
};
