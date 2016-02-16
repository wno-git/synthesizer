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
