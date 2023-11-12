#include "/home/arnemkova/OOP_labs/lab5/list/list.hpp"


int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

int main() {

    std::map<int, int, std::less<int>,allocators::Allocator<std::pair<const int,int>, 10>> my_map;

    for (int i = 0; i < 10; ++i) {
        my_map[i] = factorial(i);
    }

    for (const auto& pair : my_map) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    lists::List<int, allocators::Allocator<std::pair<const int,int>, 10>> my_list;

    for (int i = 0; i < 10; ++i) {
        my_list.push_back(i);
    }

    for (const auto& value : my_list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
