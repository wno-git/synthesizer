#pragma once

#include <string>
#include <iosfwd>

namespace syn {

class Track {
public:
    Track();

    bool loadFile(std::istream& input);

};

}
