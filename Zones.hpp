#ifndef Zones_hpp
#define Zones_hpp

#include <stdio.h>

class Zones {
    int _zoneArea = 0;
    
    //Zones: 1 - Invisible Sector; 2 - Vortex Spot; 3 - No Song Zone; 4 - Corollary Zone
    int _type;
  
public:
    Zones();
    Zones(int type);
    
    void setZoneArea(const int area);
    
    int getZoneArea() const;
};

#endif /* Hazards_hpp */
