#include "MegaMillionsTicket.h"
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"

MegaMillionsLottery::MegaMillionsLottery() {
    RandomNumber r1(1, 70);
    RandomNumber r2(1, 25);
    
    do {
        mBall1 = r1.random();
        mBall2 = r1.random();
        mBall3 = r1.random();
        mBall4 = r1.random();
        mBall5 = r1.random();
    } while (mBall1 == mBall2 || mBall1 == mBall3 || mBall1 == mBall4 || mBall1 == mBall5 || mBall2 == mBall3 || mBall2 == mBall4 || mBall2 == mBall5 || mBall3 == mBall4 || mBall3 == mBall5 || mBall4 == mBall5);
    
    mMegaBall = r2.random();
    
    mwinningTicketsSold = 0;
    mlosingTicketsSold = 0;
}

MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball)
    : mBall1(ball1), mBall2(ball2), mBall3(ball3), mBall4(ball4), mBall5(ball5), mMegaBall(megaball),
      mwinningTicketsSold(0), mlosingTicketsSold(0) // Initialize the counters
{
}

/*
MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball) {
    mBall1 = ball1;
    mBall2 = ball2;
    mBall3 = ball3;
    mBall4 = ball4;
    mBall5 = ball5;
    mMegaBall = megaball;
}
 */

int MegaMillionsLottery::getBall1() {
    // return value of ball1
    return mBall1;
}
int MegaMillionsLottery::getBall2() {
    return mBall2;
}
int MegaMillionsLottery::getBall3() {
    return mBall3;
}
int MegaMillionsLottery::getBall4() {
    return mBall4;
}
int MegaMillionsLottery::getBall5() {
    return mBall5;
}
int MegaMillionsLottery::getMegaBall() {
    return mMegaBall;
}

MegaMillionsTicket MegaMillionsLottery::quickPick() {
    RandomNumber r1(1, 70);
    RandomNumber r2(1, 25);
    
    do {
        mBall1 = r1.random();
        mBall2 = r1.random();
        mBall3 = r1.random();
        mBall4 = r1.random();
        mBall5 = r1.random();
    } while (mBall1 == mBall2 || mBall1 == mBall3 || mBall1 == mBall4 || mBall1 == mBall5 || mBall2 == mBall3 || mBall2 == mBall4 || mBall2 == mBall5 || mBall3 == mBall4 || mBall3 == mBall5 || mBall4 == mBall5);
    
    int MegaBall = r2.random();
    
    //int winningTicketsSold = 0;
    //int losingTicketsSold = 0;
    
    /*
     You are creating two additional counters inside the Lottery class. The winning counter gets incremented when the ticket you build inside quickPick( ) is a winning ticket of some kind. The losing counter gets incremented when the ticket your build inside quickPick( ) is not a winning ticket.
     
    
    MegaMillionsTicket ticket(mBall1, mBall2, mBall3, mBall4, mBall5, MegaBall);
    WinningPossibility result = checkTicket(ticket);
        if (result != WinningPossibility::NOTWINNING && result != WinningPossibility::NOTVALID) {
            mwinningTicketsSold++;
        } else {
            mlosingTicketsSold++;
        }
        
    return ticket;
    
     */
     
    return MegaMillionsTicket(mBall1, mBall2, mBall3, mBall4, mBall5, MegaBall);

}

MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket) {
    if (!ticket.isValid()) {
        return WinningPossibility::NOTVALID;
    }
    if (mBall1 < 1 || mBall1 > 70 || mBall2 < 1 || mBall2 > 70 || mBall3 < 1 || mBall3 > 70 || mBall4 < 1 || mBall4 > 70 || mBall5 < 1 || mBall5 > 70) {
        return WinningPossibility::NOTVALID;
    }
    if (mMegaBall > 25 || mMegaBall < 0) {
        return WinningPossibility::NOTVALID;
    }

    int equalCount = 0;
    
    bool matchedMegaBall = (getMegaBall() == ticket.getMegaBall());
    
    // I just tried to fix this. {
    if (getBall1() == ticket.getBall1() || getBall1() == ticket.getBall2() || getBall1() == ticket.getBall3() || getBall1() == ticket.getBall4() || getBall1() == ticket.getBall5()) {
        //cout << "ball 1: " << equalCount << endl;
        equalCount++;
    }
    if (getBall2() == ticket.getBall1() || getBall2() == ticket.getBall2() || getBall2() == ticket.getBall3() || getBall2() == ticket.getBall4() || getBall2() == ticket.getBall5()) {
        //cout << "ball 2: " << equalCount << endl;
        equalCount++;
    }
    if (getBall3() == ticket.getBall1() || getBall3() == ticket.getBall2() || getBall3() == ticket.getBall3() || getBall3() == ticket.getBall4() || getBall3() == ticket.getBall5()) {
        //cout << "ball 3: " << equalCount << endl;
        equalCount++;
    }
    if (getBall4() == ticket.getBall1() || getBall4() == ticket.getBall2() || getBall4() == ticket.getBall3() || getBall4() == ticket.getBall4() || getBall4() == ticket.getBall5()) {
        //cout << "ball 4: " << equalCount << endl;
        equalCount++;
    }
    if (getBall5() == ticket.getBall1() || getBall5() == ticket.getBall2() || getBall5() == ticket.getBall3() || getBall5() == ticket.getBall4() || getBall5() == ticket.getBall5()) {
        //cout << "ball 5: " << equalCount << endl;
        equalCount++;
    }
    // }
    
    if (equalCount == 5 && matchedMegaBall) {
        // winningTicketsSold++;
        return WinningPossibility::FIVEPLUSMEGABALL;
    }
    else if (equalCount == 5) {
        //winningTicketsSold++;
        return WinningPossibility::FIVE;
    }
    else if (equalCount == 4 && matchedMegaBall) {
        //winningTicketsSold++;
        return WinningPossibility::FOURPLUSMEGABALL;
    }
    else if (equalCount == 4) {
        // winningTicketsSold++;
        return WinningPossibility::FOUR;
    }
    else if (equalCount == 3 && matchedMegaBall) {
        //winningTicketsSold++;
        return WinningPossibility::THREEPLUSMEGABALL;
    }
    else if (equalCount == 3) {
        //winningTicketsSold++;
        return WinningPossibility::THREE;
    }
    else if (equalCount == 2 && matchedMegaBall) {
        //winningTicketsSold++;
        return WinningPossibility::TWOPLUSMEGABALL;
    }
    else if (equalCount == 1 && matchedMegaBall) {
        //winningTicketsSold++;
        return WinningPossibility::ONEPLUSMEGABALL;
    }
    else if (matchedMegaBall) {
        //winningTicketsSold++;
        return WinningPossibility::MEGABALL;
    }
    else {
        //losingTicketsSold++;
        return WinningPossibility::NOTWINNING;
    }
}

string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket) {
    if (!isValid()) {
        return "Your lottery was not valid at all!";
    }
    if (!ticket.isValid()) {
        return "Your lottery ticket was not valid at all!";
    }
    if (!isValid() && !ticket.isValid()) {
        return "Your lottery was not valid at all!";
    }
    
    int equalCount = 0;
    bool matchedMegaBall = (getMegaBall() == ticket.getMegaBall());
    
    if (getBall1() == ticket.getBall1() || getBall1() == ticket.getBall2() || getBall1() == ticket.getBall3() || getBall1() == ticket.getBall4() || getBall1() == ticket.getBall5()) {
        //cout << "ball 1: " << equalCount << endl;
        equalCount++;
    }
    if (getBall2() == ticket.getBall1() || getBall2() == ticket.getBall2() || getBall2() == ticket.getBall3() || getBall2() == ticket.getBall4() || getBall2() == ticket.getBall5()) {
        //cout << "ball 2: " << equalCount << endl;
        equalCount++;
    }
    if (getBall3() == ticket.getBall1() || getBall3() == ticket.getBall2() || getBall3() == ticket.getBall3() || getBall3() == ticket.getBall4() || getBall3() == ticket.getBall5()) {
        //cout << "ball 3: " << equalCount << endl;
        equalCount++;
    }
    if (getBall4() == ticket.getBall1() || getBall4() == ticket.getBall2() || getBall4() == ticket.getBall3() || getBall4() == ticket.getBall4() || getBall4() == ticket.getBall5()) {
        //cout << "ball 4: " << equalCount << endl;
        equalCount++;
    }
    if (getBall5() == ticket.getBall1() || getBall5() == ticket.getBall2() || getBall5() == ticket.getBall3() || getBall5() == ticket.getBall4() || getBall5() == ticket.getBall5()) {
        //cout << "ball 5: " << equalCount << endl;
        equalCount++;
    }
    
    if (equalCount == 5 && matchedMegaBall) {
        return "You matched 5 balls plus the megaball!";
    }
    else if (equalCount == 5) {
        return "You matched 5 balls!";
    }
    else if (equalCount == 4 && matchedMegaBall) {
        return "You matched 4 balls plus the megaball!";
    }
    else if (equalCount == 4) {
        return "You matched 4 balls!";
    }
    else if (equalCount == 3 && matchedMegaBall) {
        return "You matched 3 balls plus the megaball!";
    }
    else if (equalCount == 3) {
        return "You matched 3 balls!";
    }
    else if (equalCount == 2 && matchedMegaBall) {
        return "You matched 2 balls plus the megaball!";
    }
    else if (equalCount == 1 && matchedMegaBall) {
        return "You matched 1 ball plus the megaball!";
    }
    else if (matchedMegaBall) {
        return "You matched the megaball!";
    }
    else {
        return "You didn't win anything at all!";
    }
}

bool MegaMillionsLottery::isValid() {
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


bool wonMegaBall(MegaMillionsTicket t1, MegaMillionsTicket t2, MegaMillionsLottery l) {
    // Check if both tickets and the lottery are valid
    if (!t1.isValid() || !t2.isValid() || !l.isValid()) {
        return false;
    }
    
    // Get the MegaBall value from the lottery
    int lotteryMegaBall = l.getMegaBall();
    
    // Check if both tickets' MegaBall values match the lottery's MegaBall value
    return (t1.getMegaBall() == lotteryMegaBall) && (t2.getMegaBall() == lotteryMegaBall);
}
