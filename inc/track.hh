#pragma once

#include <string>
#include <cstdint>

namespace syn {

class Track {
public:
    Track();

    bool hasTrigger(const uint32_t time);

private:
    std::string notes;

};

}
