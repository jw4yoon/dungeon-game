#include "player.hpp"
#include <climits>
using namespace std;

Player::Player(string name, int hp, int atk, int def, int gold): Character{"Player", name, hp,atk,def ,gold}, maxHp(hp){
    if(name == "Vampire") maxHp = INT_MAX;
}

void Player::attack(std::shared_ptr<Element> c) {
    int attSuccess = 1;
    if (c->getName() == "Halfling") {
        srand(time(NULL));
        attSuccess = rand() % 2; // generate a number(either 0 or 1)
    }
    if (attSuccess==1) {
        receiveDamage(c);
    }
}

Player::~Player(){}


void Player::usePotion(std::shared_ptr<Element> po){
    if (po->getName() == "RH"){
        setHp(getHp()+10);
        if (getHp() > maxHp) {
            setHp(maxHp);
        }
    }
    else if (po->getName() == "BA"){
        setAtk(getAtk()+5);
    }
    else if (po->getName() == "BD"){
        setDef(getDef()+5);
    }
    else if (po->getName() == "PH"){
        setHp(getHp()-10);
    }
    else if (po->getName() == "WA"){
        setAtk(getAtk()-5);
    }
    else if (po->getName() == "WD"){
        setDef(getDef()-5);
    }
}

int Player::getMaxHp() {
    return maxHp;
}


///////////////////////////////////////////////////////////////////////
