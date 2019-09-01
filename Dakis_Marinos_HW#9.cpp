#include <iostream>
using namespace std;

bool ok(int q[], int c){

static int mp[3][3] = {
              { 0,2,1 }, // Man#0's preferences
							{ 0,2,1 }, // Man#1's preferences
							{ 1,2,0 }  // Man#2's preferences
};	
						
static int wp[3][3] = { 
              { 2,1,0 }, // Woman#0's preferences
							{ 0,1,2 }, // Woman#1's preferences
							{ 2,0,1 }  // Woman#2's preferences
 }; 

//Check if the woman is already married
  for (int i = 0; i < c; i++){
    if (q[c] == q[i]) return false;
 
 // we check for the preference of the 
    for(int i = 0; i < c; i++){
      
      //this checks if Man#c likes Man#i's wife more than his own wife, if the value is lower then it means the person likes the other more, && if man#i's wife likes man c more
      if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false;
      
      //this checks if Man#i likes Man#c's wife more than his own wife, if the value is lower then it means the person likes the other more, && if man#c's wife likes man i more
      if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
  }
 }
 return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution " << ++solution <<":" << endl << "Man" << " " << "Woman" << endl;
   //Finish this print function
	 for (int i = 0; i < 3; i++)
      cout << i << "   " << q[i] << endl;
}

void next(int q[], int c) {
   if (c == 3) 
      print(q);
   else for (q[c] = 0; q[c] < 3; ++q[c]) // Change to 1 and 9 for 8 numbers in a q, 0 and 3 for stable marriage
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[3];
   next(q, 0);
   return 0;
}
