#include "json/src/json.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "generator_sine.hh"

TEST(unit_generator_sine, missing_freq) {
    const auto json = "{}"_json;
    ASSERT_THROW(syn::GeneratorSine("g", json), std::invalid_argument);
}

TEST(unit_generator_sine, create) {
    const auto json = R"(
        {
            "freq": 1000.0
        }
    )"_json;
    ASSERT_NO_THROW(syn::GeneratorSine("g", json));
}

TEST(unit_generator_sine, generate_buffer) {
    const auto json = R"(
        {
            "freq": 1000.0
        }
    )"_json;

    syn::GeneratorSine g("g", json);

    const std::size_t clock{};
    const long samplerate {44100};
    const std::size_t n_samples {4410};

    const auto buf = g.getBuffer(clock, samplerate, n_samples);
    ASSERT_EQ(buf.size(), n_samples);
}
