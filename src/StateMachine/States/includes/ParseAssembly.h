//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>
#include <regex>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"
#include "../../../utils/stringUtils.h"

class ParseAssembly : public BaseState {
private:
    static constexpr auto FIND_COMMAND = R"(\s*([A-Za-z]+)\s*(.*?))";
    const std::regex mCommandRegex{FIND_COMMAND};
public:
    explicit ParseAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;
};



