#pragma once

#include "json/src/json.hpp"
#include <string>
#include <memory>
#include <unordered_map>

namespace syn {

class Generator {
public:
    enum class Type {
        Sine
    };

    Generator(const std::string& name_);
    virtual ~Generator() {}

    virtual Type getType() const = 0;

    const std::string& getName() const;

    static std::unique_ptr<Generator> createGenerator(
            const nlohmann::json& json);

private:
    static const std::unordered_map<std::string, Type> type_mapping;

    static Type strToType(const std::string& str);

    const std::string name;

};

}
