#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int r = 5, c = 6;
string path[r][c];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[r][c] = {{3,4,1,2,8,6},
                             {6,1,8,2,7,4},
                             {5,9,3,9,9,5},
                             {8,4,1,3,2,6},
                             {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int memo[r][c] = {0};

   // Copy the leftmost column of the weight matrix to the cost matrix. 
   for (int i = 0; i < r; i++){
   memo[i][0] = weight[i][0]; 

   //initialize the leftmost column of the path matrix.
   path[i][0] = to_string(i);
   }
   
     // For each remaining col, Calculate the cost of each square in the rows (non-recursively),
     int minCost = 0;

     for (int j = 1; j < c; j++)
       for (int i = 0; i < r; i++){
         int up = memo[(i+4)%5][j-1];
         int left = memo[i][j-1];
         int down = memo[(i+1)%5][j-1]; 

     //store the correct number in the cost matrix and the correct string in the path matrix.
        minCost = min(up,min(left, down));

     // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
  if (minCost == up)
      path[i][j] =  path[(i+4)%5][j-1] + to_string(i);

   // If left is the minimum...
   if (minCost == left)
      path[i][j] =  path[i][j-1] + to_string(i);

   // If down is the minimum..
   if (minCost == down)
      path[i][j] =  path[(i+1)%5][j-1] + to_string(i);

   // Calculate the cost of the current square, store the correct number in the cost matrix
     memo[i][j] = weight[i][j] + minCost;
     }
    
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
       
       //store elements in last column in temp array
       int temp[] = {0};
       for(int i = 0; i < c; i++)
       temp[i] = memo[i][5];
       
       //search inside temp array to find min value
       int minRow = temp[0];
       int index = 0;
       for(int i = 0; i < c-1; i++){
       if(temp[i] < minRow) {
         minRow = temp[i];
         index = i;
       }
      }

   cout << "The length of the shortest path is " << minRow;
   cout << ".\nThe rows of the path from left to right are " << path[index][c-1] << ".";
}

int main() {
   calculateCosts();
   return 0;
}