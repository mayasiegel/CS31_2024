#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

class RandomNumber{
public:
    RandomNumber( int min, int max, bool minInclusive=true, bool maxInclusive=true );
    // supply a number between min and max inclusive
    int random( );
private:
    int  mMinimum, mMaximum;
};

#endif
