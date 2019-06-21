//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>
#include <string_view>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"

class SplitAssembly : public BaseState {
public:
    explicit SplitAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;

    int remainingSplits();
private:
    static constexpr std::string_view START_DELIMITER{";START_MEASUREMENT"};
    static constexpr std::string_view STOP_DELIMITER{";STOP_MEASUREMENT"};
};



