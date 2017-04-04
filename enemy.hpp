#ifndef enemy_hpp
#define enemy_hpp

#include "character.hpp"
#include <memory>
#include <iostream>


class Enemy : public Character {
    bool hostility;
    bool mobility;
public:
    Enemy(std::string name, int hp, int atk, int def, bool hostility, bool mobility);
    virtual void dropGold(std::shared_ptr<Element> c);
    bool getMobility() override;
    bool getHostility() override;
    void setMobility(bool) override;
    void setHostility(bool) override;
    virtual void attack(std::shared_ptr<Element> c) override;
    int getHp() override;
    int getDef() override;
    std::string getName() override;
    void setHp(int newHp) override;
    virtual ~Enemy()=0;

    void eMove();
};

#endif
