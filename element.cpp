//
//  element.cpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#include "element.hpp"

//Element::Element(): row{0}, col{0}, type{""}{}

Element::Element(std::string type): row{0}, col{0}, type{type}{}
Element::~Element(){}
Element::Element(std::string type, int row, int col) : type{type}, row{row}, col{col}{}
int Element::getRow(){
    return row;
}
int Element::getCol(){
    return col;
}
void Element::setRow(int r) {
    row = r;
}
void Element::setCol(int c) {
    col = c;
}
void Element::setCord(std::shared_ptr<Element> e) {
    row = e->getRow();
    col = e->getCol();
}
std::string Element::getType(){
    return type;
}

std::string Element::getName(){
    return "Element getName";
}

int Element::getDef() {
    std::cout << "Element getDef()";
    return 0;
}
int Element::getHp() {
    std::cout<< "Element getHp()";
    return 0;
}
void Element::setHp(int hp) {
    
}

bool Element::getMobility(){
    return false;
}
void Element::setMobility(bool b){
}
bool Element::getHostility(){
    return false;
}
void Element::setHostility(bool b){
}

void Element::attack(std::shared_ptr<Element> e){
}

void Element::setFound(){}

bool Element::getFound(){
    return true;
}

int Element::getDamage() {
    return 0;
}

void Element::setDamage(int d) {
    
}

bool Element::getDragonAlive(){return true;}
void Element::setDragonAlive(bool b){}

void Element::setDragonG(std::shared_ptr<Element> dragonG){
}

std::shared_ptr<Element> Element::getDragonG(){
    return nullptr;
}

void Element::setGold(int g) {
    
}


