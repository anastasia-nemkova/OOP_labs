#include <gtest/gtest.h>

#include "/home/arnemkova/OOP_labs/lab5/list/list.hpp"

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

TEST(MapTest, MapKey) {
    std::map<int, int, std::less<int>, allocators::Allocator<std::pair<const int, int>, 10>> my_map;

    for (int i = 0; i < 10; ++i) {
        my_map[i] = factorial(i);
    }

    EXPECT_EQ(my_map.size(), 10);

    int i = 0;
    for (const auto& pair : my_map) {
        EXPECT_EQ(pair.first, i);
        EXPECT_EQ(pair.second, factorial(i));
        ++i;
    }
}

TEST(Iterator, DereferenceOperator) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(10);

    auto it = my_list.begin();
    
    EXPECT_EQ(*it, 10);
}

TEST(Iterator, ArrowOperatorWithCustomType) {
    lists::List<std::pair<const int, int>, allocators::Allocator<std::pair<const int, int>, 10>> my_list;
    my_list.push_back(std::make_pair(42, 99));

    auto it = my_list.begin();
    EXPECT_EQ(it->first, 42); 
    EXPECT_EQ(it->second, 99); 
}

TEST(Iterator, IncrementOperator) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(30);
    my_list.push_back(40);

    auto it = my_list.begin();
    
    EXPECT_EQ(*it, 30);
    
    ++it;
    
    EXPECT_EQ(*it, 40);
}

TEST(Iterator, PostIncrementOperator) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(50);
    my_list.push_back(60);

    auto it = my_list.begin();
    auto old_it = it++;
    
    EXPECT_EQ(*old_it, 50);
    EXPECT_EQ(*it, 60);
}

TEST(Iterator, Equality) {

    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;
    my_list.push_back(50);

    auto it1 = my_list.begin();
    auto it2 = my_list.begin();

    EXPECT_TRUE(it1 == it2); 
    ++it2;

    EXPECT_FALSE(it1 == it2); 
}

TEST(Iterator, Inequality) {

    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;
    my_list.push_back(60);

    auto it1 = my_list.begin();
    auto it2 = my_list.begin();

    EXPECT_FALSE(it1 != it2);
}

TEST(ListFunctional, ListPushBack) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    for (int i = 0; i < 10; ++i) {
        my_list.push_back(i);
    }

    EXPECT_EQ(my_list.length(), 10);

    int i = 0;
    for (const auto& value : my_list) {
        EXPECT_EQ(value, i++);
    }
}

TEST(ListFunctional, ConstBeginAndConstEnd) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    const auto& constList = my_list;
    auto itBegin = constList.cbegin();
    auto itEnd = constList.cend();

    EXPECT_EQ(itBegin, itEnd); 
    my_list.push_back(10);
    my_list.push_back(20);

    itBegin = constList.cbegin();
    itEnd = constList.cend();

    EXPECT_NE(itBegin, itEnd); 
    EXPECT_EQ(*itBegin, 10);  
}

TEST(ListFunctional, PushBack) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(10);
    my_list.push_back(20);

    EXPECT_EQ(my_list.length(), 2);
    EXPECT_EQ(my_list.front(), 10);
    EXPECT_EQ(my_list.back(), 20);
}

TEST(ListFunctional, PushFront) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_front(30);
    my_list.push_front(40);

    EXPECT_EQ(my_list.length(), 2);
    EXPECT_EQ(my_list.front(), 40);
    EXPECT_EQ(my_list.back(), 30);
}

TEST(ListFunctional, PopBack) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(50);
    my_list.push_back(60);
    my_list.pop_back();

    EXPECT_EQ(my_list.length(), 1);
    EXPECT_EQ(my_list.front(), 50);
    EXPECT_EQ(my_list.back(), 50);
}

TEST(ListFunctional, PopFront) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(70);
    my_list.push_back(80);
    my_list.pop_front();

    EXPECT_EQ(my_list.length(), 1);
    EXPECT_EQ(my_list.front(), 80);
    EXPECT_EQ(my_list.back(), 80);
}

TEST(ListFunctional, FrontAndBack) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(90);
    my_list.push_back(100);

    EXPECT_EQ(my_list.front(), 90);
    EXPECT_EQ(my_list.back(), 100);
}

TEST(ListFunctional, LengthAndEmpty) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    EXPECT_TRUE(my_list.empty());
    EXPECT_EQ(my_list.length(), 0);

    my_list.push_back(110);
    EXPECT_FALSE(my_list.empty());
    EXPECT_EQ(my_list.length(), 1);
}

TEST(ListFunctional, OperatorSquareBrackets) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(120);
    my_list.push_back(130);

    EXPECT_EQ(my_list[0], 120);
    EXPECT_EQ(my_list[1], 130);
}

TEST(ListFunctional, Insert) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(140);
    my_list.push_back(150);
    my_list.insert(my_list.begin(), 160);

    EXPECT_EQ(my_list.length(), 3);
    EXPECT_EQ(my_list.front(), 160);
    EXPECT_EQ(my_list.back(), 150);
}

TEST(ListFunctional, Erase) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(170);
    my_list.push_back(180);
    my_list.push_back(190);
    my_list.erase(my_list.begin());

    EXPECT_EQ(my_list.length(), 2);
    EXPECT_EQ(my_list.front(), 180);
    EXPECT_EQ(my_list.back(), 190);
}

TEST(ListFunctional, Clear) {
    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    my_list.push_back(200);
    my_list.push_back(210);
    my_list.clear();

    EXPECT_EQ(my_list.length(), 0);
    EXPECT_TRUE(my_list.empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}