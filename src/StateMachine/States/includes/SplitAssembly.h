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
};



