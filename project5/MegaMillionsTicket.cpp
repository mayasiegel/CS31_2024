#include "MegaMillionsTicket.h"
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"

MegaMillionsTicket::MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball) {
    mBall1 = ball1;
    mBall2 = ball2;
    mBall3 = ball3;
    mBall4 = ball4;
    mBall5 = ball5;
    mMegaBall = megaball;
}

int MegaMillionsTicket::getBall1() {
    // return value of ball1
    return mBall1;
}
int MegaMillionsTicket::getBall2() {
    return mBall2;
}
int MegaMillionsTicket::getBall3() {
    return mBall3;
}
int MegaMillionsTicket::getBall4() {
    return mBall4;
}
int MegaMillionsTicket::getBall5() {
    return mBall5;
}
int MegaMillionsTicket::getMegaBall() {
    return mMegaBall;
}

bool MegaMillionsTicket::isValid() {
    if (mBall1 < 1 || mBall1 > 70 || mBall2 < 1 || mBall2 > 70 || mBall3 < 1 || mBall3 > 70 || mBall4 < 1 || mBall4 > 70 || mBall5 < 1 || mBall5 > 70) {
        return false;
    }
    if (mMegaBall > 25 || mMegaBall < 0) {
        return false;
    }
    if (mBall1 == mBall2 || mBall1 == mBall3 || mBall1 == mBall4 || mBall1 == mBall5 || mBall2 == mBall3 || mBall2 == mBall4 || mBall2 == mBall5 || mBall3 == mBall4 || mBall3 == mBall5 || mBall4 == mBall5) {
        return false;
    }
    return true;
}
