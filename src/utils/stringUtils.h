//
// Created by sebastian on 23.06.19.
//

#pragma once

#include <string>
#include <vector>

namespace utils {
    // https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
    void split(std::vector<std::string> &strs, const std::string &txt,  char ch) noexcept;
}