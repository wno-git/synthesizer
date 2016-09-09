#pragma once

#include "generator.hh"
#include "json/src/json.hpp"

#include <iosfwd>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace syn {

class Track {
public:
    Track();

    bool loadFile(std::istream& input);

    size_t numGenerators() const;
    Generator& getGenerator(const std::string& name);

    std::vector<double> getBuffer(
            const std::size_t clock,
            const long samplerate,
            const std::size_t n_samples) const;

    const std::string& getMixerInput(size_t index) const;
    double getMixerLevel(size_t index) const;
    size_t mixerInputCount() const;

private:
    std::unordered_map<std::string, std::unique_ptr<Generator>> generators;

    std::vector<std::pair<std::string, double>> mixer;

    void createGenerators(const nlohmann::json& json);
    std::pair<std::string, Generator> createGenerator(
        const nlohmann::json& json);

    void loadMixer(const nlohmann::json& json);
    static std::pair<std::string, double> createMixerInput(
        const nlohmann::json& json);

};

}
