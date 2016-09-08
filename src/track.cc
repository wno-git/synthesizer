#include "track.hh"
#include "generator_factory.hh"
#include <istream>
#include <stdexcept>
#include <algorithm>

syn::Track::Track() {
}

bool syn::Track::loadFile(std::istream& input) {
    nlohmann::json json;
    input >> json;

    createGenerators(json);

    try {
        loadMixer(json);
    } catch (const std::exception& e) {
        throw std::invalid_argument(
            std::string("Could not initialize mixer: ") + e.what());
    }

    return true;
}

size_t syn::Track::numGenerators() const {
    return this->generators.size();
}

syn::Generator& syn::Track::getGenerator(const std::string& name) {
    return *generators.at(name);
}

void syn::Track::createGenerators(const nlohmann::json& json) {
    const auto& generator_list = json.find("generators");

    if (generator_list == json.end()) {
        return;
    }

    std::for_each(generator_list->begin(), generator_list->end(),
        [this] (const nlohmann::json& json) {
            auto g = GeneratorFactory::createGenerator(json);
            this->generators.emplace(g->getName(), std::move(g));
        });
}

void syn::Track::loadMixer(const nlohmann::json& json) {
    const auto& mixer_inputs = json.find("mixer");

    if (mixer_inputs == json.end()) {
        return;
    }

    for (const auto& input : *mixer_inputs) {
        this->mixer.emplace_back(createMixerInput(input));
    }
}

std::pair<std::string, double> syn::Track::createMixerInput(
        const nlohmann::json& json) {
    return {
        json.at("in").get<std::string>(),
        json.at("level")
    };
}

const std::string& syn::Track::getMixerInput(size_t index) const {
    return this->mixer.at(index).first;
}

double syn::Track::getMixerLevel(size_t index) const {
    return this->mixer.at(index).second;
}

size_t syn::Track::mixerInputCount() const {
    return this->mixer.size();
}

std::vector<double> syn::Track::getBuffer(
        const std::size_t clock,
        const long samplerate,
        const std::size_t n_samples) const {
    std::vector<double> out(n_samples);

    std::for_each(generators.begin(), generators.end(),
        [&] (auto& g) {
            const auto buf = g.second->getBuffer(clock, samplerate, n_samples);
            std::transform(out.begin(), out.end(), buf.begin(),
                out.begin(),
                [] (auto& a, auto& b) {
                    return a + b;
                });
        });

    return out;
}
