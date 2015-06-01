#pragma once

#include <cstdint>
#include <limits>
#include <cmath>

namespace syn {

class Utils {
public:
    Utils() = delete;

    static constexpr double pi2 = 3.1415 * 2.0;

    static std::int16_t dToS16(double i) {
        // TODO: investigate if there's a better way to do this

        i *= std::numeric_limits<std::int16_t>::max();

        return static_cast<std::int16_t> (std::round(i));
    }

};

}