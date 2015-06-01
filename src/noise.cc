#include "noise.hh"

syn::Noise::Noise():
    rng(),
    distr() {
}

double syn::Noise::operator()() {
    return this->distr(this->rng);
}
