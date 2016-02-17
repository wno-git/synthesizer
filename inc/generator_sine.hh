#pragma once

#include "json/src/json.hpp"
#include "generator.hh"

namespace syn {

class GeneratorSine: public Generator {
public:
    GeneratorSine(const std::string& name_, const nlohmann::json& json);

    Type getType() const override;

private:
    float freq;

    void createGenerator(const nlohmann::json& json);

};

}
