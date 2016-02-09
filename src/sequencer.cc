#include "sequencer.hh"

syn::Sequencer::Sequencer(const int samplerate_):
    samplerate(samplerate_),
    track_length(samplerate_ * 10),
    track_pos(0),
    noise(),
    sine(1000, samplerate_) {
}

bool syn::Sequencer::trackEnd() const {
    return this->track_pos == this->track_length;
}

double syn::Sequencer::nextSample() {
    const auto sample = this->sine();
    ++this->track_pos;
    return sample;
}
