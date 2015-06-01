#pragma once

namespace syn {

class Clock {
public:
    Clock();

    double steps();

private:
    std::chrono::steady_clock clock;
    std::chrono::time_point time_last;

};

}
