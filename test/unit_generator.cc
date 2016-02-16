#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "generator.hh"

TEST(unit_generator, missing_name) {
    const auto json = "{}"_json;
    ASSERT_THROW(syn::Generator::createGenerator(json), std::invalid_argument);
}

TEST(unit_generator, missing_type) {
    const auto json = R"(
        {
            "name": "test"
        }
    )"_json;

    ASSERT_THROW(syn::Generator::createGenerator(json), std::invalid_argument);
}

TEST(unit_generator, unrecognized_type) {
    const auto json = R"(
        {
            "name": "test",
            "type": "invalid"
        }
    )"_json;

    ASSERT_THROW(syn::Generator::createGenerator(json), std::invalid_argument);
}

TEST(unit_generator, create_sine_generator) {
    const auto json = R"(
        {
            "name": "test",
            "type": "sine"
        }
    )"_json;

    auto g = syn::Generator::createGenerator(json);

    ASSERT_EQ(g->getType(), syn::Generator::Type::Sine);
}
