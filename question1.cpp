// question 1!
#include <iostream>

void zeroSmaller(int &n1, int &n2 );

int main(int argc, char const *argv[])
{
    int num1, num2;
    std::cout << "Enter the 1st integer (> 0): ";
    while(!(std::cin >> num1) || num1 <1){
        std::cin.clear();
        while(std::cin.get() != '\n'){}
        std::cout << "Wrong input! Enter again: ";
    }
    while(std::cin.get() != '\n'){}
    std::cout << "Enter the 2nd integer (> 0): ";
    while(!(std::cin >> num2) || num2 <1){
        std::cin.clear();
        while(std::cin.get() != '\n'){}
        std::cout << "Wrong input! Enter again: ";
    }
    while(std::cin.get() != '\n'){}
    std::cout << "Call the zeroSmaller function...\n";
    zeroSmaller(num1, num2);
    std::cout << "The 1st integer: " << num1;
    std::cout << "\nThe 2nd integer: " << num2;
    return 0;
}

void zeroSmaller(int &n1, int &n2 ){
    if(n1 > n2){
        n2=0;
    }else if(n2 > n1){
        n1=0;
    }else{
        n1=0;
        n2=0;
    }
}


/*
Enter the 1st integer (> 0): 0
Wrong input! Enter again: Minus Five
Wrong input! Enter again: 18
Enter the 2nd integer (> 0): -5
Wrong input! Enter again: 2
Call the zeroSmaller function...
The 1st integer: 18
The 2nd integer: 0
*/