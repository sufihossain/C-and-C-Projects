// Hossain_Sufi_hw7_1.cpp
#include <iostream>
#define SEL 7            // 7 different donuts
#define TAXRATE 0.08     // tax rate = 8%

struct DONUT{   //declaring and defining a structure
    char item[20];
    double price;
    int quantity; 
};

int main()
{   int item_num {99};  //we initialize it at a random value
    int placeholder; //to simply hold a number
    std::cout << "Welcome to ECE114 Donut Cafe!\n";
    std::cout  << " No. |   Item Name        | Unit Price($)\n";
    std::cout  << "  1  | Apple Fritter      |   1.99\n";
    std::cout  << "  2  | Cinnamon Roll      |   1.49\n";
    std::cout  << "  3  | Chocolate Fry Cake |   1.29\n";
    std::cout  << "  4  | Hand-Cut Glaze     |   1.59\n";
    std::cout  << "  5  | Jelly Sticks       |   1.19\n";
    std::cout  << "  6  | White Cream        |   1.39\n";
    std::cout  << "  7  | Bavarian Cream     |   1.09\n\n";
    DONUT donuts[SEL]{  //we initialize quantity at 0
        {"Apple Fritter", 1.99 ,0},
        {"Cinnamon Roll", 1.49 , 0},
        {"Chocolate Fry Cake" ,1.29, 0 },
        {"Hand-Cut Glaze" , 1.59, 0},
        {"Jelly Sticks", 1.19,0 },
        {"White Cream", 1.39, 0},
        {"Bavarian Cream", 1.09, 0},
    };
    do{
        std::cout << "Which item do you want to purchase (0 to exit)? ";
        std::cin >> item_num;
        if(item_num == 0)   //we break and end;
            break;
        std::cout << "How many? ";
        std::cin >> placeholder;    //we use a place holder to not overwrite data in quantity
        donuts[item_num-1].quantity += placeholder; //here if someone wants more, we can just add more donuts
    }while(1);  //No input validation, as not required, hence it's it run as much as it wants
    std::cout << "\nReceipt:" << std::endl;
    double subtotal = 0;
    for(int i = 0; i < 7; i++){ //we print the items purchased
        if(donuts[i].quantity > 0){
            std::cout << donuts[i].quantity << " * " << donuts[i].item << std::endl;
            subtotal += donuts[i].quantity * donuts[i].price;
        }
    }
    std::cout << std::fixed;  //for the double values
    std::cout.precision(2); //printing them upto that decimal
    std::cout << "Subtotal: $" << subtotal<< std::endl;
    std::cout << "Tax: $" << subtotal * TAXRATE << std::endl;   //to display we can just do these simply
    std::cout << "Total: $" << (subtotal * TAXRATE) + subtotal << std::endl;
    std::cout << "\nThank you for shopping!";
    return 0;
}
/* PsuedoCode:
Welcome to ECE114 Donut Cafe!
No. | Item Name | Unit Price($)
 1 | Apple Fritter | 1.99
 2 | Cinnamon Roll | 1.49
 3 | Chocolate Fry Cake | 1.29
 4 | Hand-Cut Glaze | 1.59
 5 | Jelly Sticks | 1.19
 6 | White Cream | 1.39
 7 | Bavarian Cream | 1.09
Which item do you want to purchase (0 to exit)? 5
How many? 2
Which item do you want to purchase (0 to exit)? 1
How many? 4
Which item do you want to purchase (0 to exit)? 3
How many? 7
Which item do you want to purchase (0 to exit)? 0

Receipt:
4 * Apple Fritter
7 * Chocolate Fry Cake
2 * Jelly Sticks
Subtotal: $19.37
Tax: $1.55
Total: $20.92

Thank you for shopping!*/