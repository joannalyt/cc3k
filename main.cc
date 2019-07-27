#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "player.h"
#include "character.h"
#include "floor.h"
#include "chamber.h"

using namespace std;


bool check (shared_ptr<Floor> floor, string dir, char c) {
    return floor->checkDisplay(floor->checkTile(dir)[0],floor->checkTile(dir)[1] ,c);
}

int main(int argc, char* argv[]) {
    if(argc <= 1)
    {
        while(1) {
            cout << "Welcome to CCK3+!" << endl;
            //prompt to generate player
            cout << "Please choose a character." << endl;
            cout << "h: human." << endl;
            cout << "d: dwarf." << endl;
            cout << "e: elf." << endl;
            cout << "o: orc." << endl;

            auto newfloor = make_shared<Floor>(1);
            newfloor->genChamber();
            //newfloor->printFloor();
            char race;
            cin >> race;
            while(1) {
                if (race == 'h') {
                    auto player = make_shared<Human>();

                    newfloor->genPlayer(player);
                    break;
                } else if (race == 'd') {
                    auto player = make_shared<Dwarf>();
                    newfloor->genPlayer(player);
                    break;
                } else if (race == 'e') {
                    auto player = make_shared<Elf>();
                    newfloor->genPlayer(player);
                    break;
                } else if (race == 'o') {
                    auto player = make_shared<Orc>();
                    newfloor->genPlayer(player);
                    break;
                }
                else {
                    cout << "Please enter a valid command for players" << endl;
                    cin >> race;
                }
            }

            newfloor->genStair();
            newfloor->genPotion();
            newfloor->genGold();
            newfloor->genEnemy();
            newfloor->printFloor();

            cout << "Here are the commands you use:" << endl;
            cout << "DIR: no, so, ea, we, ne, se, sw, nw" << endl;
            cout << "USE POTION: u <direction>" << endl;
            cout << "ATTACK ENEMY: a <direction>" << endl;
            cout << "RESET GAME: r" << endl;
            cout << "QUIT: q" << endl;
            string c;
            while (cin >> c) {
                if (c == "no" ||c == "so" ||c == "ea"
                    ||c ==  "we" ||c == "ne" ||c == "se" ||c == "sw" ||c == "nw") {
                    if (check(newfloor,c, '\\')) {
                        if(newfloor->getLevel() == 5) {
                            newfloor->sethasWon(true);
                            cout << "You've won!! Your final score is: ";
                            if(race == 'h') { // add getGold function
                                cout << (newfloor->getGold()*1.5) << endl;
                            }
                            else if(race == 'd') {
                                cout << newfloor->getGold()*2 << endl;
                            }
                            else if(race == 'o') {
                                cout << newfloor->getGold()/2 << endl;
                            }
                            else if(race == 'e') {
                                cout <<newfloor->getGold() << endl;
                            }
                            break;
                        }
                        else {
                            newfloor->setLevel(newfloor->getLevel() + 1);
                            newfloor->setAction("Welcome to a new floor!"); // add getplayer function
                            // add this function
                            newfloor->reset();
                            newfloor->newLevel();
                            newfloor->genChamber();
                            newfloor->genStair();
                            newfloor->genPotion();
                            newfloor->genGold();
                            newfloor->genEnemy();
                            newfloor->printFloor();
                        }
                    }
                    if (newfloor->movePlayer(c)) {
                        //cout << "moved player" << endl;
                        newfloor->moveEnemy();
                        if (newfloor->hasLost())
                            break;
                        newfloor->printFloor();
                    } else {
                        cout << "invalid command" <<endl;
                    }
                }
                else if (c == "a") {  // attack enemy
                    cin >> c;  // read direction
                    if (check(newfloor,c, 'V') || check(newfloor,c, 'W') || check(newfloor,c, 'N') ||
                        check(newfloor,c, 'M') || check(newfloor,c, 'D') || check(newfloor,c, 'X') ||
                        check(newfloor,c, 'T') || check(newfloor,c, 'E')) {  // checks if there's enemy on the direction command
                        newfloor->pAttack(c);  // attack is in player class
                        newfloor->moveEnemy();
                        if(newfloor->hasLost()) break;// PC dies
                        newfloor->printFloor();
                    } else {
                        cout << "\033[1;31mThere's no enemy in the direction you pointed.\033[0m" << endl;
                    }
                }
                else if (c == "r") {
                    newfloor->reset(); //add
                    break;
                }
                else if (c == "q") {
                    break;
                } else {
                    cout << "Not Valid, try again " << endl;
                }
            }
            if (c == "q") {
                cout << "Thanks for Playing!" << endl;
                break;
            }
        }
    }
}

