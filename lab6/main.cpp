#include <iostream>
#include "factory.hpp"
#include "visitors.hpp"
#include "observer.hpp"
#include "errant_knight.hpp"
#include "slaver.hpp"
#include "squirrel.hpp"

int main() {
    set_t array;

    std::string NameArray[10] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "K" };

    std::srand(time(NULL));
    for (size_t i = 0; i < 10; ++i) {
        array.insert(factory(NpcType(std::rand() % 3 + 1), NameArray[i], std::rand() % 100, std::rand() % 100, "log.txt"));
        //array = load(NameArray[i],"npc.txt");
    }

    save(array, "log.txt");

    std::cout << std::endl << array;
 
    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10) {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "\nFight stats ----------" << std::endl
                << "distance: " << distance << std::endl
                << "killed: " << dead_list.size() << std::endl
                << std::endl << std::endl;
    }

    std::cout << "Survivors:\n" << array;

    return 0;

}
