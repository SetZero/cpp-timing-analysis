//
// Created by sebastian on 24.06.19.
//

#pragma once

#include <unordered_map>
#include <functional>

namespace avr {
    struct InstructionInfo {
        std::size_t wordLength;
        std::function<std::size_t()> calculator;
    };

    using iVec = const std::vector<std::vector<std::string>>&;

    const std::unordered_map<std::string, InstructionInfo> instructionMap = {
            {"ADC", { 1 , [](){return std::size_t{ 1 };} }},
            {"ADD", { 1 , [](){return std::size_t{ 1 };} }},
            {"ADIW", { 1 , [](){return std::size_t{ 2 };} }},
            {"AND", { 1 , [](){return std::size_t{ 1 };} }},
            {"ANDI", { 1 , [](){return std::size_t{ 1 };} }},
            {"ASR", { 1 , [](){return std::size_t{ 1 };} }},
            {"BCLR", { 1 , [](){return std::size_t{ 1 };} }},
            {"BLD", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRBC", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRBS", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRCC", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRCS", { 1 , [](){return std::size_t{ 1 };} }},
            {"BREAK", { 1 , [](){return std::size_t{ 1 };} }},
            {"BREQ", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRGE", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRHC", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRHS", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRID", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRIE", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRLO", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRMI", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRNE", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRPL", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRSH", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRTC", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRTS", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRVC", { 1 , [](){return std::size_t{ 1 };} }},
            {"BRVS", { 1 , [](){return std::size_t{ 1 };} }},
            {"BSET", { 1 , [](){return std::size_t{ 1 };} }},
            {"BST", { 1 , [](){return std::size_t{ 1 };} }},
            {"CBI", { 1 , [](){return std::size_t{ 2 };} }},
            {"CBR", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLC", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLH", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLI", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLN", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLR", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLT", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLV", { 1 , [](){return std::size_t{ 1 };} }},
            {"CLZ", { 1 , [](){return std::size_t{ 1 };} }},
            {"COM", { 1 , [](){return std::size_t{ 1 };} }},
            {"CP", { 1 , [](){return std::size_t{ 1 };} }},
            {"CPC", { 1 , [](){return std::size_t{ 1 };} }},
            {"CPI", { 1 , [](){return std::size_t{ 1 };} }},
            {"CPSE", { 1 , [](){return std::size_t{ 1 };} }},
            {"DEC", { 1 , [](){return std::size_t{ 1 };} }},
            {"EIJMP", { 1 , [](){return std::size_t{ 2 };} }},
            {"ELPM", { 1 , [](){return std::size_t{ 3 };} }},
            {"EOR", { 1 , [](){return std::size_t{ 1 };} }},
            {"FMUL", { 1 , [](){return std::size_t{ 2 };} }},
            {"FMULS", { 1 , [](){return std::size_t{ 2 };} }},
            {"FMULSU", { 1 , [](){return std::size_t{ 2 };} }},
            {"IJMP", { 1 , [](){return std::size_t{ 2 };} }},
            {"IN", { 1 , [](){return std::size_t{ 1 };} }},
            {"INC", { 1 , [](){return std::size_t{ 1 };} }},
            {"JMP", { 2 , [](){return std::size_t{ 3 };} }},
            {"LAT", { 1 , [](){return std::size_t{ 2 };} }},
            {"LAS", { 1 , [](){return std::size_t{ 2 };} }},
            {"LAC", { 1 , [](){return std::size_t{ 2 };} }},
            {"LDI", { 1 , [](){return std::size_t{ 1 };} }},
            {"LDS", { 1 , [](){return std::size_t{ 1 };} }},
            {"LPM", { 1 , [](){return std::size_t{ 3 };} }},
            {"LSL", { 1 , [](){return std::size_t{ 1 };} }},
            {"LSR", { 1 , [](){return std::size_t{ 1 };} }},
            {"MOV", { 1 , [](){return std::size_t{ 1 };} }},
            {"MOVW", { 1 , [](){return std::size_t{ 1 };} }},
            {"MUL", { 1 , [](){return std::size_t{ 2 };} }},
            {"MULS", { 1 , [](){return std::size_t{ 2 };} }},
            {"MULSU", { 1 , [](){return std::size_t{ 2 };} }},
            {"NEG", { 1 , [](){return std::size_t{ 1 };} }},
            {"NOP", { 1 , [](){return std::size_t{ 1 };} }},
            {"OR", { 1 , [](){return std::size_t{ 1 };} }},
            {"ORI", { 1 , [](){return std::size_t{ 1 };} }},
            {"OUT", { 1 , [](){return std::size_t{ 1 };} }},
            {"POP", { 1 , [](){return std::size_t{ 2 };} }},
            {"RET", { 1 , [](){return std::size_t{ 4 };} }},
            {"RETI", { 1 , [](){return std::size_t{ 4 };} }},
            {"RJMP", { 1 , [](){return std::size_t{ 2 };} }},
            {"ROL", { 1 , [](){return std::size_t{ 1 };} }},
            {"ROR", { 1 , [](){return std::size_t{ 1 };} }},
            {"SBC", { 1 , [](){return std::size_t{ 1 };} }},
            {"SBCI", { 1 , [](){return std::size_t{ 1 };} }},
            {"SBI", { 1 , [](){return std::size_t{ 2 };} }},
            {"SBIW", { 1 , [](){return std::size_t{ 2 };} }},
            {"SBR", { 1 , [](){return std::size_t{ 1 };} }},
            {"SBRC", { 1 , [](){return std::size_t{ 1 };} }},
            {"SBRS", { 1 , [](){return std::size_t{ 1 };} }},
            {"SEC", { 1 , [](){return std::size_t{ 1 };} }},
            {"SEH", { 1 , [](){return std::size_t{ 1 };} }},
            {"SEI", { 1 , [](){return std::size_t{ 1 };} }},
            {"SEN", { 1 , [](){return std::size_t{ 1 };} }},
            {"SER", { 1 , [](){return std::size_t{ 1 };} }},
            {"SES", { 1 , [](){return std::size_t{ 1 };} }},
            {"SET", { 1 , [](){return std::size_t{ 1 };} }},
            {"SEV", { 1 , [](){return std::size_t{ 1 };} }},
            {"SEZ", { 1 , [](){return std::size_t{ 1 };} }},
            {"SLEEP", { 1 , [](){return std::size_t{ 1 };} }},
            {"STS", { 2 , [](){return std::size_t{ 2 };} }},
            {"STS", { 1 , [](){return std::size_t{ 1 };} }},
            {"SUB", { 1 , [](){return std::size_t{ 1 };} }},
            {"SUBI", { 1 , [](){return std::size_t{ 1 };} }},
            {"SWAP", { 1 , [](){return std::size_t{ 1 };} }},
            {"TST", { 1 , [](){return std::size_t{ 1 };} }},
            {"WDR", { 1 , [](){return std::size_t{ 1 };} }},
            {"XCH", { 1 , [](){return std::size_t{ 2 };} }},
    };
}