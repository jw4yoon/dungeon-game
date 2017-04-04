//
//  gold.cpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#include "gold.hpp"

Gold::Gold(std::string name): Item{"Gold", name}{}

bool Gold::getDragonAlive(){
    return dragonAlive;
}
void Gold::setDragonAlive(bool b){
    dragonAlive=b;
}
