#pragma once
#include <string>

using namespace std;

class Ride{
    signed int RideUid, SessionCount;
    string name;
    string description;

    unsigned short int min_age;
    unsigned short int max_age;
    unsigned short int occupancy;

    public: 

    Ride(int);
    void setData(unsigned int uid, string ride_name, string desc, unsigned short int minAge, unsigned short int maxAge, unsigned short int occu);
    void loadData(unsigned short int);

    void StartNewSession();

    int getSessionId();
    void putSessionId();

    void getSessionCount();
};