#include "visitors.hpp"
#include "npc.hpp"
#include "slaver.hpp"
#include "errant_knight.hpp"
#include "squirrel.hpp"

NPCVisitor::NPCVisitor(std::shared_ptr<NPC> attacker) : attacker_(attacker) {}

bool NPCVisitor::visit(Slaver& slaver) {
    return attacker_->fight(std::make_shared<Slaver>(slaver));
}

bool NPCVisitor::visit(ErrantKnight& knight) {
    return attacker_->fight(std::make_shared<ErrantKnight>(knight));
}

bool NPCVisitor::visit(Squirrel& squirrel) {
    return attacker_->fight(std::make_shared<Squirrel>(squirrel));
}
