#include "generator_sine.hh"

syn::GeneratorSine::GeneratorSine(const std::string& name_):
        Generator(name_) {
}

syn::GeneratorSine::Type syn::GeneratorSine::getType() const {
    return Type::Sine;
}
