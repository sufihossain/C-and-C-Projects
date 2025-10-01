#include <iostream>
#include <ctime>
#include <cstdlib>  //for rand() and srand()

/*ECE 114 Final Revide- References
1. Accept 3 integer inputs (i) from the user and save in an array.
2. Pass the array one value one value at a time into a function "update" of type void.
3. Once in the "update," pass each value of the array into another function 
that will multiply it with a random numver between i/2 and (i*8 + (i/2))

4. Have a multiplication function retun the int to the update function

5. Have the update function chnage the values in the original array
6. Back in the main function, print the array befire and after the updates
*/

void update(int &num);
int multiplication(int num);

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int num[3] = {};
    std::cout << "intput 1: ";
    std::cin >> num[0];
    std::cout << "intput 2: ";
    std::cin >> num[1];
    std::cout << "intput 3: ";
    std::cin >> num[2];
    for(int i= 0; i< 3; i++){
        update(num[i]);
    }


    for(int i= 0; i< 3; i++){
        std::cout << "\nThe updated is : " << (num[i]) << " for " << i+1;
    }




    return 0;
}

void update(int &num){
    int temp = multiplication(num);
    num = temp;

}


int multiplication(int num){
    int random = (rand() % 8) +1 ;
    std::cout << "\nRandom: " << random;
    float eandom2 = (random)*num + (num/2);
    return eandom2;
}