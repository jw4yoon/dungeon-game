//
//  gold.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef gold_hpp
#define gold_hpp

#include "item.hpp"
#include <memory>


class Gold : public Item{
    bool dragonAlive = false;
public:
    Gold(std::string name);
    bool getDragonAlive() override;
    void setDragonAlive(bool) override;
   //~Gold();
};



#endif /* gold_hpp */
