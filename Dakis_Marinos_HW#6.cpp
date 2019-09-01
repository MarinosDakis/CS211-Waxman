#include <iostream>
#include <cmath>
using namespace std;

int main (){
  int q[8], c = 0, solutions = 0;
  q[0] = 0;

NC:
  c++;
  if (c == 8) goto print;
  q[c] = -1;

NR:
  q[c]++;
  if(q[c] == 8) goto backtrack;


//row test combined with diag test
for (int i = 0; i < c; i++)
  if (q[i] == q[c] || abs(q[c] - q[i]) == c-i) goto NR;
  goto NC;
  

backtrack: 
  c--;
  if (c == -1) return 0;
  goto NR;

print:
 cout << "Solution #" << ++solutions << endl;
  for(int i = 0; i < 8; i++){
		 for(int j = 0; j < 8; j++){
if(q[i] == j) cout << "1" << " ";
  else cout << "0" << " ";
		}
	cout << endl;
	}
      goto backtrack;
}
