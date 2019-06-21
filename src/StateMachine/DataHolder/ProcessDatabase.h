//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <vector>
#include <string>
#include <string_view>

class ProcessDatabase {
private:
    std::string mAssemblyLocation;
    std::string mFileContent;
public:
    void fileLocation(const std::string& fileLocation) noexcept;

    [[nodiscard]] std::string fileLocation() const noexcept;

    void fileContents(const std::string& fileLocation) noexcept;

    [[nodiscard]] std::string fileContents() const noexcept;
};



