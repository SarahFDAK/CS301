#include <map>
#include <algorithm>
#include <tuple>

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

//Initialize zones map to fill with randomized numbers between 1 and 20
std::map<int, int> zones;

//Create zone map associating each area number with its 3 neighbors
std::tuple<int, int, int> zoneField(int area){
    if(area == 1) return std::make_tuple(zones[2], zones[5], zones[6]);
    if(area == 2) return std::make_tuple(zones[1], zones[3], zones[8]);
    if(area == 3) return std::make_tuple(zones[2], zones[4], zones[10]);
    if(area == 4) return std::make_tuple(zones[3], zones[5], zones[12]);
    if(area == 5) return std::make_tuple(zones[1], zones[4], zones[14]);
    if(area == 6) return std::make_tuple(zones[1], zones[7], zones[15]);
    if(area == 7) return std::make_tuple(zones[6], zones[8], zones[16]);
    if(area == 8) return std::make_tuple(zones[2], zones[7], zones[9]);
    if(area == 9) return std::make_tuple(zones[8], zones[10], zones[17]);
    if(area == 10) return std::make_tuple(zones[3], zones[9], zones[11]);
    if(area == 11) return std::make_tuple(zones[10], zones[12], zones[18]);
    if(area == 12) return std::make_tuple(zones[4], zones[11], zones[13]);
    if(area == 13) return std::make_tuple(zones[12], zones[14], zones[19]);
    if(area == 14) return std::make_tuple(zones[5], zones[13], zones[15]);
    if(area == 15) return std::make_tuple(zones[6], zones[14], zones[20]);
    if(area == 16) return std::make_tuple(zones[7], zones[17], zones[20]);
    if(area == 17) return std::make_tuple(zones[9], zones[16], zones[18]);
    if(area == 18) return std::make_tuple(zones[11], zones[17], zones[19]);
    if(area == 19) return std::make_tuple(zones[13], zones[18], zones[20]);
    else return std::make_tuple(zones[15], zones[16], zones[19]);
    
};
//Zone map:
//Area  Neighbors
//1 A    B, E, F
//2 B    A, C, H
//3 C    B, D, J
//4 D    C, E, L
//5 E    A, D, N
//6 F    A, G, O
//7 G    F, H, P
//8 H    B, G, I
//9 I    H, J, Q
//10J    C, I, K
//11K    J, L, R
//12L    D, K, M
//13M    L, N, S
//14N    E, M, O
//15O    F, N, T
//16P    G, Q, T
//17Q    I, P, R
//18R    K, Q, S
//19S    M, R, T
//20T    O, P, S

void getAsmDirection(){
    std::cout << "\n" << verbs(choice(5)) << " " << equip(choice(9)) << " " << objectives(choice(5)) << "\n" << std::endl;
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
            else std::cout << "\nPlease choose 1-5 or enter -1 to quit.\n" << std::endl;
        }
        else std::cout << "\nPlease choose 1-5 or enter -1 to quit.\n" << std::endl;
    }while(select != -1);
    std::cout << "Thanks for playing!" << std::endl;
}

int main(){
    Player you;
    std::cout << "Welcome to Calvinball! \n";
    menu();
    
    long menuChoice = 0;
    std::string entry = "";
    while(true){
        std::getline(std::cin, entry);
        std::istringstream iss(entry);
        if(iss >> menuChoice){
            if(menuChoice == 1){
                game(you);
                break;
            }
            if(menuChoice == 2){
                std::cout << "The only rule is that you can't play it the same way twice!\n" <<
                             "Make a choice:\n" <<
                             "User Input: " << std::endl;
                continue;
            }
            if(menuChoice == 3){
                std::cout << "Thanks for playing!" << std::endl;
                return 0;
            }
            else {
                std::cout << "That isn't an option. Please make a choice.\n" <<
                             "User Input: " << std::endl;
                continue;
            }
        }
    }

    return 0;
}
