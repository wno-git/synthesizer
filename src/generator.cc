#include "generator.hh"
#include "generator_sine.hh"

const std::unordered_map<std::string, syn::Generator::Type>
        syn::Generator::type_mapping {
    {"sine", syn::Generator::Type::Sine}
};

syn::Generator::Generator(const std::string& name_):
    name(name_) {
}

const std::string& syn::Generator::getName() const {
    return this->name;
}

std::unique_ptr<syn::Generator> syn::Generator::createGenerator(
        const nlohmann::json& json) {
    if (!json.count("name")) {
        throw std::invalid_argument("Missing name");
    }

    const std::string name = json["name"];

    if (!json.count("type")) {
        throw std::invalid_argument("Missing type");
    }

    const std::string type_str = json["type"];

    Type type{};
    try {
        type = strToType(type_str);
    } catch (const std::out_of_range& e) {
        throw std::invalid_argument("Unrecognized type");
    }

    switch (type) {
    case Type::Sine:
        return std::make_unique<GeneratorSine> (name);
    default:
        throw std::invalid_argument("Unsupported type");
    }

}

syn::Generator::Type syn::Generator::strToType(const std::string& str) {
    return type_mapping.at(str);
}
