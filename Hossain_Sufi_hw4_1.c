// Sufi Hossain hw4 Q1
#include <stdio.h>
#include <time.h>
#include <stdlib.h> // for srand() and rand()
#include <math.h>   // for sqrt()
int main()
{   //Psuedocode is written at the bottom!!!!
    int value1, value2; //the random values that gives chances between 1/5 and 1/2
    int players;    //for the number of players
    int topScore = 0, round = 0;    //other variables we need to complete the operations
    int playerScores[5] = {0};  //We initialize the scores of players to 0 in array
    char ch;    //our charater inputs
    printf("\n\t~~~~~ LETS PLAY DARTS! ~~~~~");
    int rows = 20;
    int cols = 20;
    int radius = 16;
    int sol = 0;
    for (int i = -rows; i < rows; i++)
    {
        for (int j = -cols; j < cols; j++)
        {
            sol = (sqrt((i * i) + (j * j)));
            if ((sol == radius) || (sol == radius / 4) || (sol == 15) || (sol == 10))
            {
                putchar('*');
            }
            else if (((((i == j) || (-i == j) || (i == 0) || (j == 0))) ||
                      ((-j < i) && (j > 0) && (!((i > 0) && (i < j)))) ||
                      ((j < -i) && (j < 0) && (!((i < 0) && (i > j))))) &&
                     (sol < radius) && (sol > radius / 4))
            {
                putchar('*');
            }
            else if ((i == 0) && (j == 0))
            {
                putchar('A');
            }
            else if ((i == -radius) && (j == -11))
            {
                putchar('B');
            }
            else if ((i == -radius) && (j == 11))
            {
                putchar('C');
            }
            else if ((i == -5) && (j == radius + 3))
            {
                putchar('D');
            }
            else if ((i == -5) && (j == -radius - 3))
            {
                putchar('I');
            }
            else if ((i == 5) && (j == radius + 3))
            {
                putchar('E');
            }
            else if ((i == 5) && (j == -radius - 3))
            {
                putchar('H');
            }
            else if ((i == radius) && (j == 11))
            {
                putchar('F');
            }
            else if ((i == radius) && (j == -11))
            {
                putchar('G');
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }   //Actual code is after this point
    srand((unsigned)time(NULL));    //finding the time for random numbers
    printf("How many players will play (1-4)? ");
    while((scanf("%d", &players) == 0) || players <= 0 || players >= 5){    //if out of bounds the we use this 
        printf("That is not a correct number of players. Try Again: ");
        while(getchar() != '\n'){}  //this line is to clear buffers
    }
    while(topScore < 4){     //We utilize a while as to find 
        round++;    //round counter
        printf("\n        ---- Round %d ---- ", round);
        for(int i = 1; i <= players; i++){  //changes for every player
            value1 = (rand()%5)+1; // chooses a value of 1 to 5
            value2 = (rand()%2)+1;  // chooses a value of 1 or 2 //printf("first: %d , second: %d", value1, value2); //This code is for TAs if they want to have easier hits
            printf("\nPlayer %d's turn! Pick a place to aim for (A~I): ", i);
            ch = getchar();
              //This is to avoid errors
            while(((ch = getchar()) == 0) || ch < 65 || ch  > 73){   //USING ASCII HERE & for invalid inputs
                printf("That is not a correct entry. Try Again: ");
                while(getchar() != '\n'){}  //This is to avoid errors
            }
            if(ch == 65){   //only for bullseye
                if(value1 == 4){
                    printf("Bullseye!");
                    playerScores[i] += 3;
                }else{
                    printf("Miss! :(");
                }
            }
            if(ch == 67 || ch == 69 ||ch == 71 ||ch == 73){ //the odd ASCII values, 73 is I
                if(value2 == 2){    //the number it has to match
                    printf("Hit!");
                    playerScores[i] += 1;
                }else{
                    printf("Miss! :(");
                }
            }
            if(ch == 66 || ch == 68 || ch == 70 ||ch == 72){    //the even ASCII values
                if(value2 == 1){
                    printf("Hit!");
                    playerScores[i] += 1;
                }else{
                    printf("Miss! :(");
                }
            }
            if(topScore < playerScores[i]){ //this is to set a topScore
                topScore = playerScores[i];
            }if(topScore >= 4){ //this is to getout when topScore is past 3
                break;
            }
        }
    }
    if(topScore == playerScores[1]) //This is just printing who won
        printf("\n\nPlayer 1 won!!!");
    else if(topScore == playerScores[2])
        printf("\n\nPlayer 2 won!!!");
    else if(topScore == playerScores[3])
        printf("\n\nPlayer 3 won!!!");
    else if(topScore == playerScores[4])
        printf("\n\nPlayer 4 won!!!");
    for(int i = 1; i <= players ; i++){ //this is printing the points
        printf("\nPlayer %d: ", i);
        for(int j = 0; j < playerScores[i]; j++){
            printf("@");
        }
    }
    return 0;
}
/*Psuedocode:
How many players will play (1-4)? Two
That is not a correct number of players. Try Again: 2
    ---- Round 1 ---- 
Player 1's turn! Pick a place to aim for (A~I): Middle
That is not a correct entry. Try Again: a
That is not a correct entry. Try Again: 2
That is not a correct entry. Try Again: A
Miss :(
Player 2's turn! Pick a place to aim for (A~I): G
Miss :(
    ---- Round 2 ---- 
Player 1's turn! Pick a place to aim for (A~I): J
That is not a correct entry. Try Again: $
That is not a correct entry. Try Again: h
That is not a correct entry. Try Again: H
Hit!
Player 2's turn! Pick a place to aim for (A~I): A
Miss :(
    ---- Round 3 ---- 
Player 1's turn! Pick a place to aim for (A~I): B
Hit!
Player 2's turn! Pick a place to aim for (A~I): A
Miss :(
    ---- Round 4 ---- 
Player 1's turn! Pick a place to aim for (A~I): D
Miss :(
Player 2's turn! Pick a place to aim for (A~I): C
Miss :(
    ---- Round 5 ---- 
Player 1's turn! Pick a place to aim for (A~I): B
Hit!
Player 2's turn! Pick a place to aim for (A~I): E
Miss :(
    ---- Round 6 ---- 
Player 1's turn! Pick a place to aim for (A~I): I
Hit!
Player 1 won!!!
Player 1: @@@@
Player 2:
*/