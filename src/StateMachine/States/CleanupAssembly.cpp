//
// Created by sebastian on 21.06.19.
//

#include "includes/CleanupAssembly.h"

void CleanupAssembly::execute() noexcept {
    try {
        std::cout << "--- [ Cleanup Assembly ] ---" << std::endl;
        auto& section = mProcessDatabase.popSection();
        std::stringstream result;
        std::regex_replace(std::ostream_iterator<char>(result), section.begin(), section.end(), mLabel, "");
        mProcessDatabase.currentAssembly(result.str());
    } catch (std::regex_error e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

CleanupAssembly::CleanupAssembly(ProcessDatabase &pd) noexcept : BaseState{pd} {

}
