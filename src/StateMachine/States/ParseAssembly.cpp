//
// Created by sebastian on 21.06.19.
//

#include "includes/ParseAssembly.h"

void ParseAssembly::execute() noexcept {
    std::cout << "--- [ Parse Assembly ] ---" << std::endl;
    mProcessDatabase.clearParsedAssembly();
    std::string currentAssembly = mProcessDatabase.currentAssembly();

    std::vector<std::string> lines;
    utils::split(lines, currentAssembly, '\n');
    std::vector<std::string> tmpVector;
    for(const auto& v : lines) {
        tmpVector.clear();
        utils::split(tmpVector, v, ' ');
        if(std::all_of(std::begin(tmpVector), std::end(tmpVector), [](const std::string& element) {
            return !element.empty();
        })) {
            mProcessDatabase.addParsedAssembly(tmpVector);
        }
    }

    for(const auto& v1 : mProcessDatabase.currentparsedAssembly()) {
        for(const auto& v2 : v1) {
            std::cout << v2 << " ";
        }
        std::cout << std::endl;
    }
}

ParseAssembly::ParseAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}
