//
//  Board.cpp
//

#include "Board.h"
#include <stdexcept>
#include <string>
#include <iostream>

namespace cs31
{
    Board::Board() : mRoundCount( 0 )
    {
        
    }
    
    // save this Move and Score into the set of Moves and Scores
    // being managed by this Board
    void Board::endRound( Move m, Score s )
    {
        if (mRoundCount < TOTALROUNDSALLOWED) // should this be TOTALROUNDSALLOWED - 1?
        {
            moves[ mRoundCount ] = m;
            scores[ mRoundCount ] = s;
            // increment to the next round
            mRoundCount++;
        }
        else
        {
            // throw an error rather than walk off the edge of the array
            std::logic_error le( "invalid roundcount value" );
            throw( le );
        }
    }
    
    // print this Board
    // the Wordle object repetitively calls this operation as the game
    // play proceeds
    std::string Board::display( ) const
    {
        using namespace std;
        
        std::string s = "\t\t  CS31 Mastermind Game\nR-red B-blue G-green Y-yellow, P-purple O-orange\n";
        if (mRoundCount > 0)
        {
            int i = 0;
            while( i < mRoundCount )
            {
                s += std::to_string( i+1 );
                s += " : ";
                s += moves[ i ].to_string();
                s += " - ";
                s += scores[ i ].to_string();
                s += "\n";
                i++;
            }
        }
        
        return( s );
    }
    
    // TODO trivial getter method
    int Board::getCurrentRound() const
    {
        return mRoundCount;
    }

    // TODO acquire a Move for a particular round of play
    // TODO throw logic_error if the round is invalid or
    //                        if the round has not yet been played
    Move Board::getMoveForRound( int round ) const
    {
        if (round < 0 || round > mRoundCount) {
            throw std::logic_error("invalid round number");
        }
        return moves[round]; // is this correct?
    }

    // TODO acquire a Move for a particular round of play
    // TODO throw logic_error if the round is invalid or
    //                        if the round has not yet been played
    Score Board::getScoreForRound( int round ) const
    {
        if (round < 0 || round > mRoundCount) {
            throw std::logic_error("invalid round number");
        }
        return scores[round]; // is this correct?
    }

    
}

