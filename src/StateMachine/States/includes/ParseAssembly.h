//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"

class ParseAssembly : public BaseState {
public:
    explicit ParseAssembly(ProcessDatabase& pd) noexcept;
    virtual void execute() noexcept override;

};



