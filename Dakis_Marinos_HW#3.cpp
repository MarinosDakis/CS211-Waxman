#include <iostream>
using namespace std;

int main() {

  begin:
  
    cout << "Input a string of uppercase characters indicating the outcome of a race: ";
    
    startLoop:
     
      string outcome; // outcome of race
      int numberOfTeams = 0; // The number of teams
      int totalScore['Z' + 1] = {}; // scores[i] keeps track of the total score of team i
      int numberOfRunners['Z' + 1] = {}; // counts[i] keeps track of the number of runners on team i

    
      cin >> outcome;

      // If the user entered "done", exit the program
      if (outcome == "done") return 0;

      // For each runner in the race,
      for (int i = 0; i < outcome.length(); ++i) { 

         // Increase the team's score by the runner's rank (the rank is 1 more than the index)
          totalScore[outcome[i]] = (i + 1 + totalScore[outcome[i]]);
        
         // If it's the first runner of that particular team, update the total number of teams
         if (numberOfRunners[outcome[i]] == 0) ++numberOfTeams;

         // Update the number of runners on the team
          numberOfRunners[outcome[i]]++;
         }

      // If the teams do not all have the same number of runners,
      for (int i = 0; i <'Z'+ 1; i++){
      if(numberOfRunners[i] != 0 && numberOfRunners[i] != numberOfRunners[outcome[0] ] ) {
      // Print an error message and ask for input again (go back to the beginning of the loop)
      cout << "An error has occured, please input the outcome of the race again: \n";
          
          goto startLoop;
      }
    }
      
      // Print the number of teams
      cout << "There are " << numberOfTeams << " teams\n";

      // Print the number of runners on each team

      cout << "Each team has " << numberOfRunners[outcome[0]] << " runners\n";
      
      //Declarations for winningOutcome:
      char winningOutcome = outcome[0];
      double averageWinner = (double)totalScore[outcome[0]]/numberOfRunners[outcome[0]];
      
      // For each letter from A-Z,
      for (int i = 'A'; i <'Z'+ 1; i++){
        double averageParticipant = (double)totalScore[i]/numberOfRunners[i];

         // If that team participated,
         if (numberOfRunners[i] != 0){
           
           // Print the name of the team and its average score   
           cout << (char)(i) << " : with an average score of " << (double)averageParticipant << "\n";
         }
      // Also keep track of which team(s) has the best score
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
   }
   cout << "The winner is team " << winningOutcome << " with an average score of: " << (double)averageWinner << endl;

   goto begin;

      }