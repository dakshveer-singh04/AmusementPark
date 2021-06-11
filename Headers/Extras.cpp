#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

bool FoundRide(unsigned short int CurrID){
    bool flag = false;
    string line;
    ifstream file;
     
    file.open("../Files/Rides/Rides.txt");
    
    while(getline(file,line)){
        stringstream ss(line);
        int tmpId;
        ss>>tmpId;
        if (tmpId==CurrID){
            flag=true;
            break;
        }
    }
    
    return flag;
}

string getDate(){
    time_t now = time(0) ;
    tm* date_time = localtime(&now) ;

    int day = date_time->tm_mday;
    int month = date_time->tm_mon+1 ;
    int year = date_time->tm_year+1900 ;

    stringstream time ;
    time<<year;

    if (month < 10)
        time<<"0" ;
    time<<month;

    if (day < 10)
        time<<"0";
    time<<day;

    return time.str();
}