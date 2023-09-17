#include "lab1.hpp"
#include <iostream>

int main(){
    std::string str;
    int n;
    char oldValue, newValue;
    getline(std::cin, str);
    std::cin >> n >> oldValue >> newValue;
    std::string result = symbolsChange(str, n, oldValue, newValue);
    if (result != str) {
        std::cout << str << "->" << result << std::endl;
    } else {
        std::cout << str << std::endl;
    }
}
