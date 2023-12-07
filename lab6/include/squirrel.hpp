#pragma once

#include "npc.hpp"
#include "visitors.hpp"

class Squirrel : public NPC {
public:
    Squirrel(const std::string &name, int x, int y);
    Squirrel(const std::string &name, std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_Squirrel() const;

    std::string getType() const override;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<ErrantKnight> other) override;
    bool fight(std::shared_ptr<Slaver> other) override;

    bool accept(Visitor &visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &squirrel);

};