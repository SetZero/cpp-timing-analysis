//
// Created by sebastian on 23.06.19.
//

#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>
#include <optional>

namespace utils {
    // https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
    void split(std::vector<std::string> &strs, const std::string &txt,  char ch) noexcept;
    void ltrim(std::string &s);
    void rtrim(std::string &s);
    void trim(std::string &s);
    std::string ltrim_copy(std::string s);
    std::string rtrim_copy(std::string s);
    std::string trim_copy(std::string s);

    [[nodiscard]] std::optional<std::size_t> findNthSubStr(std::size_t n, const std::string& subString, const std::string& string);
}