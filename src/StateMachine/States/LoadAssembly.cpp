//
// Created by sebastian on 21.06.19.
//

#include "includes/LoadAssembly.h"

LoadAssembly::LoadAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}

void LoadAssembly::execute() noexcept {
    std::cout << "--- [ Load Assembly ] ---" << std::endl;
    const auto& fileContent = getFileContents(mProcessDatabase.fileLocation());
    if(fileContent) {
        std::cout << "File loaded!" << std::endl;
        mProcessDatabase.fileContents(*fileContent);
    } else {
        std::cout << fileContent.error() << std::endl;
    }
}

const utils::expected<const std::string, const std::string> LoadAssembly::getFileContents(const std::filesystem::path& fileLocation) const noexcept {
    return utils::readFile(fileLocation);
}
