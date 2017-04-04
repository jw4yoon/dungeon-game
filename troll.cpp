//
//  troll.cpp
//  
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//

#include "troll.hpp"


Troll::Troll() : Player{"Troll",120,25,15,0}{}

void Troll::attack(std::shared_ptr<Element> c) {
    int curHp = getHp();
    if (curHp < 120) {
        curHp += 5;
        if (curHp > 120) {
            curHp = 120;
        }
        setHp(curHp);
    }
    int attSuccess = 1;
    if (c->getName() == "Halfling") {
        srand(time(NULL));
        attSuccess = rand() % 2; // generate a number(either 0 or 1)
    }
    if (attSuccess) {
        receiveDamage(c);
    }
}

Troll::~Troll(){}
