//
// Created by sebastian on 21.06.19.
//

#include "includes/SplitAssembly.h"

void SplitAssembly::execute() noexcept {
    std::cout << "--- [ Split Assembly ] ---" << std::endl;
    const auto& content = mProcessDatabase.fileContents();

    auto start = content.find(mProcessDatabase.START_DELIMITER);
    auto stop = content.find(mProcessDatabase.STOP_DELIMITER);
    while (start != std::string::npos || stop != std::string::npos) {
        mProcessDatabase.addSection(content.substr(start + mProcessDatabase.START_DELIMITER.length(), stop - start - mProcessDatabase.STOP_DELIMITER.length()));
        start = content.find(mProcessDatabase.START_DELIMITER, start + mProcessDatabase.START_DELIMITER.size());
        stop = content.find(mProcessDatabase.STOP_DELIMITER, stop + mProcessDatabase.STOP_DELIMITER.size());
    }
    std::cout << "Split into " << mProcessDatabase.getSections().size() << " sections!" << std::endl;

}

SplitAssembly::SplitAssembly(ProcessDatabase &pd) noexcept  : BaseState{pd} {

}

int SplitAssembly::remainingSplits() {
    return mProcessDatabase.getSections().size();
}
