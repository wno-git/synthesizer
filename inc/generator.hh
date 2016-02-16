#pragma once

#include "json/src/json.hpp"
#include <string>

namespace syn {

class Generator {
public:
    Generator(const std::string& name_);
    virtual ~Generator() {}

    const std::string& getName() const;

    static Generator createGenerator(const nlohmann::json& json);

private:
    const std::string name;

};

}
