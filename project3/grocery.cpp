#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

bool isWellFormedGroceryOrderString(string grocerystring);
int pickupCount(string grocerystring);
int deliveryCount(string grocerystring);
int shipCount(string grocerystring);
int inpersonCount(string grocerystring);
int number(string s, size_t & position);
int checkGroceryStrings( string s1, string s2 ); // NEW

int main() { // throwaway
    size_t where = 0;
    // assertions (T/F)
    where = 0;
    assert( number("123abc", where) == 123 );
    assert(where == 4);
    where = 1;
    assert(number("123abc", where) == 23);
    assert(where == 4);
    where = 2;
    assert(number("123abc", where) == 3);
    assert(where == 4);
    where = 3;
    assert(number("123abc", where) == 0 ); // really it should give -1
    where = 4;
    assert(number("1230abc", where) == 0);
    
    where = 0;
    assert(number("10p5d", where) == 10); // works as expected
    assert(where == 3); // corrects position to after '10'
    where = 3;
    assert(number("10p0005d", where) == 5);
    
    where = 0;
   // assert(!number("19p", where));
    assert(number("10d5p", where));
    
    string a = "1p1d1s1i";  // one inperson order
    string b = "1p1d1s10i"; // ten inperson orders
    assert( checkGroceryStrings( "", "" ) == 0 );
    assert( checkGroceryStrings( a, a ) == 0 );
    assert( checkGroceryStrings( b, a ) == 1 );
    assert( checkGroceryStrings( a, b ) == -1 );
    
    cout << "assertions passed. " << endl;
    
    string groceryorder = "";
    cout << "Input Grocery Order String: ";
    getline(cin, groceryorder);
    
    if (isWellFormedGroceryOrderString(groceryorder)) {
        cout << "valid grocery. ";
        
        int pickup = pickupCount(groceryorder);
            if (pickup == -1) {
                cout << "invalid pickup. ";
                return -1;
            }
            else {
                cout << "valid pickup. ";
                //return 0;
            }
        int delivery = deliveryCount(groceryorder);
            if (delivery == -1) {
                cout << "invalid delivery. ";
                return -1;
            }
            else {
                cout << "valid delivery. ";
            }
        int ship = shipCount(groceryorder);
            if (ship == -1) {
                cout << "invalid ship. ";
                return -1;
            }
            else {
                cout << "valid ship. ";
            }
        int inperson = inpersonCount(groceryorder);
            if (inperson == -1) {
                cout << "invalid inperson. ";
                return -1;
            }
            else {
                cout << "valid inperson. ";
                //return 0;
            }
        return 0;
    }
    
    else {
        cout << "invalid grocery. ";
        return -1;
    }
    return 0;
}

// step 2
bool isWellFormedGroceryOrderString(string grocerystring) {
    
    bool correctString = true;
    size_t k = 0;
    //size_t where = 0;
    int totalSum = 0;
    int totalP = 0;
    int totalD = 0;
    
    while (k < grocerystring.length()) {
        //x = number(grocerystring, where);
        //k++;
        
        //while (!isdigit(grocerystring[k])
        
        while (!isdigit(grocerystring[k])) {
            
            if (grocerystring[k] != 'p' && grocerystring[k] != 'd' && grocerystring[k] != 's' && grocerystring[k] != 'i' && grocerystring[k] != 'P' && grocerystring[k] != 'D' && grocerystring[k] != 'S' && grocerystring[k] != 'I') {
                   correctString = false;
                   //break;
                }
            k++;
        }
               
        //cout << k;
        if (isdigit(grocerystring[k])) {
            int x = number(grocerystring, k);
            //k++;
            
            if (k - 1 < grocerystring.length()) {
                char c = grocerystring[k - 1];
                
                if (c == 'P' || c == 'p') {
                    totalP += x;
                    if (totalP > 20) {
                        correctString = false;
                    }
                }
                if (c == 'D' || c == 'd') {
                    totalD += x;
                    if (totalD > 10) {
                        correctString = false;
                    }
                }
                else if (c == 'S' || c == 's' || c == 'I' || c == 'i') {
                    //totalSum += x;
                    //k++;
                }
                totalSum += x;
                //k++;
            }
            else {
                correctString = false;
            }
        }
    }
    
    // (not in loop)
    if (totalSum > 99) { // || totalP > 20 || totalD > 10) {
        correctString = false;
    }
    
    if (totalSum == 0) {
        correctString = false;
    }
    
    // can't be empty
    if (grocerystring.empty()) {
        correctString = false;
    }
    
    for (size_t k = 0; k < grocerystring.size(); k++) {
        // no spaces
        if (grocerystring[k] == ' ') {
            correctString = false;
        }
        // first digit can't be letter
        if (!isdigit(grocerystring[0])) {
            correctString = false;
        }
        // leading zeros
        if (grocerystring[k] == '0') {
            if (k == 0 || !isdigit(grocerystring[k - 1])) {
                if (k + 1 < grocerystring.size() && isdigit(grocerystring[k + 1])) {
                    correctString = false;
                }
            }
        }
        // if last digit is a number
        if (isdigit(grocerystring[grocerystring.size() - 1])) {
            correctString = false;
        }
        // only pdsi
        if (isalpha(grocerystring[k])) {
            if (grocerystring[k] != 'p' && grocerystring[k] != 'd' && grocerystring[k] != 's' && grocerystring[k] != 'i' && grocerystring[k] != 'P' && grocerystring[k] != 'D' && grocerystring[k] != 'S' && grocerystring[k] != 'I') {
                correctString = false;
            }
        }
        
    }
    
    return correctString;
}

int pickupCount(string grocerystring) {
 
 if (isWellFormedGroceryOrderString(grocerystring)) {
     size_t k = 0;
     int totalP = 0;
     
     while (k < grocerystring.length()) {
         
         while (!isdigit(grocerystring[k])) {
            if (grocerystring[k] != 'p' && grocerystring[k] != 'd' && grocerystring[k] != 's' && grocerystring[k] != 'i' && grocerystring[k] != 'P' && grocerystring[k] != 'D' && grocerystring[k] != 'S' && grocerystring[k] != 'I') {
                    return -1;
                    //break;
                 }
             k++;
         }
                
         if (isdigit(grocerystring[k])) {
             int x = number(grocerystring, k);
             
             if (k - 1 < grocerystring.length()) {
                 char c = grocerystring[k - 1];
                 
                 if (c == 'P' || c == 'p') {
                     totalP += x;
                     if (totalP > 20) {
                         return -1;
                     }
                 }
             }
             else {
                 return -1;
             }
         }
     }
     
     return totalP;
 }
     
 else {
     return -1;
 }
 
}

int deliveryCount(string grocerystring) {
    
    if (isWellFormedGroceryOrderString(grocerystring)) {
        size_t k = 0;
        int totalD = 0;
        
        while (k < grocerystring.length()) {
            
            while (!isdigit(grocerystring[k])) {
                if (grocerystring[k] != 'p' && grocerystring[k] != 'd' && grocerystring[k] != 's' && grocerystring[k] != 'i' && grocerystring[k] != 'P' && grocerystring[k] != 'D' && grocerystring[k] != 'S' && grocerystring[k] != 'I') {
                       return -1;
                       //break;
                    }
                k++;
            }
                   
            if (isdigit(grocerystring[k])) {
                int x = number(grocerystring, k);
                
                if (k - 1 < grocerystring.length()) {
                    char c = grocerystring[k - 1];
                    if (c == 'D' || c == 'd') {
                        totalD += x;
                        if (totalD > 10) {
                            return -1;
                        }
                    }
                }
                else {
                    return -1;
                }
            }
        }
        
        return totalD;
    }
        
    else {
        return -1;
    }
}

int shipCount(string grocerystring){
    if (isWellFormedGroceryOrderString(grocerystring)) {
        size_t k = 0;
        int totalS = 0;
        
        while (k < grocerystring.length()) {
            
            while (!isdigit(grocerystring[k])) {
               if (grocerystring[k] != 'p' && grocerystring[k] != 'd' && grocerystring[k] != 's' && grocerystring[k] != 'i' && grocerystring[k] != 'P' && grocerystring[k] != 'D' && grocerystring[k] != 'S' && grocerystring[k] != 'I') {
                       return -1;
                       //break;
                    }
                k++;
            }
                   
            if (isdigit(grocerystring[k])) {
                int x = number(grocerystring, k);
                
                if (k - 1 < grocerystring.length()) {
                    char c = grocerystring[k - 1];
                    
                    if (c == 'S' || c == 's') {
                        totalS += x;
                    }
                }
                else {
                    return -1;
                }
            }
        }
        
        return totalS;
    }
        
    else {
        return -1;
    }
}

int inpersonCount(string grocerystring) {
    if (isWellFormedGroceryOrderString(grocerystring)) {
        size_t k = 0;
        int totalI = 0;
        
        while (k < grocerystring.length()) {
            
            while (!isdigit(grocerystring[k])) {
               if (grocerystring[k] != 'p' && grocerystring[k] != 'd' && grocerystring[k] != 's' && grocerystring[k] != 'i' && grocerystring[k] != 'P' && grocerystring[k] != 'D' && grocerystring[k] != 'S' && grocerystring[k] != 'I') {
                       return -1;
                       //break;
                    }
                k++;
            }
                   
            if (isdigit(grocerystring[k])) {
                int x = number(grocerystring, k);
                
                if (k - 1 < grocerystring.length()) {
                    char c = grocerystring[k - 1];
                    
                    if (c == 'I' || c == 'i') {
                        totalI += x;
                    }
                }
                else {
                    return -1;
                }
            }
        }
        
        return totalI;
    }
        
    else {
        return -1;
    }
}

int checkGroceryStrings(string s1, string s2) {
    int s1totalI = inpersonCount(s1);
    int s2totalI = inpersonCount(s2);

    if (!isWellFormedGroceryOrderString(s1) || !isWellFormedGroceryOrderString(s2)) {
        return 0;
    }

    if (s1totalI == s2totalI) {
        return 0;
    }

    if (s1totalI > s2totalI) {
        return 1;
    } else {
        return -1; // if s2totalI > s1totalI
    }
}


int number(string s, size_t &position) {
    int answer = 0;
    bool keepGoing = true;
    bool leadingZero = false;
   
    for ( ; position < s.length() && keepGoing; position++) {
        char c = s.at(position);
        switch (c) {
            case '0':
                if (answer == 0) {
                    if (position == 0 || !isdigit(s[position - 1])) {
                        if (position + 1 < s.length() && isdigit(s[position + 1])) {
                            leadingZero = true;
                        }
                    }
                }
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                answer = (answer * 10) + (c - '0');
                break;
            default:
                keepGoing = false;
                break;
        }
    }
    // statement
    return(answer);
}

