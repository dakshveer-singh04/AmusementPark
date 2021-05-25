#include "../Headers/Guest.cpp"
#include "../Headers/Ride.cpp"
#include <map>
#include <iostream>

using namespace std;
extern int i ;

int main(){
    unsigned int uid; 
    int ch;
    i = 0 ;
    Guest number[1000] ;  // array of objects
    map<unsigned int,Guest>database ;     // map

    do {
        cout<<"WELOCOME TO AMUSEMENT PARK"<<endl;

        cout<<"1. Admin Login"<<endl;
        cout<<"2. Support Login"<<endl;
        cout<<"3. Rides Login"<<endl;
        cout<<"4. Guest Login"<<endl;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:{
                cout<<""<<endl;
                break;
            }
            case 2:{
                cout<<""<<endl;
                break;
            }
            case 3:{
                cout<<""<<endl;
                break;
            }
            case 4:{
                cout<<"Unsaved data will be lost"<<endl;
                ch=0;
                i++ ;
                number[i].entry() ;     // entry for guest number i object
                database.insert(make_pair(i,number[i])) ;
                break;
            }
            default:{
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }

    } while(ch);

    return 0;
}