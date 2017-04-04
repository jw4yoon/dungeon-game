//
//  potion.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef potion_hpp
#define potion_hpp

#include "item.hpp"
#include <memory>

class Potion : public Item{
    bool isFound= false;
public:
    Potion(std::string name);
    void setFound() override;
    bool getFound() override;
    //~Potion();
};

#endif /* potion_hpp */
