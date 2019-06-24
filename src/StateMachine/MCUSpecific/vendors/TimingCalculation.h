//
// Created by sebastian on 23.06.19.
//

#pragma once


class BaseTimingCalculation {
public:
    virtual ~BaseTimingCalculation() = default;
    [[nodiscard]] virtual std::size_t calculateTiming(const std::vector<std::vector<std::string>>& assembly) noexcept = 0;
};



