#include "generator.hh"

syn::Generator::Generator(const std::string& name_):
    name(name_) {
}

const std::string& syn::Generator::getName() const {
    return this->name;
}

syn::Generator syn::Generator::createGenerator(const nlohmann::json& json) {
    if (!json.count("name")) {
        throw std::invalid_argument("Missing name");
    }

    const std::string name = json["name"];

    if (!json.count("type")) {
        throw std::invalid_argument("Missing type");
    }

    return Generator(name);
}
