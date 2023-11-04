
// Declared libaries
#include <stdio.h>
#include <stdlib.h>
//New liabaries 
#include <time.h>
#include <string.h>

// Call macro
#define ROWS 4
#define COLS 4
#define LETTERS 26
#define DICE 16
#define SIDES 6
#define TRUE 1
#define FALSE 0
#define SPACE ' '
// New Macros (Assignment 4)
#define NAME 20
#define WORDS 100
#define LENGTH 17 
#define MAX 10
// New preprossesor commands (Update assignment 5)
#define TIME 180


// struct creates a variable multiples  
typedef struct Player_struct {
   char name[NAME];
   char words[WORDS][LENGTH];
   int score;
   int count;
} Player;

// calls functions (calling the function before the main helps call it after)
void welcomeScreen();
void clearScreen();
void displayExplicitBoard();
void displayBoard(char board[ROWS][COLS]);
void displayDice();
void createBoard();
char getLetter();
// New Function prototypes
void playGame(Player *one, char board[ROWS][COLS]);
void displayWordsFound(Player *One);
// Update for assignment 5 (Function prototypes)
void scoreWords(Player *one);
int getWordLength(char words[LENGTH]);


int main(){

    char dice[DICE][SIDES] = {

        {'D','R','L','X','E','I'}, // row 0 
        {'C','P','O','H','S','A'}, // row 1
        {'N','H','N','L','Z','R'}, // row 2
        {'W','T','O','O','T','A'}, // row 3
        {'I','O','S','S','E','T'}, // row 4
        {'N','W','E','G','H','E'}, // row 5
        {'B','O','O','J','A','B'}, // row 6
        {'U','I','E','N','E','S'}, // row 7
        {'P','S','A','F','K','F'}, // row 8
        {'I','U','N','H','M','Q'}, // row 9
        {'Y','R','D','V','E','L'}, // row 10
        {'V','E','H','W','H','R'}, // row 11
        {'I','O','T','M','U','C'}, // row 12
        {'T','Y','E','T','T','R'}, // row 13
        {'S','T','I','T','Y','D'}, // row 14
        {'A','G','A','E','E','N'}  // row 15 (total rows 16)
    
    };
    
    char board [ROWS][COLS];

    int usedDie[DICE];
    // update assignment 4
    Player one; 

    // initialize arryas to 0
    memset (usedDie, FALSE, sizeof(usedDie));
    memset (board, SPACE, sizeof(board)); //found an example of memset on google images was help ful 

    // randomizes 
    srand(time(0));

    // Calling function
    welcomeScreen();
    // C  alling function
    clearScreen();
    // Calling funciton
    //displayExplicitBoard(); //update for assignment 3

    // Updates for assignment 2
    //clearScreen(); //update for assignment 3
    // displayBoard(board);

    // Updates for assignment 3
    //displayDice(dice); //(commentnt out for Assignment 4)
    //clearScreen(); //(commentnt out for Assignment 4) 
    createBoard(dice, board, usedDie);
    //displayBoard(board); //(commentnt out for Assignment 4)
    playGame(&one, board);

    return 0;
}


void welcomeScreen (){
    /* This project will require students to randomly generate a Boggle board. The player will have
three minutes to find as many words as possible. Words are created with three letters or more.
Words are formed from adjoining letters. Letters must join in the proper sequence to spell a
word. Letters may join horizontally, vertically, or diagonally, to the left, right, up or down. No
letter cube may be used more than once in a single word. Player words submitted will be scored
accordingly. */

    // title of the welcome screen.
    printf("BBBBB    OOOO    GGGGG    GGGG    LL      EEEEE\n");
    printf("BB  BB  OO  OO  GG       GG       LL      EE\n");
    printf("BBBBB   OO  OO  GG       GG       LL      EEEE\n");
    printf("BB  BB  OO  OO  GG  GGG  GG  GGG  LL      EE\n");
    printf("BBBBB    OOOO    GGGGGG   GGGGGG  LLLLLL  EEEEEE\n");

    // Displays rules for game
    printf("RULES OF THE GAME\n");
    printf("\t1. The player is presented with Boggle board\n");
    printf("\t2. The player will have three minutes to find as many words as possible.\n");
    printf("\t3. Words must contain three letters or more.\n");
    printf("\t4. Words are formed from adjoining letters.\n");
    printf("\t5. Letters must join in the proper sequence to speell a word.\n");
    printf("\t6. Letters may join horizontally, vertically, or diagonally, to the left, right, up or down.\n");
    printf("\t8. Player words submitted will be scored accordingly.\n");
    printf("\t9. Good luck!\n");

}

// clears Screen (different for windows or MacOS/Linux)
void clearScreen(){

    char enter;

    printf("\t\tHit <Enter> to continue\n");

    scanf("%c", &enter);
    // cls for windows
    //system("cls");
    // clear is for MacOS/Linux
    system("clear");
}

// displays Board
void displayExplicitBoard(){

    printf("|-------------------------------|\n");
    printf("|          BOGGLE BOARD         |\n");
    printf("|-------------------------------|\n");
    printf("|   T   |   A   |   O   |   C   |\n");
    printf("|-------------------------------|\n");
    printf("|   L  |    I   |   S   |   M   |\n");
    printf("|-------------------------------|\n");
    printf("|   U   |   N   |   B   |   I   |\n");
    printf("|-------------------------------|\n");
    printf("|   B   |   O   |   G   |   D   |\n");
    printf("|-------------------------------|\n");


}

// displays randomly generated numbers for the board 
void displayBoard(char board[ROWS][COLS]){

// local Variables
    int row, col; //num; // update assignement 3
    //char letter; // update assignment 3

// header board
    printf("|-------------------------------|\n");
    printf("|          BOGGLE BOARD         |\n");
    printf("|-------------------------------|\n");

// outer Loop for rows
    for(row = 0; row < ROWS; row++) {
        // Inner loop for the collums
        for(col = 0; col < COLS; col++) {

            // generate random number
            //board[row][col] = rand() % LETTERS;

            // convert number to character based on decimal value
            //board[row][col] = 'A' + board[row][col];

            // display randomly generated number 
            printf("|   %c   ", board[row][col]);

        }
        printf("|"); // Adds final line for asthetic purpose 
        printf("\n|-------------------------------|\n");
    }



}

// Displays the diced on the board as its randomized 
void displayDice(char dice[DICE][SIDES]){
  // declare variables 
  int row, col;
  printf("BOGGLE DICE\n\n");
    for(row = 0; row < DICE; ++row){
      printf(" Die %d\n",row + 1);
        for(col = 0; col < SIDES; ++col){

            printf(" %c ", dice[row][col]); // prints arrays value in the board
            
        }
        // prints new line for readability 
      printf("\n");
    }
  
}
// creates the letter board as its randomized...used the get letter function 
void createBoard(char dice[DICE][SIDES], char board[ROWS][COLS], int usedDie[DICE]){
  // declare variables
  char letter;
  int row, col, die;
  // uses loops to create board and put letters in the board. 
  for(row = 0; row < ROWS; ++row){
    col = 0;
    while (col < COLS){
      die = rand()% DICE;
      
      // changes the dice if = 0 (false) to true put letters on the board 
      if(usedDie[die] == FALSE ){
        
        letter = getLetter(dice,die);

        board[row][col] = letter;
        // changes dices value 
        usedDie[die] = TRUE;

        ++col; //increments col by 1 
         
      }
    }
  }

}
// gets letter  for the dice used in create baord funciton. 
char getLetter(char dice[DICE][SIDES], int row){
    // declare variables 
    char letter;
    int col;

    // randomize letters 
    col = rand()% SIDES;
    letter = dice[row][col];

    // retuns the letter variable 
    return letter;

}

// runs the game
void playGame(Player *one, char board[ROWS][COLS]){

  // declare local variables
  int play = TRUE; // (20)
  int idx = 0; 
  // update assignment 5
  // local variables
  unsigned int seconds = 0;
  unsigned int milliseconds = 0;
  int timeLeft = 0; // **changed from unsigned due to markle email**
  unsigned int countDownTimeSecs = TIME;
  clock_t startTime;
  clock_t countTime;

  printf("Enter your name:\n"); //asks user for name 
  scanf("%s", one->name); //stores users name 

  // initializes variables to 0 
  one->count = 0; 
  one->score = 0; 

  clearScreen(); // calls clear function

  printf("%s Lets play Boggle \n\n", one->name);

  //update assignment 5
  startTime = clock();
  timeLeft = countDownTimeSecs - seconds;

  displayBoard(board); // display board is moved here after update (assignment 5)

  //runs trough loop till it breaks was TRUE till Assignment 5
  while (timeLeft > 0){

    //displayBoard(board); //calls function //commented out and moved (update assignment 5)
    // update assigment 5 
    // local variables within while loop
    countTime = clock();
    milliseconds = countTime - startTime;
    seconds =  milliseconds/ CLOCKS_PER_SEC;
    timeLeft = countDownTimeSecs - seconds;

    printf("Enter word than press <Enter> when finished:\n"); // asks user for input

    scanf("%s", one->words[idx]);// stores variables in an array
    printf("\n");

    //incriments variables
    ++one->count;
    idx++;
    
    // conditonal statement to break from loop // commented out for assignment 5
    /*if(one->count >= MAX){
      
      break; // breaks out of loop
      
    }*/ //if statement commented out for assignment 5 
  }
  
  printf("\nTime is up!\n"); // (update assignment 5)
  
  displayWordsFound(one); // calls function to this function 

  scoreWords(one);// update assignment 5
  
}

// shows words found 
void displayWordsFound(Player *one){
  
  // control variable for loop
  int w;
  
  printf("Words found 10:\n");//prints words found 
  // loops trough the words already typed 
  for (w = 0; w < one->count; ++w){
    printf("%s\n", one->words[w]);//prints words from an array 
  }
  
}  


// update assignment 5

// gets length for words 
int getWordLength (char words[LENGTH]){
  // local variables
  int count = 0;
  int idx = 0; 
  // while loop that gets the length of words
  while(words[idx] != '\0'){

    //incriment variables 
    ++count;
    ++idx;
  
  }
  return count; 
}

// gets score 
void scoreWords(Player *one){
// for loop to loop trough the amount of words for scoring
  for(int i = 0; i < one->count; ++i){
    //the length of words is = to length 
    int length = getWordLength(one->words[i]);

  // try a switch statement if possible (note for self) or use sizeof statement
   
    // shows different cases for scores 
    switch (length) {
      case 0:
        one->score += 0; 
        break;
      
     case 1:
        one->score += 0; 
        break;
      
     case 2:
        one->score += 0; 
        break;
      
     case 3:
        one->score += 1;
        break;
      
     case 4:
        one->score += 1; 
        break;
      
     case 5:
        one->score += 2; 
        break;
      
     case 6:
        one->score += 3;
        break;
      
    case 7:
        one->score += 4; 
        break;
      
    case 8:
        one->score += 11; 
        break;
  
     case 9:
        one->score += 11;
        break;
      
     case 10:
        one->score += 11; 
        break;
  
     case 11:
        one->score += 11; 
        break;
  
     case 12:
        one->score += 11;
        break;

     case 13:
        one->score += 11; 
        break;
  
     case 14:
        one->score += 11; 
        break;
  
     case 15:
        one->score += 11;
        break;
      
     case 16:
        one->score += 11; 
        break;
  
     case 17:
        one->score += 11; 
        break;

      }
    }
  printf("Your Score is %d", one->score); //prints score for words 
}