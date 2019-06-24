//
// Created by sebastian on 23.06.19.
//

#include <iostream>
#include "AVRTimingCalculation.h"

std::size_t
AVRTimingCalculation::calculateTiming(const std::vector<std::vector<std::string>> &assembly) noexcept {
    std::size_t cycles = 0;
    for(std::size_t i = 0; i < assembly.size(); i++) {
        std::string instructionName = assembly.at(i).at(0);
        std::transform(instructionName.begin(), instructionName.end(), instructionName.begin(), ::toupper);
        if(!isLabel(instructionName)) {
            const auto &info = avr::instructionMap.find(instructionName);
            if (info != avr::instructionMap.end()) {
                if(info->second.conditionalCommand) {
                    if(i + 1 < assembly.size()) {
                        loopRange(i, assembly);
                        cycles += info->second.calculator(assembly.at(i+1).at(0), false);
                    } else {
                        cycles += info->second.calculator("", false);
                    }
                } else {
                    cycles += info->second.calculator("", false);
                }
            } else {
                std::cout << "Unknown Instruction: " << instructionName << std::endl;
            }
        } else {
            std::size_t number = *getLabelNumber(instructionName);
            labelMap.emplace(number, i);
        }
    }
    return cycles;
}

// create looprunner which follows labels to a next branch

bool AVRTimingCalculation::isLabel(const std::string& str) const noexcept {
    return std::regex_match(std::begin(str), std::end(str), mLabel);
}

std::optional<std::size_t> AVRTimingCalculation::getLabelNumber(const std::string& str) const noexcept {
    std::smatch m;
    regex_search(str, m, mLabel);
    if(m.size() < 1) {
        return std::nullopt;
    } else {
        return std::stoi(m[1]);
    }
}

std::optional<std::pair<std::size_t, std::size_t>>
AVRTimingCalculation::loopRange(std::size_t position, const std::vector<std::vector<std::string>> &assembly) const noexcept {
    std::size_t currentPosition = position;
    std::vector<std::size_t> branchPoints;

    std::size_t lastBranchStart = 0;
    std::size_t lastBranchEnd = 0;

    while(true) {
        std::string currentASM = assembly[currentPosition][0];
        std::transform(currentASM.begin(), currentASM.end(), currentASM.begin(), ::toupper);
        const auto& asmInfo = avr::instructionMap.find(currentASM);
        if(asmInfo == avr::instructionMap.end()) {
            currentPosition++;
            continue;
        } if(asmInfo->second.conditionalCommand) {
            if(const auto& a = loopRange(currentPosition+1, assembly))
                return a;
            else if(const auto& b = loopRange(currentPosition+2, assembly))
                return b;
            else
                return std::nullopt;
        } else if(asmInfo->second.flowControlCommand) {
            const std::string& label = assembly[currentPosition][1];
            const auto& labelNumber = getLabelNumber(label);
            if(labelNumber) {
                if(std::find(std::begin(branchPoints), std::end(branchPoints), currentPosition) != branchPoints.end()) {
                    branchPoints.push_back(currentPosition);
                    lastBranchEnd = currentPosition;
                    currentPosition = labelMap.at(*labelNumber) + 1;
                    lastBranchStart = currentPosition;
                    continue;
                } else {
                    return {{lastBranchStart, lastBranchEnd}};
                }
            }
        } else if(currentASM == "RET") {
            return std::nullopt;
        }
        if(currentPosition == position) {
            return {{lastBranchStart, lastBranchEnd}};
        }
        currentPosition++;
        if(currentPosition >= assembly.size()) return std::nullopt;
    }
}
