//
// Created by sebastian on 24.06.19.
//

#pragma once

#include <unordered_map>
#include <functional>


/*
 * Missing Instructions:
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_BRLT.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_CALL.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_CLS.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_EICALL.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_ICALL.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LD.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LDD.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LDD_Z.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LDS.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_RCALL.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_SBIC.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_SBIS.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_SPM.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_ST.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_STD.html
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_STD_Z.html
 */
namespace avr {
    struct InstructionInfo {
        std::size_t wordLength;
        std::function<std::size_t()> calculator;
        bool flowControlCommand = false;
    };

    using iVec = const std::vector<std::vector<std::string>>&;

    const std::unordered_map<std::string, InstructionInfo> instructionMap = {
            {"ADC", { 1 , [](){return 1; }}},
            {"ADD", { 1 , [](){return 1;}}},
            {"ADIW", { 1 , [](){return 2;}}},
            {"AND", { 1 , [](){return 1;}}},
            {"ANDI", { 1 , [](){return 1;}}},
            {"ASR", { 1 , [](){return 1;}}},
            {"BCLR", { 1 , [](){return 1;}}},
            {"BLD", { 1 , [](){return 1;}}},
            {"BRBC", { 1 , [](){return 1;}}},
            {"BRBS", { 1 , [](){return 1;}}},
            {"BRCC", { 1 , [](){return 1;}}},
            {"BRCS", { 1 , [](){return 1;}}},
            {"BREAK", { 1 , [](){return 1;}}},
            {"BREQ", { 1 , [](){return 1;}}},
            {"BRGE", { 1 , [](){return 1;}}},
            {"BRHC", { 1 , [](){return 1;}}},
            {"BRHS", { 1 , [](){return 1;}}},
            {"BRID", { 1 , [](){return 1;}}},
            {"BRIE", { 1 , [](){return 1;}}},
            {"BRLO", { 1 , [](){return 1;}}},
            {"BRMI", { 1 , [](){return 1;}}},
            {"BRNE", { 1 , [](){return 1;}}},
            {"BRPL", { 1 , [](){return 1;}}},
            {"BRSH", { 1 , [](){return 1;}}},
            {"BRTC", { 1 , [](){return 1;}}},
            {"BRTS", { 1 , [](){return 1;}}},
            {"BRVC", { 1 , [](){return 1;}}},
            {"BRVS", { 1 , [](){return 1;}}},
            {"BSET", { 1 , [](){return 1;}}},
            {"BST", { 1 , [](){return 1;}}},
            {"CBI", { 1 , [](){return 2;}}},
            {"CBR", { 1 , [](){return 1;}}},
            {"CLC", { 1 , [](){return 1;}}},
            {"CLH", { 1 , [](){return 1;}}},
            {"CLI", { 1 , [](){return 1;}}},
            {"CLN", { 1 , [](){return 1;}}},
            {"CLR", { 1 , [](){return 1;}}},
            {"CLT", { 1 , [](){return 1;}}},
            {"CLV", { 1 , [](){return 1;}}},
            {"CLZ", { 1 , [](){return 1;}}},
            {"COM", { 1 , [](){return 1;}}},
            {"CP", { 1 , [](){return 1;}}},
            {"CPC", { 1 , [](){return 1;}}},
            {"CPI", { 1 , [](){return 1;}}},
            {"CPSE", { 1 , [](){return 1;}}},
            {"DEC", { 1 , [](){return 1;}}},
            {"EIJMP", { 1 , [](){return 2;}}},
            {"ELPM", { 1 , [](){return 3;}}},
            {"EOR", { 1 , [](){return 1;}}},
            {"FMUL", { 1 , [](){return 2;}}},
            {"FMULS", { 1 , [](){return 2;}}},
            {"FMULSU", { 1 , [](){return 2;}}},
            {"IJMP", { 1 , [](){return 2;}}},
            {"IN", { 1 , [](){return 1;}}},
            {"INC", { 1 , [](){return 1;}}},
            {"JMP", { 2 , [](){return 3;}}},
            {"LAT", { 1 , [](){return 2;}}},
            {"LAS", { 1 , [](){return 2;}}},
            {"LAC", { 1 , [](){return 2;}}},
            {"LDI", { 1 , [](){return 1;}}},
            {"LDS", { 1 , [](){return 1;}}},
            {"LPM", { 1 , [](){return 3;}}},
            {"LSL", { 1 , [](){return 1;}}},
            {"LSR", { 1 , [](){return 1;}}},
            {"MOV", { 1 , [](){return 1;}}},
            {"MOVW", { 1 , [](){return 1;}}},
            {"MUL", { 1 , [](){return 2;}}},
            {"MULS", { 1 , [](){return 2;}}},
            {"MULSU", { 1 , [](){return 2;}}},
            {"NEG", { 1 , [](){return 1;}}},
            {"NOP", { 1 , [](){return 1;}}},
            {"OR", { 1 , [](){return 1;}}},
            {"ORI", { 1 , [](){return 1;}}},
            {"OUT", { 1 , [](){return 1;}}},
            {"POP", { 1 , [](){return 2;}}},
            {"RET", { 1 , [](){return 4;}, true}},
            {"RETI", { 1 , [](){return 4;}, true}},
            {"RJMP", { 1 , [](){return 2;}, true}},
            {"ROL", { 1 , [](){return 1;}}},
            {"ROR", { 1 , [](){return 1;}}},
            {"SBC", { 1 , [](){return 1;}}},
            {"SBCI", { 1 , [](){return 1;}}},
            {"SBI", { 1 , [](){return 2;}}},
            {"SBIW", { 1 , [](){return 2;}}},
            {"SBR", { 1 , [](){return 1;}}},
            {"SBRC", { 1 , [](){return 1;}}},
            {"SBRS", { 1 , [](){return 1;}}},
            {"SEC", { 1 , [](){return 1;}}},
            {"SEH", { 1 , [](){return 1;}}},
            {"SEI", { 1 , [](){return 1;}}},
            {"SEN", { 1 , [](){return 1;}}},
            {"SER", { 1 , [](){return 1;}}},
            {"SES", { 1 , [](){return 1;}}},
            {"SET", { 1 , [](){return 1;}}},
            {"SEV", { 1 , [](){return 1;}}},
            {"SEZ", { 1 , [](){return 1;}}},
            {"SLEEP", { 1 , [](){return 1;}}},
            {"STS", { 2 , [](){return 2;}}},
            {"STS", { 1 , [](){return 1;}}},
            {"SUB", { 1 , [](){return 1;}}},
            {"SUBI", { 1 , [](){return 1;}}},
            {"SWAP", { 1 , [](){return 1;}}},
            {"TST", { 1 , [](){return 1;}}},
            {"WDR", { 1 , [](){return 1;}}},
            {"XCH", { 1 , [](){return 2;}}},
            {"PUSH", { 1 , [](){return 2;}}},
    };
}