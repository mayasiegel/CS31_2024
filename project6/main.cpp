//
//  main.cpp
//  Mastermind
//
//  Created by Howard Stahl on 9/21/22.
//

#include <iostream>
#include <cassert>
#include "Random.h"
#include "Piece.h"
#include "Board.h"
#include "Score.h"
#include "Settings.h"
#include "Enums.h"
#include "Mastermind.h"


int main( ) {
    using namespace cs31;
    using namespace std;
    
    Move m;
    try {
        m.setPieces( "HappyDays" );
        assert( false );
    } catch( logic_error ) {
        assert( true );
    }
    try {
        m.setPieces( "RR" );
        assert( false );
    } catch( logic_error ) {
        assert( true );
    }
    
    // test code
    Piece p;
    assert( p.getColor() == NOTVALID );
    p = Piece( "R" );
    assert( p.getColor() == RED );
    assert( p.getColorAsString() == "R" );

    p = m.getPiece( 0 );
    assert( p.getColor() == NOTVALID );
    m.setPieces( "RBRB" );
    p = m.getPiece( 2 );
    assert( p.getColor() == RED );
    m.setPiece( 2, 'y' );
    p = m.getPiece( 2 );
    assert( p.getColor() == YELLOW );

    // cout << "assertions passed." << endl << endl;

    Score s;
    assert( s.isExactMatch()  == false );
    assert( s.getAnswer( 2 ) == WRONG );
    m.setPieces( "RBRB" );
    Move theAnswer;
    theAnswer.setPieces( "YOYO" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == false );
    assert( s.to_string() == "____" );
    theAnswer.setPieces( "rbrb" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == true );
    assert( s.to_string() == "RRRR" );
    
    // cout << "assertions passed." << endl << endl;

    Board b;
    assert( b.getCurrentRound() == 0 );
    m.setPieces( "POPO" );
    theAnswer.setPieces( "YYOP" );
    s = Score( m, theAnswer );
    b.endRound( m, s );
    assert( b.getCurrentRound() == 1 );
    assert( b.getMoveForRound( 0 ).to_string() == "POPO" );
    assert( b.getScoreForRound( 0 ).to_string() == "MM__" );

    Mastermind game1( "rbyo" );
    assert( game1.answer() == "RBYO" );
    assert( game1.gameIsOver() == false );
    m = game1.play( "BBBB" );
    s = game1.endRound( m );
    assert( s.to_string() == "_R__" );
    
    
    Mastermind game2( "ybbb" );
    assert( game2.answer() == "YBBB" );
    assert( game2.gameIsOver() == false );
    m = game2.play( "BGGG" );
    s = game2.endRound( m );
    assert( s.to_string() == "M___" );
    
    Move playedMove1;
    Move theAnswer1;
    Score s1;
    
    playedMove1.setPieces( "GRBY" );
    theAnswer1.setPieces(  "PPOO" );
    s1 = Score( playedMove1, theAnswer1 );
    
    //cout << s1.to_string();
    
    Move playedMove2;
    Move theAnswer2;
    Score s2;
    
    playedMove2.setPieces( "GRGR" );
    theAnswer2.setPieces(  "PGRG" );
    s2 = Score( playedMove2, theAnswer2 );
    
    //cout << s2.to_string();
    
    Move playedMove3;
    Move theAnswer3;
    Score s3;
    
    playedMove3.setPieces( "POYG" );
    theAnswer3.setPieces(  "BOGO" );
    s3 = Score( playedMove3, theAnswer3 );
    
    //cout << s3.to_string();
    
    Move playedMove4;
    Move theAnswer4;
    Score s4;
    
    playedMove4.setPieces( "POGG" );
    theAnswer4.setPieces(  "YGPO" );
    s4 = Score( playedMove4, theAnswer4 );
    
    //cout << s4.to_string();
    
    
    // sanity checks, long command or character that shouldnt exist
    
    // IMPLEMENT MY OWN TRY AND CATCH CONDITIONS HERE TO TEST SOME OF MY LOGIC ERRORS
    
    /*
     Test this (also check discussion board for other tests)
     
     Move played.
     played.setPieces( "YBBB" );
     Move answer;
     answer.setPieces( "BGGG" );
     Score s ( played, answer );
     assert( s.to_string( ) == "_M__" );
     */

    //cout << "assertions passed. " << endl << endl;

    // game code
    //  Choose a random answer...
    Mastermind game;
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    getline( cin, turn );
                    //cout << "'" << turn << "'" << endl;
                    Move m = game.play( turn );
                    
                    if (m.isValid())
                    {
                        Score s = game.endRound(m);
                        s.isExactMatch();  // just to avoid warning...
                    }
                    else
                    {
                        // turn was not a valid word
                        cout << turn << " was not a Mastermind game entry!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            cout << game.display( message ) << endl;
        }
        else
        {
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning Mastermind game entry was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );
    
    return( 0 );
}
