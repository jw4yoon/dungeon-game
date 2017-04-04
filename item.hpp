//
//  item.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef item_hpp
#define item_hpp
#include "element.hpp"

class Item : public Element{
    std::string name;
public:
    Item(std::string type, std::string name);
    std::string getName() override;
    virtual ~Item()=0;
};

#endif /* item_hpp */
