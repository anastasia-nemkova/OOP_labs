#include <gtest/gtest.h>
#include "../include/BitString.hpp"


TEST(compar, more) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'1', '0', '0', '1'};
    BitString bs3 = {'1', '1', '0', '1'};

    ASSERT_TRUE(bs1 > bs2);
    ASSERT_FALSE(bs2 > bs1);
    ASSERT_FALSE(bs1 > bs3);
    ASSERT_TRUE(bs3 > bs1);
    ASSERT_FALSE(bs2 > bs3);
}

TEST(compar, less) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'1', '0', '0', '1'};
    BitString bs3 = {'1', '1', '0', '1'};

    ASSERT_FALSE(bs1 < bs2);
    ASSERT_TRUE(bs2 < bs1);
    ASSERT_TRUE(bs1 < bs3);
    ASSERT_FALSE(bs3 < bs1);
    ASSERT_TRUE(bs2 < bs3);
}

TEST(compar, moreOrEqual) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'1', '0', '0', '1'};
    BitString bs3 = {'1', '1', '0', '1'};

    ASSERT_TRUE(bs1 >= bs2);
    ASSERT_FALSE(bs2 >= bs1);
    ASSERT_FALSE(bs1 >= bs3);
    ASSERT_TRUE(bs3 >= bs1);
    ASSERT_FALSE(bs2 >= bs3);
    ASSERT_TRUE(bs1 >= bs1);
}

TEST(compar, lessOrEqual) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'1', '0', '0', '1'};
    BitString bs3 = {'1', '1', '0', '1'};

    ASSERT_FALSE(bs1 <= bs2);
    ASSERT_TRUE(bs2 <= bs1);
    ASSERT_TRUE(bs1 <= bs3);
    ASSERT_FALSE(bs3 <= bs1);
    ASSERT_TRUE(bs2 <= bs3);
    ASSERT_TRUE(bs1 <= bs1);
}

TEST(arith, Add) {
    BitString bs1 = {'1', '0', '1'};
    BitString bs2 = {'0', '1', '0'};
    BitString corrrect = {'1', '1', '1'};

    BitString res = bs1 + bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(arith, Add1) {
    BitString bs1 = {'1', '0', '1', '1', '0', '1', '1', '1', '0'};
    BitString bs2 = {'0', '1', '0'};
    BitString corrrect = { '1', '0', '1', '1', '1', '0', '0', '0', '0'};

    BitString res = bs1 + bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(arith, Sub) {
    BitString bs1 = {'1'};
    BitString bs2 = {'0'};
    BitString corrrect = {'1'};

    BitString res = bs1 + bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(arith, Sub1) {
    BitString bs1 = {'1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1'};
    BitString bs2 = {'1', '1', '0', '1', '1', '1', '0', '0', '0', '0'};
    BitString corrrect = { '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '0', '0', '0', '0'};

    BitString res = bs1 - bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(arith, Sub2) {
    BitString bs1 = {'1'};
    BitString bs2 = {'0'};
    BitString corrrect = {'1'};

    BitString res = bs1 + bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(bitOp, AND) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'1', '1', '0', '1'};
    BitString corrrect = {'1', '0', '0', '1'};

    BitString res = bs1 & bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(bitOp, OR) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'0', '1', '0', '0'};
    BitString corrrect = {'1', '1', '1', '1'};

    BitString res = bs1 | bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(bitOp, XOR) {
    BitString bs1 = {'1', '0', '1', '1'};
    BitString bs2 = {'1', '1', '0', '1'};
    BitString corrrect = {'0', '1', '1', '0'};

    BitString res = bs1 ^ bs2;
    ASSERT_TRUE(res == corrrect);
}

TEST(bitOp, NOT) {
    BitString bs = {'1', '0', '1', '0'};
    BitString corrrect = {'0', '1', '0', '1'};
    BitString res = ~bs;
    ASSERT_TRUE(res == corrrect);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}