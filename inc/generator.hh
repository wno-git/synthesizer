#pragma once

#include <string>

namespace syn {

class Generator {
public:
    Generator(const std::string& name_);
    virtual ~Generator() {}

    const std::string& getName() const;

private:
    const std::string name;

};

}
