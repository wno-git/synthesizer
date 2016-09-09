#include "generator_sine.hh"
#include "utils.hh"

#include <algorithm>
#include <cmath>
#include <stdexcept>

syn::GeneratorSine::GeneratorSine(const std::string& name_,
        const nlohmann::json& json):
        Generator(name_),
        freq{} {
    createGenerator(json);
}

syn::GeneratorSine::Type syn::GeneratorSine::getType() const {
    return Type::Sine;
}

void syn::GeneratorSine::createGenerator(const nlohmann::json& json) {
    if (!json.count("freq")) {
        throw std::invalid_argument("Missing freq");
    }

    this->freq = json["freq"];
}

std::vector<double> syn::GeneratorSine::getBuffer(
        std::size_t clock,
        const long samplerate,
        const std::size_t n_samples) const {
    std::vector<double> buf(n_samples);

    std::generate(buf.begin(), buf.end(), [this, &clock, &samplerate] {
        return this->getSample(clock++, samplerate);
    });

    return buf;
}

double syn::GeneratorSine::getSample(
        const std::size_t clock,
        const long samplerate) const {
    const auto s = static_cast<double> (samplerate - 1);
    const auto p = static_cast<double> (clock);
    const auto t = p / s;

    return std::sin(syn::Utils::pi2 * this->freq * t);
}
