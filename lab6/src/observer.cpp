#include "observer.hpp"
#include "npc.hpp"

std::shared_ptr<IFightObserver> ConsoleObserver::get() {
    static ConsoleObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
}

std::shared_ptr<IFightObserver> FileObserver::get(const std::string &filename) {
    return std::make_shared<FileObserver>(filename);
}

void ConsoleObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
    if (win) {
        std::cout << std::endl << "Murder --------" << std::endl;
        attacker->print();
        defender->print();
        std::cout << attacker->getName() << " kills " << defender->getName() << std::endl;
    }
}


FileObserver::FileObserver(const std::string &filename) {
    file.open(filename, std::ios_base::app);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file");
    }
}

void FileObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
    if (file.is_open() && win) {
        file << "\nMurder --------" << std::endl;
        file << attacker->getType() << " " << *attacker << std::endl;
        file << defender->getType() << " " << *defender << std::endl;
        file << attacker->getType() << " " << attacker->getName() << " kills " << defender->getType() << " " << defender->getName() << std::endl;
    }
}

FileObserver::~FileObserver() {
    if (file.is_open()) {
        file.close();
    }
}

