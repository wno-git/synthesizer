#pragma once

#include <random>

namespace syn {

class Noise {
public:
    Noise();

    double operator()();

private:
    std::default_random_engine rng;
    std::uniform_real_distribution<> distr;

};

}
