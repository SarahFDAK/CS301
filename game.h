#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <random>
#include <sstream>

class Player {
    long _calvinBall = 0; //=1 if player possesses Calvinball
    std::string _score = ""; //score can be number, letter, gibberish, etc
    long _oppPole = 0; //=1 if opposite pole used
    long _boomerang = 0; //=1 if boomerang zone used
public:
    Player();
    
    void setPossession(long hold); //change if player has the Calvinball or not
    void setOppPoleUse(); //change to 1 if player has touched the opposite pole
    void setBoomerangUse(); //change to 1 if player has called Boomerang Zone
    
    long getPossession() const;
    long getOppPoleUse() const;
    long getBoomerangUse() const;
};

void menu(); //menu text

//Generate a random number to pass to the assembly files, dictating which rule or tool to return
long choice(long max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> dist(0,max);
    return dist(gen);
}

void game(Player you); //main game code

void getAsmDirection(); //get input from asm rules file

void getAsmEquipment(); //get input from asm equipment file

void getAsmObjective(); //get input from asm objectives file

#endif
