
#include "character.hpp"

Character::Character(std::string type, std::string name, int hp, int atk, int def , int gold): Element{type}, name{name}, currentHp{hp}, atk{atk}, def{def}, goldCount{gold}{}

Character::Character(std::string type, std::string name, int hp, int atk, int def): Element{type}, name{name}, currentHp{hp}, atk{atk}, def{def}{
    if(name == "Dragon") goldCount = 0;
    else if(name == "Merchant") goldCount = 0;
    else if(name == "Human") goldCount = 0;
    else{
        srand(time(NULL));
        goldCount = rand() % 2 + 1;
    }
}

Character::~Character(){}

int Character::getHp() {
    return currentHp;
}

int Character::getAtk() {
    return atk;
}

int Character::getDef() {
    return def;
}

std::string Character::getName(){
    return name;
}

void Character::setHp(int newHp) {
    currentHp = newHp;
}

void Character::setAtk(int atk){
    this->atk = atk;
}
void Character::setDef(int def){
    this->def = def;
}

void Character::receiveDamage(std::shared_ptr<Element>c) {
    int attackerAtk = getAtk();
    int defenderDef = c->getDef();
    int defenderHp = c->getHp();
    int damage = ((100.0/(100.0+defenderDef))*attackerAtk);
    int newHP = defenderHp - damage;
    c->setHp(newHP);
    this->damage = damage;

}

int Character::getGold() {
    return goldCount;
}

void Character::attack(std::shared_ptr<Element> c) {
    
}

void Character::setGold(std::shared_ptr<Element> g){
    if (g->getName()=="Normal"){
        goldCount += 2;
    }
    else if (g->getName()=="Small"){
        goldCount += 1;
    }
    else if (g->getName()=="Merchant"){
        goldCount += 4;
    }
    else { // "Drogon Gold"
        goldCount += 6;
    }
}

int Character::getDamage() {
    return damage;
}

void Character::setDamage(int d) {
    damage = d;
}

void Character::setGold(int g) {
    goldCount += g;
}
