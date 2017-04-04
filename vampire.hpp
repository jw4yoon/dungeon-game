//
//  vampire.hpp
//  
//
//  Created by James Jae Won Yoon on 2017-03-28.
//
//

#ifndef vampire_hpp
#define vampire_hpp

#include "player.hpp"
#include <cstdlib>
#include <climits>
class Vampire : public Player {
public:
    Vampire();
    void attack(std::shared_ptr<Element> c) override;
    ~Vampire();
};

#endif /* vampire_hpp */
