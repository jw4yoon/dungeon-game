//
//  element.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/28/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef element_hpp
#define element_hpp
#include <iostream>
#include <memory>

class Element{
    int row, col;
    std::string type;
public:
    Element(std::string type);
    virtual~Element();
    Element(std::string type, int row, int col);
    int getRow();
    int getCol();
    void setRow(int r);
    void setCol(int c);
    virtual std::string getName();
    virtual int getDef();
    virtual int getHp();
    virtual void setHp(int hp);
    virtual bool getMobility();
    virtual void setMobility(bool);
    virtual bool getHostility();
    virtual void setHostility(bool);
    virtual int getDamage();
    virtual void setDamage(int d);
    virtual void attack(std::shared_ptr<Element> e);
    void setCord(std::shared_ptr<Element> e);
    std::string getType();
    virtual void setFound();
    virtual bool getFound();
    virtual bool getDragonAlive();
    virtual void setDragonAlive(bool);
    virtual void setGold(int);
    virtual void setDragonG(std::shared_ptr<Element> dragonG);
    virtual std::shared_ptr<Element> getDragonG();

};

#endif /* element_hpp */
