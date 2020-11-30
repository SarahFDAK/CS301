
#include "Zones.hpp"

Zones::Zones(){};
Zones::Zones(int type){
    _type = type;
};

void Zones::setZoneArea(const int area){
    _zoneArea = area;
}

void Zones::setZoneUsed(){
    _used = 1;
}

int Zones::getZoneArea() const {
    return _zoneArea;
}

int Zones::getZoneType() const {
    return _type;
}

int Zones::getZoneUse() const{
    return _used;
}
