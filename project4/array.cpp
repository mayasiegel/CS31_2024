#include "header.h"

int locateMaximum(const string array[], int n) {
    if (n <= 0) {
        return -1;
    }
    int max = 0;
    for (int k = 1; k < n; k++) {
        if (array[k] > array[max]) {
            max = k;
        }
    }
    return max;
}

bool hasDuplicatedValues(const string array[], int n) {
    if (n <= 0) {
        return false;
    }
    for (int k = 1; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            if (array[k] == array[i]) {
                return true;
            }
        }
    }
    return false;
}

int countAllVowels(const string array[], int n) {
    if (n <= 0) {
        return -1;
    }
    int vowelCount = 0;
    for (int k = 0; k < n; k++) {
        for (char c : array[k]) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
                vowelCount++;
            }
        }
    }
    return vowelCount;
}

int moveToEnd(string array[], int  n, int pos) {
    if (n <= 0) {
        return -1;
    }
    if (pos < 0 || pos > n) {
        return -1;
    }
    string removedElement = array[pos];
    for (int k = pos; k < n - 1; k++) {
        array[k] = array[k + 1];
    }
    array[n - 1] = removedElement;
    return pos;
}

int countIntegers(const string array[], int n) {
    if (n <= 0) {
        return -1;
    }
    int intCount = 0;
    for (int k = 0; k < n; k++) {
        bool isValid = true;
        for (char c : array[k]) {
            if (!isdigit(c)) {
                isValid = false;
            }
        }
        if (isValid) {
            intCount++;
        }
    }
    return intCount;
}

// my version
/*
int rotateRight(string array[], int n, int amount) {
    if (n <= 0 || amount < 0) {
        return -1;
    }
    amount = amount % n;
    if (amount == 0) {
        return n * amount;
    }
    int count = 0; // # of elements moved
    for (int i = 0; count < n; i++) {
         int current = i;
         string currentVal = array[i];
         do {
             int next = (current + amount) % n;
             string temp = array[next];
             array[next] = currentVal;
             currentVal = temp;
             current = next;
             count++;
         } while (i != current);
    }
    return n * amount;
}
 */

// correct version
int rotateRight( string array[ ], int n, int amount )
// rotate the array to the right amount spots, returning the total number of items rotated.
// return -1 if the array has no elements
{
    int count = -1;
    if (n > 0 && amount >= 0)
    {
        count = 0;
        for (int i = 0; i < amount; i++)
        {
            string rightmostElement = array[ n-1 ];
            for (int j = n-1; j >= 1 ; j--)
            {
                array[ j ] = array[ j-1 ];
                count = count + 1;
            }
            array[ 0 ] = rightmostElement;
            count = count + 1;
        }
    }
    return( count );
}

// my version
/*
int shiftLeft(string array[], int n, int amount, string placeholder) {
    if (n <= 0 || amount < 0) {
        return -1;
    }
    for (int k = 0; k < n - amount; k++) {
        array[k] = array[k + amount];
    }
    for (int k = n - amount; k < n; k++) {
        array[k] = placeholder;
    }
    if (amount > n) {
        return -1;
    }
    return amount;
}
*/

// correct version
int shiftLeft( string array[ ], int n, int amount, string placeholder )
// shift the array to the left amount spots
// fill in the right most items with the placeholder value
// returns the number of times the placeholder value was put into the array
// return -1 if the array has no elements
{
    int result = -1;
    if (n <= 0)
    {
        result = -1;
    }
    else if (amount < 0)
    {
        result = -1;
    }
    else
    {
        result = 0;
        for (int i = 0; i < amount; i++)
        {
            for (int j = 0; j < n-1 ; j++)
            {
                array[ j ] = array[ j+1 ];
            }
            array[ n-1 ] = placeholder;
            result = result + 1;
        }
    }
    if (result > n)
        result = n;
    return( result );
}

