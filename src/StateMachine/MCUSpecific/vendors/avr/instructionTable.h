//
// Created by sebastian on 24.06.19.
//

#pragma once

#include <unordered_map>
#include <functional>


/*
 * Missing Instructions:
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_BRLT.html // no info?
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_CALL.html // 16 / 22b PC
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_CLS.html // no cyles?
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LD.html // more complex
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LDD.html // more complex
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_LDD_Z.html // more complex
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_RCALL.html // 16 / 22b PC
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_SPM.html //depends?
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_ST.html // complex
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_STD.html // more complex
 * https://www.microchip.com/webdoc/avrassembler/avrassembler.wb_STD_Z.html // more complex
 */
namespace avr {
    struct InstructionInfo {
        std::size_t wordLength;
        std::function<std::size_t(const std::string&, bool)> calculator;
        bool flowControlCommand = false;
        bool conditionalCommand = false;
    };

    using iVec = const std::vector<std::vector<std::string>>&;

    template<std::size_t cycl>
    using cycles = decltype([]( [[maybe_unused]] const std::string& nextASM = "", [[maybe_unused]] bool likelyTrue = false){return cycl; });

    const std::unordered_map<std::string, InstructionInfo> instructionMap = {
            {"ADC", { 1 , cycles<1>()}},
            {"ADD", { 1 , cycles<1>()}},
            {"ADIW", { 1 , cycles<2>()}},
            {"AND", { 1 , cycles<1>()}},
            {"ANDI", { 1 , cycles<1>()}},
            {"ASR", { 1 , cycles<1>()}},
            {"BCLR", { 1 , cycles<1>()}},
            {"BLD", { 1 , cycles<1>()}},
            {"BRBC", { 1 , cycles<1>()}},
            {"BRBS", { 1 , cycles<1>()}},
            {"BRCC", { 1 , cycles<1>()}},
            {"BRCS", { 1 , cycles<1>()}},
            {"BREAK", { 1 , cycles<1>()}},
            {"BREQ", { .wordLength = 1 , .calculator = cycles<1>(), .flowControlCommand = true, .conditionalCommand = true }},
            {"BRGE", { 1 , cycles<1>()}},
            {"BRHC", { 1 , cycles<1>()}},
            {"BRHS", { 1 , cycles<1>()}},
            {"BRID", { 1 , cycles<1>()}},
            {"BRIE", { 1 , cycles<1>()}},
            {"BRLO", { 1 , cycles<1>()}},
            {"BRMI", { 1 , cycles<1>()}},
            {"BRNE", { 1 , cycles<1>()}},
            {"BRPL", { 1 , cycles<1>()}},
            {"BRSH", { 1 , cycles<1>()}},
            {"BRTC", { 1 , cycles<1>()}},
            {"BRTS", { 1 , cycles<1>()}},
            {"BRVC", { 1 , cycles<1>()}},
            {"BRVS", { 1 , cycles<1>()}},
            {"BSET", { 1 , cycles<1>()}},
            {"BST", { 1 , cycles<1>()}},
            {"CBI", { 1 , cycles<2>()}},
            {"CBR", { 1 , cycles<1>()}},
            {"CLC", { 1 , cycles<1>()}},
            {"CLH", { 1 , cycles<1>()}},
            {"CLI", { 1 , cycles<1>()}},
            {"CLN", { 1 , cycles<1>()}},
            {"CLR", { 1 , cycles<1>()}},
            {"CLT", { 1 , cycles<1>()}},
            {"CLV", { 1 , cycles<1>()}},
            {"CLZ", { 1 , cycles<1>()}},
            {"COM", { 1 , cycles<1>()}},
            {"CP", { 1 , cycles<1>()}},
            {"CPC", { 1 , cycles<1>()}},
            {"CPI", { 1 , cycles<1>()}},
            {"CPSE", { 1 , cycles<1>()}},
            {"DEC", { 1 , cycles<1>()}},
            {"EIJMP", { 1 , cycles<2>()}},
            {"ELPM", { 1 , cycles<3>()}},
            {"EOR", { 1 , cycles<1>()}},
            {"FMUL", { 1 , cycles<2>()}},
            {"FMULS", { 1 , cycles<2>()}},
            {"FMULSU", { 1 , cycles<2>()}},
            {"IJMP", { 1 , cycles<2>()}},
            {"IN", { 1 , cycles<1>()}},
            {"INC", { 1 , cycles<1>()}},
            {"JMP", { 2 , cycles<3>()}},
            {"LAT", { 1 , cycles<2>()}},
            {"LAS", { 1 , cycles<2>()}},
            {"LAC", { 1 , cycles<2>()}},
            {"LDI", { 1 , cycles<1>()}},
            {"LDS", { 1 , cycles<1>()}},
            {"LPM", { 1 , cycles<3>()}},
            {"LSL", { 1 , cycles<1>()}},
            {"LSR", { 1 , cycles<1>()}},
            {"MOV", { 1 , cycles<1>()}},
            {"MOVW", { 1 , cycles<1>()}},
            {"MUL", { 1 , cycles<2>()}},
            {"MULS", { 1 , cycles<2>()}},
            {"MULSU", { 1 , cycles<2>()}},
            {"NEG", { 1 , cycles<1>()}},
            {"NOP", { 1 , cycles<1>()}},
            {"OR", { 1 , cycles<1>()}},
            {"ORI", { 1 , cycles<1>()}},
            {"OUT", { 1 , cycles<1>()}},
            {"POP", { 1 , cycles<2>()}},
            {"RET", { .wordLength = 1 , .calculator = cycles<4>(), .flowControlCommand = true}},
            {"RETI", { .wordLength = 1 , .calculator = cycles<4>(), .flowControlCommand = true}},
            {"RJMP", { .wordLength = 1 , .calculator = cycles<2>(), .flowControlCommand = true}},
            {"ROL", { 1 , cycles<1>()}},
            {"ROR", { 1 , cycles<1>()}},
            {"SBC", { 1 , cycles<1>()}},
            {"SBCI", { 1 , cycles<1>()}},
            {"SBI", { 1 , cycles<2>()}},
            {"SBIW", { 1 , cycles<2>()}},
            {"SBR", { 1 , cycles<1>()}},
            {"SBRC", { 1 , cycles<1>()}},
            {"SBRS", { 1 , cycles<1>()}},
            {"SEC", { 1 , cycles<1>()}},
            {"SEH", { 1 , cycles<1>()}},
            {"SEI", { 1 , cycles<1>()}},
            {"SEN", { 1 , cycles<1>()}},
            {"SER", { 1 , cycles<1>()}},
            {"SES", { 1 , cycles<1>()}},
            {"SET", { 1 , cycles<1>()}},
            {"SEV", { 1 , cycles<1>()}},
            {"SEZ", { 1 , cycles<1>()}},
            {"SLEEP", { 1 , cycles<1>()}},
            {"STS", { 2 , cycles<2>()}},
            {"STS", { 1 , cycles<1>()}},
            {"SUB", { 1 , cycles<1>()}},
            {"SUBI", { 1 , cycles<1>()}},
            {"SWAP", { 1 , cycles<1>()}},
            {"TST", { 1 , cycles<1>()}},
            {"WDR", { 1 , cycles<1>()}},
            {"XCH", { 1 , cycles<2>()}},
            {"PUSH", { 1 , cycles<2>()}},
            {"SBIC", { .wordLength = 1 , .calculator = [](const std::string& nextASM, bool likelyTrue) {
                if(likelyTrue) {
                    if (instructionMap.at(nextASM).wordLength == 1)
                        return 2;
                    else
                        return 3;
                } else {
                    return 1;
                }
            }, .conditionalCommand = true}},
            {"SBIS", { .wordLength = 1 , .calculator = [](const std::string& nextASM, bool likelyTrue) {
                if(likelyTrue) {
                    if (instructionMap.at(nextASM).wordLength == 1)
                        return 2;
                    else
                        return 3;
                } else {
                    return 1;
                }
            }, .conditionalCommand = true}},
            {"EICALL", { 1, cycles<4>()}},
            {"ICALL", { 1, cycles<4>()}},
            {"LDS", { 1, cycles<2>()}},
    };
}