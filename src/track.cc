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
