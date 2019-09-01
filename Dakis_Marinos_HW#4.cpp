#include <iostream>
using namespace std;

int main() {
  int b[8][8]={0},row,col,solutions;
  //place Queen
  b[0][0]=1;

  NextCol:
  col++;
  if(col==8)goto print;
  row=-1;

  NextRow:
  row++;
  if(row==8)goto backtrack;

//row test
  for(int i = 0; i < col; i++){
    if(b[row][i])goto NextRow;
    }

//upper diag
for(int i = 1;(row - i) >= 0 && (col - i) >= 0; i++){
 if(b[row - i][col - i]) goto NextRow;
}

//lower diag
for(int i = 1;(row + i) < 8 && (col - i) >= 0; i++){
  if(b[row + i][col - i]) goto NextRow;
}

b[row][col]=1;
goto NextCol;

backtrack:
      col--;
    if (col == -1) return 0;     
      row = 0;      
      while(b[row][col] != 1)
      row++;
      b[row][col]=0;
      goto NextRow;

print:
      cout << "Solution #" << ++solutions << endl;
      //Use a nested loop to print the chessboard
    for(int i = 0; i < 8; i++){
		 for(int j = 0; j < 8; j++){
			cout << b[i][j] << " ";
      
		}
	cout<<endl;
	}
      goto backtrack;
}
