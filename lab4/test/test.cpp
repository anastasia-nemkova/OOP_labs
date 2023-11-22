#include <gtest/gtest.h>

#include "../include/figures.hpp"
#include <sstream>

TEST(PentagonTest, Square) {
    std::stringstream ss;
    ss << "-2 0\n-1 2\n1 2\n2 0\n0 -2\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Pentagon<double> p(points);
    EXPECT_EQ(p.Square(), 10.0);
}

TEST(PentagonTest, Copy) {
    std::stringstream ss;
    ss << "2 0\n1 3\n2 4\n-1 0\n2 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Pentagon<double> p(points);
    Pentagon<double> p1;
    p1 = p;
    EXPECT_TRUE(p == p1);
}

TEST(HexagonTest, Center) {
    std::stringstream ss;
    ss << "0 0\n1 1\n2 1\n3 0\n2 -1\n1 -1\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Hexagon<double> h(points);
    EXPECT_EQ(h.Center().first, 1.5);
    EXPECT_EQ(h.Center().second, 0.0);
}

TEST(HexagonTest, Equality) {
    std::stringstream ss1;
    ss1 << "0 0\n1 1\n2 1\n3 0\n2 -1\n1 -1\n";
    std::vector<std::pair<double, double>> points1;
    double x, y;
    while (ss1 >> x >> y) {
        points1.emplace_back(x, y);
    }
    Hexagon<double> h1(points1);

    std::stringstream ss2;
    ss2 << "1 1\n-1 0\n2 0\n0 1\n2 1\n2 -1\n";
    std::vector<std::pair<double, double>> points2;
    while (ss2 >> x >> y) {
        points2.emplace_back(x, y);
    }
    Hexagon<double> h2(points2);

    EXPECT_FALSE(h1 == h2);
}

TEST(OctagonTest, Square) {
    std::stringstream ss;
    ss << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Octagon<double> o(points);
    EXPECT_EQ(o.Square(), 13.0);
}

TEST(OctagonTest, Center) {
    std::stringstream ss;
    ss << "0 1\n1 3\n2 2\n3 4\n4 5\n5 3\n6 2\n1 0\n";
    std::vector<std::pair<double, double>> points;
    double x, y;
    while (ss >> x >> y) {
        points.emplace_back(x, y);
    }
    Octagon<double> o(points);
    EXPECT_EQ(o.Center().first, 2.75);
    EXPECT_EQ(o.Center().second, 2.5);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}