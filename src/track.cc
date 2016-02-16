#include "track.hh"
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
    return generators.at(name);
}

void syn::Track::createGenerators(const nlohmann::json& json) {
    const auto& generator_list = json.find("generators");

    if (generator_list == json.end()) {
        return;
    }

    std::for_each(generator_list->begin(), generator_list->end(),
        [this] (const nlohmann::json& json) {
            auto g = Generator::createGenerator(json);
            this->generators.emplace(g.getName(), g);
        });
}
