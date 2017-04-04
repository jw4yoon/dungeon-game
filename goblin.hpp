#ifndef goblin_hpp
#define goblin_hpp

#include "player.hpp"

class Goblin : public Player {
public:
    Goblin();
    void receiveDamage(std::shared_ptr<Element> c) override;
    ~Goblin();
};


#endif /* goblin_hpp */
