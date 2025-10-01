// dice.cpp: by (Sufi Hossain)
#include <iostream>
#include <ctime>    //for the time
#include <cstdlib> //for the random function
#include "dice.h"   

Dice::Dice(int n){   // default constructor
    num_dice = n;   //number of dice at play
    for(int i = 0; i < num_dice; i++){  
        values.push_back(0);    //adding to the vector
    }
    srand((unsigned)time(NULL)); //random seed
}

void Dice::roll(){      //roll function definition
    for(int i = 0; i < num_dice ; i++){
        values[i] = rand()%6 + 1;   //+1 for 1 to 6
    }
} 

void Dice::print() const{    //a constant print function 
    for(int i = 0; i < num_dice ; i++){
        std::cout << "[ " << values[i] << " ] ";
    }
}

void Dice::findScore() const{   
    int counter = 0;    //counter to validate Yahtzee
    int score = values[0];  //we start with the first score 
    for(int i =1; i < num_dice ; i++){  //this is to valudate yahtzee, we start at 1
        if(values[i-1] == values[i]){
            counter++;
        }
        score += values[i]; //adding score
    }
    if(counter == (num_dice-1)){    //Yathzee or not
        score = (values[0] * num_dice *2);
        std::cout << "\nYahtzee!\nScore: " << score; 
    }
    else{
        std::cout << "\nScore: " << score;  //if not Yathzee
    }

}   
