#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

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

using namespace std;

int main(int argc, const char * argv[]) { //input check
    while(true) {
    string fileName = argv[1];
    ifstream mapFile{fileName};

    if (argc==3){
        ifstream rand{argv[2]}; //don't need? check
    }
    if(argc > 2){
        cout << "Incorrect number of command argument" << endl;
        return 1;
    }
        
        bool reset = false;
        bool pickPlayer = false;
        bool beforePlayer =false;
        shared_ptr<Player> tempPlayer = nullptr;
        int level = 1;
        while(true){
            string cmd, action, player, direction;
            bool pauseBool= false;
            Floor f;
            shared_ptr<Player> p;

            if (pickPlayer == false){
            
            f.initMap(mapFile);

                cout << "Enter a letter from s(Shade), d(Drow), v(Vampire), g(Goblin), t(Troll) to Play or q to quit or r to restart: ";
                cin >> cmd;
                if (cmd == "q"){ //termninates the program
                    cout << "Exit Game" << endl;
                    return 0;
                }
                if (cmd == "r") {
                    cout << "Game Restarts" << endl;
                    reset = true;
                    break;
                }
                if(cmd == "s") {
                    shared_ptr<Player> temp{new Shade{}};
                    p=temp;
                } // default construct, 125HP, 25 Atk, 25 Def
                else if(cmd == "d") {
                    shared_ptr<Player> temp{new Drow{}};
                    p=temp;
                } // default construct, 125HP, 25 Atk, 25 Def
                else if(cmd == "v") {
                    shared_ptr<Player> temp{new Vampire{}};
                    p=temp;
                } // default construct, 125HP, 25 Atk, 25 Def
                else if(cmd == "g") {
                    shared_ptr<Player> temp{new Goblin{}};
                    p=temp;
                }// default construct, 125HP, 25 Atk, 25 Def
                else if(cmd == "t") {
                    shared_ptr<Player> temp{new Troll{}};
                    p=temp;
                } // default construct, 125HP, 25 Atk, 25 Def
                else {
                    shared_ptr<Player> temp{new Shade{}};
                    p=temp;
                } // default is Shade
                beforePlayer=true;
            f.initPlayer(p); //bind player to map
            f.initChambers();
            f.fillChambers(level);
            f.print(beforePlayer);
            }
            else {
                ifstream mapFile{fileName};
                p=tempPlayer;
                string oldName= tempPlayer->getName();
                if (oldName == "Shade"){
                    p->setAtk(25);
                    p->setDef(25);
                }
                else if (oldName == "Drow"){
                    p->setAtk(25);
                    p->setDef(15);
                }
                else if (oldName == "Vampire"){
                    p->setAtk(25);
                    p->setDef(25);
                }
                else if (oldName == "Troll"){
                    p->setAtk(25);
                    p->setDef(15);
                }
                else if (oldName == "Goblin"){
                    p->setAtk(15);
                    p->setDef(20);
                }
                
                f.initMap(mapFile);
                f.initPlayer(p); //bind player to map
                f.initChambers();
                f.fillChambers(level);
                f.print(beforePlayer);
            }

            while (1) {
                cout << "pick your action: ";
                cin >> action;
                    if (action == "q"){ //termninates the program
                        cout << "Exit Game" << endl;
                        return 0;
                    }
                    if (action == "r") {
                        reset = true;
                        cout << "Game Restarts" << endl;
                        break;
                    }
                    if (action== "f"){
                        pauseBool = !pauseBool;
                        if (pauseBool){
                        f.actionOut << "Enemy Cannot Move";
                        }
                        else {
                          f.actionOut << "Enemy Can Move"; 
                        }
                        // stops every enemy from atking & moving by changing their hostility & mobility to 0
                    }
                    else if (action== "sw"){
                        f.setOut("PC moves South West");
                        f.moves(p->getRow()+1, p->getCol()-1);
                        
                    }
                    else if (action== "so"){
                        f.setOut("PC moves South");
                        f.moves(p->getRow()+1, p->getCol()); // check surrounding is insdie the move
                        
                    }
                    else if (action== "se"){
                        f.setOut("PC moves South East");
                        f.moves(p->getRow()+1, p->getCol()+1);
                    }
                    else if (action== "we"){
                        f.setOut("PC moves West");
                        f.moves(p->getRow(), p->getCol()-1);
                    }
                    else if (action== "ea"){
                        f.setOut("PC moves East");
                        f.moves(p->getRow(), p->getCol()+1);
                    }
                    else if (action== "nw"){
                        f.setOut("PC moves North West");
                        f.moves(p->getRow()-1, p->getCol()-1);
                    }
                    else if (action== "no"){
                        f.setOut("PC moves North");
                        f.moves(p->getRow()-1, p->getCol());
                    }
                    else if (action== "ne"){
                        f.setOut("PC moves North East");
                        f.moves(p->getRow()-1, p->getCol()+1);
                    }
                    // if use or attack
                    else if (action== "u" || action=="a"){
                        cin >> direction;
                            if (direction== "sw"){
                                if (action == "u") {
                                    f.usePotion(p->getRow()+1, p->getCol()-1);
                                } else {
                                    f.attack(p->getRow()+1, p->getCol()-1);
                                }
                            }
                                
                            else if (direction== "so"){
                                if (action == "u") {
                                    f.usePotion(p->getRow()+1, p->getCol());
                                } else {
                                    f.attack(p->getRow()+1, p->getCol());
                                }
                            }
                                
                            else if (direction== "se"){
                                if (action == "u") {
                                    f.usePotion(p->getRow()+1, p->getCol()+1);
                                } else {
                                    f.attack(p->getRow()+1, p->getCol()+1);
                                }
                            }
                                
                            else if (direction== "we"){
                                if (action == "u") {
                                    f.usePotion(p->getRow(), p->getCol()-1);
                                } else {
                                    f.attack(p->getRow(), p->getCol()-1);
                                }
                            }
                                
                            else if (direction== "ea"){
                                if (action  == "u") {
                                    f.usePotion(p->getRow(), p->getCol()+1);
                                } else {
                                    f.attack(p->getRow(), p->getCol()+1);
                                }
                            }
                                
                            else if (direction== "nw"){
                                if (action == "u") {
                                    f.usePotion(p->getRow()-1, p->getCol()-1);
                                } else {
                                    f.attack(p->getRow()-1, p->getCol()-1); 
                                }
                            }
                                
                            else if (direction== "no"){
                                if (action == "u") {
                                    f.usePotion(p->getRow()-1, p->getCol());
                                } else {
                                    f.attack(p->getRow()-1, p->getCol()); 
                                }
                            }
                                
                            else if (direction== "ne"){
                                if (action == "u") {
                                    f.usePotion(p->getRow()-1, p->getCol()+1);
                                } else {
                                    f.attack(p->getRow()-1, p->getCol()+1); 
                                }
                            }
                    }
                if (f.getLevel() == true) {
                    ++level;
                    reset=true;
                    tempPlayer=p;
                    mapFile.close();
                    pickPlayer=true;
                    break;
                    
                }
                if(!pauseBool){
                    f.enemyMove();
                }
                if (p->getHp() <= 0) {
                    return 0;
                }
                f.print(beforePlayer);
            }
            if(reset){
                if (level>5){
                    cout << "Player WIN" << endl;
                    cout << "The Score is ";
                    if (p->getName() == "Shade") {
                        cout << p->getGold() * 1.5;
                    } else {
                        cout << p->getGold();
                    }
                    cout << endl << "Do you want to restart(r)? or quit(q)?" << endl;
                    std::string s;
                    cin >> s;
                    if (s == "r") {
                        break;
                    } else {
                        return 0;
                    }
                }
                if (pickPlayer){
                    mapFile.close();
                    continue;
                }
                break;
            }
        }
        if(reset){
            mapFile.close();
            continue;
        }
    }
}
