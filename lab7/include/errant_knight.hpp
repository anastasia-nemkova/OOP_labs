#pragma once

#include "npc.hpp"


class ErrantKnight : public NPC {
public:
    ErrantKnight(const std::string &name, int x, int y);
    ErrantKnight(const std::string &name, std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_ErrantKnight() const;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<ErrantKnight> other) override;
    bool fight(std::shared_ptr<Slaver> other) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, ErrantKnight &errantKnight);

};