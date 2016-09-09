#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace syn {

class Generator {
public:
    enum class Type {
        Sine
    };

    Generator(const std::string& name_);
    virtual ~Generator() {}

    virtual Type getType() const = 0;

    virtual std::vector<double> getBuffer(
        std::size_t clock,
        const long samplerate,
        const std::size_t n_samples) const = 0;

    const std::string& getName() const;

private:
    const std::string name;

};

}
