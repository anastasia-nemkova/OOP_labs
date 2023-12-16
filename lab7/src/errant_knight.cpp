#include "errant_knight.hpp"
#include "squirrel.hpp"
#include "slaver.hpp"

ErrantKnight::ErrantKnight(const std::string &name, int x, int y) : NPC(ErrantKnightType, name, x, y) {}
ErrantKnight::ErrantKnight(const std::string &name, std::istream &is) : NPC(ErrantKnightType, name, is) {}

void ErrantKnight::print() {
    std::cout << *this;
}

void ErrantKnight::save(std::ostream &os) {
    os << ErrantKnightType << std::endl;
    NPC::save(os);
}

bool ErrantKnight::is_ErrantKnight() const {
    return true;
}

bool ErrantKnight::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<ErrantKnight>(this,[](ErrantKnight*){}));
}

bool ErrantKnight::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, false);
    return false;
}

bool ErrantKnight::fight(std::shared_ptr<ErrantKnight> other) {
    fight_notify(other, false);
    return false;
}

bool ErrantKnight::fight(std::shared_ptr<Slaver> other) {
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, ErrantKnight &errantKnight) {
    os << "errantKnight: " << *static_cast<NPC* >(&errantKnight) << std::endl;
    return os;
}