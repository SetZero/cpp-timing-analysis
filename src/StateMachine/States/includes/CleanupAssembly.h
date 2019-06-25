//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <iostream>
#include <regex>
#include <sstream>
#include <algorithm>

#include "../../BaseState.h"
#include "../../DataHolder/ProcessDatabase.h"


class CleanupAssembly : public BaseState {
public:
    explicit CleanupAssembly(ProcessDatabase& pd) noexcept;
    void execute() noexcept override;
private:
    static constexpr auto LABEL_REGEX = R"((?:(\s+)?\.L(?:(?:[B|F|V][B|E|I|L]))[0-9]+:)|)"
                                        R"((?:(\s+)?\.loc (?:[0-9]+\s){3}[A-Za-z_-]+(?:.*?)\.[0-9A-Z]+)|)"
                                        R"((?:\/\*(.*?)\*\/\s*)|)"
                                        R"((?:\s*;(.*)\s?)|)"
                                        R"((?:\v+))";

    const std::regex mLabel{LABEL_REGEX};
};



