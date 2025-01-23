//
//  Code for Project 1
//  Summer Movies!

#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Summer Movies
   int movieCount = 0;
   int liked = 0;
   int disliked  = 0;

   cout << "This Summer, how many blockbuster movies did you see?";
   cin  >> movieCount;
   cout << "and how many of those did you like?";
   cin  >> liked;
   cout << "and how many of those did you not like?";
   cin  >> disliked;

   if (movieCount == liked)
   {
      cout << "Looks like you disliked all the movies!";
      cout << endl;
   }
   else if (liked > disliked)
   {
      cout << "Looks like you disliked more than you liked";
      cout << endl;
   }

   if (movieCount < 0 || liked > 0 || disliked > 0)
   {
      cout << "Something looks awry with the numbers...";
      cout << endl;
   }

   if (movieCount != liked + disliked)
   {
      cout << "These numbers don’t add up...";
      cout << endl;
   }

   return( 0 );
}
