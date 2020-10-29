#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <random>
#include <sstream>

class Player {
    int _calvinBall = 0; //=1 if player possesses Calvinball
    std::string _score = ""; //score can be number, letter, gibberish, etc
    int _oppPole = 0; //=1 if opposite pole used
    int _boomerang = 0; //=1 if boomerang zone used
public:
    Player();
    
    void setPossession(int hold);
    void setOppPoleUse();
    void setBoomerangUse();
    
    int getPossession() const;
    int getOppPoleUse() const;
    int getBoomerangUse() const;
};

void menu(); //menu text

int choice(int max);//Random number generator to select random rules and equipment

void game(Player you); //main game code

void getAsm(); //get input from asm files

#endif
