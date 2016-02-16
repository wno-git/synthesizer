#pragma once

#include "generator.hh"

namespace syn {

class GeneratorSine: public Generator {
public:
    GeneratorSine(const std::string& name_);

    Type getType() const override;

};

}
