//
// Created by sebastian on 23.06.19.
//

#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <regex>

#include "../TimingCalculation.h"
#include "instructionTable.h"

class AVRTimingCalculation : public BaseTimingCalculation {
public:
    [[nodiscard]] std::size_t calculateTiming(const std::vector<std::vector<std::string>>& assembly) const noexcept override;
private:
    static constexpr auto LABEL_REGEX = R"(\.L([0-9]+):)";
    const std::regex mLabel{LABEL_REGEX};

    [[nodiscard]] bool isLabel() const noexcept;
    [[nodiscard]] std::size_t getLabelNumber() const noexcept;
};



