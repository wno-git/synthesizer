#pragma once

#include <string>
#include <istream>

namespace syn {

class Track {
public:
    Track();

    bool loadFile(std::istream& input);

};

}
