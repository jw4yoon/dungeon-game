//
//  vampire.cpp
//  
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//

#include "vampire.hpp"

Vampire::Vampire() : Player{"Vampire",50,25,25,0}{}

void Vampire::attack(std::shared_ptr<Element> c) {
    int attSuccess = 1;
    if (c->getName() == "Halfling") {
        attSuccess = rand() % 2;
    }
    if (attSuccess) {
        if (c->getName() == "Dwarf"){
            setHp(getHp() - 5);
        } else {
            setHp(getHp() + 5);
        }
        receiveDamage(c);
    }
}

Vampire::~Vampire(){}
