#pragma once
#include <string>

using namespace std;

class Ride{
    signed int RideUid;
    string name;
    string description;

    unsigned short int min_age;
    unsigned short int max_age;

    public: 

    Ride(unsigned int, string, string, unsigned short int, unsigned short int);
};