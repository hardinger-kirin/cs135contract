//Honors Contract Course Program - Hangman
//Kirin Hardinger
//12.3.2021 - 12.5.2021
//NOTE: this program does include a borrowed code snippet from my own program Project 10, madlibs.c (readbleStrLength function)

//preprocessor directives
#include <stdio.h>
#define MAX_PHRASE_LENGTH 100

//function prototypes
//reads file and saves the hangman phrase and hint phrase into their respective arrays. displays a starting/welcome screen
void gameSetup(FILE* fptr, char hangmanPhrase[], char hintPhrase[], char guessedPhrase[]);

//plays the game. runs displayHangman and processGuess functions
void gameLoop(char hintPhrase[], char guessedPhrase[], char hangmanPhrase[]);

//displays the hangman, hint for phrase, phrase as guessed [blanks and correctly-guessed characters], and the last-guessed letter
void displayHangman(char hintPhrase[], char guessedPhrase[], char previousLetter, int mistakeCount);

//processes the user's guess. Returns 1 for a hit, 0 for a miss
_Bool processGuess(char hangmanPhrase[], char guessedPhrase[], char* previousLetter);

//returns whether the user has won or not
_Bool hasWon(char guessedPhrase[]);

//returns the readable chaaracter length of a given string (no carriage returns, newlines, null characters)
int readableStrLength(char givenString[]);

int main(int argc, char* argv[]) {
    char *filename;
    FILE *fptr;

    char hangmanPhrase[MAX_PHRASE_LENGTH + 1];
    char hintPhrase[MAX_PHRASE_LENGTH + 1];
    char guessedPhrase[MAX_PHRASE_LENGTH + 1];

    //check for command arguments
    if (argc < 2) {
        printf("Include a hangman file name. Try again!\n");
        return 1;
    } else {
        filename = argv[1];
    }

    //open file and check for null
    fptr = fopen(filename, "r");

    if(!fptr) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    //start game
    gameSetup(fptr, hangmanPhrase, hintPhrase, guessedPhrase);

    //play game and evaluate win/lose
    gameLoop(hintPhrase, guessedPhrase, hangmanPhrase);

    //exit program
    return 0;
}

void gameSetup(FILE* fptr, char hangmanPhrase[], char hintPhrase[], char guessedPhrase[]) {
    int strLength;

    //save hangman phrase
    fgets(hangmanPhrase, MAX_PHRASE_LENGTH + 1, fptr);
    //null terminate the phrase
    strLength = readableStrLength(hangmanPhrase);
    hangmanPhrase[strLength] = '\0';

    //initialize guessedPhrase. put underscores for available letters and spaces for spaces
    for(int index = 0; hangmanPhrase[index] != '\0'; index++) {
        if(hangmanPhrase[index] == ' ') {
            guessedPhrase[index] = ' ';
        } else {
            guessedPhrase[index] = '_';
        }
    }
    //null terminate the phrase
    guessedPhrase[strLength] = '\0';

    //save hint phrase
    fgets(hintPhrase, MAX_PHRASE_LENGTH + 1, fptr);
    //null terminate the phrase
    strLength = readableStrLength(hintPhrase);
    hintPhrase[strLength] = '\0';

    //display title block and rules
    printf("***WELCOME TO HANGMAN***\n");
    printf("Enter your guess one character at a time (lowercase).\n");
    printf("You are allowed six mistakes! After that, it's GAME OVER.\n");
    printf("Good luck!\n\n");
}

void gameLoop(char hintPhrase[], char guessedPhrase[], char hangmanPhrase[]) {
    //initialize variables
    int mistakeCount = 0;
    char previousLetter = ' ';

    //loop the game as long as the player has neither lost nor won
    while(mistakeCount < 6 && !hasWon(guessedPhrase)) {
        //displays the hangman each round
        displayHangman(hintPhrase, guessedPhrase, previousLetter, mistakeCount);

        //prompts the user for their next guessed letter and processes if it's a hit or miss. if it's a miss, the mistake count increases by 1.
        if(!processGuess(hangmanPhrase, guessedPhrase, &previousLetter)) {
            mistakeCount++;
        }
    }

    //executes win/lose outcome
    if(hasWon(guessedPhrase)) {
        //display completed phrase
        printf("%s\n", guessedPhrase);

        //confetti! yay!!
        printf("|    .      !     ~\n");
        printf("    !   \"    .        ~\n");
        printf("  |  .     ~\n");
        printf(" !        !     .   .     .\n");

        printf("You won! Congratulations!\n");
    } else {
        //display completed hangman
        displayHangman(hintPhrase, guessedPhrase, previousLetter, mistakeCount);
        printf("\n\nHa ha, you lose! Better luck next time.\n");
    }
}

void displayHangman(char hintPhrase[], char guessedPhrase[], char previousLetter, int mistakeCount) {
    //display hangman
    switch(mistakeCount) {
        case 0:
            printf("--------------\n");
            printf("|            |\n");
            printf("|\n"); 
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            break;
        case 1:
            printf("\n\n\n");
            printf("--------------\n");
            printf("|            |\n");
            printf("|            _\n"); 
            printf("|           | |\n");
            printf("|            -\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            break;
        case 2:
            printf("\n\n\n");
            printf("--------------\n");
            printf("|            |\n");
            printf("|            _\n"); 
            printf("|           | |\n");
            printf("|            -\n");
            printf("|            |\n");
            printf("|            |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            break;
        case 3:
            printf("\n\n\n");
            printf("--------------\n");
            printf("|            |\n");
            printf("|            _\n"); 
            printf("|           | |\n");
            printf("|            -\n");
            printf("|           /|\n");
            printf("|            |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            break;
        case 4:
            printf("\n\n\n");
            printf("--------------\n");
            printf("|            |\n");
            printf("|            _\n"); 
            printf("|           | |\n");
            printf("|            -\n");
            printf("|           /|\\\n");
            printf("|            |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            break;
        case 5:
            printf("\n\n\n");
            printf("--------------\n");
            printf("|            |\n");
            printf("|            _\n"); 
            printf("|           | |\n");
            printf("|            -\n");
            printf("|           /|\\\n");
            printf("|            |\n");
            printf("|           /\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            break;
        case 6:
            printf("\n\n\n");
            printf("--------------\n");
            printf("|            |\n");
            printf("|            _\n"); 
            printf("|           |x|\n");
            printf("|            -\n");
            printf("|           /|\\\n");
            printf("|            |\n");
            printf("|           / \\\n");
            printf("|\n");
            printf("|\n");
            printf("--------------\n");
            
            //game is over: no need to show the hint, guessed phrase thus far, or previously guessed letter
            return;
            break;
        default:
            break;
    }

    //show the user the hint, phrase as has been guessed so far, and the previously guessed letter
    printf("%s\n", hintPhrase);
    printf("%s\n", guessedPhrase);

    printf("You previously guessed %c.\n", previousLetter);
    
    printf("\n");
}

_Bool processGuess(char hangmanPhrase[], char guessedPhrase[], char* previousLetter) {
    //initialize variables
    char guessedLetter;
    int numCorrectGuesses = 0;

    //prompt user for their guess
    printf("Enter your guess (one character).\n");
    scanf(" %c", &guessedLetter);
    *previousLetter = guessedLetter;

    //swapping the matching characters at the index
    //guessedPhrase was initialized to underscores and spaces while hangmanPhrase was initialized to the complete phrase from the file (gameSetup function)
    //by switching the characters stored at the index (using a temporary char variable), we can easily print the phrase as it has been guessed
    //underscores are preserved for unguessed letters, and correctly guessed ones are populated at the appropriate spot
    for(int index = 0; hangmanPhrase[index] != '\0'; index++) {
        if(hangmanPhrase[index] == guessedLetter) {

            char temp = hangmanPhrase[index];
            hangmanPhrase[index] = guessedPhrase[index];
            guessedPhrase[index] = temp;

            numCorrectGuesses++;
        }
    }

    if (numCorrectGuesses == 0) {
        return 0;
    } else {
        return 1;
    }
}

_Bool hasWon(char guessedPhrase[]) {
    //if there are still underscores remaining, then the user has not guessed all letters and has not won.
    for(int index = 0; guessedPhrase[index] != '\0'; index++) {
        if(guessedPhrase[index] == '_') {
            return 0;
        }
    }
    return 1;
}

int readableStrLength(char givenString[]) {
    int index;

    //iterate over each character in string to count number of characters
    for(index = 0; index < MAX_PHRASE_LENGTH; index++)
    {
        //do not count returns or new lines, and only read until null character
        if (givenString[index] == '\r' || givenString[index] == '\n' || givenString[index] == '\0')
        {
            break;
        }
    }

    return index;
}