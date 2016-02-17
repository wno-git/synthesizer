#include "generator_factory.hh"
#include "generator_sine.hh"

const std::unordered_map<std::string, syn::Generator::Type>
        syn::GeneratorFactory::type_mapping {
    {"sine", syn::Generator::Type::Sine}
};

std::unique_ptr<syn::Generator> syn::GeneratorFactory::createGenerator(
        const nlohmann::json& json) {
    if (!json.count("name")) {
        throw std::invalid_argument("Missing name");
    }

    const std::string name = json["name"];

    if (!json.count("type")) {
        throw std::invalid_argument("Missing type");
    }

    const std::string type_str = json["type"];

    Generator::Type type{};
    try {
        type = strToType(type_str);
    } catch (const std::out_of_range& e) {
        throw std::invalid_argument("Unrecognized type");
    }

    switch (type) {
    case Generator::Type::Sine:
        return std::make_unique<GeneratorSine> (name, json);
    default:
        throw std::invalid_argument("Unsupported type");
    }

}

syn::Generator::Type syn::GeneratorFactory::strToType(const std::string& str) {
    return type_mapping.at(str);
}
