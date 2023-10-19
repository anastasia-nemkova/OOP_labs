#include <gtest/gtest.h>

#include "point.hpp"
#include "figure.hpp"
#include "octagon.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include <sstream>


TEST(pentagon, square) {
    std::stringstream ss;
    ss << "-2 0\n-1 2\n1 2\n2 0\n0 -2\n";
    //Pentagon p(ss);
    Figure *fig = new Pentagon(ss);
    EXPECT_EQ(fig->Square(), 10);
    //EXPECT_EQ(p.Square(), 10);
}

TEST(pentagon1, square1) {
    //std::stringstream ss;
    //ss << "-2 0\n-1 2\n1 2\n2 0\n0 -2\n";
    Pentagon p(Point(-2, 0), Point(-1, 2), Point(1, 2), Point(2, 0), Point(0, -2));
    //Figure *fig = new Pentagon(ss);
    //EXPECT_EQ(fig->Square(), 10);
    EXPECT_EQ(p.Square(), 10);
}

TEST(pentagon, copy) {
    std::stringstream ss;
    ss << "2 0\n1 3\n2 4\n-1 0\n2 0\n";
    Pentagon p(ss);
    Pentagon p1(p);

    EXPECT_TRUE(p == p1);
}

TEST(hexagon, center) {
    std::stringstream ss;
    ss << "0 0\n1 1\n2 1\n3 0\n2 -1\n1 -1\n";
    Hexagon h(ss);

    EXPECT_EQ(h.Center().getX(), 1.5);
    EXPECT_EQ(h.Center().getY(), 0);
}

TEST(hexagon, eqval) {
    std::stringstream ss;
    ss << "0 0\n1 1\n2 1\n3 0\n2 -1\n1 -1\n";
    Hexagon h(ss);
    ss <<"1 1\n-1 0\n2 0\n0 1\n2 1\2 -1\n";
    Hexagon h1(ss);

    EXPECT_FALSE(h == h1);
}

TEST(hexagon, move) {
    std::stringstream ss;
    ss << "0 0\n1 1\n2 1\n3 0\n2 -1\n1 -1\n";
    Hexagon h(ss);
    Hexagon h1 = std::move(h);

    EXPECT_TRUE(h == h1);
}

TEST(octagon, square) {
    std::stringstream ss;
    ss << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    Octagon o(ss);

    EXPECT_EQ(o.Square(), 13);
}

TEST(octagon, center) {
    std::stringstream ss;
    ss << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    Octagon o(ss);

    EXPECT_EQ(o.Center().getX(), 2.75);
    EXPECT_EQ(o.Center().getY(), 2.5);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}