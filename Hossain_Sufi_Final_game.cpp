#include <iostream>
#include <iomanip>  //For setw for width
#include <ctime>    //for the time
#include <cstdlib>  //for the random functions

bool validation (int &n);   //input validation function
bool money(int &n, int &b); //budget validation function


int main(int argc, char const *argv[])
{       
    int difficulty; //for the level of difficulty
    int budget = 9000;  //starting budget that will be adjusted according to difficulty
    int placeholder_price;  //placeholder object
    
    int terrain;    //terrain 
    double Vehicle=0;   //The Actual score of the car 
    std::string level[3] = {"Easy" , "Medium" , "Hard"};    //array with difficulty names
    std::string area[3] = {"Jungle","Arctic","LeMans Race Track"};  //area names
    
    int wheel;  //for wheel inputs
    std::string tires[4] = {"Offroad", "Track", "Snow", "Current"}; //wheel names
    int tire_price[4] = {100, 200, 300, 0}; //wheel prices
    
    int suspension; //input
    std::string suspension_name[4] = {"Independent", "Double Wishbone", "Soft", "Current"}; //names
    int suspension_price[4] = {100, 200, 300, 0};   //prices

    int clerance;   //for ground clerance
    std::string clearance_name[4] = {"5 inches", "10 inches", "14 inches", "Current"};  //names
    int clearance_price[4] = {200, 100, 300, 0};    //prices

    int color;  //paint job selection
    std::string color_name[4] = {"Diamond encrusted", "Gold Plated", "White", "Gray"};  //names
    int color_price[4] = {5000, 1500, 100, 0};  //prices

    int engine; //different engines
    std::string engine_name[4] = {"Cosworth DFV V8", "Toyota 2JZ", "Hemi 5.7L", "Current Inline 3"};    //engine names
    int engine_price[4] = {500, 800, 1000, 0};  //prices

    int DT; //drive train
    std::string DT_name[4] = {"All wheel drive", "Rear wheel drive", "4 wheel drive", "Current front wheel drive"}; //names
    int DT_price[4] = {1000, 400, 700, 0};  //prices

    int headlight;  //input object
    std::string headlight_name[4] = {"LED", "RGB", "Flood lights", "Current"};  //names
    int headlight_price[4] = {300, 500, 800, 0};    //prices

    int spoiler;    //only a yes or no, custom input validation
    int spoiler_price = 500;

    int turbo;  //only yes or no, custom input validation
    int turbo_price = 500;

    std::cout << "      WELCOME TO RACING TYCOON!\n***Once this game starts, you must complete the entire game***\nPlease select your difficulty mode:\n"
              << "1: Easy\n2: Medium\n3: Hard\n"
              << "Please enter modes 1, 2, or 3: ";
    while(!(std::cin >> difficulty) || difficulty < 1 || difficulty > 3){    //input validation
        std::cout << "Invalid input! Enter again: ";
        std::cin.clear();                                    //clear failbit
        while(std::cin.get() != '\n'){}                      //flush input buffer
    }
    while(std::cin.get() != '\n'){} //again clears buffer since using cin

    std::cout << "\nWelcome to Racing Tycoon on " << level[difficulty-1] << " mode!\n";
    budget = (budget/difficulty);
    std::cout << "Since you are on "  << level[difficulty-1] << " mode, your current budget is: $" << budget;
    std::cout << "\n\nWhat terrain do you want to race in?\n1: Jungle\n2: Arctic\n3: LeMans Race Track"
              << "\nPlease enter terrain 1, 2, or 3: ";

    while(!(std::cin >> terrain) || terrain < 1 || terrain > 3){    //input validation
        std::cout << "Invalid input! Enter again: ";
        std::cin.clear();                                    //clear failbit
        while(std::cin.get() != '\n'){}                      //flush input buffer
    }
    while(std::cin.get() != '\n'){}

    std::cout << "You have chosen " << area[terrain-1] << " terrain!\n";
    
    //For Wheels
    std::cout << "\nWhat wheels do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(15) << tires[i] << "$" << tire_price[i] << '\n';   /// 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";
    
    while(1){
        while(validation(wheel))
            continue;
        placeholder_price = tire_price[wheel-1];
        std::cout << "You have chosen " << tires[wheel-1] << " wheels!\n";
        if(money(placeholder_price, budget) )
            continue;
        else
            break;
    }

    //for suspension:            //Indept is for offroad, double is for track, soft is for arctic
    std::cout << "\nWhat suspension configuration do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(16) << suspension_name[i] << "$" << suspension_price[i] << '\n';   /// 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";
    
    while(1){
        while(validation(suspension))
            continue;
        placeholder_price = suspension_price[suspension-1];
        std::cout << "You have chosen " << suspension_name[suspension-1] << " suspension system!\n";
        if(money(placeholder_price, budget) )
            continue;
        else
            break;
    }

   //ground clearance
    std::cout << "\nWhat level of ground clearence do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(15) << clearance_name[i] << "$" << clearance_price[i] << '\n';   /// 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";

    while(1){
        while(validation(clerance))
            continue;
        placeholder_price = clearance_price[clerance-1];
        std::cout << "You have chosen " << clearance_name[clerance-1] << " of ground clerance!\n";
        if(money(placeholder_price, budget) )
            continue;
        else
            break;
    }

    //color
    std::cout << "\nWhat paint job do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(20) << color_name[i] << "$" << color_price[i] << '\n';   /// 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";
    
    while(1){
        while(validation(color))
            continue;
        placeholder_price = color_price[color-1];
        std::cout << "You have chosen " << color_name[color-1] << " paint job!\n";
        if(money(placeholder_price, budget))
            continue;
        else
            break;
    }

    //engine                                    //consworth performs well at low temp, toyota has good tuning for track, hemi is pure power
    std::cout << "\nWhat engine do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(20) << engine_name[i] << "$" << engine_price[i] << '\n'; 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";
    
    while(1){
        while(validation(engine))
            continue;
        placeholder_price = engine_price[engine-1];
        std::cout << "You have chosen the " << engine_name[engine-1] << " engine!\n";
        if(money(placeholder_price, budget) )
            continue;
        else
            break;
    }

    //drive train: FWD, AWD, 4WD, RWD
    std::cout << "\nWhat drive train do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(30) << DT_name[i] << "$" << DT_price[i] << '\n';   /// 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";
    
    while(1){
        while(validation(DT))
            continue;
        placeholder_price = DT_price[DT-1];
        std::cout << "You have chosen the " << DT_name[DT-1] << " drive train!\n";
        if(money(placeholder_price, budget) )
            continue;
        else
            break;
    }

    //headlights 
    std::cout << "\nWhat headlights do you want?\n";
    for(int i = 0; i < 4; i++){
        std::cout << i+1 << " " << std::left << std::setw(15) << headlight_name[i] << "$" << headlight_price[i] << '\n';   /// 
    }
    std::cout << "\nPlease enter 1, 2, 3, or 4: ";
    
    while(1){
        while(validation(headlight))
            continue;
        placeholder_price = headlight_price[headlight-1];
        std::cout << "You have chosen the " << headlight_name[headlight-1] << " drive train!\n";
        if(money(placeholder_price, budget) )
            continue;
        else
            break;
    }

    //spoiler:down force
    std::cout << "\nDo you want to add a spoiler for $500 for added downforce?\n1: Yes \n2: No "
              << "\nPlease enter 1 or 2: ";

    while (1)
    {
        while(!(std::cin >> spoiler) || spoiler < 1 || spoiler > 2){    //input validation
            std::cout << "Invalid input! Enter again: ";
            std::cin.clear();                                    //clear failbit
            while(std::cin.get() != '\n'){}                      //flush input buffer
        }
        while(std::cin.get() != '\n'){}
        if(spoiler == 1){
            if((budget-spoiler_price)<0){
                std::cout << "You do not have enough purchasing power for this mod, please buy another mod!\n";
                std::cout<< "You have $" << budget  << " left in your budget, make a new selection: ";
                continue;
            }else{
                budget -= spoiler_price;
                std::cout<< "You have $" << budget  << " left in your budget.";
                break;
            }
        }else{
            break;
        }
    }

    //turbo
    std::cout << "\nDo you want to add a turbo for $500 for added power?\n1: Yes \n2: No "
              << "\nPlease enter 1 or 2: ";

    while (1)
    {
        while(!(std::cin >> turbo) || turbo < 1 || turbo > 2){    //input validation
            std::cout << "Invalid input! Enter again: ";
            std::cin.clear();                                    //clear failbit
            while(std::cin.get() != '\n'){}                      //flush input buffer
        }
        while(std::cin.get() != '\n'){}
        if(turbo == 1){
            if((budget-turbo_price)<0){
                std::cout << "You do not have enough purchasing power for this mod, please buy another mod!\n";
                std::cout<< "You have $" << budget  << " left in your budget, make a new selection: ";
                continue;
            }else{
                budget -= turbo_price;
                std::cout<< "You have $" << budget  << " left in your budget.";
                break;
            }
            
        }else{
            break;
        }
    }

    //display a list of mods done
    std::cout << "\n\nCONGRATULATIONS You have completed RACING TYCOON!\nHere is a list of modifications you have selected with prices:\n";
    std::cout << std::left << std::setw(18) << "Wheels: " << std::left << std::setw(27) <<tires[wheel-1] << "$" << tire_price[wheel-1] << std::endl;
    std::cout << std::left << std::setw(18) << "Suspension: " << std::left << std::setw(27) <<suspension_name[suspension-1] << "$" << suspension_price[suspension-1]<< std::endl;
    std::cout << std::left << std::setw(18) << "Ground Clearance: " << std::left << std::setw(27) << clearance_name[clerance-1] << "$" << clearance_price[clerance-1]<< std::endl;
    std::cout << std::left << std::setw(18) << "Paint: " << std::left << std::setw(27) <<color_name[color-1] << "$" << color_price[color-1]<< std::endl;
    std::cout << std::left << std::setw(18) << "Engine: " << std::left << std::setw(27) <<engine_name[engine-1] << "$" << engine_price[engine-1]<< std::endl;
    std::cout << std::left << std::setw(18) << "Drive Train: " << std::left << std::setw(27) <<DT_name[DT-1] << "$" << DT_price[DT-1]<< std::endl;
    std::cout << std::left << std::setw(18) << "Headlights: " <<  std::left << std::setw(27) <<headlight_name[headlight-1] << "$" << headlight_price[headlight-1]<< std::endl;
    std::cout << std::left << std::setw(18) << "Spoiler: " << std::left << std::setw(27) <<"Standard" << "$" << ((spoiler == 1)? "500" : "0") << std::endl;
    std::cout << std::left << std::setw(18) << "Turbo: " << std::left << std::setw(27) <<"Standard" << "$" << ((turbo == 1)? "500" : "0") << std::endl;

    Vehicle = 0;//three massive blocks depeding on terrain to add and calculate scores
    if(terrain == 1){   //calculating scores depending on terrain
        if(wheel == 1){
            Vehicle += 10;
        }else if(wheel == 2){
            Vehicle -= 5; //Track wheels have no traction offroad, very bad
        }
        if(suspension == 1){
            Vehicle += 10;
        }else if(suspension == 2 || suspension == 3){
            Vehicle += 5;   //half points in the jungle as even with other suspensions, it'll work
        }else if(suspension ==4){
            Vehicle -= 5;   //Negative points if bad suspension
        }
        if(clerance == 3){
            Vehicle += 10;  //14 inches is recommended for offroading
        }else if(clerance == 2){
            Vehicle += 5;   //10 inches is muimum offroading 
        }else if(clerance == 1 || clerance == 4){
            Vehicle -= 5;   //Anything lower than 10 inches is bad for offroading
        }
        if(engine == 3){
            Vehicle += 10;  //Hemi is great for offroading
        }else if(engine == 2 || engine == 1){
            Vehicle += 5;   //2jz and consworth are also good engines for offroading
        }
        if(DT == 3){
            Vehicle += 10;
        }else if(DT == 1){
            Vehicle += 5;   //AWD is sill beneficial offroad
        } else if(DT == 2 || DT == 4){
            Vehicle -= 5;   //RWD and FWD are not great offroad
        }
        if(headlight == 1 || headlight == 3){
            Vehicle += 5;   //these are good to have offroad
        }
        if(turbo == 1){
            Vehicle += 10;  //a turbo definitely helps improve performance
        }
    }else if(terrain == 2){
        if(wheel == 3){
            Vehicle += 10;
        }else if(wheel == 1){
            Vehicle += 5;   //offroad wheels might work on snow
        }else if(wheel == 2){
            Vehicle -= 5;   //track wheels are terrible for snow
        }
        if(suspension == 3){
            Vehicle += 10;
        }else if(suspension == 1 || suspension == 2){
            Vehicle += 5;
        }
        if(clerance == 2 || clerance == 3){
            Vehicle += 10;
        }else if(clerance == 1){
            Vehicle -= 5;   //5 inches is too low for snow
        }
        if(engine == 1){
            Vehicle += 10;
        }else if(engine == 2 || engine == 3){
            Vehicle += 5;   //Other engines are good and poweful as well
        }
        if(DT == 1){
            Vehicle += 10;
        }else if(DT == 3){
            Vehicle += 5;
        }else if(DT == 2 || DT == 4){
            Vehicle -= 5;   //Everthing else is not that great for snow
        }
        if(headlight == 1 || headlight == 3){
            Vehicle += 5;   //these are good to have in snow
        }
        if(turbo == 1){
            Vehicle += 10;  //a turbo definitely helps improve performance
        }
    }else if(terrain == 3){
        if(wheel == 2){
            Vehicle += 10;
        }else if(wheel == 3){
            Vehicle -= 5;   //Snow wheels are really bad for track
        }
        if(clerance == 1){
            Vehicle += 10;
        }else if(clerance == 2 || clerance == 3){
            Vehicle -= 5;   //too much height is bad on the track
        }
        if(engine == 2){
            Vehicle += 10;
        }else if(engine == 1 || engine == 3){
            Vehicle += 5;   //Others are powerful engine
        }
        if(DT == 1){
            Vehicle += 10;  //AWD is best for Racing
        }else if(DT == 2){
            Vehicle += 5;   //RWD is also good for racing
        }
        if(spoiler == 1){
            Vehicle += 10;   //This is great for downforce on track
        }
        if(turbo == 1){
            Vehicle += 10;  //a turbo definitely helps improve performance
        }
    }

    int position = 0;
    int savings = budget/100;   //they get savings points upto 10 points for every 100 dollars
    if(savings > 10){   //essentially the max points for savings one can get is 10 points
        savings = 10;   
    }
    Vehicle += savings;
    srand((unsigned)time(NULL));    //random seed
    int B_luck = rand() % 6; //finding the the bad luck factor 0-5
    Vehicle -= B_luck;
    std::cout << "\nYou had a savings variable of: " << savings << " for your remamining budget of $" << budget
              << "\nand this variable has been added to your total score.\n";
    std::cout << "\nYou had a bad luck variable of: " << B_luck << std::endl;
    if(B_luck == 0){
        std::cout << "Your vehicle is in it's best shape to race with your proposed modification!\n";
    }else if(B_luck == 1 || B_luck == 2){
        std::cout << "Your vehicle had some minor imperfections while it's production,\nthis may affect it's reliability on the track.\n";
    }else if(B_luck == 3){
        std::cout << "There is some kind of probelm that may hinder it's ability to compete properly!\n";
    }else if(B_luck ==4 || B_luck == 5){
        std::cout << "There is some major malfunction in your vehicle, maybe with the engine or transmission!\nSorry for your bad luck.\n";
    }

    //have a predermined list of scores, then calculate results
    if(terrain == 1){
        if(Vehicle == 62 ||Vehicle == 56 ||Vehicle == 50){  //lucky numbers for certain terrains
            Vehicle += 1;
            std::cout << "\nCongratulations, you are lucky, you get +1 point for your score!\nYour Vehicle socre matched the lucky number for this terrain!\n";   //A good luck charm if they are lucky
        }
        if(Vehicle >62){
            position = 1;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 1       |          62\n"
                << "Racer 2       |          56\n"
                << "Racer 3       |          50\n";
        }else if(Vehicle > 56){
            position = 2;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          62\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 2       |          56\n"
                << "Racer 3       |          50\n";
        }else if(Vehicle > 50){
            position = 3;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          62\n"
                << "Racer 2       |          56\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 3       |          50\n";
        }else{
            position = 4;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          62\n"
                << "Racer 2       |          56\n"
                << "Racer 3       |          50\n"
                << "  You         |          " << Vehicle << std::endl;
        }
    }else if(terrain == 2){
        if(Vehicle == 62 ||Vehicle == 56 ||Vehicle == 50){
            Vehicle += 1;
            std::cout << "\nCongratulations, you are lucky, you get +1 point for your score!\nYour Vehicle socre matched the lucky number for this terrain!\n";   //A good luck charm if they are lucky
        }
        if(Vehicle > 62){
            position = 1;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 1       |          62\n"
                << "Racer 2       |          56\n"
                << "Racer 3       |          50\n";
        }else if(Vehicle > 56){
            position = 2;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          62\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 2       |          56\n"
                << "Racer 3       |          50\n";
        }else if(Vehicle > 50){
            position = 3;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          62\n"
                << "Racer 2       |          56\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 3       |          50\n";
        }else{
            position = 4;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          62\n"
                << "Racer 2       |          56\n"
                << "Racer 3       |          50\n"
                << "  You         |          " << Vehicle << std::endl;
        }

    }else if(terrain == 3){
        if(Vehicle == 56 ||Vehicle == 49 ||Vehicle == 44){
            Vehicle += 1;
            std::cout << "\nCongratulations, you are lucky, you get +1 point for your score!\nYour Vehicle socre matched the lucky number for this terrain!\n";   //A good luck charm if they are lucky
        }
        if(Vehicle > 56){
            position = 1;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 1       |          56\n"
                << "Racer 2       |          49\n"
                << "Racer 3       |          44\n";
        }else if(Vehicle > 49){
            position = 2;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          56\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 2       |          49\n"
                << "Racer 3       |          44\n";
        }else if(Vehicle > 44){
            position = 3;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          56\n"
                << "Racer 2       |          49\n"
                << "  You         |          " << Vehicle << std::endl
                << "Racer 3       |          44\n";
        }else{
            position = 4;
            std::cout << "You are at position: " << position << std::endl;
            std::cout << "Your competitiors had vehicle scores of: \n";
            std::cout << "Competitor    |   Vehicle Score\n"
                << "Racer 1       |          56\n"
                << "Racer 2       |          49\n"
                << "Racer 3       |          44\n"
                << "  You         |          " << Vehicle << std::endl;
        }

    }
    if(terrain == 1){
        if(position == 1){
            std::cout << "\nCongratulations! You WON! You have the best vehicle score compared to the comeptition."
                      << "\nSince you are on " << level[difficulty-1]  << " mode, you have made the best choices"
                      << "\nhence there are no suggestions!\n\n";
        }else if(position >= 2){
            std::cout << "\nSorry, you did not have the highest vehicle score, you did not win."
                      << "\nYou needed to be at position 1 to win, you are at position " << position
                      << "\nSince you are on " << area[terrain-1] << " terrain, the following choices would have been the best choices:\n"
                      << "Offroad wheels, independent suspensions, 14 inches of ground clerance, a Hemi 5.7L engine,\n4 wheel drive, with flood lights, and a turbo.\n\n";
        }
    }else if(terrain == 2){
        if(position == 1){
            std::cout << "\nCongratulations! You WON! You have the best vehicle score compared to the comeptition."
                      << "\nSince you are on " << level[difficulty-1]  << " mode, you have made the best choices"
                      << "\nhence there are no suggestions!\n\n";
        }else if(position >= 2){
            std::cout << "\nSorry, you did not have the highest vehicle score, you did not win."
                      << "\nYou needed to be at position 1 to win, you are at position " << position
                      << "\nSince you are on " << area[terrain-1] << " terrain, the following choices would have been the best choices:\n"
                      << "Snow tires, soft suspensions, atleast 10 inches of ground clerace, a Consworth engine,\nall wheel drive, and a turbo for added power.\n\n";
        }
    }else if(terrain == 3){
        if(position == 1){
            std::cout << "\nCongratulations! You WON! You have the best vehicle score compared to the comeptition."
                      << "\nSince you are on " << level[difficulty-1]  << " mode, you have made the best choices"
                      << "\nhence there are no suggestions!\n\n";
        }else if(position >= 2){
            std::cout << "\nSorry, you did not have the highest vehicle score, you did not win."
                      << "\nYou needed to be at position 1 to win, you are at position " << position
                      << "\nSince you are on " << area[terrain-1] << " terrain, the following choices would have been the best choices:\n"
                      << "Track tires, double wishbone suspensions, low ground clerance for aero dynamics ~5 inches,\na 2JZ engine or a HEMI 5.7L, with all wheel or rear wheel drive, and a turbo and spoiler for added power and grip.\n\n";
        }
    }
    std::cout << "Thank you for playing RACING TYCOON!\nPlease play again soon!";

    return 0;
}

bool validation (int &n){   //passby ref
    std::cin >> n;  //we take the input inside
    if( n < 1 || n > 4){    //input validation  
        std::cout << "Invalid input! Enter again: ";
        std::cin.clear();    //clear failbit
        while(std::cin.get() != '\n'){} //flush input buffer
        return true;    
    }else{
        while(std::cin.get() != '\n'){}
        return false;
    }
}

bool money(int &money, int &budget){    //passby ref to change actual values
    if((budget-money) < 0){
        std::cout << "You do not have enough purchasing power for this mod, please buy another mod!\n";
        std::cout<< "You have $" << budget  << " left in your budget, make a new selection: ";
        return true;    //so the if statement runs
    }else{
        budget -= money;
        std::cout<< "You have $" << budget  << " left in your budget\n";
        return false;
    }
}