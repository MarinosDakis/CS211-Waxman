#include <iostream>
#include <cmath>
using namespace std;

//Each time you place a bishop on a square, you must check for conflicts with previous bishops. If the row difference is the same as the column difference, they are in the same diagonal. 

//To calculate the row and column (pass n as a parameter to the ok function): 
//Row = position / n 
//Column = position % n

bool ok(int q[], int c, int n) {
  for (int i = 0; i < c; i++)
   if(abs(q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n)) return false;
   return true;
}

// The function below is from a working n queens program.
// Add a 2nd parameter, k, and modify the function so that it will work for the k bishops program.
// You will have to change the board representation,
// the conditions for when you've found a solution and when to backtrack, and the ok function call.
int kbishops(int n, int k) {
   int* q = new int[k];
   q[0] = 0;
   int c = 0, solutions = 0;
   while (c >= 0) {
      ++c;
      if (c == k) {
         ++solutions;
         --c;
      }
      else
      //Each time you go to the next bishop, instead of starting on the first square, start at the position of the previous bishop
         q[c] = q[c-1];
      while (c >= 0) {
         ++q[c];
         //if you have placed all k bishops on the chessboard. Backtrack after you have run out of squares (on the entire board) on which to place the current bishop.
         if (q[c] == pow(n,2))
            --c;
         else if (ok(q, c, n))
            break;
      }
   }
   delete[] q;
   return solutions;
}

int main() {
   int n, k;
   while (true) {
      cout << "Enter value of n: ";
      cin >> n;
      if (n == -1)
         break;
      cout << "Enter value of k: ";
      cin >> k;
      cout << "number of solutions: " << kbishops(n, k) << "\n";
   }
   return 0;
}