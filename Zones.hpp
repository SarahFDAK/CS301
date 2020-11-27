#ifndef Zones_hpp
#define Zones_hpp

#include <stdio.h>
#include "PlayingField.h"

class Zones {
    int _zoneArea = 0;
    
    //bats are type 1, pits are type 2
    int _type;
  
public:
    Zones();
    Zones(int type);
    
    void setZoneArea(const int area);
    
    int getZoneArea() const;
};

#endif /* Hazards_hpp */
