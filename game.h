#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <random>
#include <sstream>

class Player {
    int _playerZone = 0; //Area of field where player is
    int _calvinBall = 0; //=1 if player possesses Calvinball
    std::string _score = ""; //score can be number, letter, gibberish, etc
    int _oppPole = 0; //=1 if opposite pole used
    int _boomerang = 0; //=1 if boomerang zone used
public:
    Player();
    Player(const int sector);
    
    void setPlayerSector(int sector);
    void setPossession(int ball); //change if player has the Calvinball or not
    void setOppPoleUse(); //change to 1 if player has touched the opposite pole
    void setBoomerangUse(); //change to 1 if player has called Boomerang Zone
    
    int getPossession() const;
    int getOppPoleUse() const;
    int getBoomerangUse() const;
    int getPlayerSector() const;
};

void menu(); //menu text

int choice(int min, int max, std::mt19937 gen);

void game(Player you); //main game code

void getAsmDirection(); //get input from asm rules file

void getAsmEquipment(); //get input from asm equipment file

void getAsmObjective(); //get input from asm objectives file

#endif
