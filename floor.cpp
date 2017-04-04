#include "floor.hpp"
#include "human.hpp"
#define Debug2si
using namespace std;
Floor::Floor(): level{1}{
    p = nullptr;
}

void Floor::initPlayer(shared_ptr<Player> p){
    this->p = p;
    actionOut << "Player character has spawned";
}

void Floor::print(bool pickPlayer){
    for(int i = 0; i < 25; ++i){
        for(int j = 0; j < 79; ++j){
            if (map[i][j]->getType() == "VWall") cout << "|";
            else if(map[i][j]->getType() == "HWall") cout << "-";
            else if(map[i][j]->getType() == "Floor") cout << ".";
            else if(map[i][j]->getType() == "Doorway") cout << "+";
            else if(map[i][j]->getType() == "Passage") cout << "#";
            else if(map[i][j]->getType() == "Solid") cout << " ";
            else if(map[i][j]->getType() == "Player") cout << "@";
            else if(map[i][j]->getType() == "Enemy") {
                if (map[i][j]->getName()=="Human"){
                    cout << "H";
                }
                else if (map[i][j]->getName()=="Dwarf"){
                    cout << "W";
                }
                else if (map[i][j]->getName()=="Elf"){
                    cout << "E";
                }
                else if (map[i][j]->getName()=="Orcs"){
                    cout << "O";
                }
                else if (map[i][j]->getName()=="Merchant"){
                    cout << "M";
                }
                else if (map[i][j]->getName()=="Dragon"){
                    cout << "D";
                }
                else if (map[i][j]->getName()=="Halfling"){
                    cout << "L";
                }
             
            }
            else if(map[i][j]->getType() == "Gold") cout << "G";
            else if(map[i][j]->getType() == "Potion") cout << "P";
            else if(map[i][j]->getType() == "Stairs") cout << "\\";
        }
        cout << endl;
    }
    
    if (pickPlayer){
    cout << "Race: "<< p->getName() << "    Gold: " << p->getGold() << "                                               "<< "Floor "<< level << endl;
    cout << "HP: " << p->getHp() << endl;
    cout << "Atk: " << p->getAtk() << endl;
    cout << "Def: " << p->getDef() << endl;
    cout << "Action : ";
    cout << actionOut.str() << endl;
    actionOut.str("");
    }
}

void Floor::initMap(ifstream &mapFile) { //make map according to file

    vector<shared_ptr<Element>> row;
    string line, input;
    std::vector<std::string> v;
    while(getline(mapFile, line)){
        v.push_back(line);
    }
    shared_ptr<Element> e;
    for (int i=0; i<25; ++i){
        for (int j=0; j<79; ++j){
            input= v[i][j];
            if(input == "|") e = *new shared_ptr<Element>{new Element{"VWall", i, j}};
            else if(input == "-") e = *new shared_ptr<Element>{new Element{"HWall", i, j}};
            else if(input ==".") e = *new shared_ptr<Element>{new Element{"Floor", i, j}};
            else if(input == " ") e = *new shared_ptr<Element>{new Element{"Solid", i, j}};
            else if(input == "+") e = *new shared_ptr<Element>{new Element{"Doorway", i, j}};
            else if(input == "#") e = *new shared_ptr<Element>{new Element{"Passage", i, j}};
            else e = *new shared_ptr<Element>{new Element{"Floor", i, j}};

            row.emplace_back(e);
        }
    map.emplace_back(row);
    row.clear();
    }
}



void Floor::initChambers(){ //create chambers according to map
    vector<shared_ptr<Element>> row;
    for(int i = 3; i < 7; ++i){ //chamber 0
        int j = 3;
        while(map[i][j]->getType() == "Floor"){
            row.emplace_back(map[i][j]);
            ++j;
        }
    }
    chambers.emplace_back(row);
    row.clear();

    
    for(int i = 3; i < 7; ++i){ //chamber 1
        int j = 39;
        while(map[i][j]->getType() == "Floor"){
            row.emplace_back(map[i][j]);
            ++j;
        }
    }
    chambers.emplace_back(row);
    row.clear();
    
    for(int i = 7; i < 13; ++i){ //chamber 1
        int j = 61;
        while(map[i][j]->getType() == "Floor"){
            chambers[1].emplace_back(map[i][j]);
            ++j;
        }
    }
    
    for(int i = 10; i < 13; ++i){ //chamber2
        int j = 38;
        while(map[i][j]->getType() == "Floor"){
            row.emplace_back(map[i][j]);
            ++j;
        }
    }
    chambers.emplace_back(row);
    row.clear();
    
    for(int i = 15; i < 22; ++i){ //chamber 3
        int j = 4;
        while(map[i][j]->getType() == "Floor"){
            row.emplace_back(map[i][j]);
            ++j;
        }
    }
    chambers.emplace_back(row);
    row.clear();
    
    for(int i = 19; i < 22; ++i){ //chamber 4
        int j = 37;
        while(map[i][j]->getType() == "Floor"){
            row.emplace_back(map[i][j]);
            ++j;
        }
    }
    chambers.emplace_back(row);
    row.clear();
    
    for(int i = 16; i < 19; ++i){ //chamber 4
        int j = 65;
        while(map[i][j]->getType() == "Floor"){
            chambers[4].emplace_back(map[i][j]);
            ++j;
        }
    }
}

void Floor::resetChambers(){
    chambers.clear();
    map.clear();
}


void Floor::fillChambers(int level){ //fill chambers with everything
    this->level=level;
    srand(time(NULL));
    int randChamber;
    int randFloor;
    int charChamber;
    int mapRow;
    int mapCol;
    //spawn player
    randChamber = rand() % 5;
    charChamber = randChamber;
    randFloor = rand() % chambers[randChamber].size();
//    mapRow = chambers[randChamber][randFloor]->getRow();
//    mapCol = chambers[randChamber][randFloor]->getCol();
    p->setCord(chambers[randChamber][randFloor]);
    chambers[randChamber][randFloor] = p;
    map[chambers[randChamber][randFloor]->getRow()][chambers[randChamber][randFloor]->getCol()] = p;
    while(true){ //spawn stairsp
        randChamber = rand() % 5;
        randFloor = rand() % chambers[randChamber].size();
        if(chambers[randChamber][randFloor]->getType() == "Floor" && randChamber != charChamber){ //stairs can't be in same chamber as player
            mapRow = chambers[randChamber][randFloor]->getRow();
            mapCol = chambers[randChamber][randFloor]->getCol();
            shared_ptr<Element> temp = *new shared_ptr<Element>{new Element{"Stairs", mapRow, mapCol}};
            *chambers[randChamber][randFloor] = *temp; //don't have stairs class yet
            break;
        }
    }
    
    vector<string> enemies; //spawn items that will fill the chambers
    vector<string> potions; //potions array according to spawn probability
    vector<string> golds;//gold array according to spawn probability
    
    if(1){ //level determines spawn probability
        for(int i = 0; i < 4; ++i){ //enemies array according to spawn probability
            //shared_ptr<Enmey> e(new Human{}};
            enemies.emplace_back("Human");
        }
        for(int i = 0; i < 3; ++i){
            enemies.emplace_back("Dwarf");
        }
        for(int i = 0; i < 5; ++i){
            enemies.emplace_back("Halfling");
        }
        enemies.emplace_back("Elf");
        enemies.emplace_back("Elf");
        enemies.emplace_back("Orcs");
        enemies.emplace_back("Orcs");
        enemies.emplace_back("Merchant");
    
        
        potions.emplace_back("RH"); //need potion constructor with type, and with grid
        potions.emplace_back("BA");
        potions.emplace_back("BD");
        potions.emplace_back("PH");
        potions.emplace_back("WA");
        potions.emplace_back("WD");
        
        
        
        golds.emplace_back("Normal");
        golds.emplace_back("Normal");
        golds.emplace_back("Normal");
        golds.emplace_back("Normal");
        golds.emplace_back("Normal");
        golds.emplace_back("Dragon");
        golds.emplace_back("Small");
        golds.emplace_back("Small");
        }

    int count = 20;
    int randConstruct;
    while(count > 0){ //spawn enemies in chambers
        randChamber = rand() % 5;
        randFloor = rand() % chambers[randChamber].size();
        randConstruct = rand() % 17;
        shared_ptr<Element>e;
        
        if(chambers[randChamber][randFloor]->getType() == "Floor"){
            if(enemies[randConstruct] == "Human") e = shared_ptr<Element>{new Human{}};
            else if(enemies[randConstruct] == "Dwarf") e =shared_ptr<Element>{new Dwarf{}};
            else if(enemies[randConstruct] == "Halfling") e=shared_ptr<Element>{new Halfling{}};
            else if(enemies[randConstruct] == "Elf") e=shared_ptr<Element>{new Elf{}};
            else if(enemies[randConstruct] == "Orcs") e=shared_ptr<Element>{new Orcs{}};
            else if(enemies[randConstruct] == "Merchant") e=shared_ptr<Element>{new Merchant{}};


            

            e->setCord(chambers[randChamber][randFloor]);
            chambers[randChamber][randFloor] = e; //make function that switches each other
            map[chambers[randChamber][randFloor]->getRow()][chambers[randChamber][randFloor]->getCol()] = e;
            
            --count;
        }
    }
    count = 10;
    while(count > 0){ //spawn potions in chambers
        randChamber = rand() % 5;
        randFloor = rand() % chambers[randChamber].size();
        randConstruct = rand() % 5;
        shared_ptr<Element>e;
        
        if(chambers[randChamber][randFloor]->getType() == "Floor"){
                if(potions[randConstruct] == "RH") e=shared_ptr<Element>{new Potion{"RH"}};
                else if(potions[randConstruct] == "BA") e=shared_ptr<Element>{new Potion{"BA"}};
                else if(potions[randConstruct] == "BD") e=shared_ptr<Element>{new Potion{"BD"}};
                else if(potions[randConstruct] == "PH") e=shared_ptr<Element>{new Potion{"PH"}};
                else if(potions[randConstruct] == "WA") e=shared_ptr<Element>{new Potion{"WA"}};
                else if(potions[randConstruct] == "WD") e=shared_ptr<Element>{new Potion{"WD"}};
            
                e->setCord(chambers[randChamber][randFloor]);
                chambers[randChamber][randFloor] = e; //make function that switches each other
                map[chambers[randChamber][randFloor]->getRow()][chambers[randChamber][randFloor]->getCol()] = e;
                
                --count;
        }

    }
    count = 10;
    while(count > 0){ //spawn gold in chambers
        randChamber = rand() % 5;
        randFloor = rand() % chambers[randChamber].size();
        randConstruct = rand() % 7;
        shared_ptr<Element>e;
        
        if(chambers[randChamber][randFloor]->getType() == "Floor"){
            if(golds[randConstruct] == "Normal") e=shared_ptr<Element>{new Gold{"Normal"}};
            else if(golds[randConstruct] == "Small") e=shared_ptr<Element>{new Gold{"Small"}};
            else if(golds[randConstruct] == "Dragon") {
                e=shared_ptr<Element>{new Gold{"Dragon"}};
                e->setDragonAlive(true);
                while (true) {
                    int randDragonRow = rand() % 3 - 1;
                    int randDragonCol = rand() % 3 - 1;
                    if (randDragonRow == 0 && randDragonCol == 0) {
                        continue;
                    } else if (map[chambers[randChamber][randFloor]->getRow()+randDragonRow][chambers[randChamber][randFloor]->getCol()+randDragonCol]->getType() == "Floor"){
                        shared_ptr<Element>d{new Dragon{}};
                        d->setDragonG(e);
                        d->setCord(map[chambers[randChamber][randFloor]->getRow()+randDragonRow][chambers[randChamber][randFloor]->getCol()+randDragonCol]);
                        
                        map[chambers[randChamber][randFloor]->getRow()+randDragonRow][chambers[randChamber][randFloor]->getCol()+randDragonCol] = d;
                        break;
                    }
                }
            }
            
            e->setCord(chambers[randChamber][randFloor]);
            chambers[randChamber][randFloor] = e; //make function that switches each other
            map[chambers[randChamber][randFloor]->getRow()][chambers[randChamber][randFloor]->getCol()] = e;
            
            --count;
        }
        
    }

}

void Floor::checkSurround(int row, int col){
    // elementArray is an array contains eight surrounding elements
    vector<std::shared_ptr<Element>> elementArray;
    
    shared_ptr<Element> nw=map[row+1][col-1];
    elementArray.emplace_back(nw);
    shared_ptr<Element> no=map[row+1][col];
    elementArray.emplace_back(no);
    shared_ptr<Element> ne=map[row+1][col+1];
    elementArray.emplace_back(ne);
    shared_ptr<Element> we=map[row][col-1];
    elementArray.emplace_back(we);
    shared_ptr<Element> ea=map[row][col+1];
    elementArray.emplace_back(ea);
    shared_ptr<Element> sw=map[row-1][col-1];
    elementArray.emplace_back(sw);
    shared_ptr<Element> so=map[row-1][col];
    elementArray.emplace_back(so);
    shared_ptr<Element> se=map[row-1][col+1];
    elementArray.emplace_back(se);
    for (int i=0; i<7; ++i){
        //if player sees potion or enemy surrounding him return true
        shared_ptr<Element> curElement= elementArray[i];
        if (curElement->getType() == "Potion"){
            if (curElement->getFound()==false){
            actionOut<< " and sees an unknown potion ";
            }
            else {
                actionOut << " and sees " << curElement->getName();
            }
        }
        else if(curElement->getType() == "Enemy"){
            actionOut << " and sees " << curElement->getName();
        }
    }
}

bool Floor::checkPlayer(shared_ptr<Element> e){
    int row = e->getRow();
    int col = e->getCol();
    // elementArray is an array contains eight surrounding elements
    vector<std::shared_ptr<Element>> elementArray;
    
    shared_ptr<Element> nw=map[row+1][col-1];
    elementArray.emplace_back(nw);
    shared_ptr<Element> no=map[row+1][col];
    elementArray.emplace_back(no);
    shared_ptr<Element> ne=map[row+1][col+1];
    elementArray.emplace_back(ne);
    shared_ptr<Element> we=map[row][col-1];
    elementArray.emplace_back(we);
    shared_ptr<Element> ea=map[row][col+1];
    elementArray.emplace_back(ea);
    shared_ptr<Element> sw=map[row-1][col-1];
    elementArray.emplace_back(sw);
    shared_ptr<Element> so=map[row-1][col];
    elementArray.emplace_back(so);
    shared_ptr<Element> se=map[row-1][col+1];
    elementArray.emplace_back(se);
    for (int i=0; i<8; ++i){
        //if player sees potion or enemy surrounding him return true
        shared_ptr<Element> curElement= elementArray[i];
        if (curElement->getType() == "Player"){
            return true;
        }
    }
    return false;
}

void Floor::moves(int row, int col){
    shared_ptr<Element> moveElement=map[row][col];
    if (moveElement->getType() == "Floor"){
        // moved position is now pointing the player
        map[row][col] = p;
        // original located is changed to floor
        if (doorway){
            doorway=false;
            map[p->getRow()][p->getCol()]= shared_ptr<Element>{new Element {"Doorway", p->getRow(), p->getCol()}};
        }
        else{
        map[p->getRow()][p->getCol()]= shared_ptr<Element>{new Element {"Floor", p->getRow(), p->getCol()}};
        }
        // p position fields are updated to new position
        p->setRow(row);
        p->setCol(col);
        if (p->getName() == "Troll") {
            p->getMaxHp();
            if (p->getHp()+5 > p->getMaxHp()) {
                p->setHp(p->getMaxHp());
            } else {
                p->setHp(p->getHp()+5);
            }
        }
        checkSurround(row, col);
    }
    else if (moveElement->getType() == "Gold"){
        if (!moveElement->getDragonAlive()){
        p->setGold(moveElement);
        map[row][col] =p;
        map[p->getRow()][p->getCol()]= shared_ptr<Element>{new Element {"Floor", p->getRow(), p->getCol()}};
        p->setRow(row);
        p->setCol(col);
        if (p->getName() == "Troll") {
            p->getMaxHp();
            if (p->getHp()+5 > p->getMaxHp()) {
                p->setHp(p->getMaxHp());
            } else {
                p->setHp(p->getHp()+5);
            }
        }
        checkSurround(row, col);
        }
        else{
        actionOut.str("");
        actionOut<<"You must kill the dragon to have this dragon hoard ";
        }
    }
    else if (moveElement->getType() == "Doorway"){
        doorway= true;
        // moved position is now pointing the player
        map[row][col] = p;
        // original located is changed to floor
        if (passway){
            map[p->getRow()][p->getCol()]= shared_ptr<Element>{new Element {"Passage", p->getRow(), p->getCol()}};
            passway= false;
        }
        else{
        map[p->getRow()][p->getCol()]= shared_ptr<Element>{new Element {"Floor", p->getRow(), p->getCol()}};
        }
        // p position fields are updated to new position
        p->setRow(row);
        p->setCol(col);
        if (p->getName() == "Troll") {
            p->getMaxHp();
            if (p->getHp()+5 > p->getMaxHp()) {
                p->setHp(p->getMaxHp());
            } else {
                p->setHp(p->getHp()+5);
            }
        }
        checkSurround(row, col);
    }
    else if (moveElement->getType() == "Passage"){
        passway=true;
        // moved position is now pointing the player
        map[row][col] = p;
        // original located is changed to floor
        if (doorway){
            doorway =false;
            map[p->getRow()][p->getCol()]=shared_ptr<Element>{new Element {"Doorway", p->getRow(), p->getCol()}};
        }
        else {
        map[p->getRow()][p->getCol()]= shared_ptr<Element>{new Element {"Passage", p->getRow(), p->getCol()}};
        }
        // p position fields are updated to new position
        p->setRow(row);
        p->setCol(col);
        if (p->getName() == "Troll") {
            p->getMaxHp();
            if (p->getHp()+5 > p->getMaxHp()) {
                p->setHp(p->getMaxHp());
            } else {
                p->setHp(p->getHp()+5);
            }
        }
        checkSurround(row, col);
    }
    else if (moveElement->getType() == "Stairs") {
        if (p->getName() == "Troll") {
            p->getMaxHp();
            if (p->getHp()+5 > p->getMaxHp()) {
                p->setHp(p->getMaxHp());
            } else {
                p->setHp(p->getHp()+5);
            }
        }
        nextLevel = true;
        level++;
    }
    else {
        actionOut.str("");
        actionOut << "Failed to move to the new positon";
    }
}

void Floor::usePotion(int row, int col){
    actionOut.str("");
    shared_ptr<Element> potionElement=map[row][col];
    if (potionElement->getType()=="Potion"){
        p->usePotion(potionElement);
        actionOut<<"PC uses " << potionElement->getName();
        shared_ptr<Element> temp = *new shared_ptr<Element>{new Element{"Floor", row, col}};
        *map[row][col] = *temp;
        string potionName=potionElement->getName();
        if (p->getName() == "Troll") {
            p->getMaxHp();
            if (p->getHp()+5 > p->getMaxHp()) {
                p->setHp(p->getMaxHp());
            } else {
                p->setHp(p->getHp()+5);
            }
        }
        for (int i=0; i<25; ++i){
            for (int j=0; j<79; ++j){
                if (map[i][j]->getType()=="Potion"){
                    if (map[i][j]->getName()==potionName){
                        map[i][j]->setFound();
                    }
                }
            }
        }
        
        
        
    }
    else {
        actionOut<< "Failed to use potion as this is not a potion";
    }
}

void Floor::attack(int row, int col){
    shared_ptr<Element> enemyElement=map[row][col];
    if (enemyElement->getType() == "Enemy"){
        p->attack(map[row][col]);
        actionOut << enemyElement->getName() << " received " << p->getDamage() << " damage ";
        p->setDamage(0);
        if (enemyElement->getName() == "Merchant") {
            enemyElement->setHostility(true);
        }
        if (map[row][col]->getHp() <=0) {
            if (enemyElement->getName()=="Dragon"){
                enemyElement->getDragonG()->setDragonAlive(false);
                actionOut << "Enemy " << enemyElement->getName() << " died ";
                shared_ptr<Element> temp = *new shared_ptr<Element>{new Element{"Floor", row, col}};
                *map[row][col] = *temp;
            } else if (enemyElement->getName() != "Human" && enemyElement->getName() != "Merchant") {
                srand(time(NULL));
                int randGold = rand() % 2 + 1;
                p->setGold(randGold);
                if (p->getName() == "Goblin") {
                    p->setGold(5);
                }
                actionOut << "Enemy " << enemyElement->getName() << " died ";
                shared_ptr<Element> temp = *new shared_ptr<Element>{new Element{"Floor", row, col}};
                *map[row][col] = *temp;
            } else {
                shared_ptr<Element> temp{new Gold{"Merchant"}};
                temp->setCord(map[row][col]);
                map[row][col] = temp;
            }
            
        }
    }
    else {
        actionOut << "Failed to attack as this is not an Enemy" << endl;
    }
}
                           
                           
void Floor::pauseEnemy(){
    actionOut << "Pause enemy";
}


void Floor::eMoves(shared_ptr<Element> e){
    srand(time(NULL));
    while (1){
    int randRow= rand() % 3 - 1;
    int randCol= rand() % 3 - 1;
    int moveRow= e->getRow()+randRow;
    int moveCol= e->getCol()+randCol;
    if (map[moveRow][moveCol]->getType()=="Floor"){
        e->setMobility(false);
        map[moveRow][moveCol] = e;
        map[e->getRow()][e->getCol()]= shared_ptr<Element>{new Element {"Floor", e->getRow(), e->getCol()}};
        e->setRow(moveRow);
        e->setCol(moveCol);
        break;
    }
    }
}

void Floor::enemyMove(){
    for (int i=0; i<25; ++i){
        for (int j=0; j<79; ++j){
            if (map[i][j]->getType()=="Enemy"){
                if(map[i][j]->getHostility()== false){
                    if (map[i][j]->getMobility()==true){
                        eMoves(map[i][j]);
                    }
                }
                else { //Hostility is true
                    if (map[i][j]->getName()=="Dragon" && checkPlayer(map[i][j]->getDragonG())){
                        map[i][j]->attack(p);
                        actionOut << endl << "PC received "<< map[i][j]->getDamage() << " damage ";
                        map[i][j]->setDamage(0);
                        if (p->getHp() <= 0) {
                            cout << "Player Dead" << endl;
                            cout << "Score is " << p->getGold() << endl; // score
                            return;
                        }
                    }
                    else if (checkPlayer(map[i][j])){
                        map[i][j]->attack(p);
                        actionOut << endl << "PC received "<< map[i][j]->getDamage() << " damage ";
                        map[i][j]->setDamage(0);
                        if (map[i][j]->getName() == "Elf" && p->getName() != "Drow") {
                            map[i][j]->attack(p);
                            actionOut << endl << "PC received "<< map[i][j]->getDamage() << " damage ";
                            map[i][j]->setDamage(0);
                        }
                        if (p->getHp() <= 0) {
                            cout << "Player Dead" << endl;
                            cout << "Score is " << p->getGold() <<endl;  // score
                            return;
                        }
                    }
                    else {
                        if (map[i][j]->getMobility()==true){
                            eMoves(map[i][j]);
                        }
                    }
                }
            }
//            else if (map[i][j]->getType() == "Gold" && map[i][j]->getName() == "Dragon") {
//
        }
    }
    for (int i=0; i<25; ++i){
        for (int j=0; j<79; ++j){
            if (map[i][j]->getType()=="Enemy"){
                if(map[i][j]->getName()!="Dragon"){
                    map[i][j]->setMobility(true);
                }
            }
        }
    }
}

bool Floor::getLevel() {
    return nextLevel;
}

void Floor::setOut(std::string s){
    actionOut << s;
}
