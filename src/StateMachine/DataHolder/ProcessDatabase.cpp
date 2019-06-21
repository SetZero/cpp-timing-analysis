//
// Created by sebastian on 21.06.19.
//

#include "ProcessDatabase.h"

void ProcessDatabase::fileLocation(const std::string &fileLocation) noexcept {
    mAssemblyLocation = fileLocation;
}

std::string ProcessDatabase::fileLocation() const noexcept {
    return mAssemblyLocation;
}

void ProcessDatabase::fileContents(const std::string &fileLocation) noexcept {
    mFileContent = fileLocation;
}

std::string ProcessDatabase::fileContents() const noexcept {
    return mFileContent;
}

const std::vector<std::string> &ProcessDatabase::getSections() const noexcept {
    return mSections;
}

void ProcessDatabase::addSection(const std::string &section) noexcept {
    mSections.push_back(section);
}

void ProcessDatabase::clearSections() noexcept {
    mSections.clear();
}
