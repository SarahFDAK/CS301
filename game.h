#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <random>
#include <sstream>

#include "PlayingField.hpp"
#include "Zones.hpp"
#include "Calvinball.hpp"

class Player {
    int _playerZone = 0; //Area of field where player is
    int _opponentZone = 0;
    int _calvinBall = 0; //=1 if player possesses Calvinball
    int _playerFlag=0;
    int _opponentFlag=0;
    std::string _score = ""; //score can be number, letter, gibberish, etc
    int _oppPole = 0; //=1 if opposite pole used
    int _boomerang = 0; //=1 if boomerang zone used
public:
    Player();
    Player(const int sector);
    
    void setPlayerSector(int sector);
    void setOpponentSector(int sector);
    void setPlayerFlag(int sector);
    void setOpponentFlag(int sector);
    void setPossession(int ball); //change if player has the Calvinball or not
    void setOppPoleUse(); //change to 1 if player has touched the opposite pole
    void setBoomerangUse(); //change to 1 if player has called Boomerang Zone
    void move(const Field& field);

    int event(const Field& field, Zones& invisible, Zones& vortex,
              Zones& noSong, Zones& corollary, Calvinball& gameBall);
    int eventOpponent(const Field& field, Zones& invisible, Zones& vortex,
              Zones& noSong, Zones& corollary, Calvinball& gameBall);
    int getPossession() const;
    int getOppPoleUse() const;
    int getBoomerangUse() const;
    int getPlayerSector() const;
    int getOpponentSector() const;
    int getPlayerFlag() const;
    int getOpponentFlag() const;
};

void menu(); //menu text

int choice(int min, int max, std::mt19937 gen);

void game(Player you); //main game code

void getAsmDirection(); //get input from asm rules file

void getAsmEquipment(); //get input from asm equipment file

void getAsmObjective(); //get input from asm objectives file

#endif
