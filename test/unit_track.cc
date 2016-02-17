#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "track.hh"

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
