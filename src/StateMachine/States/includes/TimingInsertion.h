//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>
#include <regex>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"
#include "../../../utils/stringUtils.h"

class TimingInsertion : public BaseState {
private:
    static constexpr auto FIND_DUMMY = R"(([a-zA-Z]+\s*(?:.*))(42))";
    const std::regex regex{FIND_DUMMY};
public:
    explicit TimingInsertion(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;

};



