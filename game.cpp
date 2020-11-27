#include <map>
#include <algorithm>
#include <tuple>

#include "game.h"
#include "PlayingField.h"

//link to assembly functions
extern "C" char* verbs(long);
extern "C" char* equip(long);
extern "C" char* objectives(long);
extern "C" char* points(long);

Player::Player(){};

void Player::setPossession(long ball){
    _calvinBall = ball;
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
std::mt19937 rand(){
    std::random_device rd;
    std::mt19937 gen(rd());
    return gen;
}
long choice(long min, long max,std::mt19937 gen){
    std::uniform_int_distribution<long> dist(min,max);
    return dist(gen);
}

//Initialize sectors map to fill with randomized numbers between 1 and 20
std::map<int, int> sectors;

//Create zone map associating each area number with its 3 neighbors
std::tuple<int, int, int> zoneField(int areaNum){
    if(areaNum == 1) return std::make_tuple(sectors[2], sectors[5], sectors[6]);
    if(areaNum == 2) return std::make_tuple(sectors[1], sectors[3], sectors[8]);
    if(areaNum == 3) return std::make_tuple(sectors[2], sectors[4], sectors[10]);
    if(areaNum == 4) return std::make_tuple(sectors[3], sectors[5], sectors[12]);
    if(areaNum == 5) return std::make_tuple(sectors[1], sectors[4], sectors[14]);
    if(areaNum == 6) return std::make_tuple(sectors[1], sectors[7], sectors[15]);
    if(areaNum == 7) return std::make_tuple(sectors[6], sectors[8], sectors[16]);
    if(areaNum == 8) return std::make_tuple(sectors[2], sectors[7], sectors[9]);
    if(areaNum == 9) return std::make_tuple(sectors[8], sectors[10], sectors[17]);
    if(areaNum == 10) return std::make_tuple(sectors[3], sectors[9], sectors[11]);
    if(areaNum == 11) return std::make_tuple(sectors[10], sectors[12], sectors[18]);
    if(areaNum == 12) return std::make_tuple(sectors[4], sectors[11], sectors[13]);
    if(areaNum == 13) return std::make_tuple(sectors[12], sectors[14], sectors[19]);
    if(areaNum == 14) return std::make_tuple(sectors[5], sectors[13], sectors[15]);
    if(areaNum == 15) return std::make_tuple(sectors[6], sectors[14], sectors[20]);
    if(areaNum == 16) return std::make_tuple(sectors[7], sectors[17], sectors[20]);
    if(areaNum == 17) return std::make_tuple(sectors[9], sectors[16], sectors[18]);
    if(areaNum == 18) return std::make_tuple(sectors[11], sectors[17], sectors[19]);
    if(areaNum == 19) return std::make_tuple(sectors[13], sectors[18], sectors[20]);
    else return std::make_tuple(sectors[15], sectors[16], sectors[19]);
    
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

//Create vector to hold numbers 1 through 20 to shuffle randomly for distribution
//later; create vector to hold field area numbers
std::vector<int> areas;
std::vector<Field> fields;

//Populate area numbers vector and fields vector
for(int i = 0; i < 20; i++){
    areas.push_back(i+1);
    Field area(i+1);
    fields.push_back(area);
}

//Randomly shuffle rooms 1-20, then push them to the area numbers map
std::shuffle(areas.begin(), areas.end(), rand());
for(int j = 0; j < 20; j++){
    sectors[j+1] = areas[j];
}

//Create neighbor area for each field area using the zoneField map and the sectors
//tuple.
for(int k = 0; k < 20; k++){
    int zone1, zone2, zone3;
    std::tie(zone1, zone2, zone3) = zoneField(k+1);
    fields[k].setWilson1(zone1);
    fields[k].setWilson2(zone2);
    fields[k].setWilson3(zone3);
}


void getAsmDirection(){
    std::cout << "\n" << verbs(choice(0,5)) << " " << equip(choice(0,9)) << " " << objectives(choice(0,5)) << "\n" << std::endl;
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
