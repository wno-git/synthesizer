#pragma once

#include "generator.hh"
#include "json/src/json.hpp"
#include <string>
#include <iosfwd>
#include <utility>
#include <unordered_map>

namespace syn {

class Track {
public:
    Track();

    bool loadFile(std::istream& input);

    size_t numGenerators() const;
    Generator& getGenerator(const std::string& name);

private:
    std::unordered_map<std::string, Generator> generators;

    void createGenerators(const nlohmann::json& json);
    std::pair<std::string, Generator> createGenerator(
        const nlohmann::json& json);

};

}
