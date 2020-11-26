#include "game.h"

//link to assembly functions
extern "C" char* verbs(long);
extern "C" char* equip(long);
extern "C" char* objectives(long);

Player::Player(){};

void Player::setPossession(long hold){
    _calvinBall = hold;
}

void Player::setOppPoleUse(){
    _oppPole = 1;
}

void Player::setBoomerangUse(){
    _boomerang = 1;
}

long Player::getPossession() const{
    return _calvinBall;
}

long Player::getOppPoleUse() const{
    return _oppPole;
}

long Player::getBoomerangUse() const{
    return _boomerang;
}

void menu(){
    std::cout << "1) Start Game\n" <<
                 "2) Rules\n" <<
                 "3) Quit\n" <<
                 "User Input: " << std::endl;
}

//Generate a random number to pass to the assembly files, dictating which rule or tool to return
long choice(long max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> dist(0,max);
    return dist(gen);
}

void getAsmDirection(){
    std::cout << "\n" << verbs(choice(5)) << " " << equip(choice(9)) << " " << objectives(2) << "\n" << std::endl;
}

void game(Player you){
    long select = 0;
    std::string gEntry;
    getAsmDirection();
    do{
        std::cout << "Make a selection:\n" <<
                     "1) Move left\n" <<
                     "2) Move Right\n" <<
                     "3) Run in circles\n" <<
                     "4) Touch opposite pole\n" <<
                     "5) Declare Boomerang Zone\n" <<
                     "Enter -1 to quit" << std::endl;
        std::getline(std::cin, gEntry);
        std::istringstream gameString(gEntry);
        if(gameString >> select){
            
            if(select == 1){
                std::cout << "\nYou moved left.\n";
                getAsmDirection();
            }
            else if(select == 2){
                std::cout << "\nYou moved right.\n";
                getAsmDirection();
            }
            else if(select == 3){
                std::cout <<"\nYou ran in circles.\n";
                getAsmDirection();
            }
            else if(select == 4){
                if(you.getOppPoleUse() == 1){
                    std::cout << "\nSorry, you already touched the opposite pole to get out of something.\n" << std::endl;
                }
                else{
                    you.setOppPoleUse();
                    std::cout << "\nYou touched the opposite pole! Now you don't have to do anything!\n" << std::endl;
                    getAsmDirection();
                }
            }
            else if(select == 5){
                if(you.getBoomerangUse() == 1){
                    std::cout << "\nSorry, you already called the Boomerang Zone to get out of something.\n" << std::endl;
                }
                else{
                    you.setBoomerangUse();
                    std::cout << "\nYou called Boomerang Zone! That means I have to do that!! D:\n" << std::endl;
                    getAsmDirection();
                }
            }
        }
        else std::cout << "\nPlease choose 1-5 or enter -1 to quit.\n" << std::endl;
    }while(select != -1);
    std::cout << "Thanks for playing!" << std::endl;
}


