//
// Created by sebastian on 23.06.19.
//

#include <iostream>
#include "AVRTimingCalculation.h"

std::size_t
AVRTimingCalculation::calculateTiming(const std::vector<std::vector<std::string>> &assembly) const noexcept {
    std::size_t cycles = 0;
    for(const auto& instruction: assembly) {
        std::string instructionName = instruction.at(0);
        std::transform(instructionName.begin(), instructionName.end(), instructionName.begin(), ::toupper);
        const auto& info = avr::instructionMap.find(instructionName);
        if(info != avr::instructionMap.end()) {
            cycles += info->second.calculator();
        } else {
            std::cout << "Unknown Instruction: " << instructionName << std::endl;
        }
    }
    return cycles;
}
