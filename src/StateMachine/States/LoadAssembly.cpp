//
// Created by sebastian on 21.06.19.
//

#include "includes/LoadAssembly.h"

void LoadAssembly::execute() noexcept {
    std::cout << "--- [ Load Assembly ] ---" << std::endl;

}

LoadAssembly::LoadAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}
