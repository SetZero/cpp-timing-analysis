//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>
#include <filesystem>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"
#include "../../../utils/expected.h"
#include "../../../utils/fileUtils.h"

class LoadAssembly : public BaseState {
public:
    explicit LoadAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;
private:
    [[nodiscard]] const utils::expected<const std::string, const std::string> getFileContents(const std::filesystem::path& fileLocation) const noexcept;
};



