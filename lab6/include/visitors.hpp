#pragma once

#include <memory>

class Slaver;
class ErrantKnight;
class Squirrel;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual bool visit(Slaver& slaver) = 0;
    virtual bool visit(ErrantKnight& knight) = 0;
    virtual bool visit(Squirrel& squirrel) = 0;
};

class NPC;

class NPCVisitor : public Visitor {
public:
    NPCVisitor(std::shared_ptr<NPC> attacker);
    
    bool visit(Slaver& slaver) override;
    bool visit(ErrantKnight& knight) override;
    bool visit(Squirrel& squirrel) override;

private:
    std::shared_ptr<NPC> attacker_;
};
