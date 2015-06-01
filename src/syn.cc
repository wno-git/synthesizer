#include <iostream>
#include <cstdint>
#include "utils.hh"
#include "sequencer.hh"

int main(int argc, char** argv) {
    const int samplerate = 44100;
    syn::Sequencer sequencer(samplerate);

    while (!sequencer.trackEnd()) {
        const auto sample = sequencer.nextSample();
        const auto out = syn::Utils::dToS16(sample);
        std::cout.write(
                reinterpret_cast<const char*> (&out),
                sizeof(std::int16_t));
    }
}
