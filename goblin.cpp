//
//  goblin.cpp
//
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//


#include "goblin.hpp"

Goblin::Goblin(): Player{"Goblin",110,15,20,0}{}

// override receive damage(orcs)
void Goblin::receiveDamage(std::shared_ptr<Element> c) {
    int attackerAtk = getAtk();
    int defenderDef = c->getDef();
    int defenderHp = c->getHp();
    int damage = ((100.0/(100.0+defenderDef))*attackerAtk);
    if (c->getName() == "Orcs") {
        damage *= 1.5;
    }
    int newHP = defenderHp - damage;
    c->setHp(newHP);
    setDamage(damage);
}



Goblin::~Goblin(){}
