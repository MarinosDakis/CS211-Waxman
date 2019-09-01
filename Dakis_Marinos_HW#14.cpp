#include <iostream>
#include <vector>
using namespace std;

int main() {
 vector<int> t[3];
 int n;
 cout << "How many initial rings do you want? ";
 cin >> n;

 // The initial value of to depends on whether n is odd or even
 int from = 0, to = 1, move = 0;
 if (n%2 == 0) to = 2;

 for(int i = n + 1; i >= 1; i--)
  // Initialize the towers;
   t[0].push_back(i); 
   t[1].push_back(n+1);
   t[2].push_back(n+1);

   // while t[1] does not contain all of the rings [middle tower]
 while(t[1].size() < n+1){
     cout << "Move #" << ++move << ": Transfer ring " << t[from].back() << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

 //move the top element of tower "from" to tower "to"
   t[to].push_back(t[from].back());
   t[from].pop_back();

 /*
 from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3

 to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3 
*/
 
 //even variation [ <--- left direction]
 if(n%2 == 0) {
   if(t[(to + 1)%3].back() < t[(to + 2)%3].back())
     from = (to + 1)%3;
    else
     from = (to + 2)%3;
     
   if(t[from].back() < t[(from + 2)%3].back())
     to = (from + 2)%3;
    else 
     to = (from + 1)%3;
 }

//odd variation [right direction --->]
if(n%2 != 0) {
   if(t[(to + 1)%3].back() < t[(to + 2)%3].back())
     from = (to + 1)%3;
    else
     from = (to + 2)%3;

   if(t[from].back() < t[(from + 1)%3].back())
     to = (from + 1)%3;
    else 
     to = (from + 2)%3;
}

  }
 }
