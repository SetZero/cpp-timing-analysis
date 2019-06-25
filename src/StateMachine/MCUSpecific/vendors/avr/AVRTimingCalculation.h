//
// Created by sebastian on 23.06.19.
//

#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <unordered_map>

#include "../TimingCalculation.h"
#include "instructionTable.h"
#include "../../../../utils/containerUtils.h"

struct BranchInfo {
    std::vector<std::size_t> branchPoints;
    std::size_t startPosition;
    std::size_t endPosition;
};

class AVRTimingCalculation : public BaseTimingCalculation {
public:
    [[nodiscard]] std::size_t calculateTiming(const std::vector<std::vector<std::string>>& assembly) noexcept override;
private:
    static constexpr auto LABEL_REGEX = R"(\.L([0-9]+):?)";
    const std::regex mLabel{LABEL_REGEX};
    std::unordered_map<std::size_t, std::size_t> labelMap;

    [[nodiscard]] bool isLabel(const std::string& str) const noexcept;
    [[nodiscard]] std::optional<std::size_t> getLabelNumber(const std::string& str) const noexcept;
    [[nodiscard]] std::optional<std::pair<std::size_t, std::size_t>>
        loopRange(std::size_t position, const std::vector<std::vector<std::string>> &assembly, BranchInfo& branchPoints) const noexcept;
};



