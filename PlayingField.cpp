#include "PlayingField.hpp"

Field::Field(){};

Field::Field(int room){
    _area = room;
}

int Field::getArea() const {
    return _area;
}

int Field::getWilson1() const {
    return _wilson1;
}

int Field::getWilson2() const {
    return _wilson2;
}

int Field::getWilson3() const {
    return _wilson3;
}

void Field::setWilson1(const int room){
    _wilson1 = room;
}

void Field::setWilson2(const int room){
    _wilson2 = room;
}

void Field::setWilson3(const int room){
    _wilson3 = room;
}



