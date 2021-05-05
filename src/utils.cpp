//
// Created by ccossou on 30/06/2020.
//

#include "utils.hpp"
#include <algorithm>
#include <locale>

using namespace std;

string string_cleanup(string const & text) {
    string copy{text};

    // Delete spaces at beginning of string
    auto string_start {find_if_not(copy.begin(), copy.end(), [](unsigned char c){return isspace(c);})}; // [](char c){return isspace(c);}
    copy.erase(copy.begin(), string_start);

    // Delete spaces at end of string
    auto string_end {find_if_not(copy.rbegin(), copy.rend(), [](unsigned char c){return isspace(c);})};
    copy.erase(string_end.base(), copy.end());

    return copy;

}