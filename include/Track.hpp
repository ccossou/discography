//
// Created by ccossou on 23/06/2020.
//

#ifndef DISCOGRAPHY_TRACK_HPP
#define DISCOGRAPHY_TRACK_HPP

#include <string>

class Track {

public:

    Track();
    explicit Track(std::string name);
    Track(std::string name, std::string artist);
    Track(std::string name, std::string artist, std::string album);

    void display(std::ostream &flux) const;

    const std::string &name() const;
    const std::string &album() const;
    const std::string &artist() const;

private:
    std::string name_;
    std::string artist_;
    std::string album_;

};

std::ostream &operator<<(std::ostream &flux, Track const& track);
std::istream &operator>>(std::istream &entry, Track & track);

#endif //DISCOGRAPHY_TRACK_HPP
