#ifndef elf_hpp
#define elf_hpp

#include "enemy.hpp"
#include <memory>

class Elf : public Enemy {
public:
    Elf();
//    void attack(std::shared_ptr<Element> c) override;
    ~Elf();
};

#endif /* elf_hpp */
