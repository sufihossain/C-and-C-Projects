// Sufi Hossain HW5 Q2
#include <stdio.h>

void printArray(int * arr, int size);   //for printing the array
void shiftLeft(int * arr, int size, int pos);   //Declaration for shifting left
void multiply(int * arr, int size, int amount); //multiplying the numbers and printing

int main(int argc, char const *argv[]){
    int length;  // array length
    int shift;   // left shift amount
    int multiple;   //the multiple amount
    printf("Welcome to use the \"Array Shifter and Multiplier\" Program.\n");   // Retrieve Parameters from user
    printf("Enter the size of an integer array (3~15): ");
    while(scanf("%d", &length) == 0 || length < 3 || length > 15){
        printf("Wrong input! Enter again: ");
        while(getchar() != '\n'){}   // clear the input buffer for the invalid input
    }
    while(getchar() != '\n'){}   // clear the input buffer for the valid input
    int nums[length];	// Create a dyanmic array of Size requested by user
    for(int i = 0; i < length ; i++){   //Taking inputs
        printf("Enter integer #%d: ", i+1);
        while(scanf("%d", &nums[i]) == 0){  //if input isnt a number
            printf("Wrong input! Enter again: ");
            while(getchar() != '\n');
        }
    }
    while(getchar() != '\n');
    printArray(nums, length);   //calling the function printArray
    printf("\n\nHow many positions do you want to shift to the left (1~%d)? ", length-1);   //the shift must be 1 less than size
    while(scanf("%d", &shift) == 0 || shift < 1 || shift > (length-1)){
        printf("Wrong input! Enter again: ");
        while(getchar() != '\n'){}   // clear the input buffer for the invalid input
    }
    while(getchar() != '\n');
    shiftLeft(nums, length, shift);
    printf("\n\nEnter an integer to multiply each element of the array? ");
    while(scanf("%d", &multiple) == 0){
        printf("Wrong input! Enter again: ");
        while(getchar() != '\n'){}   // clear the input buffer for the invalid input
    }
    while(getchar() != '\n');
    multiply(nums, length, multiple);
    return 0;
}

void printArray(int * arr, int size){   //Defining the functions
    printf("Array:");
    for(int i = 0; i < size; i++){
        printf(" %d", *(arr + i));  //pointer arithmetic notation
    }
}
void shiftLeft(int * arr, int size, int pos){
    int localArray[size];   //We create  a local variable to first transfer the array into their positions
    for(int i = 0; i < size; i++){  
        if(i<pos){  
            localArray[size-pos+i] = arr[i];    //to move the arrays that with wrap arounf to the right side
        }else if(i >= pos){
            localArray[i-pos]= arr[i];  // for those that will move left
        }
    }
    for(int i = 0; i < size; i++){
        arr[i] = localArray[i]; //now giving those values in their positon back to the original
    }
    printArray(arr, size);  //printing the array using another function
}
void multiply(int * arr, int size, int amount){ //multiple declaration
    printf("Array:");
    for(int i = 0; i < size; i++){
        int number = *(arr + i);
        printf(" %d", amount*number);   //we directly multiply and output the value
    }
}

/* Psuedo Code:
Welcome to use the "Array Shifter and Multiplier" Program.
Enter the size of an integer array (3~15): 15
Enter integer #1: 15
Enter integer #2: 14
Enter integer #3: 13
Enter integer #4: 12
Enter integer #5: 11
Enter integer #6: 10
Enter integer #7: 9
Enter integer #8: 8
Enter integer #9: 7
Enter integer #10: 6
Enter integer #11: 5
Enter integer #12: 4
Enter integer #13: 3
Enter integer #14: 2
Enter integer #15: 1
Array: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

How many positions do you want to shift to the left (1~14)? 9
Array: 6 5 4 3 2 1 15 14 13 12 11 10 9 8 7          // if i is less than shuft: new i = (size - (shift - i))
                                                    // if i is equal to or greater:  new i = i - shift
Enter an integer to multiply each element of the array? -4
Array: -24 -20 -16 -12 -8 -4 -60 -56 -52 -48 -44 -40 -36 -32 -28*/