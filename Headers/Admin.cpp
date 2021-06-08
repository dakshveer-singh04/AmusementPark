#include "Admin.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Admin::Admin(){
    loadPass();
    loadRideCount();
    loadMaxRideCount();
}

void Admin::loadPass(){
    /*  Function to read the password from file
        and load it in the Class
    */
    string p;

    ifstream file;
    file.open("../Files/Admin/Password.txt");

    if(file.is_open()){
        file >> p;
        file.close(); 
    } else{
        cout<<"Error opening password" <<endl;
        return;
    }

    this->pass = p;
}


void Admin::changePass(){
    /*  Function to change password*/

    //later add a password checker 
    string old_pass,pass1,pass2;
    do {
        cout<<"Enter old password : ";
        cin>>old_pass;
    } while( old_pass != this->pass);
    
    do {
        cout<<"Enter new password : ";
        cin>>pass1;
        cout<<"Confirm password : ";
        cin>>pass2;

        if ( pass1 == pass2 ){
            
            ofstream file;
            file.open("../Files/Admin/Password.txt");
            file.seekp(0);
            file<<pass1;
            file.close();

            this->loadPass();
            break;
        }
        else{
            cout<<"The passwords don't match! Try again! "<<endl;
        }

    } while( true );
}


void Admin::loadRideCount(){
    /*  Function to read the RideCount from file
        and load it in the Class
        
        First number in file is required
    */
    string s; char c;
    int i;

    ifstream file;
    file.open("../Files/Admin/Count.txt");

    if(file.is_open()){
        file >> s; // waste string
        file >> c; // waste char
        file >> i;
        file.close(); 

    } else{
        cout<<"Error opening Count" <<endl;
        return;
    }

    this->rideCount = i;
    cout<<"Current Count is : "<<this->rideCount<<endl;
}


void Admin::updateRideCount(int j){
    /*  Function to update the RideCount from file
        and load it in the Class
        
        First number in file is required
    */
    string s("Ride : ");

    fstream file;
    file.open("../Files/Admin/Count.txt");

    if(file.is_open()){
        file<< s<< j<<endl;
        file.close(); 
        
    } else{
        cout<<"Error opening Count" <<endl;
        return;
    }

    cout<<"Current Count is : "<<j<<endl;
    this->rideCount = j ;
}


void Admin::loadMaxRideCount(){
    /*  Function to read the RideCount from file
        and load it in the Class
        
        First number in file is required
    */
    string s; char c;
    int i;

    ifstream file;
    file.open("../Files/Admin/Count.txt");
    
    file>>s>>c>>i;

    if(file.is_open()){
        file>>s>>c>>i;
        file.close(); 

    } else{
        cout<<"Error opening Count" <<endl;
        return;
    }

    this->maxRideCount = i;
    cout<<"Current Count is : "<<this->maxRideCount<<endl;
}


void Admin::updateMaxRideCount(int j){
    /*  Function to update the RideCount from file
        and load it in the Class
        
        First number in file is required
    */
    string s("MaxRide : "),tmp;
    char c; int i;

    fstream file;

    file.open("../Files/Admin/Count.txt");
    file>>tmp>>c>>i;
    if(file.is_open()){
        file<<s<<j<<endl;
        file.close(); 
        
    } else{
        cout<<"Error opening Count" <<endl;
        return;
    }
    
    cout<<"Current max Count is : "<<j<<endl;
    this->maxRideCount = j ;
}



void Admin::addRide(){
    unsigned int uid = this->maxRideCount + 1;
    unsigned short int minAge, maxAge;
    string ride_name,desc;

    cout<<"Enter ride name : ";
    cin.ignore();
    cin>>ride_name;

    cout<<"Enter ride description : ";
    cin.ignore();
    getline(cin,desc);

    cout<<"Enter minimum age : ";
    cin>>minAge;

    cout<<"Enter maximum age : ";
    cin>>maxAge;

    stringstream ss;
    ss<<uid<<",";
    ss<<ride_name<<",";
    ss<<desc<<",";
    ss<<minAge<<",";
    ss<<maxAge<<'\n';

    fstream file;
    file.open("../Files/Rides/Rides.txt");

    if (file.is_open()){
        string s;
        for (int i=0; i<this->rideCount; i++){
            getline(file,s);
        }
        file<<ss.str();

        this->rideCount++;
        this->updateRideCount(this->rideCount);
        this->maxRideCount++;
        this->updateMaxRideCount(this->maxRideCount);
    } 
    else{
        cout<<"Problem opening Rides file!"<<endl;  
    }
}

void Admin::deleteRide(){
    int id;
    cout<<"Enter ride Id to delete : ";
    cin>>id;

    if ( id>this->maxRideCount || id<1 ){
        cout<<"Invalid Id to delete!"<<endl;
    } else{
        bool flag=false;
        string line;
    
        ifstream file;
        file.open("../Files/Rides/Rides.txt");
        ofstream outfile("../Files/Rides/tmp.txt"); //file to store non deleted values

        while(getline(file,line)){
            stringstream ss(line);
            int tmpId;
            ss>>tmpId;
            if (tmpId!=id){
                outfile<<line<<endl;
            } else if (tmpId==id) {
                flag=true;
            }
        }

        outfile.close();
        file.close();

        //deleting previous file
        remove("../Files/Rides/Rides.txt");
        rename("../Files/Rides/tmp.txt","../Files/Rides/Rides.txt");
    
        if (flag){
            this->rideCount--;
            this->updateRideCount(this->rideCount);
            cout<<"Ride deleted successfully"<<endl;
        } else{
            cout<<"Ride not found!"<<endl;
        }
    }
}