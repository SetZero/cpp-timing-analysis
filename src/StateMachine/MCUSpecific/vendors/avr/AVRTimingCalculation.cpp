//
// Created by sebastian on 23.06.19.
//

#include <iostream>
#include "AVRTimingCalculation.h"

std::size_t
AVRTimingCalculation::calculateTiming(const std::vector<std::vector<std::string>> &assembly) const noexcept {
    std::size_t cycles = 0;
    for(std::size_t i = 0; i < assembly.size(); i++) {
        std::string instructionName = assembly.at(i).at(0);
        std::transform(instructionName.begin(), instructionName.end(), instructionName.begin(), ::toupper);
        if(!isLabel()) {
            const auto &info = avr::instructionMap.find(instructionName);
            if (info != avr::instructionMap.end()) {
                if(info->second.flowControlCommand) {
                    cycles += info->second.calculator("", false);
                } else {
                    if(i + 1 < assembly.size()) {
                        // if the next assembly is a flow control whichs label leeds to
                        // something before this code it is a loop and therefore it is more likely to be executed
                        cycles += info->second.calculator(assembly.at(i+1).at(0), false);
                    } else {
                        cycles += info->second.calculator("", false);
                    }
                }
            } else {
                std::cout << "Unknown Instruction: " << instructionName << std::endl;
            }
        } else {
            std::size_t number = getLabelNumber();
        }
    }
    return cycles;
}

// create looprunner which follows labels to a next branch

bool AVRTimingCalculation::isLabel() const noexcept {
    return false;
}

std::size_t AVRTimingCalculation::getLabelNumber() const noexcept {
    return 0;
}
