#include "header.h"

void testone(int n)
{
    const int N = 6;
    int answer;
    
    // Act as if  a  were declared:
    //   string a[6] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[6] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "tau", "beta", "epsilon", ""
    };
    
    string* a = &aa[1];
    string* z = aa;
    a[-1].string::~basic_string();
    a[N].string::~basic_string();
    
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);
    
    string b[N] = {
        "delta", "gamma", "beta", "tau", "epsilon", "alpha"
    };
    
    
    string c[N] = {
        "ones", "two", "three", "alpha", "beta", "alpha"
    };
    
        
    string d[N] = {
        "one", "23" , "four", "56", "seven", "89"
    };
    
    switch (n)
    {
            case  52:
              answer = rotateRight(b, 2, 4);
              assert( answer == 8 );
              assert( b[ 0 ] == "delta" );
              assert( b[ 1 ] == "gamma" );
              assert( b[ 2 ] == "beta" );
              assert( b[ 3 ] == "tau" );
              assert( b[ 4 ] == "epsilon" );
              assert( b[ 5 ] == "alpha" );
              break;
            case  53:
              answer = rotateRight(b, 2, 3 );
              assert( answer == 6 );
              assert( b[ 0 ] == "gamma" );
              assert( b[ 1 ] == "delta" );
              assert( b[ 2 ] == "beta" );
              assert( b[ 3 ] == "tau" );
              assert( b[ 4 ] == "epsilon" );
              assert( b[ 5 ] == "alpha" );
              break;
            case  63:
              answer = shiftLeft(c, 6, 10, "bar" );
              assert( answer == 6 );
              assert( c[ 0 ] == "bar" );
              assert( c[ 1 ] == "bar" );
              assert( c[ 2 ] == "bar" );
              assert( c[ 3 ] == "bar" );
              assert( c[ 4 ] == "bar" );
              assert( c[ 5 ] == "bar" );
              break;
         default:
            cout << "Bad argument" ;
            break;
    }
    
    new (&a[-1]) string;
    new (&a[N]) string;
}

int main(  )
{
    int number = 0;
    cout << "Provide a test number: ";
    cin  >> number;
    testone( number );
    cout << "Test passed!" << endl;
    return( 0 );
}

/*
int main () {
    string array[5] = {"samwell", "margaery", "daenerys", "tyrion",  "jon"};
    string array2[3] = {"a", "c", "b"};
    string array3[4] = {"hello", "bye", "bye", "later"};
    string array5[2] = {"1", "2"};
    string array6[2] = {"1 1", "2"};
    
    assert(locateMaximum(array, 5) == 3);
    assert(locateMaximum(array, 5) != 0);
    assert(locateMaximum(array2, 3) == 1);
    assert(hasDuplicatedValues(array3, 4) == true);
    assert(hasDuplicatedValues(array, 5) == false);
    assert(countAllVowels(array2, 3) == 1);
    assert(moveToEnd(array, 5, 1) == 1);
    assert(countIntegers(array5, 1) == 1);
    assert(countIntegers(array6, 2) == 1);
    assert(rotateRight(array, 5, 1) == 5);
    assert(rotateRight(array, 5, 2) == 10);
    assert(shiftLeft(array, 5, 1, "abc") != -1);

    cerr << "assertions passed." << endl;
    
    if (locateMaximum(array, 5) != -1) {
        cout << "valid maximum. ";
    }
    if (hasDuplicatedValues(array, 5) != true) {
        cout << "valid duplicate. ";
    }
    if (countAllVowels(array, 1) == 2) {
        cout << "valid vowels. ";
    }
    if (moveToEnd(array, 5, 1) == 1) {
        cout << "valid end. ";
    }
    if (countIntegers(array, 5) != -1) {
        cout << "valid integer. ";
    }
    if (rotateRight(array, 5, 1) == 5) {
        cout << "valid rotate. ";
    }
    if (shiftLeft(array, 5, 1, "abc") != -1) {
        cout << "valid shift. " << endl;
    }
    else {
        cout << "invalid. ";
        return -1;
    }
    return 0;

}

*/
