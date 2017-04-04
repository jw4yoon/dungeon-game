//
//  character.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/24/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef character_hpp
#define character_hpp
#include "element.hpp"
#include <math.h>
#include <iostream>
#include <memory>

class Character : public Element{
    int currentHp;
    int atk;
    int def;
    std::string name;
    int goldCount;
    int damage = 0;
public:
    Character();
    Character(std::string type, std::string name, int hp, int atk, int def , int gold);
    Character(std::string type, std::string name, int hp, int atk, int def); // for enemies
    int getHp() override;
    int getAtk();
    int getDef() override;
    std::string getName() override;
    void setHp(int newHp) override;
    void setAtk(int atk);
    void setDef(int def);
    void setGold(std::shared_ptr<Element> g);
    int getGold();
    void setGold(int) override;
    int getDamage() override;
    void setDamage(int d) override;
    virtual void attack(std::shared_ptr<Element> c) override;
    virtual void receiveDamage(std::shared_ptr<Element> c);
    virtual ~Character()=0;
    
};

#endif /* character_hpp */
