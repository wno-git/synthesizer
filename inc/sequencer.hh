#pragma once

#include "noise.hh"
#include "sine.hh"

namespace syn {

class Sequencer {
public:
    Sequencer(const int samplerate_);

    bool trackEnd() const;
    double nextSample();

    bool loadSong(const std::string& song);

private:
    const int samplerate;
    const int track_length;
    int track_pos;

    syn::Noise noise;
    syn::Sine sine;

};

}
