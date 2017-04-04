#ifndef human_hpp
#define human_hpp

#include "enemy.hpp"

class Human : public Enemy {
public:
    Human();
    //void dropGold(std::shared_ptr<Character> c) override;
    ~Human();
};

#endif /* human_hpp */