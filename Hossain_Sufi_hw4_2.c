// Sufi Hossain hw4 Q2
#include <stdio.h>
int main(int argc, char const *argv[])
{   //PsuedoCode is at the end!!!
    char input, ch; //we only need two variables, for first enter and send value
    printf("Welcome to Two Truths and a Lie!\nYou will be given three statements,and your job will be to determine which\nis a lie.\npress enter/return to continue.");    //No duplicate statements!
    while((input = getchar()) != '\n'){ //to only get a enter and not anything else
        //printf("only click enter/return please"); //statement could be said if anything else is typed but wasn't specified in hw examples
        while(getchar() != '\n');   //we clear the buffer
    }
    printf("\nStatement A: I came from Bangladesh.");
    printf("\nStatement B: I completed my high school in NYC.");
    printf("\nStatement C: I lived in Florida.");
    printf("\nEnter the letter that corresponds to the statement you think is a lie: ");
    while((ch = getchar()) == 0 || ch != 'A' ||  ch != 'a' || ch != 'B' || ch != 'b' || ch != 'C' || ch != 'c' ){   //while is for if anything is incorrect
        switch (ch){    //We use switches for this
            case 'A' : case 'a' :
                printf("\nSorry! I was born and raised in Bangladesh.\n\nOops, you lost. Try again!");
                break;
            case 'B' : case 'b' :
                printf("\nSorry! I moved to NYC when I began high school.\n\nOops, you lost. Try again!");
                break;
            case 'C' : case 'c' :
                printf("\nCorrect! I never lived in Florida.\n\nCongratulations! You won!");
                break;
            default:
                printf("Invalid input! Enter A, B, or C: ");
                while(getchar() != '\n');
        }
        if(ch == 'A' ||  ch == 'a' || ch == 'B' || ch == 'b' || ch == 'C' || ch == 'c' ){   //to get out of the while loop
            break;
        }
    }
    return 0;
}
/*PsuedoCode:
Welcome to Two Truths and a Lie!
You will be given three statements, and your job will be to determine which
is a lie.
Press enter/return to continue.

Statement A: I came from Bangladesh.
Statement B: I completed my highschool in NYC.
Statement C: I lived in Florida.
Enter the letter that corresponds to the statement you think is a lie: C

Correct! I never lived in Florida.

Congratulations! You won!*/