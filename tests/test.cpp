//
// Created by ccossou on 07/07/2020.
//
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE

#include "utils.hpp"
#include "catch.hpp"
#include "Track.hpp"

using namespace std;
using namespace Catch::Matchers;


TEST_CASE( "Read entry for track", "[Track]") {
    std::istringstream entree{ "Frica | Frida | Carla's Dreams" };
    Track track{};

    entree >> track;

    CHECK_THAT(track.name(), Equals("Frica"));
    CHECK_THAT(track.album(), Equals("Frida"));
    CHECK_THAT(track.artist(), Equals("Carla's Dreams"));
}

TEST_CASE( "Read entry for tracks with spaces", "[Track]") {
    std::istringstream entree{ "Levels       |  Levels   |     Avicii" };
    Track track{};

    entree >> track;

    CHECK_THAT(track.name(), Equals("Levels"));
    CHECK_THAT(track.album(), Equals("Levels"));
    CHECK_THAT(track.artist(), Equals("Avicii"));
}

TEST_CASE( "Read entry for tracks without album", "[Track]") {
    std::istringstream entree{ "Levels       | |     Avicii" };
    Track track{};

    entree >> track;

    CHECK_THAT(track.name(), Equals("Levels"));
    CHECK_THAT(track.album(), Equals("Unknown Album"));
    CHECK_THAT(track.artist(), Equals("Avicii"));
}

TEST_CASE( "Read entry for tracks with only track name", "[Track]") {
    std::istringstream entree{ "Levels       | |   " };
    Track track{};

    entree >> track;

    CHECK_THAT(track.name(), Equals("Levels"));
    CHECK_THAT(track.album(), Equals("Unknown Album"));
    CHECK_THAT(track.artist(), Equals("Unknown Artist"));
}

TEST_CASE( "Read entry for tracks with nothing", "[Track]") {
    std::istringstream entree{ "      | |   " };
    Track track{};

    entree >> track;

    CHECK_THAT(track.name()  , Equals("Unknown Track") );
    CHECK_THAT(track.album() , Equals("Unknown Album") );
    CHECK_THAT(track.artist(), Equals("Unknown Artist"));
}

TEST_CASE( "string_cleanup", "[utils]") {
    string const input{"      my word   "};
    string output{};

    output = string_cleanup(input);

    CHECK_THAT(output, Equals("my word"));

}