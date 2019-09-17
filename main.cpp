/* ------------------------------------------------
   prog1RockPaperScissors.cpp
 
   Program #1: Play the game of Paper / Rock / Scissors against the computer.
   Class: CS 141
   Author: *** Hao Phan ***
	 
	 See the program description page on the course web site at bit.ly/cs141
	 Within Codio you can run the solution by doing the following steps:
   1. Select the Tools / Terminal menu option
	 2. Within the terminal window, type in:  ./solution

   Grading Rubric:
		 55 Execution points
						  Option 1: (Computer always chooses R) and:
					 2		 User input of X immediately exits program
					 3		 User input of x (lower case) immediately exits program
				  10		 Program handles both lower and upper case user input (e.g. 'r' and 'R'); also
					          move number increments each move
				  15		 Score updates correctly for all user inputs: r, p, s
						  Option 2: Computer's move is random and:
					 7		 Predetermined input sequence correctly leads to computer win
				   8		 Predetermined input sequence correctly leads to human win
		         Option 3: 
           2     Correctly displays and updates the graphical score
		       8     Correctly displays and updates the graphical score, with assessment results hidden

		 45 Programming Style (Given only if program runs substantially correctly)
					10 Meaningful identifier names
					10 Comments: Has header.  Comments on each block of code.
					15 Appropriate data and control structures.  Code duplication is avoided.
					10 Code Layout: Appropriate indentation and blank lines.
 
   Having sample program output is not required within this header of your program, though it is helpful.
	 
	 
*/
/***
 * Mallavarapu: Avoid repetition of code
 * ***/

#include <iostream>    // For cin and cout
#include <cstdlib>     // For rand()
using namespace std;


//-----------------------------------------------------------------------------------------
int main()
{
    // Display Instructions
    cout << "CS 141 Program #1: Rock/Paper/Scissors                                \n"
         << endl
         << "Welcome to the game of Rock/Paper/Scissors where you play against     \n"
         << "the computer.  On each move the computer will choose R, P, or S, then \n"
         << "the user will be prompted for their choice, and then the score will   \n"
         << "be updated.  P beats R, R beats S, and S beats P. The score starts    \n"
         << "at 0.  Add one if the person wins, subtract one if the computer wins. \n"
         << "The game ends if the score reaches -5 or + 5.                         \n"
         << "User input of 'x' or 'X' causes the game to exit.                     \n"
         << endl
         << "Here we go!  \n"
         << endl;
    
//make a define for the program;
    int gameScore = 0;
    char playerChoice = ' ';
    char computerChoice;
    int computerChoiceVersion;
    int yourTurn = 1;
    cout << "Select how the computer chooses its move: \n"
         << "1. Always choose Rock \n"
         << "2. Random guess \n"
         << "3. Random guess with graphical score \n"
         << "Enter your choice: ";
    cin >> computerChoiceVersion;
    cout << endl;
  
//main loop of game;
    while ((gameScore > -5)&&(gameScore < 5)){
        playerChoice = toupper(playerChoice);
//Option 1: computer always chose R;
        if (computerChoiceVersion == 1){
            computerChoice == 'R';
            cin >> playerChoice;
            playerChoice = toupper(playerChoice);
            cout << yourTurn << "." << " Your move:" << endl;
//Exit game: press x or X;
            if (playerChoice == 'X'){
                yourTurn += 1;
                break;
            }
//if-else statement: when player make choice;
            if (playerChoice == 'R'){
                yourTurn += 1; 
                gameScore += 0;
                cout << "   Computer Chose " << 'R' << endl;
                cout << "   Tie. Score: " << gameScore << endl;
                cout << "" << endl;
            }
            else if ( playerChoice == 'S'){
                yourTurn += 1; 
                gameScore -= 1;
                cout << "   Computer Chose " << 'R' << endl;
                cout << "   Computer's point. Score: " << gameScore << endl;
                cout << "" << endl;
            }
            else if (playerChoice == 'P'){
                yourTurn += 1; 
                gameScore += 1;
                cout << "   Computer Chose " << 'R' << endl;
                cout << "   User's point. Score: " << gameScore << endl;
                cout << "" << endl;
            }
            else {
                cout << "please input a valid choice!" << endl;
            }
        }
//option 2: computerChoice will choose random R,P,S;
        if (computerChoiceVersion == 2){
            cout << yourTurn << "." << " Your move: ";
            cin >> playerChoice;
            playerChoice = toupper(playerChoice);
            computerChoice = rand() % 3;
//conversion: when the computer receives 0, it will convert to a value of R;
            if (computerChoice == 0){
                computerChoice = 'R';
//Exit game: press x or X;
                if (playerChoice == 'X'){
                    yourTurn += 1;
                    break;
                }
//if-else statement: when player make choice; 
                if (playerChoice == 'R'){
                    yourTurn += 1;
                    gameScore += 0;
                    cout << "   Computer chose " << 'R' << endl;
                    cout << "   Tie. Score: " << gameScore << endl; 
                }
                else if ( playerChoice == 'S'){
                    yourTurn += 1; 
                    gameScore -= 1;
                    cout << "   Computer chose " << 'R' << endl;
                    cout << "   Computer's point. Score: " << gameScore << endl; 
                }
                else if (playerChoice == 'P'){
                    yourTurn += 1; 
                    gameScore += 1;
                    cout << "   Computer chose " << 'R' << endl;
                    cout << "   User's point. Score: " << gameScore << endl; 
                }
                else {
                    cout << "please input a valid choice!" << endl; 
                }
                }
//conversion: when the computer receives 1, it will convert to a value of P;
            if (computerChoice == 1){
                computerChoice = 'P';
//Exit game: press x or X;
                if (playerChoice == 'X'){
                    yourTurn += 1;
                    break;
                }
//if-else statement: when player make choice; 
                if (playerChoice == 'R'){
                    yourTurn += 1; 
                    gameScore -= 1;
                    cout << "   Computer chose " << 'P' << endl;
                    cout << "   Computer's point. Score: " << gameScore << endl; 
                }
                else if ( playerChoice == 'S'){
                    yourTurn += 1; 
                    gameScore += 1;
                    cout << "   Computer chose " << 'P' << endl;
                    cout << "   User's point. Score: " << gameScore << endl;
                }
                else if (playerChoice == 'P'){
                    yourTurn += 1; 
                    gameScore += 0;
                    cout << "   Computer chose " << 'P' << endl;
                    cout << "   Tie. Score: " << gameScore << endl; 
                }
                else {
                    cout << "please input a valid choice!" << endl; 
                }
                } 
//conversion: when the computer receives 2, it will convert to a value of S;
            if (computerChoice == 2){
                computerChoice = 'S';
//Exit game: press x or X;
                if (playerChoice == 'X'){
                    yourTurn += 1;
                    break;
                }
//if-else statement: when player make choice;  
                if (playerChoice == 'R'){
                    yourTurn += 1; 
                    gameScore += 1;
                    cout << "   Computer chose " << 'S' << endl;
                    cout << "   User's point. Score: " << gameScore << endl; 
                }
                else if ( playerChoice == 'S'){
                    yourTurn += 1; 
                    gameScore += 0;
                    cout << "   Computer chose " << 'S' << endl;
                    cout << "   Tie. Score: " << gameScore << endl; 
                }
                else if (playerChoice == 'P'){
                    yourTurn += 1; 
                    gameScore -= 1;
                    cout << "   Computer chose " << 'S' << endl;
                    cout << "   Computer's point. Score: " << gameScore << endl; 
                }
                else {
                    cout << "please input a valid choice!" << endl; 
                }
                }
        }
//option 3: have Graphical output shown;
        if (computerChoiceVersion == 3){
            cout << yourTurn << "." << " Your move: ";
            cin >> playerChoice;
            playerChoice = toupper(playerChoice);
            computerChoice = rand() % 3;
//conversion: when the computer receives 0, it will convert to a value of R;
            if (computerChoice == 0){
                computerChoice = 'R';
//Exit game: press x or X;
                if (playerChoice == 'X'){
                    yourTurn += 1;
                    break;
                }
//if-else statement: when player make choice and computer will show graphical score; 
                if (playerChoice == 'R'){
                    yourTurn += 1;
                    gameScore += 0;
                    cout << "   Computer chose " << 'R' << endl;
                    cout << "   Tie. Score: " << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else if ( playerChoice == 'S'){
                    yourTurn += 1;
                    gameScore -= 1;
                    cout << "   Computer chose " << 'R' << endl;
                    cout << "   Computer's point." << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else if (playerChoice == 'P'){
                    yourTurn += 1;
                    gameScore += 1;
                    cout << "   Computer chose " << 'R' << endl;
                    cout << "   User's point." << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else {
                    cout << "please input a valid choice!" << endl;
                }
                }
//conversion: when the computer receives 1, it will convert to a value of P;
            if (computerChoice == 1){
                computerChoice = 'P';
//Exit game: press x or X;
                if (playerChoice == 'X'){
                    yourTurn += 1;
                    break;
                }
//if-else statement: when player make choice and computer will show graphical score;                 
                if (playerChoice == 'R'){
                    yourTurn += 1;
                    gameScore -= 1;
                    cout << "   Computer chose " << 'P' << endl;
                    cout << "   Computer's point." << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else if ( playerChoice == 'S'){
                    yourTurn += 1; 
                    gameScore += 1;
                    cout << "   Computer chose " << 'P' << endl;
                    cout << "   User's point." << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else if (playerChoice == 'P'){
                    yourTurn += 1; 
                    gameScore += 0;
                    cout << "   Computer chose " << 'P' << endl;
                    cout << "   Tie. Score: " << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else {
                    cout << "please input a valid choice!" << endl;
                }
                } 
//conversion: when the computer receives 2, it will convert to a value of S;
            if (computerChoice == 2){
                computerChoice = 'S';
//Exit game: press x or X;
                if (playerChoice == 'X'){
                    yourTurn += 1;
                    break;
                }
//if-else statement: when player make choice and computer will show graphical score;  
                if (playerChoice == 'R'){
                    yourTurn += 1;
                    gameScore += 1;
                    cout << "   Computer chose " << 'S' << endl;
                    cout << "   User's point." << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else if ( playerChoice == 'S'){
                    yourTurn += 1;
                    gameScore += 0;
                    cout << "   Computer chose " << 'S' << endl;
                    cout << "   Tie. Score: " << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else if (playerChoice == 'P'){
                    yourTurn += 1;
                    gameScore -= 1;
                    cout << "   Computer chose " << 'S' << endl;
                    cout << "   Computer's point." << endl;
                    cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5" << endl;
                    cout << "   ----------------------------------" << endl;
                    cout << "   ";
                    for (int i=0; i < gameScore + 5; i++){
                    cout << "...";
                    }
                    cout << "..^" << endl;
                }
                else {
                    cout << "please input a valid choice!" << endl; 
                }
                }
                }
    }
//end of main loop: The computer will give results depending on the player's choice and the match result.
    if(((computerChoiceVersion == 1) && (playerChoice == 'X')) || ((computerChoiceVersion == 1) && (gameScore > -5))||((computerChoiceVersion == 1) && (gameScore < 5))){
        if (gameScore == 0){ 
            cout << "Exiting program..." << endl;
            cout << "Tie game!" << endl;
        }
        else if (gameScore > 0){ 
            cout << "User wins!" << endl;
        }
        else { 
            cout << "Computer wins!" << endl;
        }

        cout << endl << "Ending program..." << endl;
        }
    else if(((computerChoiceVersion == 2) && (playerChoice == 'X')) || ((computerChoiceVersion == 2)&&(gameScore > -5)) || ((computerChoiceVersion == 2) && (gameScore < 5))){
        if (gameScore == 0){ 
        cout << "Exiting program..." << endl;
        cout << "Tie game!" << endl;
        }
        else if (gameScore > 0){ 
        cout << "User wins!" << endl;
        }
        else { 
        cout << "Computer wins!" << endl;
        }

        cout << endl << "Ending program..." << endl;
        }
    else if(((computerChoiceVersion == 3) && (playerChoice == 'X')) || ((computerChoiceVersion == 3) && (gameScore > -5)) || ((computerChoiceVersion == 3) && (gameScore < 5))){
        if (gameScore == 0){ 
          cout << "Exiting program..." << endl;
          cout << "Tie game!" << endl;
        }
        else if (gameScore > 0){
          cout << "Exiting program..." << endl; 
          cout << "User wins!" << endl;
        }
        else {
          cout << "Exiting program..." << endl; 
          cout << "Computer wins!" << endl;
      }
          cout << endl << "Ending program..." << endl;

      }
    
    
    return 0;   // Keep C++ happy
}//end main()
