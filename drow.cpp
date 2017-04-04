//
//  drow.cpp
//
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//

#include "drow.hpp"
using namespace std;

Drow::Drow(): Player{"Drow",150,25,15,0}{}

Drow::~Drow(){}

void Drow::usePotion(std::shared_ptr<Element> po){
    if (po->getName() == "RH"){
        setHp(getHp()+15);
        if (getHp() > getMaxHp()) {
            setHp(getMaxHp());
        }
    }
    else if (po->getName() == "BA"){
        setAtk(getAtk()+8);
    }
    else if (po->getName() == "BD"){
        setDef(getDef()+8);
    }
    else if (po->getName() == "PH"){
        setHp(getHp()-15);
    }
    else if (po->getName() == "WA"){
        setAtk(getAtk()-8);
    }
    else if (po->getName() == "WD"){
        setDef(getDef()-8);
    }
}

