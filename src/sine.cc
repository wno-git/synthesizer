#include "sine.hh"
#include "utils.hh"

#include <cmath>

syn::Sine::Sine(const double freq_, const int samplerate_):
    freq(freq_),
    phase(0),
    samplerate(samplerate_){
}

double syn::Sine::operator()() {
    const auto s = static_cast<double> (samplerate - 1);
    const auto p = static_cast<double> (phase);
    const auto t = p / s;

    const auto out = std::sin(syn::Utils::pi2 * freq * t);

    ++phase;
    phase %= samplerate;

    return out;
}
