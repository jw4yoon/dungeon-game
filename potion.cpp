//
//  potion.cpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#include "potion.hpp"


Potion::Potion(std::string name): Item{"Potion", name}{}

void Potion::setFound(){
    isFound=true;
}

bool Potion::getFound(){
    return isFound;
}
