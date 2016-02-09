#include <iostream>
#include <fstream>
#include <cstdint>
#include "utils.hh"
#include "sequencer.hh"
#include "track.hh"

int main(int argc, char** argv) {
    const int samplerate = 44100;
    syn::Sequencer sequencer(samplerate);

    if (argc != 2) {
        std::cerr << "Invalid arguments" << std::endl;
        return 1;
    }

    auto track_file = argv[1];

    std::cerr << "Loading track " << track_file << std::endl;

    std::fstream track_io {track_file, std::ios_base::in};

    syn::Track track;
    if (!track.loadFile(track_io)) {
        std::cerr << "Failed to load track " << track_file << std::endl;
        return 1;
    }

    while (!sequencer.trackEnd()) {
        const auto sample = sequencer.nextSample();
        const auto out = syn::Utils::dToS16(sample);
        std::cout.write(
                reinterpret_cast<const char*> (&out),
                sizeof(std::int16_t));
    }
}
