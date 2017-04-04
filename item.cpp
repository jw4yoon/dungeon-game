//
//  item.cpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#include "item.hpp"

Item::~Item(){}
std::string Item::getName(){
    return name;
}

Item::Item(std::string type, std::string name): Element{type}, name{name}{}
