


#include "elf.hpp"

Elf::Elf() : Enemy{"Elf",140,30,10, true, true}{}

//void Elf::attack(std::shared_ptr<Element> c) {
//    int attSuccess = 1;
//    for (int i = 0; i < 2; ++i) { // attack twice except for drow
//        attSuccess = rand() % 2;
//        if (attSuccess) {
//            receiveDamage(c);
//        }
//        if (c->getName() == "Drow") {
//            break;
//        }
//    }
//}

Elf::~Elf() {}
