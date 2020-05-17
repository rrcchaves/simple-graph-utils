#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "base/simplevertex.h"

TEST_CASE("Creating vertex from scratch", "[SimpleVertex]") {
    sg::SimpleVertex v1(3, "A", 2);
    REQUIRE(v1.id() == 3);
    REQUIRE(v1.name() == "A");
    REQUIRE(v1.name() != "a");
    REQUIRE(v1.weight() == 2);
    
    sg::SimpleVertex v2(5, "B");
    REQUIRE(v2.id() == 5);
    REQUIRE(v2.name() == "B");
    REQUIRE(v2.name() != "b");
    REQUIRE(v2.weight() == 0);
}

TEST_CASE("Creating vertex from another vertex", "[SimpleVertex]") {
    sg::SimpleVertex v1(7, "C", 4);
    sg::SimpleVertex v2(v1);
    sg::SimpleVertex v3 = v1;
    REQUIRE(v1 == v2);
    REQUIRE(v1 == v3);
    REQUIRE(v2 == v3);
}

TEST_CASE("Swapping vertices", "[SimpleVertex]") {
    sg::SimpleVertex v1(9, "D", 3);
    sg::SimpleVertex v2(1, "E");
    v1.swap(v2);
    REQUIRE(v1.id() == 1);
    REQUIRE(v1.name() == "E");
    REQUIRE(v1.name() != "e");
    REQUIRE(v1.weight() == 0);
    REQUIRE(v2.id() == 9);
    REQUIRE(v2.name() == "D");
    REQUIRE(v2.name() != "d");
    REQUIRE(v2.weight() == 3);
}

TEST_CASE("Changing vertex weight", "[SimpleVertex]") {
    sg::SimpleVertex v1(11, "F");
    REQUIRE(v1.id() == 11);
    REQUIRE(v1.name() == "F");
    REQUIRE(v1.name() != "f");
    REQUIRE(v1.weight() == 0);
    v1.set_weight(6);
    REQUIRE(v1.id() == 11);
    REQUIRE(v1.name() == "F");
    REQUIRE(v1.name() != "f");
    REQUIRE(v1.weight() == 6);
}

TEST_CASE("Checking print internal state", "[SimpleVertex]") {
    sg::SimpleVertex v1(13, "G", 8);
    std::ostringstream out1;
    v1.print(out1);
    REQUIRE(out1.str() == "{ id: 13, name: \"G\", weight: 8 }");
    sg::SimpleVertex v2(17, "H");
    std::ostringstream out2;
    v2.print(out2);
    REQUIRE(out2.str() == "{ id: 17, name: \"H\", weight: 0 }");
}

