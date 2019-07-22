//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>
#include <memory>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"
#include "../../MCUSpecific/vendors/TimingCalculation.h"
#include "../../MCUSpecific/vendors/avr/AVRTimingCalculation.h"
#include "../../MCUSpecific/vendors/arm/ARMTimingCalculation.h"

class TimingCalculation : public BaseState {
public:
    explicit TimingCalculation(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;
private:
    std::unique_ptr<BaseTimingCalculation> mImpl;
};



