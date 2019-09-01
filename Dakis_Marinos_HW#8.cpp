#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {

  //helper array to compare which boxes to check
  int helper[8][5] = {
    {-1}, //row 0                   [0][1]
    {0,-1}, //row 1              [2][3][4][5]
    {0,-1}, //row 2                 [6][7]
    {0,1,2,-1}, //row 3
    {0,1,3,-1}, //row 4
    {1,4,-1}, //row 5
    {2,3,4,-1}, //row 6
    {3,4,5,6,-1} //row 7
  };
  
   //this checks if there is a duplicate number in the row
   for (int i = 0; i < c; i++)
   if( q[i] == q[c]) return false;

  //this checks if there is any adjacent diagonally
   for (int i = 0; i < 5; i++){
     if (helper[c][i] == -1) return true;
     if (abs(q[c] - q[helper[c][i]]) == 1) return false;
   }
   return true; 
}

void print(int q[]) {
	static int count = 0;
  	cout << " Solution number: " << ++count << endl;

  cout << " ";
  for (int i = 0; i < 2; i++) cout << q[i];
  cout << endl;
  for (int i = 2; i < 6; i++) cout << q[i];
  cout << endl << " ";
  for (int i = 6; i < 8; i++) cout << q[i];
  cout << endl;     
}

void next(int q[], int c) {
   if (c == 8) 
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c]) // Change to 1 and 9 for 8 numbers in a q, 0 and 3 for stable marriage
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}