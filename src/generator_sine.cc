#include "generator_sine.hh"
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
