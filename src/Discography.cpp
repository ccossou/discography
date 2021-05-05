//
// Created by ccossou on 23/06/2020.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include "Discography.hpp"

using namespace std;

disco::Discography::Discography(vector<Track> tracks) {
    track_list_ = move(tracks);
}

void disco::Discography::to_file(std::string const& filename) {
    std::ofstream out{filename};
    if (not out)
        throw runtime_error("Unable to write to file.");
    else
    {
        for (const auto& track : track_list_) {
            out << track << endl;
        }
        out.close();

        if (not out){
            std::perror("Unable to write to file.");
        }
    }
}

void disco::Discography::from_file(string const& filename) {
    std::ifstream file{filename};
    if (!file)
        throw runtime_error("Unable to open file.");
    else
    {
        //Empty previous discography
        clear();

        string line{};


        while (getline(file, line)) {
            Track track{};

            istringstream flux{line};
            flux >> track;

            push_back(track);

        }
    }
}

void disco::Discography::sort_by_track() {
    std::sort(track_list_.begin(), track_list_.end(),
            [](const Track & a, const Track & b) {
        return a.name() < b.name();
    } );
}

void disco::Discography::sort_by_album() {
    std::sort(track_list_.begin(), track_list_.end(),
              [](const Track & a, const Track & b) {
                  return a.album() < b.album();
              } );
}

void disco::Discography::sort_by_artist() {
    std::sort(track_list_.begin(), track_list_.end(),
              [](const Track & a, const Track & b) {
                  return a.artist() < b.artist();
              } );
}

void disco::Discography::display(DisplayType display_type) {
    switch (display_type)
    {
        case DisplayType::Album:
            this->sort_by_album();
            this->display_albums();
            break;

        case DisplayType::Artist:
            this->sort_by_artist();
            this->display_artists();
            break;

        case DisplayType::Track:
            this->sort_by_track();
            this->display_tracks();
            break;
    }
}

void disco::Discography::push_back(Track& track){
    track_list_.push_back(track);
}

void disco::Discography::clear(){
    track_list_.clear();
}

void disco::Discography::display_tracks() const {
    for (const auto& track : this->track_list_) {
        cout << "--> " << track << endl;
    }
}

void disco::Discography::display_albums() const {
    string tmp_album{};
    string tmp_artist{};
    for (const auto& track : this->track_list_) {
        if ((tmp_album != track.album()) or (tmp_artist != track.artist())) {
            tmp_album = track.album();
            tmp_artist = track.artist();
            cout << "--> ";
            cout << track.album();
            cout << " | ";
            cout << track.artist();
            cout << endl;
        }
        cout << "   /--> " << track.name() << endl;
    }
}

void disco::Discography::display_artists() const {
    string tmp_album{};
    string tmp_artist{};
    for (const auto& track : this->track_list_) {
        if (tmp_artist != track.artist()) {
            tmp_artist = track.artist();
            cout << "--> " << track.artist() << endl;
        }
        if (tmp_album != track.album()) {
            tmp_album = track.album();
            cout << "   /--> " << track.album() << endl;
        }
        cout << "       /--> " << track.name() << endl;
    }
}