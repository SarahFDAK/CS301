
#include "game.h"

Player::Player(){};

Player::Player(int sector){
    _playerZone = sector;
};

void Player::setPlayerSector(int sector){
    _playerZone = sector;
};

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

int Player::getPossession() const{
    return _calvinBall;
};

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

/*int Explorer::event(const Cave& cave, const Hazards& bat1, const Hazards& bat2,
                     const Hazards& pit1, const Hazards &pit2, Wumpus &wompa){
    if(cave.getRoom() == bat1.getHazardRoom() ||
       cave.getRoom() == bat2.getHazardRoom()){
        std::cout << "A giant bat grabbed you and carried you off!\n";
        while(_yourRoom == cave.getRoom())
            _yourRoom = randInt(1, 20);
        return 1;
    }
    else if(cave.getRoom() == pit1.getHazardRoom() ||
            cave.getRoom() == pit2.getHazardRoom()){
        std::cout << "Oh no, you fell in a pit!\n";
        return 2;
    }
    else if(cave.getRoom() == wompa.getWumpRoom()){
        std::cout << "GLOMP! The Wumpus just had you for snacks!\n";
        return 3;
    }
    return 1;
}

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
