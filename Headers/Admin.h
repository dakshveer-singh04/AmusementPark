#pragma once
#include <string>

using namespace std;

class Admin{
    string pass;
    float guestIndex;
    unsigned int rideCount;
    unsigned int maxRideCount;

    void loadPass();
    void changePass();

    void loadRideCount();
    void updateRideCount(int);
    
    void loadMaxRideCount();
    void updateMaxRideCount(int);

    void addRide();
    void deleteRide();

    void updateRide();

    void searchGuest();

    public :

    Admin();
    friend int main();
};