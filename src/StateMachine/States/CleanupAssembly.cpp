//
// Created by sebastian on 21.06.19.
//

#include "includes/CleanupAssembly.h"

void CleanupAssembly::execute() noexcept {
    std::cout << "Cleanup Assembly" << std::endl;
}

CleanupAssembly::CleanupAssembly(ProcessDatabase &pd) noexcept : BaseState{pd} {

}
