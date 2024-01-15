#include "../catch.hpp"
#include "karatsuba.h"
#define CATCH_CONFIG_MAIN


TEST_CASE("Check if Karatsuba is correct", "[karatsuba_mult]"){
    REQUIRE(karatsuba_mult(12345, 123) == 1518435);
    REQUIRE(karatsuba_mult(5678, 1234) == 7006652);
    REQUIRE(karatsuba_mult(5, 11) == 5);
    REQUIRE(karatsuba_mult(0, 123) == 0);
    REQUIRE(karatsuba_mult(99999, 2) == 199998);
}