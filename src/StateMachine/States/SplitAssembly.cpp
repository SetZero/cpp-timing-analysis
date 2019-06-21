//
// Created by sebastian on 21.06.19.
//

#include "includes/SplitAssembly.h"

void SplitAssembly::execute() noexcept {
    std::cout << "Split Assembly" << std::endl;
}

SplitAssembly::SplitAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}

int SplitAssembly::remainingSplits() {
    static size_t counter = 2;
    return counter--;
}
