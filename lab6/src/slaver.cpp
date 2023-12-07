#include "errant_knight.hpp"
#include "squirrel.hpp"
#include "slaver.hpp"

Slaver::Slaver(const std::string &name, int x, int y) : NPC(SlaverType, name, x, y) {}
Slaver::Slaver(const std::string &name, std::istream &is) : NPC(SlaverType, name, is) {}

void Slaver::print() {
    std::cout << *this;
}

void Slaver::save(std::ostream &os) {
    os << SlaverType << std::endl;
    NPC::save(os);
}

bool Slaver::is_slaver() const {
    return true;
}

std::string Slaver::getType() const {
    return "Slaver";
}

bool Slaver::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

bool Slaver::fight(std::shared_ptr<Squirrel> other) {
    fight_notify(other, true);
    return true;
}

bool Slaver::fight(std::shared_ptr<ErrantKnight> other) {
    fight_notify(other, false);
    return false;
}

bool Slaver::fight(std::shared_ptr<Slaver> other) {
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Slaver &slaver) {
    os << "slaver: " << *static_cast<NPC* >(&slaver) << std::endl;
    return os;
}