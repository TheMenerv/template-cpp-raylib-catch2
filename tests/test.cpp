#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "../src/addition.h"

TEST_CASE("Addition", "[addition]") {
    REQUIRE(add(2, 2) == 4);
}