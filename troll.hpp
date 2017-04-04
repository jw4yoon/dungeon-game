//
//  troll.hpp
//  
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//

#ifndef troll_hpp
#define troll_hpp

#include "player.hpp"
#include <memory>

class Troll : public Player {
public:
    Troll();
    void attack(std::shared_ptr<Element> c) override;
    ~Troll();
};

#endif /* troll_hpp */
