#include "generator.hh"

syn::Generator::Generator(const std::string& name_):
    name(name_) {
}

const std::string& syn::Generator::getName() const {
    return this->name;
}
