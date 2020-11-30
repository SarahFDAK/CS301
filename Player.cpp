
#include "game.h"

Player::Player(){};

Player::Player(int sector){
    _playerZone = sector;
};

void Player::setPlayerSector(int sector){
    _playerZone = sector;
};

void Player::setOpponentSector(int sector){
    _opponentZone = sector;
}

void Player::setPlayerFlag(int sector){
    _playerFlag = sector;
}

void Player::setOpponentFlag(int sector){
    _opponentFlag = sector;
}

void Player::setPossession(int ball){
    _calvinBall = ball;
};

void Player::setOppPoleUse(){
    _oppPole = 1;
};

void Player::setBoomerangUse(){
    _boomerang = 1;
};

int Player::getPlayerSector() const{
    return _playerZone;
};

int Player::getOpponentSector() const{
    return _opponentZone;
}

int Player::getPossession() const{
    return _calvinBall;
};

int Player::getPlayerFlag() const{
    return _playerFlag;
}

int Player::getOpponentFlag() const{
    return _opponentFlag;
}

int Player::getOppPoleUse() const{
    return _oppPole;
};

int Player::getBoomerangUse() const{
    return _boomerang;
};

//Member function to move player around the field
void Player::move(const Field& field){
    //List neighboring areas
    std::cout << "Choose a sector to enter: " <<
                field.getWilson1() << ", " <<
                field.getWilson2() << ", or " <<
                field.getWilson3() << ".\n";
    std::string newRoom;
    int choice;
    while(true){
        std::getline(std::cin, newRoom);
        std::istringstream iss(newRoom);
        //Check if user entry is an integer and if it matches one of the listed neighbors. If so, move player to new area.
        if(iss >> choice){
            if(choice == field.getWilson1()){
                _playerZone = field.getWilson1();
               break;
            }
            else if(choice == field.getWilson2()){
                _playerZone = field.getWilson2();
                break;
            }
            else if(choice == field.getWilson3()){
                _playerZone = field.getWilson3();
                break;
            }
            else
                std::cout << "That wasn't an option! Please try again: \n";
        }
    }
};

//Member function to check player location relative to various Zones, opponent flag, and the Calvinball
//Sets each zone to "used" once the player or opponent has encountered it so each appears once/game
int Player::event(const Field& field, Zones& invisible, Zones& vortex,
                    Zones& noSong, Zones& corollary, Calvinball &gameBall){
    if(field.getArea() == corollary.getZoneArea()){
        if(corollary.getZoneUse() == 0){
            std::cout << "\nFor some reason, a giant bat grabbed you and carried you off! I don't know what that has to do with the corollary zone...\n" << std::endl;
            corollary.setZoneUsed();
            return 1;
        }
        else return 6;
    }
    else if(field.getArea() == noSong.getZoneArea()){
        if(noSong.getZoneUse() == 0){
            std::cout << "\nIt's the no song zone, so, I guess don't sing...?\n" << std::endl;
            noSong.setZoneUsed();
            return 2;
        }
        else return 6;
    }
    else if(field.getArea() == invisible.getZoneArea()){
        if(invisible.getZoneUse() == 0){
            std::cout << "\nYou just ran into the Invisible Sector! Cover your eyes until you're out of it because everything " <<
                "is invisible to you. And you're only out when you're hit with the Calvinball! BWAHAHAHAHA!\n" << std::endl;
            invisible.setZoneUsed();
            return 3;
        }
        else return 6;
    }
    else if(field.getArea() == vortex.getZoneArea()){
        if(vortex.getZoneUse() == 0){
            std::cout << "\nYou're in the Vortex Spot - now you have to spin around until you fall down.\n" << std::endl;
            vortex.setZoneUsed();
            return 4;
        }
        else return 6;
    }
    else if(field.getArea() == gameBall.getBallZone()){
        std::cout << "Look! The Calvinball!!" << std::endl;
        return 5;
    }
    else if(field.getArea() == _opponentFlag){
        std::cout << "\nThere's your opponent's flag!\n" << std::endl;
        return 7;
    }
    return 6;
}

//Member function to check opponent location relative to various Zones, player flag, and the Calvinball
//Sets each zone to "used" once the player or opponent has encountered it so each appears once/game
int Player::eventOpponent(const Field& field, Zones& invisible, Zones& vortex,
                  Zones& noSong, Zones& corollary, Calvinball& gameBall){
    if(field.getArea() == corollary.getZoneArea()){
        if(corollary.getZoneUse() == 0){
            std::cout << "\nFor some reason, a giant bat grabbed your opponent and carried them off! " <<
                         "I don't know what that has to do with the corollary zone...\n" << std::endl;
            corollary.setZoneUsed();
            return 1;
        }
        else return 6;
    }
    else if(field.getArea() == noSong.getZoneArea()){
        if(noSong.getZoneUse() == 0){
            std::cout << "\nYour opponent is in the No Song Zone. Thank goodness we don't have to listen to them sing...?\n" << std::endl;
            noSong.setZoneUsed();
            return 2;
        }
        else return 6;
    }
    else if(field.getArea() == invisible.getZoneArea()){
        if(invisible.getZoneUse() == 0){
            std::cout << "\nYour opponent just ran into the Invisible Sector! They have to cover their eyes until they're out of it because everything " <<
                "is invisible to them. Hit them with the Calvinball! BWAHAHAHAHA!\n" << std::endl;
            invisible.setZoneUsed();
            return 3;
        }
        else return 6;
    }
    else if(field.getArea() == vortex.getZoneArea()){
        if(vortex.getZoneUse() == 0){
            std::cout << "\nYour opponent is in the Vortex Spot - now they have to spin around until they fall down.\n" << std::endl;
            vortex.setZoneUsed();
            return 4;
        }
        else return 6;
    }
    else if(field.getArea() == gameBall.getBallZone()){
        std::cout << "Oh no! Your opponent sees the Calvinball!!" << std::endl;
        return 5;
    }
    else if(field.getArea() == _playerFlag) return 7;
    return 6;
}
