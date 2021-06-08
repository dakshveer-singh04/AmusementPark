#include "Ride.h"

Ride::Ride(unsigned int uid, string ride_name, string desc, unsigned short int minAge, unsigned short int maxAge){
    this->RideUid=uid;
    this->name = ride_name;
    this->description = desc;
    this->min_age = minAge;
    this->max_age = maxAge;
}

