//
// Created by sebastian on 23.06.19.
//

#include <iostream>
#include "AVRTimingCalculation.h"

std::size_t
AVRTimingCalculation::calculateTiming(const std::vector<std::vector<std::string>> &assembly) noexcept {
    std::map<std::size_t, std::size_t> cyclesLineCounter;
    for(std::size_t i = 0; i < assembly.size(); i++) {
        std::string instructionName = assembly.at(i).at(0);
        std::transform(instructionName.begin(), instructionName.end(), instructionName.begin(), ::toupper);

        if(isLabel(instructionName)) {
            std::size_t number = *getLabelNumber(instructionName);
            labelMap.emplace(number, i);
            continue;
        }

        const auto &info = avr::instructionMap.find(instructionName);
        if (info == avr::instructionMap.end()) {
            std::cout << "Unknown Instruction: " << instructionName << std::endl;
            continue;
        }

        if(info->second.flowControlCommand) {
            //if(i + 1 < assembly.size()) {
                BranchInfo branchInfo{std::vector<std::size_t>{}, 0, 0};
                const auto& loop = loopRange(i, assembly, branchInfo);
                if(loop) {
                    std::cout << "Loop from " << loop->first << " to " << loop->second << std::endl;

                    utils::erase_if(cyclesLineCounter, [&](std::pair<std::size_t, std::size_t> el) {
                        return el.first < loop->first || el.first > loop->second;
                    });
                    cyclesLineCounter.emplace(i, info->second.calculator(assembly.at(i).at(0), false));
                } else {
                    cyclesLineCounter.emplace(i, info->second.calculator(assembly.at(i).at(0), true));
                }
            //} else {
            //    cyclesLineCounter.emplace(i, info->second.calculator("", false));
            //}
            continue;
        }

        cyclesLineCounter.emplace(i, info->second.calculator("", false));
    }
    std::size_t cycles = 0;
    for(const auto& lineCycle : cyclesLineCounter) {
        cycles += lineCycle.second;
    }
    return cycles;
}

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
AVRTimingCalculation::loopRange(std::size_t position, const std::vector<std::vector<std::string>> &assembly, BranchInfo& branchInfo) noexcept {
    std::size_t currentPosition = position;

    while(true) {
        std::string currentASM = assembly[currentPosition][0];
        std::transform(currentASM.begin(), currentASM.end(), currentASM.begin(), ::toupper);
        const auto& asmInfo = avr::instructionMap.find(currentASM);
        if(asmInfo == avr::instructionMap.end()) {
            currentPosition++;
            continue;
        } if(asmInfo->second.conditionalCommand) {
            if(const auto& a = loopRange(currentPosition+1, assembly, branchInfo))
                return a;
            else if(const auto& b = loopRange(currentPosition+2, assembly, branchInfo))
                return b;
            else
                return std::nullopt;
        } else if(asmInfo->second.flowControlCommand) {
            const std::string& label = assembly[currentPosition][1];
            const auto& labelNumber = getLabelNumber(label);
            if(labelNumber) {
                if(std::find(std::begin(branchInfo.branchPoints), std::end(branchInfo.branchPoints), currentPosition) == branchInfo.branchPoints.end()) {
                    branchInfo.branchPoints.push_back(currentPosition);
                    branchInfo.endPosition = currentPosition;
                    const auto& labelPos = labelMap.find(*labelNumber);
                    if(labelPos != labelMap.end()) {
                        currentPosition = labelPos->second + 1;
                    } else {
                        const auto& number = findLabelPosition(*labelNumber, assembly);
                        if(number) {
                            currentPosition = *number + 1;
                            labelMap.emplace(*labelNumber, *number);
                        }
                    }
                    branchInfo.startPosition = currentPosition;
                    if(currentPosition >= assembly.size()) {
                        return branchInfoCheck(branchInfo);
                    } else {
                        continue;
                    }
                } else {
                    return branchInfoCheck(branchInfo);
                }
            } else {
                return std::nullopt;
            }
        }
        if(currentPosition == position) {
            return branchInfoCheck(branchInfo);
        }
        currentPosition++;
        if(currentPosition >= assembly.size()) return std::nullopt;
    }
}

std::optional<std::size_t>
AVRTimingCalculation::findLabelPosition(std::size_t labelNumber, const std::vector<std::vector<std::string>> &assembly) const noexcept {
    for(std::size_t i = 0; i < assembly.size(); i++) {
        if(auto number = getLabelNumber(assembly[i][0])) {
            if(labelNumber == *number) {
                return i;
            }
        }
    }
    return std::nullopt;
}

std::optional<std::pair<std::size_t, std::size_t>>
AVRTimingCalculation::branchInfoCheck(const BranchInfo &branchPoints) const noexcept {
    const auto& start = std::min(branchPoints.startPosition, branchPoints.endPosition);
    const auto& stop = std::max(branchPoints.startPosition, branchPoints.endPosition);
    if(start == stop) return std::nullopt;
    else return {{start, stop}};
}
