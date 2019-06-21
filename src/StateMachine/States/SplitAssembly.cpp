//
// Created by sebastian on 21.06.19.
//

#include "includes/SplitAssembly.h"

void SplitAssembly::execute() noexcept {

}

SplitAssembly::SplitAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}

int SplitAssembly::remainingSplits() {
    return 0;
}
