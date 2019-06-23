//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"
#include "../../../utils/stringUtils.h"

class ParseAssembly : public BaseState {
public:
    explicit ParseAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;
};



