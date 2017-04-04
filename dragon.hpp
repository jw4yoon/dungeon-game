//
//  dragon.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef dragon_hpp
#define dragon_hpp

#include "enemy.hpp"

class Dragon : public Enemy{
    std::shared_ptr<Element> dragonG;
public:
    Dragon();
    void setDragonG(std::shared_ptr<Element> dragonG) override;
    std::shared_ptr<Element> getDragonG() override;
};

#endif /* dragon_hpp */
