#include <map>
#include <algorithm>
#include <tuple>

#include "game.h"

//link to assembly functions
extern "C" char* verbs(int);
extern "C" char* equip(int);
extern "C" char* objectives(int);
extern "C" char* points(int);

void menu(){
    std::cout << "1) Start Game\n" <<
                 "2) Rules\n" <<
                 "3) Quit\n" <<
                 "User Input: " << std::endl;
}

//Generate a random number to pass to the assembly files, dictating which rule or tool to return
std::mt19937 PRNG(){
    std::random_device rd;
    std::mt19937 gen(rd());
    return gen;
}

//Use mt19937 to generate a random number within entered range
int choice(int min, int max,std::mt19937 gen){
    std::uniform_int_distribution<int> dist(min,max);
    return dist(gen);
}

//Initialize field map to fill with randomized numbers between 1 and 20
std::map<int, int> sectors;

//Create field map associating each area number with its 3 neighbors
std::tuple<int, int, int> populateField(int areaNum){
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
//Field map:
//Sector  Neighbors
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


//Read information from ASM verbs, equipment, and objectives files
void getAsmDirection(){
    std::cout << "\n" << verbs(choice(0,5,PRNG())) << " " << equip(choice(0,9,PRNG())) << " " << objectives(choice(0,5,PRNG())) << "\n" << std::endl;
}

//Check if user entered a number, opposite, or boomerang
int gameChoice(std::string gEntry){
    int option;
    std::istringstream gameString(gEntry);
    if(gameString >> option) return option;
    //else if(gEntry == "opposite") return 6;
    //else if(gEntry == "boomerang") return 7;
    else{
        std::cout << "THAT wasn't an option! I guess I'll decide for you." << std::endl;
        return choice(1, 5, PRNG());
    }
}

//Provide choice for randomized area assignment
int sectorNum(){
    return choice(1,20,PRNG());
}

//Provide choice for randomized points assignment
int setPoints(){
    return choice(0,12,PRNG());
}

void game(Player you){
    
    //Create Calvinball and zones to distribute on map
    Calvinball gameBall;
    Zones invisible(1);
    Zones vortex(2);
    Zones noSong(3);
    Zones corollary(4);
    
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

    //Randomly shuffle rooms 1-20, then push them to the sector numbers map
    std::shuffle(areas.begin(), areas.end(), PRNG());
    for(int j = 0; j < 20; j++){
        sectors[j+1] = areas[j];
    }

    //Create neighbor area for each field area using the sectors map and the populateField
    //tuple.
    for(int k = 0; k < 20; k++){
        int zone1, zone2, zone3;
        std::tie(zone1, zone2, zone3) = populateField(k+1);
        fields[k].setWilson1(zone1);
        fields[k].setWilson2(zone2);
        fields[k].setWilson3(zone3);
    }
        
    //Set starting area for Calvinball and various sectors and zones
    while(gameBall.getBallZone()==0 ||
          gameBall.getBallZone() == you.getPlayerSector())
        gameBall.setBallZone(sectorNum());
    while(vortex.getZoneArea() == 0 ||
          vortex.getZoneArea() == gameBall.getBallZone() ||
          vortex.getZoneArea() == you.getPlayerSector())
        vortex.setZoneArea(sectorNum());
    while(noSong.getZoneArea() == 0 ||
          noSong.getZoneArea() == you.getPlayerSector() ||
          noSong.getZoneArea() == gameBall.getBallZone() ||
          noSong.getZoneArea() == vortex.getZoneArea())
        noSong.setZoneArea(sectorNum());
    while(invisible.getZoneArea() == 0 ||
          invisible.getZoneArea() == you.getPlayerSector() ||
          invisible.getZoneArea() == gameBall.getBallZone() ||
          invisible.getZoneArea() == vortex.getZoneArea() ||
          invisible.getZoneArea() == noSong.getZoneArea())
        invisible.setZoneArea(sectorNum());
    while(corollary.getZoneArea() == 0 ||
          corollary.getZoneArea() == you.getPlayerSector() ||
          corollary.getZoneArea() == gameBall.getBallZone() ||
          corollary.getZoneArea() == vortex.getZoneArea() ||
          corollary.getZoneArea() == noSong.getZoneArea() ||
          corollary.getZoneArea() == invisible.getZoneArea())
        corollary.setZoneArea(sectorNum());
    
    //initialize variables to be used in the game
    int select = 0;
    std::string gEntry;
    getAsmDirection();
    std::string youPoint = "zip";
    std::string opponentPoint = "nada";
    
    //every 3 rounds, report the score
    int round = 0;
    
    
    do{
        //Increment the round - will range 1 to 3
        round++;
        
        //Set Field object and player zone to allow for shorter member function calls
        int myZone = you.getPlayerSector();
        Field nextDoor = fields[myZone-1];
        
        if(you.getPossession() == 1){
            std::cout << "You have the Calvinball! Do you want to: \n" <<
            "1 - Throw it at your opponent\n" <<
            "2 - Run for the Randomizer Tree\n" <<
            "3 - Fall down and play dead\n" <<
            "Player Choice: ";
            std::getline(std::cin, gEntry);
            select = gameChoice(gEntry);
            if(select == 1){
                int hit = choice(0,1,PRNG());
                if(hit==1){ youPoint = points(setPoints());
                    std::cout << "Got 'em!! The score is now " << youPoint << " to " << opponentPoint << "\n" << std::endl;
                }
                else std::cout << "MISSED...\n" << std::endl;
                you.setPossession(0);
                gameBall.setBallZone(sectorNum());
            }
            else if(select == 2){
                while(you.getPlayerSector() == myZone) you.setPlayerSector(sectorNum());
            }
            else continue;
        }
        else{
            std::cout << "\nYou are in area " << myZone <<". Neighboring sectors are: " <<
            nextDoor.getWilson1() << ", " <<
            nextDoor.getWilson2() << ", and " <<
            nextDoor.getWilson3() << ".\n";
            if(myZone == gameBall.getBallZone()){
                std::cout << "Look! The Calvinball!!" << std::endl;
                int WHAT = choice(1,3,PRNG());
                switch(WHAT){
                    case 1: std::cout << "\nYou GOT it! RUN!\n" << std::endl;
                            you.setPossession(1);
                            break;
                    case 2: std::cout << "\nSHOOT! You kicked it away!\n" << std::endl;
                            while(gameBall.getBallZone() == myZone) gameBall.setBallZone(sectorNum());
                            break;
                    case 3: std::cout << "\nWhaddaya MEAN you don't want the Calvinball?? Fine... carry on...\n" << std::endl;
                            break;
                }
            }
            if(myZone == vortex.getZoneArea() || myZone == invisible.getZoneArea() ||
               myZone == noSong.getZoneArea() || myZone == corollary.getZoneArea()){
                int uhoh = choice(1,4,PRNG());
                switch(uhoh){
                    case 1: std::cout << "\nYou just ran into the Invisible Sector! Cover your eyes until you're out of it because everything " <<
                        "is invisible to you. And you're only out when you're hit with the Calvinball! BWAHAHAHAHA!\n" << std::endl;
                        opponentPoint = points(setPoints());
                        break;
                    case 2: std::cout << "\nYou're in the Vortex Spot - now you have to spin around until you fall down.\n" << std::endl;
                        break;
                    case 3: std::cout << "No song zone" << std::endl;
                    case 4: std::cout << "Corollary zone" << std::endl;
                }
            }
            you.move(nextDoor);
            
            std::cout << "Enter to continue or -1 to quit: " << std::endl;
            std::getline(std::cin, gEntry);
            std::istringstream quit(gEntry);
            if(quit >> select){
                if(select == -1) continue;
            }
        }
        if(round == 3){
            std::cout << "\nThe score is " << youPoint << " to " << opponentPoint << "\n"<< std::endl;
            round = 0;
            continue;
        }
    }while(select != -1);
    std::cout << "Thanks for playing!" << std::endl;
}

int main(){
    Player you(choice(1,20,PRNG()));
    std::cout << "Welcome to Calvinball! \n";
    menu();
    
    int menuChoice = 0;
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
                             "If you get caught in one of the Problem Sectors, you can type \"opposite\" or \"boomerang\" once " <<
                             "a game to get out of it.\n" <<
                             "Make a choice:\n" <<
                             "User Input: ";
                continue;
            }
            if(menuChoice == 3){
                std::cout << "Thanks for playing!" << std::endl;
                return 0;
            }
            else {
                std::cout << "That isn't an option. Please make a choice.\n" <<
                             "User Input: ";
                continue;
            }
        }
    }

    return 0;
}
