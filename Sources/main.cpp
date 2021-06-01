#include "../Headers/Guest.cpp"
#include "../Headers/Ride.cpp"
#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;
int i;

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
        cout<<"4. Guest Booking New"<<endl;
        cout<<"5. Guest Login"<<endl ;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:{
                int admin ;
                cout<<"Enter your admin id\t" ;
                cin>>admin ;


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
                int tickets ;
                cout<<"Unsaved data will be lost"<<endl;
                cout<<"How many tickets you want to book\t" ;
                cin>>tickets ;
                ch=0;
                for (int x=0 ; x<tickets ; x++)
                {
                    i++ ;
                    number[i].entry() ;     // entry for guest number i object
                    database.insert(make_pair(i,number[i])) ;
                    cout<<"Your uid is "<<i<<endl ;  
                }
                break;
            }

            case 5:{
                cout<<"Enter your UID"<<endl ;
                cin>>uid ;
                auto itr = database.find(uid) ;
                Guest tmp_obj = itr->second ;
                tmp_obj.bookride() ;

            }

            default:{
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }

    } while(ch);

    return 0;
}