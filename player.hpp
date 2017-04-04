

#ifndef player_hpp
#define player_hpp

#include "character.hpp"
#include "potion.hpp"
#include <iostream>

class Player : public Character{
    int maxHp;
public:
    Player(std::string name, int hp, int atk, int def, int gold);
    virtual void usePotion(std::shared_ptr<Element> po);
    virtual void attack(std::shared_ptr<Element> character) override;
    int getMaxHp();
    virtual ~Player()=0;
};
#endif /* player_hpp */
