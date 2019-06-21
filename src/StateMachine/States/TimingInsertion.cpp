//
// Created by sebastian on 21.06.19.
//

#include "includes/TimingInsertion.h"

void TimingInsertion::execute() noexcept {
    std::cout << "Timing Insertion" << std::endl;
}

TimingInsertion::TimingInsertion(ProcessDatabase &pd) noexcept : BaseState{pd} {

}
