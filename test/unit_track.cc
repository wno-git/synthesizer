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

TEST(unit_track, load_generators) {
    std::istringstream json(R"(
        {
            "generators": [
                {
                    "name": "g1"
                },
                {
                    "name": "g2"
                }
            ]
        }
    )");

    syn::Track track;
    track.loadFile(json);

    ASSERT_EQ(track.numGenerators(), 2);

    ASSERT_NO_THROW(track.getGenerator("g1"));
    ASSERT_NO_THROW(track.getGenerator("g2"));

    ASSERT_EQ(track.getGenerator("g1").getName(), "g1");
    ASSERT_EQ(track.getGenerator("g2").getName(), "g2");
}
