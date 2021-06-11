#pragma once
#include "Ride.h"
#include "Extras.cpp"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//Ride password is parkRide_<ride_uid>

Ride::Ride(int CurrID){
    this->loadData(CurrID);
    this->getSessionCount();
    cout<<"Ride Instance created successfully!"<<endl;
}

void Ride::loadData(unsigned short int CurrID){
    string line;
    ifstream file;
     
    file.open("../Files/Rides/Rides.txt");
    
    while(getline(file,line)){
        stringstream ss(line);

        unsigned short int minAge, maxAge, occupancy;
        string ride_name, desc, tmp;

        int tmpId;
        ss>>tmpId;

        if (tmpId==CurrID){
            getline(ss,tmp,',');
            getline(ss,name,',');
            getline(ss,desc,',');
            ss>>minAge;
            getline(ss,tmp,',');
            ss>>maxAge;
            getline(ss,tmp,',');
            ss>>occupancy;

            this->setData(CurrID,ride_name,desc,min_age,max_age,occupancy);

            break;
        }
    }
}

void Ride::setData(unsigned int uid, string ride_name, string desc, unsigned short int minAge, unsigned short int maxAge, unsigned short int occu){
    this->RideUid=uid;
    this->name = ride_name;
    this->description = desc;
    this->min_age = minAge;
    this->max_age = maxAge;
    this->occupancy = occu;
}


int Ride::getSessionId(){

    string path("../Files/Rides/Ride");
    path.append( to_string(this->RideUid));
    path.append(".txt");


    fstream rideFile;
    rideFile.open(path);

    string date;
    rideFile>>date;

    if (date == getDate()) {
        int ans;
        rideFile>>ans;
        this->SessionCount = ans;

    } else {
        this->SessionCount = 0;
    }
}


void Ride::putSessionId(){
    string path("../Files/Rides/Ride");
    path.append( to_string(this->RideUid));
    path.append(".txt");

    fstream rideFile;
    rideFile.open(path);

    string date;
    rideFile<<getDate()<<endl;
    rideFile<<this->SessionCount<<endl;
}

void Ride::getSessionCount(){
    string path("../Files/Rides/Ride");
    path.append( to_string(this->RideUid));
    path.append(".txt");

    ifstream rideFile;
    rideFile.open(path);

    string tmp;
    int ans;
    rideFile>>tmp;
    rideFile>>ans;

    cout<<"Session Count is "<<ans<<endl;
    this->SessionCount = ans;
}


void Ride::StartNewSession(){

    int SessionId = ++ this->SessionCount;
    
}

