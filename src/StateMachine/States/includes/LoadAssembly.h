//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"

class LoadAssembly : public BaseState {
public:
    explicit LoadAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;

};



