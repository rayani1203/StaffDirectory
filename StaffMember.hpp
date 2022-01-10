#include <iostream>

#ifndef STAFF
#define STAFF
class StaffMember
{
    public:
    //Constructor + Destructor
    StaffMember(int age, std::string name, int ID, char role);
    StaffMember();
    ~StaffMember();
    
    //Getters and setters
    int get_age();
    std::string get_name();
    int get_ID();
    char get_role();

    void set_age(int newAge);
    void set_name(std::string newName);
    void set_ID(int newID);
    void set_role(char newRole);

    void set_next(StaffMember* p_new_next);
    StaffMember* get_next();

    private:

    int staffAge;
    std::string staffName;
    int staffID;
    char staffRole;
    
    StaffMember *p_next;

};
#endif