//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"

class TimingInsertion : public BaseState {
public:
    explicit TimingInsertion(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;

};



