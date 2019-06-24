//
// Created by sebastian on 23.06.19.
//

#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "../TimingCalculation.h"
#include "instructionTable.h"

class AVRTimingCalculation : public BaseTimingCalculation {
    [[nodiscard]] std::size_t calculateTiming(const std::vector<std::vector<std::string>>& assembly) const noexcept override;
};



