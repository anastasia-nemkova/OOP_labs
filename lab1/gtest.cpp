#include <gtest/gtest.h>
#include "lab1.hpp"

TEST(test1, symbols) {
    std::string s = "Vader said: No, I am your father!";
    int n = 2;
    char oldValue = 'a';
    char newValue = 'o';
    ASSERT_TRUE(symbolsChange(s, n, oldValue, newValue) == "Vader soid: No, I am your fother!");
}

TEST(test2, symbols) {
    std::string s = " ";
    int n = 2;
    char oldValue = 'a';
    char newValue = 'o';
    ASSERT_TRUE(symbolsChange(s, n, oldValue, newValue) == " ");
}

TEST(test3, symbols) {
    std::string s = "Hufgdj Hf kf ghffdff";
    int n = 3;
    char oldValue = 'f';
    char newValue = 'p';
    ASSERT_TRUE(symbolsChange(s, n, oldValue, newValue) == "Hufgdj Hf kp ghffdpf");
}

TEST(test4, symbols) {
    std::string s = "Vader said: No, I am your father!";
    int n = -2;
    char oldValue = 'a';
    char newValue = 'o';
    ASSERT_FALSE(symbolsChange(s, n, oldValue, newValue) == "Vader soid: No, I am your fother!");
}

TEST(test5, symbols) {
    std::string s = "abc abc abc abc";
    int n = 13;
    char oldValue = 'b';
    char newValue = 'c';
    ASSERT_TRUE(symbolsChange(s, n, oldValue, newValue) == "abc abc abc abc");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}