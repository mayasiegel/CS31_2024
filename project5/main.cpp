#include <iostream>
#include <cctype>
#include <string>
#include <cassert>

#include "MegaMillionsTicket.h"
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"

using namespace std;

/*
int main()
{
    // test code for the Random class
    
    RandomNumber r( 1, 75 );  // balls 1-5
    int value = r.random( );
    assert( value >= 1 && value <= 75 );
    value = r.random( );
    assert( value >= 1 && value <= 75 );
    value = r.random( );
    assert( value >= 1 && value <= 75 );
    
    // test code for the MegaMillionsTicket class
    MegaMillionsTicket ticket( 1, 2, 3, 4, 5, 6 );
    
    // driver code. access to public parts of class. getBall accesses private parts of class
    assert( ticket.getBall1() == 1);
    assert( ticket.getBall2() == 2);
    assert( ticket.getBall3() == 3);
    assert( ticket.getBall4() == 4);
    assert( ticket.getBall5() == 5);
    assert( ticket.getMegaBall() == 6);
    assert( ticket.isValid() );
    
    MegaMillionsTicket badTicket( 100, -12, 100, -12, 0, 50 );
    assert( badTicket.isValid() == false );
    
    MegaMillionsTicket badTicket1(1, 2, 3, 3, 4, 1);
    assert(badTicket1.isValid() == false);
     
    
    // test code for the MegaMillionsLottery class
    MegaMillionsLottery lottery( 1, 2, 3, 4, 5, 6 );
    assert( lottery.getBall1() == 1);
    assert( lottery.getBall2() == 2);
    assert( lottery.getBall3() == 3);
    assert( lottery.getBall4() == 4);
    assert( lottery.getBall5() == 5);
    assert( lottery.getMegaBall() == 6);
    assert( lottery.isValid() );

    MegaMillionsLottery badLottery( 5, 5, 1, 1, 12, 500 );
    assert( badLottery.isValid() == false );

    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert( lottery.whatHappened( ticket ) == "You matched 5 balls plus the megaball!" );

    ticket = MegaMillionsTicket( 1, 2, 3, 4, 5, 12 );
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert( lottery.whatHappened( ticket ) == "You matched 5 balls!" );

    ticket = MegaMillionsTicket( 1, 2, 3, 4, 15, 12 );

    MegaMillionsTicket quickPickTicket( 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 20; i++)
    {
        quickPickTicket = lottery.quickPick();
        // all the ball numbers need to be different...
        assert( quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
                quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
                quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
                quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
                quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
                quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
                quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
                quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
                quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
                quickPickTicket.getBall4() != quickPickTicket.getBall5());
     }
    
    
    
    MegaMillionsLottery lottery;
    assert(lottery.getwinningTicketsSold() == 0);
    assert(lottery.getlosingTicketsSold() == 0);

    MegaMillionsTicket t1 = lottery.quickPick();

    if (lottery.checkTicket(t1) == MegaMillionsLottery::WinningPossibility::NOTWINNING) {
        assert(lottery.getlosingTicketsSold() == 1);
        assert(lottery.getwinningTicketsSold() == 0);
    } else {
        assert(lottery.getwinningTicketsSold() == 1);
        assert(lottery.getlosingTicketsSold() == 0);
    }
 
    MegaMillionsLottery lottery( 23, 42, 17, 69, 1, 4 );  // valid with a MegaBall=4
    MegaMillionsTicket one( 23, 42, 17, 69, 1, 1 );       // valid with a MegaBall=1
    MegaMillionsTicket four( 23, 42, 17, 69, 1, 4 );      // valid with a MegaBall=4
    MegaMillionsTicket notvalid( -23, 42, 17, 69, 1, 4 ); // not valid!

    // all are valid but one ticket did not have the Lottery's MegaBall
    //assert( wonMegaBall( one, four, lottery ) == false );
    // all are valid and both tickets had the Lottery's MegaBall!
    //assert( wonMegaBall( four, four, lottery ) );
    // some lottery tickets are not valid!
    //assert( wonMegaBall( notvalid, four, lottery ) == false );

     cout << "assertions passed." << endl;
    
     
     return( 0 );
    }



bool ticketsAreNotTheSame(MegaMillionsTicket t1, MegaMillionsTicket t2)
{
   return ( !( t1.getBall1() == t2.getBall1() && t1.getBall2() == t2.getBall2() && t1.getBall3() == t2.getBall3() && t1.getBall4() == t2.getBall4() && t1.getBall5() == t2.getBall5() &&  t1.getMegaBall() == t2.getMegaBall() ) );
}

void testone(int n)
{
    MegaMillionsLottery lottery( 23, 42, 17, 69, 1, 4 );

    switch (n)
    {

        case 18:
                {
                MegaMillionsTicket t( 1, 69, 17, 23, 42, 4 );
                    std::cout << lottery.whatHappened(t);
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 5 balls plus the megaball!" );
                }
                break;

        case 20:
                {
                MegaMillionsTicket t( 23, 9, 17, 69, 42, 12 );
                    //std::cout << lottery.whatHappened(t);
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::FOUR);
                assert( lottery.whatHappened( t ) == "You matched 4 balls!" );
                }
                break;

        case 23:
                {
                MegaMillionsTicket t( 9, 8, 17, 42, 23, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 3 balls plus the megaball!" );
                }
                break;

        case 24:
                {
                MegaMillionsTicket t( 7, 8, 69, 9, 42, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 2 balls plus the megaball!" );
                }
                break;

        case 25:
                {
                MegaMillionsTicket t( 6, 8, 23, 7, 9, 4 );
                assert( lottery.checkTicket( t ) ==
                   MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
                assert( lottery.whatHappened( t ) == "You matched 1 ball plus the megaball!" );
                }
                break;



        default:
                cout << "Bad argument" ;
                break;
            
            
    }
}
*/
/*
int main()
{
     cout << "Enter test number: ";
     int n;
     cin >> n;
     testone(n);
     cout << "Passed!" << endl;
     return( 0 );
}
*/


int main() {
    cout << "Welcome to Mega Millions Lottery!" << endl;

    // Create a lottery draw
    MegaMillionsLottery lottery;
    bool playAgain = true;

    while (playAgain) {
        // Get user's ticket numbers
        int b1, b2, b3, b4, b5, megaBall;
        cout << "Enter your 5 numbers (1-75) and the MegaBall (1-25): " << endl;
        cout << "Number 1: "; cin >> b1;
        cout << "Number 2: "; cin >> b2;
        cout << "Number 3: "; cin >> b3;
        cout << "Number 4: "; cin >> b4;
        cout << "Number 5: "; cin >> b5;
        cout << "MegaBall: "; cin >> megaBall;

        // Create a ticket with the user's numbers
        MegaMillionsTicket userTicket(b1, b2, b3, b4, b5, megaBall);

        // Check the ticket against the lottery
        MegaMillionsLottery::WinningPossibility result = lottery.checkTicket(userTicket);
        string outcome = lottery.whatHappened(userTicket);

        // Display results
        cout << "\nLottery Results:" << endl;
        cout << "Winning Numbers: " << lottery.getBall1() << " " << lottery.getBall2() << " "
             << lottery.getBall3() << " " << lottery.getBall4() << " " << lottery.getBall5()
             << " MegaBall: " << lottery.getMegaBall() << endl;

        cout << "Your Result: " << outcome << endl;

        // Ask if the user wants to play again
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    cout << "Thanks for playing Mega Millions Lottery! Good luck next time!" << endl;
    return 0;
}


