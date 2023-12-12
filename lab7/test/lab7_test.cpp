#include <gtest/gtest.h>

#include "npc.hpp"
#include "slaver.hpp"
#include "errant_knight.hpp"
#include "squirrel.hpp"
#include "observer.hpp"

TEST(FightTest, SlaverVsErrantKnight) {
    testing::internal::CaptureStdout();

    auto slaver = factory(SlaverType, "Slaver", 0, 0, "test_fight.txt");
    auto errantKnight = factory(ErrantKnightType, "ErrantKnight", 1, 1, "test_fight.txt");
    ASSERT_TRUE(slaver->accept(errantKnight));
    slaver->mustDie();
    ASSERT_TRUE(errantKnight->is_alive());
    ASSERT_FALSE(slaver->is_alive());
    testing::internal::GetCapturedStdout();

}

TEST(FightTest, ErrantKnightVsSquirrel) {
    auto errantKnight = factory(ErrantKnightType, "ErrantKnight", 0, 0, "test_fight.txt");
    auto squirrel = factory(SquirrelType, "Squirrel", 1, 1, "test_fight.txt");
    ASSERT_FALSE(errantKnight->accept(squirrel));
    ASSERT_TRUE(squirrel->is_alive());
}

TEST(FightTest, SlaverVsSquirrel) {
    testing::internal::CaptureStdout();

    auto slaver = factory(SlaverType, "Slaver", 0, 0, "test_fight.txt");
    auto squirrel = factory(SquirrelType, "Squirrel", 1, 1, "test_fight.txt");
    ASSERT_TRUE(squirrel->accept(slaver));
    squirrel->mustDie();
    ASSERT_FALSE(squirrel->is_alive());
    testing::internal::GetCapturedStdout();
}

TEST(FightTest, LargeBattle) {
    testing::internal::CaptureStdout();
    set_t npcs;
    npcs.insert(factory(SlaverType, "Slaver1", 0, 0, "test_fight.txt"));
    npcs.insert(factory(SlaverType, "Slaver2", 1, 1, "test_fight.txt"));
    npcs.insert(factory(ErrantKnightType, "ErrantKnight1", 2, 2, "test_fight.txt"));
    npcs.insert(factory(ErrantKnightType, "ErrantKnight2", 3, 3, "test_fight.txt"));
    npcs.insert(factory(SquirrelType, "Squirrel1", 4, 4, "test_fight.txt"));
    npcs.insert(factory(SquirrelType, "Squirrel2", 5, 5, "test_fight.txt"));
    ASSERT_EQ(6, npcs.size());

    set_t npcsToRemove;

    for (auto& attacker : npcs) {
        for (auto& defender : npcs) {
            if (attacker->is_alive())
                if (defender->is_alive())
                    if (defender->accept(attacker)) {
                        defender->mustDie();
                        npcsToRemove.insert(defender);
                    }
        }
    }
    for (const auto& npc : npcsToRemove) {
        npcs.erase(npc);
    }
    testing::internal::GetCapturedStdout();
    ASSERT_EQ(2, npcs.size());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}