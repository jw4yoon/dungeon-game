//
//  drow.hpp
//
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//

#ifndef drow_hpp
#define drow_hpp

#include "player.hpp"
#include <iostream>

class Drow : public Player {
public:
    Drow();
    void usePotion(std::shared_ptr<Element> po) override;
    ~Drow();
};

#endif /* drow_hpp */
