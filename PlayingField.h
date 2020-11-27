#ifndef PlayingField_hpp
#define PlayingField_hpp

#include <stdio.h>
#include <iostream>
#include <random>


class Field {
    //Field's area number
    int _area;
    //Neighboring areas - dating myself by naming the neighbor after
    //Home Improvement. Perhaps the neighbor is a volleyball...
    int _wilson1;
    int _wilson2;
    int _wilson3;
    
public:
    Field();
    Field(int _area);
    
    void setWilson1(const int room);
    void setWilson2(const int room);
    void setWilson3(const int room);
    
    int getArea() const;
    int getWilson1() const;
    int getWilson2() const;
    int getWilson3() const;
};

#endif 
