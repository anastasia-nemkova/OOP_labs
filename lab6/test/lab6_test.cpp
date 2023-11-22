#include <gtest/gtest.h>

#include "npc.hpp"
#include "slaver.hpp"
#include "errant_knight.hpp"
#include "squirrel.hpp"
#include "visitors.hpp"
#include "factory.hpp"

TEST(FightTest, Fighting) {
    Slaver slaver("TestSlaver", 10, 20);
    ErrantKnight knight("TestKnight", 30, 40);
    Squirrel squirrel("TestSquirrel", 50, 60);

    EXPECT_FALSE(slaver.fight(std::make_shared<Slaver>(slaver)));
    EXPECT_FALSE(slaver.fight(std::make_shared<ErrantKnight>(knight)));
    EXPECT_TRUE(slaver.fight(std::make_shared<Squirrel>(squirrel)));
    EXPECT_TRUE(squirrel.fight(std::make_shared<Squirrel>(squirrel)));
    EXPECT_TRUE(knight.fight(std::make_shared<Slaver>(slaver)));
}

TEST(ObserverTest, Observerfunc) {
    auto slaver = std::make_shared<Slaver>("TestSlaver", 10, 20);
    auto knight = std::make_shared<ErrantKnight>("TestKnight", 30, 40);
    
    testing::internal::CaptureStdout();

    auto consoleObserver = std::make_shared<ConsoleObserver>();
    knight->subscribe(consoleObserver);
    knight->fight(slaver);

    std::string consoleOutput = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "\nMurder --------\nerrantKnight: TestKnight {30, 40} \nslaver: TestSlaver {10, 20} \nTestKnight kills TestSlaver\n";

    EXPECT_EQ(consoleOutput, expectedOutput);
}

TEST(FileObserverTest, FileObserverfunc) {
    auto slaver = std::make_shared<Slaver>("TestSlaver", 10, 20);
    auto knight = std::make_shared<ErrantKnight>("TestKnight", 30, 40);
    auto fileObserver = std::make_shared<FileObserver>("test.txt");

    knight->subscribe(fileObserver);
    save({slaver, knight}, "test.txt");
    knight->fight(slaver);

    std::ifstream file("test.txt"); 
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf(); 
        std::string fileContent = buffer.str();

        std::string expectedContent = "2\n1\nTestSlaver {10, 20} \n2\nTestKnight {30, 40} \n\nMurder --------\nErrantKnight TestKnight {30, 40} \nSlaver TestSlaver {10, 20} \nErrantKnight TestKnight kills Slaver TestSlaver\n";
        EXPECT_EQ(fileContent, expectedContent);
    }
        file.close();
}


TEST(VisitorTest, VisitorFunc) {
    auto slaver = std::make_shared<Slaver>("TestSlaver", 10, 20);
    auto errantKnight = std::make_shared<ErrantKnight>("TestKnight", 30, 40);
    auto squirrel = std::make_shared<Squirrel>("TestSquirrel", 50, 60);

    auto npcVisitor = std::make_shared<NPCVisitor>(slaver);

    EXPECT_FALSE(slaver->accept(*npcVisitor));
    EXPECT_FALSE(errantKnight->accept(*npcVisitor));
    EXPECT_TRUE(squirrel->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(errantKnight);

    EXPECT_TRUE(slaver->accept(*npcVisitor));
    EXPECT_FALSE(errantKnight->accept(*npcVisitor));
    EXPECT_FALSE(squirrel->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(squirrel);

    EXPECT_FALSE(slaver->accept(*npcVisitor));
    EXPECT_FALSE(errantKnight->accept(*npcVisitor));
    EXPECT_TRUE(squirrel->accept(*npcVisitor));
}

TEST(MainFightTest, BigFighting) {
    testing::internal::CaptureStdout();

    set_t array;

    array.insert(factory(SlaverType, "TestSlaver1", 10, 20, "test_fight.txt"));
    array.insert(factory(ErrantKnightType, "TestKnight1", 30, 40, "test_fight.txt"));
    array.insert(factory(SquirrelType, "TestSquirrel1", 50, 60, "test_fight.txt"));

    array.insert(factory(SlaverType, "TestSlaver2", 15, 25, "test_fight.txt"));
    array.insert(factory(ErrantKnightType, "TestKnight2", 35, 45, "test_fight.txt"));
    array.insert(factory(SquirrelType, "TestSquirrel2", 55, 65, "test_fight.txt"));

    array.insert(factory(SlaverType, "TestSlaver3", 20, 30, "test_fight.txt"));
    array.insert(factory(ErrantKnightType, "TestKnight3", 40, 50, "test_fight.txt"));
    array.insert(factory(SquirrelType, "TestSquirrel3", 60, 70, "test_fight.txt"));

    auto dead_list = fight(array, 50);
    for (auto &d : dead_list)
        array.erase(d);

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(array.size(), 3);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}