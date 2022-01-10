#include <iostream>
#include "StaffMember.hpp"
#include "Directory.hpp"

//StaffMember function definitions
StaffMember::StaffMember(int age, std::string name, int ID, char role){
    staffAge = age;
    staffName = name;
    staffID = ID;
    staffRole = role;
}

StaffMember::StaffMember(){
    staffAge = 0;
    staffName = "";
    staffID = 0;
    staffRole = ' ';
}

StaffMember::~StaffMember(){

}

int StaffMember::get_age(){
    return staffAge;
}

std::string StaffMember::get_name(){
    return staffName;
}

int StaffMember::get_ID(){
    return staffID;
}

char StaffMember::get_role(){
    return staffRole;
}

StaffMember* StaffMember::get_next(){
    return p_next;
}

void StaffMember::set_age(int newAge){
    staffAge = newAge;
}

void StaffMember::set_name(std::string newName){
    staffName = newName;
}

void StaffMember::set_ID(int newID){
    staffID = newID;
}

void StaffMember::set_role(char newRole){
    staffRole = newRole;
}

void StaffMember::set_next(StaffMember* p_new_next){
    p_next = p_new_next;
}


//Directory function definitions
Directory::Directory(){
    p_head = nullptr;
}

Directory::~Directory(){
    while(p_head!=nullptr){
        StaffMember* p_old_head = p_head;
        p_head = p_head->get_next();
        delete p_old_head;
        p_old_head = nullptr;
    }
}


StaffMember* Directory::get_p_head(){
    return p_head;
}

//Insert a new node(staff member at the back of the linked list)
void Directory::insert_at_back(StaffMember* p_new_staff){
    StaffMember* p_travis = p_head;
    //If this is the first element in the list
    if(p_head == nullptr){
        p_head = p_new_staff;
        std::cout<<"Inserting " + p_new_staff->get_name() + " ..."<<std::endl;
        std::cout<<std::endl;
    }
    else{
        //Find the last element of the linked list and insert the new element after it
        while(p_travis->get_next() != nullptr){
            p_travis = p_travis->get_next();
        }
        p_travis->set_next(p_new_staff);
        p_new_staff->set_next(nullptr);
        std::cout<<"Inserting " + p_new_staff->get_name() + " into the back of the directory ..."<<std::endl;
        std::cout<<std::endl;
    }
}

//Insert a new staff member at the front of the linked list and make it the head of the list
void Directory::insert_at_front(StaffMember* p_new_staff){
    StaffMember* p_temp = p_head;
    p_new_staff->set_next(p_temp);
    p_head = p_new_staff;
    std::cout<<"Inserting " + p_new_staff->get_name() + " ..."<<std::endl;
    std::cout<<std::endl;
}

//Print an entire directory
void Directory::print(){
    std::cout<<"Printing the entire directory...";
    std::cout<<std::endl;
    
    StaffMember* p_travis = p_head;
    
    int count = 0;
    //Iterate over the entire linked list and print each element of the list
    while(p_travis != nullptr){
        count++;
        print(count);
        p_travis = p_travis->get_next();
    }
    std::cout<<"----END OF DIRECTORY-----"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

//Print a specific staff member based on their location within the directory
void Directory::print(int location){
    StaffMember* p_travis = p_head;
    if(p_head == nullptr){
        std::cout<<"Sorry, there are no staff members to print."<<std::endl;
        std::cout<<std::endl;
        return;
    }
    //Ensure the location provided is within the list
    int i = 1;
    while(p_travis != nullptr){
        p_travis = p_travis->get_next();
        i++;
    }
    if(location > i){
        std::cout<<"Sorry, the location you have specified does not exist in this directory as it is larger than its capacity."<<std::endl;
    }

    //Find the element of the list specified by the location parameter and print its information
    i = 1;
    p_travis = p_head;
    while((i < location) && (p_travis != nullptr)){
        p_travis = p_travis->get_next();
        i++;
    }
    std::cout<<"Staff Member Number "<<i<<":"<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"Name: "<<p_travis->get_name()<<std::endl;
    std::cout<<"Age: "<<p_travis->get_age()<<std::endl;
    std::cout<<"ID: "<<p_travis->get_ID()<<std::endl;
    std::cout<<"Role: "<<p_travis->get_role()<<std::endl;
    std::cout<<std::endl;
}

//Print a specific staff member based on their ID
void Directory::print_ID(int ID){
    StaffMember * p_travis = p_head;
    if(p_head == nullptr){
        std::cout<<"Sorry, there are no staff members to print."<<std::endl;
        std::cout<<std::endl;
        return;
    }

    int count = 1;
    if(p_travis->get_ID() == ID){
        print(count);
    }
    count++;
    
    //Iterate through the linked list until the matching ID is found and print the corresponding element
    while((p_travis->get_next() != nullptr) && (p_travis->get_next()->get_ID() != ID)){
        p_travis = p_travis->get_next();
        count++;
    }
    //If no matching ID is found
    if(p_travis->get_next() == nullptr){
        std::cout<<"Sorry, there are no staff members in the directory with that ID"<<std::endl;
        std::cout<<std::endl;
    }
    else if(p_travis->get_next()->get_ID() == ID){
        print(count);
    }
}

//Remove a staff member from the directory based on their ID
void Directory::remove(int ID){
    StaffMember * p_travis = p_head;
    if(p_head == nullptr){
        std::cout<<"Sorry, there are no staff members to remove."<<std::endl;
        std::cout<<std::endl;
        return;
    }

    //If the first element is to be removed
    if(p_travis->get_ID() == ID){
        p_head = p_travis->get_next();
    }
    else{ //Iterate through the list, find the element with the corresponding ID, and remove it
    while((p_travis->get_next() != nullptr) && (p_travis->get_next()->get_ID() != ID)){
        p_travis = p_travis->get_next();
    }
    if(p_travis->get_next() == nullptr){
        std::cout<<"Sorry, there are no staff members in the directory with that ID"<<std::endl;
        std::cout<<std::endl;
    }
    else if(p_travis->get_next()->get_ID() == ID){
        std::cout<<"Removing staff member with ID "<<ID<<" ..."<<std::endl;
        std::cout<<std::endl;
        p_travis->set_next(p_travis->get_next()->get_next());
    }
    }
}

//Remove a staff member from the directory based on their name
//Same algorithm as remove by ID
void Directory::remove(std::string name){
    StaffMember * p_travis = p_head;
    if(p_head == nullptr){
        std::cout<<"Sorry, there are no staff members to remove."<<std::endl;
        std::cout<<std::endl;
        return;
    }
    if(p_travis->get_name() == name){
        p_head = p_travis->get_next();
    }
    else{
    while((p_travis->get_next() != nullptr) && (p_travis->get_next()->get_name() != name)){
        p_travis = p_travis->get_next();
    }
    if(p_travis->get_next() == nullptr){
        std::cout<<"Sorry, there are no staff members in the directory with that name. Note: this is case sensitive, so try matching case.";
        std::cout<<std::endl;
    }
    else if(p_travis->get_next()->get_name() == name){
        std::cout<<"Removing staff member with name "<<name<<" ..."<<std::endl;
        std::cout<<std::endl;
        p_travis->set_next(p_travis->get_next()->get_next());
    }
    }
}

//Sort the linked list based on the role of the staff members, juniormost members first
void Directory::sort_by_role(){
    std::cout<<"Sorting by role (Associate -> Manager -> Partner) ..."<<std::endl;
    std::cout<<std::endl;

    if(p_head == nullptr){
        std::cout<<"Sorry, there are no staff members to sort."<<std::endl;
        std::cout<<std::endl;
        return;
    }

    StaffMember * p_trav = p_head;
    StaffMember * p_prev = p_head;
    StaffMember * p_another = p_head;

    //Count the number of elements in the linked list
    int count = 0;
    while(p_trav != nullptr){
        count++;
        p_trav = p_trav->get_next();
    }

    //Isolate the head of the list to effectively create a second list that the first list is being sorted into
    p_trav = p_head->get_next();
    p_head->set_next(nullptr);

    for(int i = 1; i < count; i++){
        p_prev = p_trav;
        p_another = p_head;
        p_trav = p_trav->get_next();
        //If the role is associate (the lowest) insert it at the front
        if(tolower(p_prev->get_role()) == 'a'){
            insert_at_front(p_prev);
        }
        //If the role is partner (the highest) insert it at the back
        if(tolower(p_prev->get_role()) == 'p'){
            insert_at_back(p_prev);
        }
        if(tolower(p_prev->get_role()) == 'm'){
            //If the role is manager and there are only partners in the list, insert it at the front
            if(tolower(p_head->get_role()) == 'p'){
                p_another = p_head;
                p_prev->set_next(p_another);
                p_head = p_prev;
            } else {
             //Otherwise, if the role is manager, insert it as soon as the associates end
            while((p_another->get_next() != nullptr) && (tolower(p_another->get_next()->get_role()) == 'a')){
                p_another = p_another->get_next();
            }
            p_prev->set_next(p_another->get_next());
            p_another->set_next(p_prev);
        }
        }
    }
}