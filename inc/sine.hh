#pragma once

namespace syn {

class Sine {
public:
    Sine(const double freq_, const int samplerate_);

    double operator()();

private:
    const double freq;
    int phase;
    int samplerate;

};

}

