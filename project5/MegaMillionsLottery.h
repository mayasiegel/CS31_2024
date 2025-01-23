#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

#include "MegaMillionsTicket.h"

using namespace std;

#ifndef MEGAMILLIONSLOTTERY_h
#define MEGAMILLIONSLOTTERY_h

class MegaMillionsLottery {
private:
    int mBall1;
    int mBall2;
    int mBall3;
    int mBall4;
    int mBall5;
    int mMegaBall;
    
    int mwinningTicketsSold;
    int mlosingTicketsSold;
    
    
    
public:
    enum class WinningPossibility {
        MEGABALL, ONEPLUSMEGABALL, TWOPLUSMEGABALL, THREE, THREEPLUSMEGABALL, FOUR, FOURPLUSMEGABALL, FIVE, FIVEPLUSMEGABALL, NOTWINNING, NOTVALID
    };
    MegaMillionsLottery();
    MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);
    int getBall1();
    int getBall2();
    int getBall3();
    int getBall4();
    int getBall5();
    int getMegaBall();
    
    int getwinningTicketsSold();
    int getlosingTicketsSold();
    
    MegaMillionsTicket quickPick();
    WinningPossibility checkTicket(MegaMillionsTicket ticket);
    string whatHappened(MegaMillionsTicket ticket);
    
    bool isValid();
    bool wonMegaBall( MegaMillionsTicket t1, MegaMillionsTicket t2, MegaMillionsLottery l );
    
    
};

#endif
