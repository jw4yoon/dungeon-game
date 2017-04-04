//
//  enemy.cpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#include "enemy.hpp"

Enemy::Enemy(std::string name, int hp, int atk, int def, bool hostility, bool mobility): Character{"Enemy", name, hp, atk, def}, hostility{hostility}, mobility{mobility}{}


void Enemy::attack(std::shared_ptr<Element> c) {
    int attSuccess = 1;
    attSuccess = rand() % 2;
    if (attSuccess) {
        receiveDamage(c);
    }
}

bool Enemy::getMobility() {
    return mobility;
}

bool Enemy::getHostility() {
    return hostility;
}

void Enemy::setMobility(bool b) {
    mobility = b;
}

void Enemy::setHostility(bool b) {
    hostility = b;
}

void Enemy::dropGold(std::shared_ptr<Element> c) {
    //std::cout << "dropgold" << std::endl;
}

int Enemy::getHp() {
    return Character::getHp();
}
int Enemy::getDef() {
    return Character::getDef();
}
std::string Enemy::getName(){
    return Character::getName();
}
void Enemy::setHp(int newHp) {
    Character::setHp(newHp);
}

Enemy::~Enemy() {}

void Enemy::eMove(){
    
}
