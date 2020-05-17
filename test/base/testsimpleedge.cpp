#include "catch.hpp"

#include "base/simpleedge.h"

TEST_CASE("Creating edge from scratch", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    REQUIRE(e1.id() == 1);
    REQUIRE(e1.end1() == v1);
    REQUIRE(e1.end1() != v2);
    REQUIRE(e1.end2() == v2);
    REQUIRE(e1.end2() != v1);
    REQUIRE(e1.weight() == 5);
    REQUIRE(e1.flag() == 0x06);
    sg::SimpleVertex v3(3, "C", 7, 0x08);
    REQUIRE_THROWS_WITH(sg::SimpleEdge(2, v3, v3, 9, 0x0A), "SimpleEdge: edge with same ends is not allowed.");
}

TEST_CASE("Creating edge from another edge", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    sg::SimpleEdge e2(e1);
    sg::SimpleEdge e3 = e2;
    REQUIRE(e1 == e2);
    REQUIRE(e2 == e3);
    REQUIRE(e1 == e3);
}

TEST_CASE("Swapping edges", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    sg::SimpleVertex v3(3, "C", 11);
    sg::SimpleVertex v4(4, "D", 7, 0x08);
    sg::SimpleEdge e2(2, v3, v4, 9, 0x0A);
    e1.swap(e2);
    REQUIRE(e1.id() == 2);
    REQUIRE(e1.end1() == v3);
    REQUIRE(e1.end2() == v4);
    REQUIRE(e1.weight() == 9);
    REQUIRE(e1.flag() == 0x0A);
    REQUIRE(e2.id() == 1);
    REQUIRE(e2.end1() == v1);
    REQUIRE(e2.end2() == v2);
    REQUIRE(e2.weight() == 5);
    REQUIRE(e2.flag() == 0x06);
}

TEST_CASE("Swapping endpoints' order", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    sg::SimpleEdge e2(1, v2, v1, 5, 0x06);
    REQUIRE(e1 == e2);
    sg::SimpleEdge e3(2, v2, v1, 5, 0x06);
    REQUIRE(e1 == e3);
    sg::SimpleEdge e4(1, v2, v1, 8, 0x06);
    REQUIRE(e1 != e4);
    sg::SimpleEdge e5(1, v2, v1, 5, 0x09);
    REQUIRE(e1 != e5);
}

TEST_CASE("Changing just the edge id", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    sg::SimpleEdge e2(2, v1, v2, 5, 0x06);
    sg::SimpleEdge e3(3, v2, v1, 5, 0x06);
    REQUIRE(e1 == e2);
    REQUIRE(e2 == e3);
    REQUIRE(e1 == e3);
}

TEST_CASE("Changing just the edge weight", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    REQUIRE(e1.id() == 1);
    REQUIRE(e1.end1() == v1);
    REQUIRE(e1.end1() != v2);
    REQUIRE(e1.end2() == v2);
    REQUIRE(e1.end2() != v1);
    REQUIRE(e1.weight() == 5);
    REQUIRE(e1.flag() == 0x06);
    e1.set_weight(13);
    REQUIRE(e1.id() == 1);
    REQUIRE(e1.end1() == v1);
    REQUIRE(e1.end1() != v2);
    REQUIRE(e1.end2() == v2);
    REQUIRE(e1.end2() != v1);
    REQUIRE(e1.weight() == 13);
    REQUIRE(e1.flag() == 0x06);
}

TEST_CASE("Changing just the edge flag", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    REQUIRE(e1.id() == 1);
    REQUIRE(e1.end1() == v1);
    REQUIRE(e1.end1() != v2);
    REQUIRE(e1.end2() == v2);
    REQUIRE(e1.end2() != v1);
    REQUIRE(e1.weight() == 5);
    REQUIRE(e1.flag() == 0x06);
    e1.set_flag(0xCA);
    REQUIRE(e1.id() == 1);
    REQUIRE(e1.end1() == v1);
    REQUIRE(e1.end1() != v2);
    REQUIRE(e1.end2() == v2);
    REQUIRE(e1.end2() != v1);
    REQUIRE(e1.weight() == 5);
    REQUIRE(e1.flag() == 0xCA);
}

TEST_CASE("Checking print internal state of an edge", "[SimpleEdge]") {
    sg::SimpleVertex v1(1, "A");
    sg::SimpleVertex v2(2, "B", 3, 0x04);
    sg::SimpleEdge e1(1, v1, v2, 5, 0x06);
    std::ostringstream out1;
    e1.print(out1);
    REQUIRE(out1.str() == "{ id: 1, end1: { id: 1, name: \"A\", weight: 0, flag: 0x00 }, end2: { id: 2, name: \"B\", weight: 3, flag: 0x04 }, weight: 5, flag: 0x06 }");
}


