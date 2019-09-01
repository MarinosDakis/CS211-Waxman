#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//this function checks if the row goes off the board
bool ok(int q[], int c){
  for (int i = 0; i < c; i++)
  if (q[i] == q[c] || abs(q[c] - q[i]) == c-i) return false;
 return true;
}

//this function backtracks to the previous valid state
void backtrack(int &col){
 col--;
if(col == -1) exit(1);
}

// this function prints out the 1d array in a board 
void print(int q[]){
 static int solutions = 0;

cout << "Solution #" << ++solutions << endl;
  for(int i = 0; i < 8; i++){
		 for(int j = 0; j < 8; j++){
if(q[i] == j) cout << "1" << " ";
  else cout << "0" << " ";
		}
	cout << endl;
	}
}

int main(){
int q[8] = {0}, c = 0;

bool from_backtrack = false;

while(true){
 while(c < 8){

if(!from_backtrack) { /*column section*/
c++; /*increase column number */
if (c == 8) break; /*check column number, break if c == 8*/
q[c]= -1; /*initialize row number */
}

from_backtrack = false;
 while(q[c] < 8){ /*row section*/
  q[c]++; /*increase row number */
  while (q[c] == 8){ /*check row number, call backtrack*/
  backtrack(c);
  q[c]++;
}
  if (ok(q,c)) break; /*call ok function, break if true */
  }
}

print(q) ; /*print section*/
backtrack(c); /*backtrack section*/
from_backtrack = true;
 }
}
