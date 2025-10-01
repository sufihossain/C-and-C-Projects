// hw9_2.cpp: This is a completed file. You don't need to change anything.
#include <iostream>
#include "dice.h"

int rollAgain();  //returns 1 for another roll, returns 0 to quit program

int main(){
    
    /* Header */
    std::cout << "*** Yahtzee! ***\n";
    std::cout << "How many dice would you like to play with (2~6)? ";
    int n;  //number of dice

    /* Get number of dice */
    while(!(std::cin >> n) || n < 2 || n > 6){    //input validation
        std::cout << "Invalid input! Enter again: ";
        std::cin.clear();                                    //clear failbit
        while(std::cin.get() != '\n'){}                      //flush input buffer
    }
    while(std::cin.get() != '\n'){}

    /* Initialize dice for the game */
    Dice dice(n);                   

    /* Main game loop */
    while(rollAgain()){
        dice.roll();                //randomize dice
        dice.print();               //print dice
        dice.findScore();           //calculate and print score
    }
    
    /* End program */
    std::cout << "\nGood game!" << std::endl;

    return 0;
}

/* Roll again or quit? (input validation) */
int rollAgain(){
    std::string input;  //user input

    std::cout << "\nEnter r to roll or enter q to quit: ";

    while(true){       //repeat until input is valid
        std::getline(std::cin, input);

        if(input == "r")        //roll again
            return 1;

        else if(input == "q")   //quit
            return 0;

        else{
            std::cout << "Invalid input! Enter again: ";
        }
    }
}