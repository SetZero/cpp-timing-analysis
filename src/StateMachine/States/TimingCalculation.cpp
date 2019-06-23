//
// Created by sebastian on 21.06.19.
//

#include "includes/TimingCalculation.h"

void TimingCalculation::execute() noexcept {
    std::cout << "Timing Calculation" << std::endl;
}

TimingCalculation::TimingCalculation(ProcessDatabase &pd) noexcept : BaseState{pd}, mImpl{std::make_unique<AVRTimingCalculation>()} {

}
