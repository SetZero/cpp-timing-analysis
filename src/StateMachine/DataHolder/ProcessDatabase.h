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
    std::vector<std::string> mSections;
    std::string mCurrentAssembly;
public:
    void fileLocation(const std::string& fileLocation) noexcept;

    [[nodiscard]] std::string fileLocation() const noexcept;

    void fileContents(const std::string& fileLocation) noexcept;

    [[nodiscard]] std::string fileContents() const noexcept;

    void addSection(const std::string& section) noexcept;

    void clearSections() noexcept;

    [[nodiscard]] const std::vector<std::string>& getSections() const noexcept;

    [[nodiscard]] const std::string popSection() noexcept;

    [[nodiscard]] std::string currentAssembly() const noexcept;

    void currentAssembly(const std::string& assembly) noexcept;
};



