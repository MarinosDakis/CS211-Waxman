#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

bool ok(int q[], int c) {
  for (int i = 0; i < c; i++)
  if (q[c] == q[i] || abs(q[c] - q[i]) == c-i) return false;
 return true;
}

int nqueens(int n){
  int numSolutions = 0, c = 0;
  // Dynamically declare an array of size n and initialize the first element to 0.
   int *q;
   q = new int [n];
   q[0] = 0;

   // Start in the 1st row, 1st column

   while (c >= 0) { // End the loop if you backtrack from the first column
      c++;// Move to the next column
      if (c == n){// If you have passed the last column,
          c--; // Call the print function and backtrack
       numSolutions++;
    }   
      else q[c] = -1;// Otherwise, move to one before the first row
      while (c >= 0) {
         // Move to the next row
         q[c]++;
         // If you have passed the end of the column, backtrack
         if(q[c] == n) c--;
         // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop
          else
           if(ok(q,c)) break;   
      }
   }
   delete [] q; 
   return numSolutions;
 }

int main() {
  int n;
  cout << "How many variations of the nQueens would you like to try? ";
  cin >> n;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
}

