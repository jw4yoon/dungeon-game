//
//  dragon.cpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#include "dragon.hpp"

Dragon::Dragon(): Enemy{"Dragon",150,20,20, true, false}{}

void Dragon::setDragonG(std::shared_ptr<Element> dragonG){
    this->dragonG=dragonG;
}
std::shared_ptr<Element> Dragon::getDragonG(){
    return dragonG;
}
