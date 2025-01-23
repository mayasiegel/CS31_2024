#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

#ifndef MEGAMILLIONSTICKET_h
#define MEGAMILLIONSTICKET_h

class MegaMillionsTicket {
private:
    int mBall1;
    int mBall2;
    int mBall3;
    int mBall4;
    int mBall5;
    int mMegaBall;
    
public:
    MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);
    int getBall1();
    int getBall2();
    int getBall3();
    int getBall4();
    int getBall5();
    int getMegaBall();
    
    bool isValid();
    
};

#endif
