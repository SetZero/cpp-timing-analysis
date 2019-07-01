//
// Created by sebastian on 21.06.19.
//

#include "includes/TimingInsertion.h"

void TimingInsertion::execute() noexcept {
    std::cout << "--- [ Timing Insertion ] ---" << std::endl;

    auto value = mProcessDatabase.currentAssembly();
    auto matches = std::distance(std::sregex_iterator(std::begin(value), std::end(value), regex), std::sregex_iterator());
    if(matches > 1) {
        std::cout << "There were multiple matches with the timing constant, please insert the timing \"" << mProcessDatabase.timing() << "\" manually!";
        return;
    }
    if(matches <= 0) {
        std::cout << "There is no timing constant in this Code... " << std::endl;
        return;
    }

    std::string newValue;
    std::string timingString = "$1 ";
    timingString.append(std::to_string(mProcessDatabase.timing()));

    std::regex_replace (std::back_inserter(newValue), std::begin(value), std::end(value), regex, timingString);
    const std::size_t position = mProcessDatabase.position();

    const auto startPosition = utils::findNthSubStr(position+1, std::string(ProcessDatabase::START_DELIMITER), mProcessDatabase.fileContents());
    const auto stopPosition = utils::findNthSubStr(position+1, std::string(ProcessDatabase::STOP_DELIMITER), mProcessDatabase.fileContents());
    if(startPosition && stopPosition) {
        if(*startPosition < *stopPosition) {
            auto newContent = mProcessDatabase.fileContents();
            newContent.replace(*startPosition, *stopPosition - *startPosition, newValue);
            std::cout << "Start: " << *startPosition << ", Stop: " << *stopPosition << std::endl;
            //mProcessDatabase.fileContents(newContent);
        } else {
          /*  for(auto it = mProcessDatabase.fileContents().begin() + *startPosition; it != mProcessDatabase.fileContents().end(); it++) {
                std::cout << *it;
           }*/
           std::cout << "Start: " << *startPosition << ", Stop: " << *stopPosition << std::endl;
        }
    }

    mProcessDatabase.position(mProcessDatabase.position() + 1);
}

TimingInsertion::TimingInsertion(ProcessDatabase &pd) noexcept : BaseState{pd} {

}
