//
//  floor.hpp
//  CC3Kproject
//
//  Created by Heerak Bae on 3/27/17.
//  Copyright © 2017 Heerak Bae. All rights reserved.
//

#ifndef floor_hpp
#define floor_hpp
#include <vector>
#include <fstream>
#include <sstream>
#include "floor.hpp"
#include "element.hpp"
#include "character.hpp"
#include "player.hpp"
#include "drow.hpp"
#include "goblin.hpp"
#include "shade.hpp"
#include "troll.hpp"
#include "vampire.hpp"
#include "enemy.hpp"
#include "human.hpp"
#include "dwarf.hpp"
#include "elf.hpp"
#include "halfling.hpp"
#include "orcs.hpp"
#include "merchant.hpp"
#include "dragon.hpp"
#include "item.hpp"
#include "potion.hpp"
#include "gold.hpp"
#include <stdexcept>
#include <memory>
#include <cstdlib>

class Floor{
    std::vector<std::vector<std::shared_ptr<Element>>> map;
    std::shared_ptr<Player> p;
    std::vector<std::vector<std::shared_ptr<Element>>> chambers;
    bool nextLevel = false;
    bool doorway = false;
    bool passway = false;
    int level;
public:
    std::ostringstream actionOut;
    Floor();
    //~Floor();
    void initMap(std::ifstream &mapFile);
    void initChambers();
    void pauseEnemy();
    void fillChambers(int level);
    void resetChambers(); //don't really need it, but for effciency might want
    void initPlayer(std::shared_ptr<Player> p);
    void moves(int row, int col);
    void usePotion(int row, int col);
    void attack(int row, int col);
    void checkSurround(int r, int c);
    void print(bool pickPlayer);
    bool checkPlayer(std::shared_ptr<Element> e);
    void enemyMove();
    void eMoves(std::shared_ptr<Element> e); // enemyMove helperfunction
    bool getLevel();
    void setOut(std::string s);
};

#endif /* floor_hpp */
