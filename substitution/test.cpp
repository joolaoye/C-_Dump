#include <iostream>
#include "substitution.h"
#define CATCH_CONFIG_MAIN
#include  "../catch.hpp"



TEST_CASE("Test Substitution Encryption", "[rotate]"){
    char a[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char b[] = "NJQSUYBRXMOPFTHZVAWCGILKED";
    char c[] = "YUKFRNLBAVMWZTEOGXHCIPJSQD";
    char d[] = "yukfrnlbavmwzteogxhcipjsqd";
    char e[] = "YUKFRNLBAVMWZteogxhcipjsqd";

    REQUIRE(rotate("A", a) == "Z");
    REQUIRE(rotate("a", a) == "z");
    REQUIRE(rotate("ABC", b) == "NJQ");
    REQUIRE(rotate("XyZ", b) == "KeD");
    REQUIRE(rotate("This is CS50", c) == "Cbah ah KH50");
    REQUIRE(rotate("This is CS50", d) == "Cbah ah KH50");
    REQUIRE(rotate("This is CS50", e) == "Cbah ah KH50");
}