//
// Created by sebastian on 21.06.19.
//

#include "includes/CleanupAssembly.h"

void CleanupAssembly::execute() noexcept {
    std::cout << "--- [ Cleanup Assembly ] ---" << std::endl;
    auto& section = mProcessDatabase.popSection();
    std::stringstream result;
    std::regex_replace(std::ostream_iterator<char>(result), section.begin(), section.end(), mLabel, "");
    mProcessDatabase.currentAssembly(result.str());
}

CleanupAssembly::CleanupAssembly(ProcessDatabase &pd) noexcept : BaseState{pd} {

}
