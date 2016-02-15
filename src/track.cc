#include "track.hh"
#include "json/src/json.hpp"
#include <istream>
#include <stdexcept>

using json = nlohmann::json;

syn::Track::Track() {
}

bool syn::Track::loadFile(std::istream& input) {
    json j;
    input >> j;

    return true;
}
