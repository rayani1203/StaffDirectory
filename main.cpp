#include <iostream>
#include "Directory.hpp"
#include "StaffMember.hpp"

int main(){
    std::cout<<"Hello, welcome to the staff directory system. To begin, please enter anything:"<<std::endl;
    std::string start;
    std::cin>>start;
    std::cout<<std::endl;

    Directory * staffDirectory = new Directory();

    //Create an array of staff members to hold the new staff members being created 
    std::cout<<"Enter the number (integer) of staff you wish to be able to create: "<<std::endl;
    int capacity;
    std::cin>>capacity;
    StaffMember * Members[capacity];
    
    //Variable to track the number of staff members that have been created and which tells you which element of the array is being manipulated
    int count = 0;
    while(true){
        restart:
        std::cout<<"Select one of the following options by pressing the corresponding key:"<<std::endl;
        std::cout<<"Insert a new staff member (I),\nRemove a staff member (R),\nSort the staff by their role (S),\nPrint the staff directory(P),\nTerminate the program (T)"<<std::endl;

        char input;
        std::cin>>input;
        std::cout<<std::endl;

        //End the program if the user chooses to terminate
        if(tolower(input) == 't'){
            return 0;
        }

        //If the user chooses to insert
        else if(tolower(input) == 'i'){
            //If the array created at the beginning is full
            if(count == capacity){
                std::cout<<"Sorry, you have created the maximum amount of staff that you allowed. You cannot create any more staff members."<<std::endl;
                std::cout<<std::endl;
                goto restart;
            }

            //Enter the name, age, ID and role of the new staff member
            std::string name;
            std::cout<<"Enter the new staff member's name:"<<std::endl;
            std::cin>>name;
            std::cout<<std::endl;
            
            int age;
            std::cout<<"Their age?"<<std::endl;
            std::cin>>age;
            std::cout<<std::endl;

            int ID;
            std::cout<<"Enter a unique ID for them: "<<std::endl;
            std::cin>>ID;
            std::cout<<std::endl;

            role:
            char role;
            std::cout<<"Finally, enter their role in the company as a single character: Associate (A), Manager (M), or Partner (P)"<<std::endl;
            std::cin>>role;
            std::cout<<std::endl;
            //If the user's input is not a valid role, allow them to try again
            if((tolower(role) != 'm') && (tolower(role) != 'a') && (tolower(role) != 'p')){
                std::cout<<"Sorry, this is not a valid role. Please try again:"<<std::endl;
                goto role;
            }

            //Create a new staff member with the parameters defined by the user
            Members[count] = new StaffMember(age, name, ID, role);

            //Insert the new staff into the directory
            insert:
            std::cout<<"Would you like to insert them at the front (F) or back (B) of the directory?"<<std::endl;
            std::cin>>input;
            std::cout<<std::endl;

            if(tolower(input) == 'b'){
                staffDirectory->insert_at_back(Members[count]);
            }
            else if(tolower(input) == 'f'){
                staffDirectory->insert_at_front(Members[count]);
            }
            //If the user does not enter a valid input, let them try again
            else{
                std::cout<<"Sorry, that input was not recognized, please try again.";
                std::cout<<std::endl;
                goto insert;
            }
            //Increment the variable tracking the number of staff members created
            count++;
        }

        else if(tolower(input) == 'r'){
            remove:
            std::cout<<"Would you like to identify the staff member you are removing by ID (I) or name (N)?"<<std::endl;
            std::cin>>input;
            std::cout<<std::endl;

            if(tolower(input) == 'i'){
                int IDinput;
                std::cout<<"Please enter the ID of the staff member you would like to remove: "<<std::endl;
                std::cin>>IDinput;
                std::cout<<std::endl;

                staffDirectory->remove(IDinput);
            }

            else if(tolower(input) == 'n'){
                std::string name;
                std::cout<<"Please enter the name of the staff member you would like to remove: "<<std::endl;
                std::cin>>name;
                std::cout<<std::endl;

                staffDirectory->remove(name);
            }

            else{
                std::cout<<"Sorry, that input was not recognized, please try again."<<std::endl;
                std::cout<<std::endl;
                goto remove;
            }
        }

        else if(tolower(input) == 's'){
            staffDirectory->sort_by_role();
        }

        else if(tolower(input) == 'p'){
            print:
            std::cout<<"Would you like to print the entire directory (E) or a specific staff member (S)?"<<std::endl;
            std::cin>>input;
            std::cout<<std::endl;

            if(tolower(input) == 'e'){
                staffDirectory->print();
            }

            else if(tolower(input) == 's'){
                specificPrint:
                std::cout<<"Would you like to identify the specific staff member by their ID (I) or location in directory (L)?"<<std::endl;
                std::cin>>input;
                std::cout<<std::endl;

                if(tolower(input) == 'i'){
                    int IDinput;
                    std::cout<<"Please enter the ID of the staff member you wish to print: ";
                    std::cin>>IDinput;
                    std::cout<<std::endl;

                    staffDirectory->print_ID(IDinput);
                }

                else if(tolower(input) == 'l'){
                    int location;
                    std::cout<<"Enter the loction in the directory (1, 2, 3, ...) of the staff member you wish to print: ";
                    std::cin>>location;
                    std::cout<<std::endl;

                    staffDirectory->print(location);
                }

                else{
                    std::cout<<"Sorry, that input was not recognized, please try again.";
                    std::cout<<std::endl;
                    goto specificPrint; 
                }
            }
            
            else{
                std::cout<<"Sorry, that input was not recognized, please try again.";
                std::cout<<std::endl;
                goto print; 
            }
        }
    }
    return 0;
}