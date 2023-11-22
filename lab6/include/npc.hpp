#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <cmath>
#include <time.h>
#include "observer.hpp"

class NPC;
class Slaver;
class ErrantKnight;
class Squirrel;
class Visitor;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    SlaverType = 1,
    ErrantKnightType = 2,
    SquirrelType = 3
};


class NPC : public std::enable_shared_from_this<NPC> {
private:
    NpcType type;
    std::string name;
    int x{0};
    int y{0};
public:
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, const std::string &_name, int _x, int _y);
    NPC(NpcType t, const std::string &_name, std::istream &is);
    
    const std::string& getName() const;
    virtual std::string getType() const = 0;
    
    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool fight(std::shared_ptr<Slaver> other) = 0;
    virtual bool fight(std::shared_ptr<ErrantKnight> other) = 0;
    virtual bool fight(std::shared_ptr<Squirrel> other) = 0;

    virtual bool accept(Visitor &visitor) = 0;

    virtual void print() = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    ~NPC() = default;
};
