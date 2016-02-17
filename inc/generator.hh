#pragma once

#include <string>
#include <memory>

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

private:
    const std::string name;

};

}
