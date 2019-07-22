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
        if(mProcessDatabase.arch() == Architectures::AVR) {
            utils::split(tmpVector, v, ' ');
        } else if(mProcessDatabase.arch() == Architectures::ARM){
            std::smatch match;
            if (std::regex_match(v, match, mCommandRegex)) {
                for (size_t i = 1; i < match.size(); ++i) {
                    std::ssub_match sub_match = match[i];
                    tmpVector.push_back(sub_match.str());
                }
            } else {
                tmpVector.push_back(v);
            }
        }
        if(!tmpVector.empty()) {
            utils::trim(tmpVector.at(0));
        }
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
