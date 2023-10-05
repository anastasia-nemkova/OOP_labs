#include <iostream>
#include "BitString.hpp"

int main() {
    try {
        BitString bs1 = {'1', '0', '1', '1'};
        BitString bs2 = {'0', '1', '1', '0'};

        std::cout << "bs1: ";
        bs1.print(std::cout) << std::endl;
        std::cout << "bs2: ";
        bs2.print(std::cout) << std::endl;


        std::cout << "bs1 == bs2: " << (bs1 == bs2) << std::endl;
        std::cout << "bs1 != bs2: " << (bs1 != bs2) << std::endl;
        std::cout << "bs1 > bs2: " << (bs1 > bs2) << std::endl;
        std::cout << "bs1 < bs2: " << (bs1 < bs2) << std::endl;
        std::cout << "bs1 >= bs2: " << (bs1 >= bs2) << std::endl;
        std::cout << "bs1 <= bs2: " << (bs1 <= bs2) << std::endl;


        BitString add = bs1 + bs2;
        std::cout << "bs1 + bs2: ";
        add.print(std::cout) << std::endl;

        BitString sub = bs1 - bs2;
        std::cout << "bs1 - bs2: ";
        sub.print(std::cout) << std::endl;

        bs1 += bs2;
        std::cout << "bs1 += bs2: ";
        bs1.print(std::cout) << std::endl;

        bs1 -= bs2;
        std::cout << "bs1 -= bs2: ";
        bs1.print(std::cout) << std::endl;



        BitString _and = bs1 & bs2;
        std::cout << "bs1 & bs2: ";
        _and.print(std::cout) << std::endl;

        BitString _or = bs1 | bs2;
        std::cout << "bs1 | bs2: ";
        _or.print(std::cout) << std::endl;

        BitString _xor = bs1 ^ bs2;
        std::cout << "bs1 ^ bs2: ";
        _xor.print(std::cout) << std::endl;

        BitString _no = ~bs1;
        std::cout << "~bs1: ";
        _no.print(std::cout) << std::endl;

        bs2 = bs1;
        std::cout << "bs1 = bs2: ";
        bs2.print(std::cout) << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
