#include <gtest/gtest.h>
#include <sstream>

#include "track.hh"

TEST(unit_track, load_empty_track) {
    std::istringstream json("{}");

    syn::Track track;
    EXPECT_TRUE(track.loadFile(json));
}
