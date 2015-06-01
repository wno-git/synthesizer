#include <iostream>
#include <cstdint>
#include "utils.hh"
#include "noise.hh"
#include "sine.hh"

int main(int argc, char** argv) {
    const int samplerate = 44100;
    syn::Noise noise;
    syn::Sine sine(1000, samplerate);

    for (;;) {
        const auto i = syn::Utils::dToS16(sine());
        std::cout.write(
                reinterpret_cast<const char*> (&i),
                sizeof(std::int16_t));
    }
}
