// Hossain_Sufi_hw9_1.cpp
#include <iostream>
#include <sstream>  //for isstreamstring
#include <string>   //for the string
#include <cstring>  //for the length

struct Complex{
    double real;   //for the real number
    double imag;   //for the imaginary number
};

void extraction(std::string &string, Complex &a);  //for extraction
void addition(Complex a, Complex b);    //addition prototype
void multiplication(Complex a, Complex b);  //mult prototype

int main(int argc, char const *argv[])
{   Complex a;  //for the first complex
    Complex b;  //second complex
    std::string str1, str2; //input strings
    std::cout << "=== Complex Numbers ===\nEnter a+bj: ";
    std::getline(std::cin, str1);   //getting the entire line
    std::cout << "Enter c+dj: ";
    std::getline(std::cin, str2);
    std::string placeholder1 = "\0", placeholder2 = "\0";   //initializing placeholder strings
    for(int i = 0; i < str1.length(); i++){ //deleting spaces if there are any
        if(str1[i] != ' '){
            placeholder1 += str1[i];    //appending it into the new string
        }
    }
    str1 = placeholder1;    //putting it back into the original
    for(int i = 0; i < str2.length(); i++){
        if(str2[i] != ' '){
            placeholder2 += str2[i];
        }
    }
    str2 = placeholder2;    //isstringstream essentially takes each piece of data one by one
    extraction(str1, a);
    extraction(str2, b);
    
    /*std::istringstream iss(str1);   //so we have objects of iss for str1
    iss >> a.real >> a.imag;    //we parse it and get the relevant details
    std::istringstream isk(str2);   //objects for isk for str2
    isk >> b.real >> b.imag;*/
    std::cout << "\n=== Addition ===\n";    
    std::cout << "(" << str1 << ") * (" << str2 << ") : ";
    addition(a, b); //function call
    std::cout << "\n\n=== Multiplication ===\n" << "(" << str1 << ") * (" << str2 << ") : ";
    multiplication(a,b);

	return 0;
}

void extraction(std::string &string, Complex &name){   //pass by ref
    std::istringstream iss(string);
    iss >> name.real >> name.imag;
}


void addition(Complex a, Complex b){    
    double real = a.real + b.real;  //we do simple arthmetic for the functions 
    double imag = a.imag + b.imag;
    if(imag >= 0)
        std::cout << real << "+" << imag << "j";    //we display the + as it's hidden by default
    else
        std::cout << real << imag << "j";
}

void multiplication(Complex a, Complex b){
    double real = (a.real * b.real) + (-1 * a.imag * b.imag );  //we take i^2 is -1 into account and perform calculation
    double imag = (a.imag * b.real) + (a.real * b.imag);
    if(imag >= 0)
        std::cout << real << "+" << imag << "j";
    else
        std::cout << real << imag << "j";
}

/*Psuedo code:
Enter a+bj: 3.2 + 2.5j
Enter c+dj: -1.9 - 6.2 j

=== Addition ===
(3.2+2.5j) + (-1.9-6.2j) = 1.3-3.7j

=== Multiplication ===
(3.2+2.5j) * (-1.9-6.2j) = 9.42-24.59j
*/