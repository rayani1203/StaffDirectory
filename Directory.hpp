#include <iostream>
#include "StaffMember.hpp"

class Directory
{
    public:
    Directory();
    ~Directory();

    StaffMember* get_p_head();
    
    void insert_at_front(StaffMember* p_new_staff);
    void insert_at_back(StaffMember* p_new_staff);
    void print();
    void print(int location);
    void print_ID(int ID);
    void remove(int ID);
    void remove(std::string name);
    void sort_by_role();

    private:
    StaffMember *p_head;
};

