//
// Created by ccossou on 23/06/2020.
//

#include "cli.hpp"
#include <iostream>
#include "utils.hpp"
#include "Track.hpp"

using namespace std;
using namespace disco;

string get_command() {
    cout << "> ";

    string input{};
    getline(cin, input);

    return input;
}

tuple<Command, string> analyse_command(string const & input_text) {
    std::istringstream flux {input_text};

    string first_word{};
    flux >> first_word;
    first_word = string_cleanup(first_word);

    string parameters{};
    getline(flux, parameters);
    parameters = string_cleanup(parameters);

    if (first_word == "display")
            return {Command::Display, parameters};

    else if (first_word == "add")
            return {Command::Add, parameters};

    else if (first_word == "save")
            return {Command::Save, parameters};

    else if (first_word == "load")
            return {Command::Load, parameters};

    else if (first_word == "quit" or first_word == "exit")
            return {Command::Quit, string{}};

    else if (first_word == "help")
        return {Command::Help, string{}};

    else
            throw runtime_error("Invalid Command. Type 'help' for more info.");
}

bool run_command(Discography & discography, Command command, std::string const & instructions) {
    switch (command) {
        case Command::Display:
            if (instructions == "artist") {
                discography.display(DisplayType::Artist);
            }
            else if (instructions == "album") {
                discography.display(DisplayType::Album);
            }
            else if (instructions == "track") {
                discography.display(DisplayType::Track);
            }
            else {
                throw runtime_error("Unknown display type.");
            }
            break;

        case Command::Add:
        {
            istringstream flux{instructions};
            Track track{};
            flux >> track;
            discography.push_back(track);
            break;
        }

        case Command::Load:
            discography.from_file(instructions);
            break;

        case Command::Save:
            discography.to_file(instructions);
            break;

        case Command::Help:
            cout << "Allowed commands are:" << endl;
            cout << "\tdisplay: Display catalog info (options are: artist, album, track)" << endl;
            cout << "\tadd: add a new song, syntax is: add track | album | artist" << endl;
            cout << "\t     (Items can be left blanck if unknown, but a space is needed between each, e.g track | | artist)" << endl;
            cout << "\tsave: Save catalog to disk (a filename need to be specified)" << endl;
            cout << "\tload: Load catalog from disk (a filename need to be specified)" << endl;
            cout << "\tquit: Quit" << endl;
            cout << "\texit: Quit" << endl;
            cout << "\thelp: Display help." << endl;
            break;

        case Command::Quit:
            return false;

    }

    return true;
}
