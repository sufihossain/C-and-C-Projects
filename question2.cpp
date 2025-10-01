// LastName_FirstName_Q2.cpp for Q2
#include <iostream>
#include <vector>
#include <string>
    //VERYYY HARD
struct Component {
    double length;    // in mm
    double width;     // in mm
    double height;    // in mm
    double unitPrice; // in dollars
    int quantity;     // quantity of a component type
};

int main(int argc, char const *argv[])
{
    //std::vector <double> length;

    std::vector <Component> item;
    std::cout << "*** PCB calculator ***\n";
    int counter;
    Component temp; //VERYY OMPORTANT CONCEPT
    //RELEARN!!!!
    
    std::cout << "\nEnter the length of component #1 in mm: ";
        std::cin >> temp.length;
        std::cout << "Enter the width of component #1 in mm: ";
        std::cin >> temp.width;
        std::cout <<  "Enter the height of component #1 in mm: ";
        std::cin >> temp.height;
        std::cout <<  "Enter the unit price of component #1 in dollars: ";
        std::cin >> temp.unitPrice;
        std::cout << "Enter the quantity of component #1 being used: ";
        std::cin >> temp.quantity;
        item.push_back(temp);
        while(std::cin.get() != '\n'){}
        std::cout << "Enter a lowercase y to continue or anything else to exit: ";
    //int i =0;
    while(std::cin.get() == 'y'){
        while(std::cin.get() != '\n'){} //clearing buffer
        std::cout << "\nEnter the length of component #1 in mm: ";
        std::cin >> temp.length;
        //std::cin >> item[i].length;// This doesnt' work
        std::cout << "Enter the width of component #1 in mm: ";
        std::cin >> temp.width;
        //std::cin >> item[i].width;// This doesnt' work
        std::cout <<  "Enter the height of component #1 in mm: ";
        std::cin >> temp.height;
        //std::cin >> item[i].height;// This doesnt' work
        std::cout <<  "Enter the unit price of component #1 in dollars: ";
        std::cin >> temp.unitPrice;
        //std::cin >> item[i].unitPrice;// This doesnt' work
        std::cout << "Enter the quantity of component #1 being used: ";
        std::cin >> temp.quantity;
        //std::cin >> item[i].quantity;// This doesnt' work
        item.push_back(temp);
        while(std::cin.get() != '\n'){}
        std::cout << "Enter a lowercase y to continue or anything else to exit: ";
        //i++;
    }
    double highest =0, area = 0, cost=0;
    for(int i = 0; i < item.size(); i++){
        if(item[i].height > highest){
            highest = item[i].height;
        }
        area += item[i].length * item[i].width * item[i].quantity;
        cost += item[i].quantity * item[i].unitPrice;
    }
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << "\nMaximum height of the components: " << highest << " mm^2\n";
    std::cout << "Total area of the components: " << area << " mm^2\n";
    std::cout << "Total cost of the components: $" << cost ;
    return 0;
}


/*
Sample	run	#2 (Hint: Combined base	area=	7.5 *	3 *	2 +	6.3	* 2.5	*	3	+	5	*	5	*	2	=	142.25):
*** PCB calculator ***

Enter the length of component #1 in mm: 7.5
Enter the width of component #1 in mm: 3
Enter the height of component #1 in mm: 5
Enter the unit price of component #1 in dollars: 0.15
Enter the quantity of component #1 being used: 2
Enter a lowercase y to continue or anything else to exit: y

Enter the length of component #2 in mm: 6.3
Enter the width of component #2 in mm: 2.5
Enter the height of component #2 in mm: 2.5
Enter the unit price of component #2 in dollars: 0.17
Enter the quantity of component #2 being used: 3
Enter a lowercase y to continue or anything else to exit: y

Enter the length of component #3 in mm: 5
Enter the width of component #3 in mm: 5
Enter the height of component #3 in mm: 10
Enter the unit price of component #3 in dollars: 0.71
Enter the quantity of component #3 being used: 2
Enter a lowercase y to continue or anything else to exit: n

Maximum height of the components: 10.00 mm
Total area of the components: 142.25 mm^2
Total cost of the components: $2.23
*/