#pragma once

#include "generator.hh"
#include "json/src/json.hpp"

#include <memory>
#include <string>
#include <unordered_map>

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
