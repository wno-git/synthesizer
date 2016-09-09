#include "track.hh"

#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>


TEST(unit_track, load_empty_track) {
    std::istringstream json("{}");

    syn::Track track;
    ASSERT_TRUE(track.loadFile(json));
}

TEST(unit_track, load_bad_json) {
    std::istringstream json("{");

    syn::Track track;
    ASSERT_THROW(track.loadFile(json), std::invalid_argument);
}

TEST(unit_track, generate_buffer) {
    std::istringstream json("{}");

    syn::Track track;
    track.loadFile(json);

    const std::size_t buf_len = 4410;
    const auto buf = track.getBuffer(0, 44100, buf_len);
    ASSERT_EQ(buf.size(), buf_len);
}

TEST(unit_track, load_mixer_empty) {
    std::istringstream json(R"(
        {
            "mixer": [
            ]
        }
    )");

    syn::Track track;
    track.loadFile(json);
}

TEST(unit_track, load_mixer_two_inputs) {
    std::istringstream json(R"(
        {
            "mixer": [
                {
                    "in": "foo",
                    "level": 0.1
                },
                {
                    "in": "bar",
                    "level": 0.2
                }
            ]
        }
    )");

    syn::Track track;
    track.loadFile(json);

    ASSERT_EQ(track.mixerInputCount(), 2);

    ASSERT_EQ(track.getMixerInput(0), "foo");
    ASSERT_EQ(track.getMixerLevel(0), 0.1);

    ASSERT_EQ(track.getMixerInput(1), "bar");
    ASSERT_EQ(track.getMixerLevel(1), 0.2);
}

TEST(unit_track, load_mixer_bad_level) {
    std::istringstream json(R"(
        {
            "mixer": [
                {
                    "in": "foo",
                    "level": "bar"
                }
            ]
        }
    )");

    syn::Track track;

    ASSERT_THROW(track.loadFile(json), std::invalid_argument);
}
