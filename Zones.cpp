
#include "Zones.hpp"

Zones::Zones(){};
Zones::Zones(int type){
    _type = type;
};

void Zones::setZoneArea(const int area){
    _zoneArea = area;
}

int Zones::getZoneArea() const {
    return _zoneArea;
};
