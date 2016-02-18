#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstddef>
#include <array>
#include <algorithm>
#include "utils.hh"
#include "track.hh"

int main(int argc, char** argv) {
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

    const long samplerate = 44100; // hardcoded for testing
    std::size_t clock = 0;

    while (true) {
        const long buflen = 441; // hardcoded for testing
        const auto buf_d = track.getBuffer(clock, samplerate, buflen);
        std::array<std::int16_t, buflen> buf_i;

        std::transform(buf_d.begin(), buf_d.end(), buf_i.begin(),
            syn::Utils::dToS16);

        std::cout.write(
                reinterpret_cast<const char*> (buf_i.data()),
                sizeof(std::int16_t) * buf_i.size());
    }
}
