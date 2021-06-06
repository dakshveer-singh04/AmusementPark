#include "Admin.h"
#include <fstream>
#include <iostream>

using namespace std;

Admin::Admin(){
    loadPass();
}

void Admin::loadPass(){
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