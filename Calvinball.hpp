#ifndef Calvinball_hpp
#define Calvinball_hpp

#include <stdio.h>

class Calvinball {
    int _ballZone = 0;
    
public:
    Calvinall();
    Calvinball(int area);
    
    void setBallZone(const int area);
    
    int getBallZone() const;
};

#endif
