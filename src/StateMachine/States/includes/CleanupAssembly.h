//
// Created by sebastian on 21.06.19.
//

#pragma once

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"


class CleanupAssembly : public BaseState {
public:
    explicit CleanupAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;

};



