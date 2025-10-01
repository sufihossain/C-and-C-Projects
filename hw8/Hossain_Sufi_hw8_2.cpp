// Hossain Sufi HW8 _ 2
#include <iostream>
#include <vector> //for the dynamic array as vectors
#include <ctime>    //for the time
#include <cstdlib>  //for the random functions

int main(int argc, char const *argv[])
{
    std::vector<int> numtick1, numtick5;   // dynamic array == vectors
    int num{};  //the input number
    int count1{}, count5{};  //counters
    std::string raffle; //response for the raffel
    std::cout << "   - - - - - 50/50 Raffle - - - - -\n   Record and select winners below!\n";
    std::cout << "\nEnter a raffle (\"one\" or \"five\" or quit with \"quit\"): ";
    while(true){    //we run it until break conditions are met
        std::getline(std::cin, raffle); //no need for input buffers
        std::cin.clear();   //incase if something raises a flag
        if(raffle == "one"){    //for first case
            std::cout << "Enter a ticket (1~500): "; 
            while(!(std::cin>> num) || num < 1 || num > 500){   //input validation
                std::cout << "Wrong! Try again: ";
                std::cin.clear();   //clear flag
                while(std::cin.get() != '\n'){} //to clear the buffer
            }
            while(std::cin.get() != '\n'){} //clear buffer
            numtick1.push_back(num);    //adding ticket nums to the vector
            count1++;   //counter for minimum rounds
            std::cout << "Enter a raffle (\"one\" or \"five\" or quit with \"quit\"): ";
        }else if(raffle == "five"){ //condition for $5 raffle
            std::cout << "Enter a ticket (1~500): ";
            while(!(std::cin >> num) || num < 1 || num > 500){   //input validation
                std::cout << "Wrong! Try again: ";
                std::cin.clear();
                while(std::cin.get() != '\n'){}
            }
            while(std::cin.get() != '\n'){}
            numtick5.push_back(num);
            count5++;
            std::cout << "Enter a raffle (\"one\" or \"five\" or quit with \"quit\"): ";
        }else if(raffle == "quit"){ //condition for quit
            if(count1 >= 2 && count5 >= 2)  //checking the counter condition
                break;
            else
                std::cout << "\nYou can't quit yet!\n\n";
            std::cout << "Enter a raffle (\"one\" or \"five\" or quit with \"quit\"): ";
        }else{
            std::cout << "Wrong! Try again: ";
        }
        continue;
    }
    srand((unsigned)time(NULL));    //random seed
    int random_num1 = rand() % numtick1.size(); //finding the random num first raffle
    int random_num5 = rand() % numtick5.size(); //second raffle
    std::cout << "\nThe winner of the $1 draw is ticket number " << numtick1[random_num1] << "! Winning $" << (int)((0.5)*(count1)) << "!\n"; //print with money
    std::cout << "The winner of the $5 draw is ticket number " << numtick5[random_num5] << "! Winning $" << (int)((0.5)*(count5)*5) << "!";
    return 0;
}
/* Psuedocode:
 - - - - - 50/50 Raffle - - - - -
 Record and select winners below!

Enter a raffle ("one" or "five" or quit with "quit"): ONE
Wrong! Try again: 1
Wrong! Try again: one
Enter a ticket (1~500): 55
Enter a raffle ("one" or "five" or quit with "quit"): five
Enter a ticket (1~500): 56
Enter a raffle ("one" or "five" or quit with "quit"): q
Wrong! Try again: quit

You can't quit yet!

Enter a raffle ("one" or "five" or quit with "quit"): five
Enter a ticket (1~500): 577
Wrong! Try again: fifty-seven
Wrong! Try again: 57
Enter a raffle ("one" or "five" or quit with "quit"): one
Enter a ticket (1~500): 66
Enter a raffle ("one" or "five" or quit with "quit"): five
Enter a ticket (1~500): 32
Enter a raffle ("one" or "five" or quit with "quit"): five
Enter a ticket (1~500): 194
Enter a raffle ("one" or "five" or quit with "quit"): five
Enter a ticket (1~500): 332
Enter a raffle ("one" or "five" or quit with "quit"): quit
The winner of the $1 draw is ticket number 55! Winning $1!
The winner of the $5 draw is ticket number 57! Winning $12!
*/