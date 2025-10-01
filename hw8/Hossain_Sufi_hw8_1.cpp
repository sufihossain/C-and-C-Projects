// Hossain_Sufi_hw8_1.cpp: Template for ECE114 HW8, Q1
#include <iostream>
#include <fstream>  // for reading file
#include <string>   // for std::string
#include <vector>   // for std::vector
#include <cctype>   // for tolower and isalpha (optional)

enum {ARG_PROGNAME, ARG_INFILE, ARG_NARGS}; // indices for argv

int main(int argc, char const *argv[])
{
    if(argc != ARG_NARGS){  // value 2
        std::cout << "Usage: " << argv[ARG_PROGNAME] << " textfile.txt\n";
        return EXIT_FAILURE;    //this ends program with returning 1
    }
    std::ifstream myfile(argv[ARG_INFILE]); //myfile is an object of the type ifstream that will handle stuff
    // or std::ifstream myfile(argv[TEXTFILE]);
    if(myfile.is_open() != 1){
        std::cout << "Unable to open " << argv[ARG_INFILE] << std::endl;
        return EXIT_FAILURE;
    }
    std::vector<std::string> PWords;    //the vector for palindromes
    std::string Placeholder;   // the random line placeholder
    while(!(myfile.eof())){ //Until end of line file
        myfile >> Placeholder;  //It inputs every string one by one
        bool condition =  true;   //bool for adding into PWords
        if(Placeholder.size() <= 1){ //it fails if a single letter
            condition = false;
            continue;
        }
        for(int i = 0 ; i < (int)(Placeholder.size()/2) ; i++){    //seeing is it's equal
            if(isalpha(Placeholder[i])){    
                if(tolower(Placeholder[i]) != tolower(Placeholder[Placeholder.size() - i-1])){
                    condition = false;
                    break;  //this ONLY breaks out of for loop
                }
            }else if(!(isalpha(Placeholder[i]))){
                condition = false;
                break;
            }
        }
        if(condition == true){  //it will only add if conditions are met
            PWords.push_back(Placeholder);
        }
        continue;
    }
    myfile.close();
    std::cout << "The total number of palindromes: " << PWords.size() << std::endl;
    std::cout << "Palindrome(s):\n";
    for(int i = 0 ; i < PWords.size() ; i++){
        std::cout << PWords[i] << std::endl;
    }
    return 0;
}
/* PsuedoCode:
Sample	Output	#1 (Not	enough	command-line	arguments.)
hajim-ece-mll1:hw8 mlee42$ ./LastName_FirstName_hw8_1
Usage: ./LastName_FirstName_hw8_1 textfile.txt

Sample	Output	#2: (Do	not	have	that	file	in	the	directory or	could	not	open	
that	file.)
hajim-ece-mll1:hw8 mlee42$ ./LastName_FirstName_hw8_1 Waly.txt
Unable to open Waly.txt

Sample	Output	#3: (Too	many	command-line	arguments)
hajim-ece-mll1:hw8 mlee42$ ./LastName_FirstName_hw8_1 file1.txt
file2.txt
Usage: ./LastName_FirstName_hw8_1 textfile.txt

Sample	Output	#4: (Read	file1.txt.)
hajim-ece-mll1:hw8 mlee42$ ./LastName_FirstName_hw8_1 file1.txt
The total number of palindromes: 0

Sample	Output	#5:	(Read	file2.txt.)
hajim-ece-mll1:hw8 mlee42$ ./LastName_FirstName_hw8_1 file2.txt
The total number of palindromes: 18
Palindrome(s):
Radar
Solos
civic
tenet
Level
Racecar
Noon
Kayak
Madam
Deified
Rotator
Dad
Anna
Reviver
Pop
WoW
refer
ABCDcba */