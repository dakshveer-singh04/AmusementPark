#pragma once
#include <string>
#include <iostream>

unsigned int id ;

using namespace std;

class Guest{
    private : 
        unsigned int uid; 
        bool booking_status;
        string name;
        unsigned short int age;
        char gender;
        unsigned int height;
        
    public:
        void entry() ;
        void bookride() ;
        
};

class admin{
    private:
    unsigned int admin_id ;
    
    public:
    void login(int admin_id) ;
    
};