//
// Created by ccossou on 23/06/2020.
//

#include "Track.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Track::Track(string name, string artist, string album)
        : name_{name}, artist_{artist}, album_{album}
{}

Track::Track(string name, string artist)
: Track{name, artist, ""}
{}

Track::Track(string name)
: Track{name, "", ""}
{}

Track::Track()
        : Track{"", "", ""}
{}

void Track::display(ostream &flux) const
{
    if (name_.empty()) {
        flux << "Unkown track";
    }
    else {
        flux << name_;
    }

    flux << " | ";

    if (album_.empty()) {
        flux << "Unkown Album";
    }
    else {
        flux << album_;
    }

    flux << " | ";

    if (artist_.empty()) {
        flux << "Unkown Artist";
    }
    else {
        flux << artist_;
    }
}

ostream &operator<<(ostream &flux, Track const& track)
{
    track.display(flux) ;
    return flux;
}

istream &operator>>(istream &entry, Track & track)
{
    string word{};
    ostringstream flux {};

    while (entry >> word && word != "|") {
        flux << word << " ";
    }
    string track_name{flux.str()};
    track_name = string_cleanup(track_name);
    if (track_name.empty()) {
        track_name = "Unknown Track";
    }

    flux.str(string{});
    while (entry >> word && word != "|") {
        flux << word << " ";
    }
    string album_name{flux.str()};
    album_name = string_cleanup(album_name);
    if (album_name.empty()) {
        album_name = "Unknown Album";
    }

    flux.str(string{});
    while (entry >> word && word != "|") {
        flux << word << " ";
    }
    string artist_name{flux.str()};
    artist_name = string_cleanup(artist_name);
    if (artist_name.empty()) {
        artist_name = "Unknown Artist";
    }

    track = Track{track_name, artist_name, album_name};

    return entry;
}

const string &Track::name() const {
    return name_;
}

const string &Track::album() const {
    return album_;
}

const string &Track::artist() const {
    return artist_;
}
