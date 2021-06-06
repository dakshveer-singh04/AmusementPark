#pragma once
#include <string>

using namespace std;

class Admin{
    string pass;
    unsigned int rideCount;

    void loadPass();
    void loadRideCount();
    void changePass();

    public :
    Admin();
    friend int main();
};

