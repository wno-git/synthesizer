#pragma once

#include "generator.hh"

#include "json/src/json.hpp"

namespace syn {

class GeneratorSine: public Generator {
public:
    GeneratorSine(const std::string& name_, const nlohmann::json& json);

    Type getType() const override;

    std::vector<double> getBuffer(
        std::size_t clock,
        const long samplerate,
        const std::size_t n_samples) const override;

private:
    double freq;

    void createGenerator(const nlohmann::json& json);

    inline double getSample(
            const std::size_t clock,
            const long samplerate) const;

};

}
