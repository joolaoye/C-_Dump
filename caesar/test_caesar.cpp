#include <iostream>
#include <cassert>
#include "caesar.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("Test Caesar Cipher Encryption", "[rotate]") {
    REQUIRE(rotate("a", 1) == "b");
    REQUIRE(rotate("barfoo", 23) == "yxocll");
    REQUIRE(rotate("BARFOO", 3) == "EDUIRR");
    REQUIRE(rotate("BaRFoo", 4) == "FeVJss");
    REQUIRE(rotate("barfoo", 65) == "onesbb");
    REQUIRE(rotate("world, say hello!", 12) == "iadxp, emk tqxxa!");
}