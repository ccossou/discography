//
// Created by ccossou on 23/06/2020.
//

#ifndef DISCOGRAPHIE_DISCOGRAPHY_HPP
#define DISCOGRAPHIE_DISCOGRAPHY_HPP

#include <fstream>
#include <vector>
#include "Track.hpp"

namespace disco{

enum class DisplayType {Track, Artist, Album};


class Discography {

public:

    explicit Discography(std::vector<Track> tracks);

    void to_file(std::string const& filename);
    void from_file(std::string const& filename);

    void display(DisplayType display_type);

    void push_back(Track& track);
    void clear();

    void display_tracks() const;
    void display_albums() const;
    void display_artists() const;

    void sort_by_track();
    void sort_by_album();
    void sort_by_artist();


private:
    std::vector<Track> track_list_;

};

} // namespace disco
#endif //DISCOGRAPHIE_DISCOGRAPHY_HPP
