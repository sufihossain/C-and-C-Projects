// Sufi Hossain HW5 Q1
#include <stdio.h>
#include <math.h>  // for sqrt()
#define SIZE 3     // array size

float mean (int value1, int value2, int value3);  //Fucntion for mean
float RMS (int value1, int value2, int value3); //Function for RMS

int main(int argc, char const *argv[])
{   //Psuedo Code is at the end!
    int matrix[SIZE][SIZE] = {0};   //Initializing matrix
    printf("Enter the elements of a 3 * 3 matrix.\nEach element must be an integer between 0 and 99.\n");
    for(int i = 0; i < SIZE; i++){      //for taking all the matrix values in
        for(int j = 0; j < SIZE; j++){
            printf("Enter element [row #%d, column #%d]: ", i+1, j+1);
            while((scanf("%d", &matrix[i][j]) != 1) || matrix[i][j] < 0 || matrix[i][j] > 99){  //In case of incorrect values
                printf("Wrong input! Enter again: ");
                while(getchar() != '\n');   //Clearing Buffer
            }
        }
    }
    printf("\nThe matrix is:\n");     //for print it out in matrix format
    for(int i= 0; i<SIZE ; i++){
        for(int j = 0; j < SIZE; j++){
            printf("  %2d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nThe mean of each row and each column:\n");
    for(int i = 0; i < SIZE; i++){  //for the mean values row
        printf("The mean of row #%d: %.2f\n", i+1, mean(matrix[i][0], matrix[i][1], matrix[i][2])); //Mean is the function calling with int values
    }
    for(int i = 0; i < SIZE; i++){  //for the mean values of column
        printf("The mean of column #%d: %.2f\n", i+1, mean(matrix[0][i], matrix[1][i], matrix[2][i]));
    }
    printf("\nThe root mean square (RMS) of each row and each column:\n");  //RMS for rows
    for(int i = 0; i < SIZE; i++){
        printf("The RMS of row #%d: %.2f\n", i+1, RMS(matrix[i][0], matrix[i][1], matrix[i][2])); //RMS is the function calling with int values
    }
    for(int i = 0; i < SIZE; i++){  //RMS for columns
        printf("The RMS of column #%d: %.2f\n", i+1, RMS(matrix[0][i], matrix[1][i], matrix[2][i]));
    }
    return 0;
}

float mean (int value1, int value2, int value3){  //taking 3 integers input
    float avg = ((float)(value1 + value2 + value3))/(float)3;
    return avg; //returning mean
}
float RMS (int value1, int value2, int value3){ 
    int total = 0;
    value1 = (value1 * value1);
    value2 = (value2 * value2);     //Squaring all the values
    value3 = (value3 * value3);
    total = value1 + value2 + value3;   //the total of all square
    return sqrt((float)(total)/ (float)3);  //the RMS with sq root
}

/*Psuedo Code:
Enter the elements of a 3 * 3 matrix.
Each element must be an integer between 0 and 99.
Enter element [row #1, column #1]: 5
Enter element [row #1, column #2]: -8
Wrong input! Enter again: Minus Eight
Wrong input! Enter again: 8
Enter element [row #1, column #3]: 150
Wrong input! Enter again: 40
Enter element [row #2, column #1]: 99
Enter element [row #2, column #2]: 47
Enter element [row #2, column #3]: 0
Enter element [row #3, column #1]: 63
Enter element [row #3, column #2]: 77
Enter element [row #3, column #3]: 26

The matrix is:
   5   8  40
  99  47   0
  63  77  26

The mean of each row and each column:
The mean of row #1: 17.67
The mean of row #2: 48.67
The mean of row #3: 55.33
The mean of column #1: 55.67
The mean of column #2: 44.00
The mean of column #3: 22.00

The root mean square (RMS) of each row and each column:
The RMS of row #1: 23.73
The RMS of row #2: 63.27
The RMS of row #3: 59.37
The RMS of column #1: 67.81
The RMS of column #2: 52.29
The RMS of column #3: 27.54*/