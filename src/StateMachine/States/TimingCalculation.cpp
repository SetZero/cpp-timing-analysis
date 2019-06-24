//
// Created by sebastian on 21.06.19.
//

#include "includes/TimingCalculation.h"

void TimingCalculation::execute() noexcept {
    std::cout << "--- [ Timing Calculation ] ---" << std::endl;
    mProcessDatabase.timing(
            mImpl->calculateTiming(mProcessDatabase.currentparsedAssembly())
            );
    std::cout << "Instructions needed: " << mProcessDatabase.timing() << std::endl;
}

TimingCalculation::TimingCalculation(ProcessDatabase &pd) noexcept :
    BaseState{pd}, mImpl{std::make_unique<AVRTimingCalculation>()} {
}
