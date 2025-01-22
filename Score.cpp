//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score( Move move, Move answer )
{
    // Provided A Played Move And The Correct Answer To The Game, Determine All ANSWER Values – RIGHT, WRONG or MAYBE
    
    // TODO start with if statement checking if the played move and the correct answer
    
    // WRONG
    // if a value in arraymove isn't found anywhere in arrayanswer, its WRONG
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        array[i] = WRONG;
    }
    
    bool used[REQUIREDLENGTH] = {false};
    
    // RIGHT
    // if a value in arraymove equals a value in arrayanswer in the exact same place, its RIGHT
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (move.getPiece(i).getColor() == answer.getPiece(i).getColor()) {
            array[i] = RIGHT;
            used[i] = true;
        }
    }
    // MAYBE
    // if a value in arraymove equals a value in arrayanswer but in a different place, MAYBE and a M is placed at the value in arraymove
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (array[i] == WRONG) {
            for (int j = REQUIREDLENGTH - 1; j >= 0; j--) {
                // start at the top of REQUIREDLENGTH? does it matter?
                if (!used[j] && move.getPiece(i).getColor() == answer.getPiece(j).getColor()) {
                    array[i] = MAYBE;
                    used[j] = true;
                    break;
                }
            }
        }
    }

}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    // Return true If All The ANSWERs Are The Value RIGHT; false Otherwise
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (array[i] != RIGHT) {
            return(false);
        }
    }
    return(true);
}

}

