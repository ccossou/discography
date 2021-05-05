//
// Created by ccossou on 23/06/2020.
//

#ifndef DISCOGRAPHY_CLI_HPP
#define DISCOGRAPHY_CLI_HPP

#include <tuple>
#include <string>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include "Discography.hpp"

enum class Command {Display, Add, Save, Load, Quit, Help};

// Get what the user wants
std::string get_command();

// Analyse command request
std::tuple<Command, std::string> analyse_command(std::string const & input_text);

bool run_command(disco::Discography & discography, Command command, std::string const & instructions);

#endif //DISCOGRAPHY_CLI_HPP
