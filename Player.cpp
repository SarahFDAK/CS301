
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

void Player::move(const Field& field){
    std::cout << "Choose a sector to enter: " <<
                field.getWilson1() << ", " <<
                field.getWilson2() << ", or " <<
                field.getWilson3() << ".\n";
    std::string newRoom;
    int choice;
    while(true){
        std::getline(std::cin, newRoom);
        std::istringstream iss(newRoom);
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

int Player::eventOpponent(const Field& field, Zones& invisible, Zones& vortex,
                  Zones& noSong, Zones& corollary, Calvinball& gameBall){
    if(field.getArea() == corollary.getZoneArea()){
        if(corollary.getZoneUse() == 0){
            std::cout << "\nFor some reason, a giant bat grabbed your and carried them off! I don't know what that has to do with the corollary zone...\n" << std::endl;
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
    
/*
//Shoot function 
void Explorer::shoot(Cave& cave, Wumpus &wompa){
    if(_arrows == 0)
        std::cout << "Sorry, you're out of arrows...\n";
    std::cout << "Which room do you want to shoot into?\n" << cave.getWilson1() <<
                ", " << cave.getWilson2() << ", " << cave.getWilson3() << std::endl;
    std::string input;
    int choice;
//    int count = 0;
    std::cin.ignore();
    std::getline(std::cin, input);
    std::istringstream iss(input);
//    while(count < 3){
    //check if user input is an integer
        if(iss >> choice){
            //check which neighboring cave it went to and see if the wumpus is there
            if(choice == cave.getWilson1()){
                if(wompa.getWumpRoom() == cave.getWilson1()){
                    wompa.setWumpLife(false);
                    std::cout << "You got the Wumpus! Congrats!\n";
                }
                //if the wumpus is in a different connected room, wake it up and
                //move it and decrease arrow count
                else if(wompa.getWumpRoom() == cave.getWilson2() ||
                        wompa.getWumpRoom() == cave.getWilson3()){
                    std::cout << "You woke up the Wumpus...\n";
                    wompa.moveWumpus(1, 20);
                    _arrows--;
                    //count ++;
                }
                //Else just lose an arrow
                else{
                    std::cout << "You didn't hit anything...\n";
                    _arrows--;
                }
            }
            else if(choice == cave.getWilson2()){
                if(wompa.getWumpRoom() == cave.getWilson2()){
                    wompa.setWumpLife(false);
                    std::cout << "You got the Wumpus! Congrats!\n";
                }
                else if(wompa.getWumpRoom() == cave.getWilson1() ||
                        wompa.getWumpRoom() == cave.getWilson3()){
                    std::cout << "You woke up the Wumpus...\n";
                    wompa.moveWumpus(1, 20);
                    _arrows--;
                    //count ++;
                }
                else{
                    std::cout << "You didn't hit anything...\n";
                    _arrows--;
                }
            }
            else if(choice == cave.getWilson3()){
                if(wompa.getWumpRoom() == cave.getWilson3()){
                    wompa.setWumpLife(false);
                    std::cout << "You got the Wumpus! Congrats!\n";
                }
                else if(wompa.getWumpRoom() == cave.getWilson1() ||
                        wompa.getWumpRoom() == cave.getWilson2()){
                    std::cout << "You woke up the Wumpus...\n";
                    wompa.moveWumpus(1, 20);
                    _arrows--;
                    //count ++;
                }
                else{
                    std::cout << "You didn't hit anything...\n";
                    _arrows--;
                }
            }
            else
                std::cout << "That isn't one of the options...\n";
        }
//        std::cout << "Please enter a room number:\n";
//        std::getline(std::cin, input);
//    }
    
}
    
void Explorer::missed(const int usedArrow) {
    if(_arrows > 1)
        _arrows -= 1;
    else
        std::cout << "You are out of arrows. Better run away!\n";
};

int Explorer::getExplorerLife() const {
    return _lifeStat;
};
int Explorer::getExplorerRoom() const {
    return _yourRoom;
};
int Explorer::getArrowNum() const {
    return _arrows;
};
*/

