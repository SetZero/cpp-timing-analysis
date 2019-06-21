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
