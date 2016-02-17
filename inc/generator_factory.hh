#pragma once

#include "json/src/json.hpp"
#include "generator.hh"
#include <unordered_map>
#include <string>
#include <memory>

namespace syn {

class GeneratorFactory {
public:
    virtual ~GeneratorFactory() {}

    static std::unique_ptr<Generator> createGenerator(
            const nlohmann::json& json);

private:
    static const std::unordered_map<std::string, Generator::Type>
        type_mapping;

    static Generator::Type strToType(const std::string& str);

};

}
