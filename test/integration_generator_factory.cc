#include "json/src/json.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "generator_factory.hh"

TEST(unit_generator, missing_name) {
    const auto json = "{}"_json;
    ASSERT_THROW(syn::GeneratorFactory::createGenerator(json),
        std::invalid_argument);
}

TEST(unit_generator, missing_type) {
    const auto json = R"(
        {
            "name": "test"
        }
    )"_json;

    ASSERT_THROW(syn::GeneratorFactory::createGenerator(json),
        std::invalid_argument);
}

TEST(unit_generator, unrecognized_type) {
    const auto json = R"(
        {
            "name": "test",
            "type": "invalid"
        }
    )"_json;

    ASSERT_THROW(syn::GeneratorFactory::createGenerator(json),
        std::invalid_argument);
}

TEST(integration_generator_factory, create_sine_generator) {
    const auto json = R"(
        {
            "name": "test",
            "type": "sine",
            "freq": 1000.0
        }
    )"_json;

    auto g = syn::GeneratorFactory::createGenerator(json);

    ASSERT_EQ(g->getType(), syn::Generator::Type::Sine);
}
