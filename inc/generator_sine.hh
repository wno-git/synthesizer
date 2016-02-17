#pragma once

#include "json/src/json.hpp"
#include "generator.hh"

namespace syn {

class GeneratorSine: public Generator {
public:
    GeneratorSine(const std::string& name_, const nlohmann::json& json);

    Type getType() const override;

    std::vector<double> getBuffer(
        const std::size_t clock,
        const long samplerate,
        const std::size_t n_samples) const override;

private:
    float freq;

    void createGenerator(const nlohmann::json& json);

};

}
