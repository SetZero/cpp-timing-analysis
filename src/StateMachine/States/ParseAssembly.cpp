//
// Created by sebastian on 21.06.19.
//

#include "includes/ParseAssembly.h"

void ParseAssembly::execute() noexcept {
    std::cout << "Parse Assembly" << std::endl;
}

ParseAssembly::ParseAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}
