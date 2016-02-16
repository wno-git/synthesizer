#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "generator.hh"

TEST(unit_generator, missing_name) {
    const auto json = "{}"_json;
    ASSERT_THROW(syn::Generator::createGenerator(json), std::invalid_argument);
}
