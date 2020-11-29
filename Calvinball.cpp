#include "Calvinball.hpp"

Calvinball::Calvinball(){};

Calvinball::Calvinball(int area){
    _ballZone = area;
}

void Calvinball::setBallZone(const int area) {
    _ballZone = area;
};

int Calvinball::getBallZone() const {
    return _ballZone;
};

