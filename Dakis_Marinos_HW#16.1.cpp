#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Returns the cost of the shortest path from the left to the square in row i, column j.
int cost(int r, int c) {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};

   // Declare the cost matrix.
   static int memo[NUM_ROWS][NUM_COLS] = {0};

   // Check for the base case.
   if (c == 0){
   path[r][0] = to_string(r);  
   return weight[r][0];
   } 
   
  // If the cost has already been calculated, return it.
   if(memo[r][c] != 0) return memo[r][c];
  
   // Calculate the costs of the 3 adjacent squares by calling the function recursively.
   int up = cost((r+4)%5, c-1);
   int left = cost(r, c-1);
   int down = cost((r+1)%5, c-1);
   // Find the minimum of the 3 costs.
   int minCost = min(up,min(left, down));

// Update the path matrix (store the path to the current square in path[i][j]):

   // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
  if (minCost == up)
      path[r][c] =  path[(r+4)%5][c-1] + to_string(r);

   // If left is the minimum...
   if (minCost == left)
      path[r][c] =  path[r][c-1] + to_string(r);

   // If down is the minimum..
   if (minCost == down)
      path[r][c] =  path[(r+1)%5][c-1] + to_string(r);

   // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
   memo[r][c] = weight[r][c] + minCost;
   return memo[r][c];
}
  
int main() {
       int ex[NUM_ROWS];
	   
	//store elements in last column in temp array
      for(int i = 0; i < NUM_ROWS; i++) ex[i] = cost(i,NUM_COLS-1);
	  
    // now find the smallest of them    
    // get the shortest path out of each cell on the right
       int minRow = ex[0];
       int index = 0;
       for (int i = 0; i < NUM_ROWS; i++){
          if (ex[i] < minRow) minRow = ex[i];
          index = i;
       }
      
   cout << "The length of the shortest path is " << minRow << ".";

   cout << "\nThe rows of the path from left to right are " << path[index][NUM_COLS-1] << ".";

   return 0;
}
