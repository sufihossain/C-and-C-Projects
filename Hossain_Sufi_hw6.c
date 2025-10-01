// Hossain_Sufi_hw6.c
#include <stdio.h>
#include <string.h> // for strstr and strlen
#include <ctype.h> //for the isupper and toupper conversions etc
#define N_CONFIDENTIAL 1 /* Number of words to redact at each security level */
#define N_SECRET 3
#define N_TOPSECRET 6
#define N_SIZE 10   /* Maximum length of word to redact */
#define LENGTH 100  /* Maximum message length is less than 100 */

void capitalize(char * );   //For capitilization
void redact(char *, const char [][N_SIZE], int);

int main(){
    //Psuedocode at the end...
    const char * securityLevels[4] = {"UNCLASSIFIED", "CONFIDENTIAL", "SECRET", "TOP SECRET"};  //Security Levels
    const char confidentialWords[N_CONFIDENTIAL][N_SIZE] = {"COOKIE"};    // Words to Redact
    const char secretWords[N_SECRET][N_SIZE] = {"TONY", "COOKIE", "JAR"};
    const char topSecretWords[N_TOPSECRET][N_SIZE] = {"TONY", "COOKIE", "JAR", "TAKE", "EVAN", "SAW"};
    int level;  //the level inputted
    char text[LENGTH];  //the sentence string array
    printf("~~~~ AUTO REDACTION 3000 ~~~~\nLEVELS OF CLASSIFICATION:\n");
    for(int i = 0; i < 4; i++ )
        printf("%9d: %s\n", i, securityLevels[i]);
    printf("\nEnter level of classification (0~3): ");
    while(scanf("%d", &level) != 1 || level < 0 || level > 3){  //if any incorrect input
        printf("INVALID ENTRY. Enter again:");
        while(getchar() != '\n');   //Clearing input buffer
    }
    while(getchar() != '\n');  //Clearing input buffer
    printf("\nEnter your %s message here:\n", securityLevels[level]);
    fgets(text, LENGTH, stdin); //taking input for message
    capitalize(text);   //we make it into uppercase first
    if (level == 1){
        redact(text, confidentialWords, N_CONFIDENTIAL);    //depending on confindentiality level the redaction is done
    }else if (level == 2){
        redact(text, secretWords, N_SECRET);
    }else if (level == 3){
        redact(text, topSecretWords, N_TOPSECRET);
    }
    printf("\nHere is your message:\n%s", text);    //the redacted message printed
    return 0;
}

void capitalize(char * text){   //function definitions
    for(int i = 0; i < strlen(text)-1; i++){        //the minus 1 is there to clear the \n for the line
        if(isalpha(text[i])){   //incase if its a space or anything else
            if(isupper(text[i])){       //to check if it's upper case already
                text[i] = text[i];
            }
            else if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
        }
        else
            text[i] = text[i];
    }
}
void redact(char *text, const char words[][N_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        char *local = text; // strstr moves the pointer to right before the location of the first letter where the word was found 
        while ((local = strstr(local, words[i])) != NULL) {  //essentially until there are no more redactable words
            for (int j = 0; j < strlen(words[i]); j++) { //we can use words[i] as we need the whole row of chars, so don't do words[][]
                local[j] = '#'; // Replace the word with '#'
            }
        }
    }
}

/*Psuedocode:
~~~~ AUTO REDACTION 3000 ~~~~
LEVELS OF CLASSIFICATION:
    0: UNCLASSIFIED
    1: CONFIDENTIAL
    2: SECRET
    3: TOP SECRET

Enter level of classification (0~3): three
INVALID ENTRY. Enter again: -1
INVALID ENTRY. Enter again: 4
INVALID ENTRY. Enter again: 0

Enter your UNCLASSIFIED message here:
Evan saw Tony take a cookie from the cookie jar!

Here is your message:
EVAN SAW TONY TAKE A COOKIE FROM THE COOKIE JAR!
*/