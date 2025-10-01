//Hossain Sufi HW7 Q2
#include <iostream>

int main(int argc, char const *argv[])
{
    FILE * fp;
    fp = fopen("dictionary.txt", "w");  // we first open the file for writing
    if (argc != 2){  
        std::cout << "Usage: " << argv[0] << " filename\n";
        exit(EXIT_FAILURE); // return 1 and ends program
    }
    if ((fp = fopen(argv[1], "r")) == NULL){ //So we have the dictionary, and we compare it to see if opens, if not, then invalid
        std::cout << "Can't open "<< argv[1];
        exit(EXIT_FAILURE); //returns 1 and ends program
    }
    fp = fopen(argv[1] ,"w"); //we open the current file and overwrite or make one
    for(int i = 0; i< 10; i++){ //for the 0 to 9
        for(int j = 0; j < 2; j++){ //for the  r or R
            for(int k = 0; k<2 ; k++){  //for the first e or 3
                for(int l = 0; l<2; l++){   //for the c or C
                    for(int m = 0; m < 2; m++){ //for the a or 4
                        for(int n = 0; n < 2; n++){ //for the second e or 3
                            fprintf(fp, "%c%cd%c%crp%ct%d\n", (j%2 == 0)? 'r' : 'R', (k%2 == 0)? 'e' : '3', (l%2 ==0)? 'c' : 'C', (m%2 ==0)? 'a' : '4', (n%2 ==0)? 'e' : '3', i );
                        }   //for each of the iterations, if odd we print one option, and for even we print another, thats why the if else conditions are there
                    }
                }
            }
        }
    }
    fclose(fp); // we close the file
    return 0;
}
/*Psuedo Code:
Sample	Run #1 (no	command-line	arguments):
hajim-ece-mll1:hw7 mlee42$ ./LastName_FirstName_hw7_2
Usage: ./LastName_FirstName_hw7_2 filename.txt

Sample	Run#2 (more	than	1	command-line	argument):
hajim-ece-mll1:hw7 mlee42$ ./LastName_FirstName_hw7_2 dictionary.txt ^_^
Usage: ./LastName_FirstName_hw7_2 filename.txt

Sample	Run#3	(Invalid	file	name):
hajim-ece-mll1:hw7 mlee42$ ./LastName_FirstName_hw7_2 dic/tionary.txt
Cannot open dic/tionary.txt

Sample	Run#4	(Correct	output):
hajim-ece-mll1:hw7 mlee42$ ./LastName_FirstName_hw7_2 dictionary.txt*/